#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<pll> A(M);
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first < b.first; });
    vector<vector<ll>> V;
    ll p = 0;
    REP(i, M) {
        if (p != A[i].first) {
            vector<ll> v;
            V.push_back(v);
        }
        ll idx = V.size() - 1;
        V[idx].push_back(A[i].second);
        p = A[i].first;
    }
    set<ll> st;
    st.insert(N);
    REP(i, V.size()) {
        set<ll> rem, ins;
        REP(j, V[i].size()) {
            if (st.find(V[i][j]) != st.end()) {
                rem.insert(V[i][j]);
            }
            if (st.find(V[i][j] - 1) != st.end()) {
                ins.insert(V[i][j]);
            }
            if (st.find(V[i][j] + 1) != st.end()) {
                ins.insert(V[i][j]);
            }
        }

        for (auto &v:rem) {
            st.erase(v);
        }
        for (auto &v:ins) {
            st.insert(v);
        }
#if false
        for (auto &v:st) {
            cout << v << " ";
        }
        cout << endl;
#endif
    }

    ll ans = st.size();
    cout << ans << endl;

    return 0;
}