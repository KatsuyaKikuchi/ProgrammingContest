#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<ll> siz;
std::map<ll, pll> fib_pair;

bool check2(const vector<ll> sub, ll fib) {
    REP(i, sub.size()) {
        if (sub[i] == fib)
            return true;
    }
    return false;
}

bool check(const vector<vector<ll>> &graph, ll idx, ll parent, ll fib0, ll fib1) {
    vector<ll> tmp;
    bool find = false;
    for (auto &nxt:graph[idx]) {
        if (nxt == parent)
            continue;
        if (find || siz[nxt] != fib0)
            tmp.push_back(siz[nxt]);
        else
            find = true;
    }
    if (!find)
        return false;
    // subだけでfib1が作れるかチェック
    vector<ll> sub;
    ll sum = 0;
    if (fib1 <= 3)
        return true;
    for (auto &t:tmp) {
        if (fib_pair.count(t) == 0 && t != 1)
            sum += t;
        else
            sub.push_back(t);
    }
    pll pair = fib_pair[fib1];
    if (sum > 0) {
        if (sub.size() >= 2)
            return false;
        if (sub.size() == 1) {
            return sub[0] == pair.first || sub[0] == pair.second;
        }
        return sum + 1 == fib1;
    }

    if (sub.size() == 1) {
        return fib1 == sub[0] + 1;
    }
    return check2(sub, pair.first) || check2(sub, pair.second);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<vector<ll>> v(N);
    REP(_, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<ll> fib;
    fib.push_back(1);
    fib.push_back(1);
    while (fib.back() < N) {
        ll n = fib.size() - 1;
        ll x = fib[n] + fib[n - 1];
        fib.push_back(x);
        fib_pair[x] = pll(fib[n], fib[n - 1]);
    }

    if (fib.back() != N) {
        cout << "NO" << endl;
        return 0;
    }
    if (N <= 3) {
        cout << "YES" << endl;
        return 0;
    }

    // 直線部分をまーじ
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) {
        return siz[a] > siz[b];
    });
    vector<bool> seen(N, false);
    siz.assign(N, 1);
    {
        REP(i, N) {
            if (seen[i])
                continue;
            if (v[i].size() > 1)
                continue;
            stack<ll> s;
            s.push(i);
            while (!s.empty()) {
                ll t = s.top();
                s.pop();
                ll p = -1;
                for (auto &nxt: v[t]) {
                    if (seen[nxt])
                        continue;
                    p = nxt;
                    break;
                }
                if (p < 0)
                    continue;
                if (v[p].size() > 2) {
                    q.push(t);
                    break;
                }
                seen[t] = true;
                siz[p] += siz[t];
                s.push(p);
            }
        }
    }

    vector<ll> cnt(N, 0);

    while (!q.empty()) {
        ll t = q.top();
        q.pop();
        if (seen[t])
            continue;
        //cout << t << endl;
        seen[t] = true;
        ll parent = -1;
        for (auto &nxt : v[t]) {
            if (!seen[nxt]) {
                parent = nxt;
                break;
            }
        }

        //! parent以外を使って、fib-treeのsub-treeが作成できるかチェック

        if (siz[t] > 1) {
            if (fib_pair.count(siz[t]) == 0) {
                cout << "NO" << endl;
                return 0;
            }
            pll pair = fib_pair[siz[t]];
            bool exist = check(v, t, parent, pair.first, pair.second) || check(v, t, parent, pair.second, pair.first);
            if (!exist) {
                cout << "NO" << endl;
                return 0;
            }
        }

        if (parent >= 0) {
            cnt[parent]++;
            siz[parent] += siz[t];
            if (v[parent].size() - cnt[parent] <= 1)
                q.push(parent);
        }
    }
    cout << "YES" << endl;
    return 0;
}