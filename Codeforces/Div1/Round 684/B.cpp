#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

void solve() {
    ll N, M, K;
    cin >> N >> M >> K;
    vector<Vertex> v(N);
    map<pll, bool> edge;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].node.push_back(b);
        v[b].node.push_back(a);
        edge[pll(std::min(a, b), std::max(a, b))] = true;
    }
    {
        std::set<pll> st;
        vector<bool> enable(N, true);
        vector<ll> count(N, 0);
        REP(i, N) {
            count[i] = v[i].node.size();
            st.insert(pll(count[i], i));
        }
        vector<ll> ans;
        while (!st.empty()) {
            auto p = st.begin();
            //cout << p->first << " " << p->second << endl;
            if (p->first < K) {
                ll index = p->second;
                REP(i, v[index].node.size()) {
                    ll nxt = v[index].node[i];
                    if (!enable[nxt])
                        continue;
                    auto x = st.find(pll(count[nxt], nxt));
                    if (x == st.end())
                        continue;
                    st.erase(x);
                    count[nxt]--;
                    st.insert(pll(count[nxt], nxt));
                }
            }
            else {
                ans.push_back(p->second);
            }
            enable[p->second] = false;
            st.erase(p);
        }
        if (ans.size() > 0) {
            cout << 1 << " " << ans.size() << endl;
            REP(i, ans.size()) {
                cout << ans[i] + 1 << " ";
            }
            cout << endl;
            return;
        }
    }
    {
        //! clique
        std::set<pll> st;
        vector<ll> count(N, 0);
        vector<bool> enable(N, true);
        ll edge_num = M;
        REP(i, N) {
            count[i] = v[i].node.size();
            st.insert(pll(count[i], i));
        }
        while (!st.empty()) {
            if ((K - 1) * K / 2 > edge_num)
                break;
            auto p = st.begin();
            //cout << p->first << " " << p->second << endl;
            if (p->first < K - 1) {
                ll index = p->second;
                REP(i, v[index].node.size()) {
                    ll nxt = v[index].node[i];
                    if (!enable[nxt])
                        continue;
                    if (!edge[pll(std::min(index, nxt), std::max(index, nxt))])
                        continue;
                    auto x = st.find(pll(count[nxt], nxt));
                    if (x == st.end())
                        continue;
                    st.erase(x);
                    edge[pll(std::min(index, nxt), std::max(index, nxt))] = false;
                    count[nxt]--;
                    if (enable[nxt])
                        edge_num--;
                    st.insert(pll(count[nxt], nxt));
                }
            }
            else if (p->first >= K) {
                break;
            }
            else {
                ll index = p->second;
                vector<ll> vs;
                vs.push_back(p->second);
                REP(i, v[index].node.size()) {
                    ll nxt = v[index].node[i];
                    if (edge[pll(std::min(index, nxt), std::max(index, nxt))])
                        vs.push_back(nxt);
                }
                bool exist = true;
                REP(i, vs.size()) {
                    FOR(j, vs.size(), i + 1) {
                        ll a = vs[i];
                        ll b = vs[j];
                        if (!edge[pll(std::min(a, b), std::max(a, b))]) {
                            exist = false;
                            break;
                        }
                    }
                    if (!exist)
                        break;
                }

                if (exist) {
                    cout << 2 << endl;
                    REP(i, vs.size()) {
                        cout << vs[i] + 1 << " ";
                    }
                    cout << endl;
                    return;
                }
                std::map<ll, ll> mp;
                vector<ll> rmv;
                FOR(i, vs.size(), 1) {
                    ll idx = vs[i];
                    REP(j, v[vs[i]].node.size()) {
                        ll nxt = v[vs[i]].node[j];
                        if (!edge[pll(std::min(idx, nxt), std::max(idx, nxt))]) {
                            continue;
                        }
                        mp[nxt]++;
                        if (mp[nxt] == K - 1) {
                            rmv.push_back(nxt);
                        }
                    }
                }


                REP(i, rmv.size()) {
                    ll idx = rmv[i];
                    FOR(j, vs.size(), 1) {
                        ll nxt = vs[j];
                        auto x = st.find(pll(count[nxt], nxt));
                        if (x == st.end())
                            continue;
                        edge[pll(std::min(idx, nxt), std::max(idx, nxt))] = false;
                        st.erase(x);
                        count[nxt]--;
                        if (enable[nxt])
                            edge_num--;
                        st.insert(pll(count[nxt], nxt));
                    }
                    auto x = st.find(pll(count[idx], idx));
                    if (x == st.end())
                        continue;
                    st.erase(x);
                    count[idx] -= K - 1;
                    edge_num -= K - 1;
                    if (count[idx] > 0)
                        st.insert(pll(count[idx], idx));
                    else {
                        enable[idx] = false;
                    }
                }
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}