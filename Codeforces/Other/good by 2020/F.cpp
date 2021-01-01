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
    vector<ll> d;
    vector<ll> p0;
    vector<ll> idx0;
    vector<vector<ll>> p1;
    vector<ll> idx1;
    vector<bool> bit(M + 1, false);
    REP(i, N) {
        ll n;
        cin >> n;
        if (n == 1) {
            ll x;
            cin >> x;
            x--;
            p0.push_back(x);
            bit[x] = true;
            idx0.push_back(i);
        }
        else {
            vector<ll> t(2);
            REP(_, n) {
                cin >> t[_];
                t[_]--;
            }
            sort(t.begin(), t.end());
            p1.push_back(t);
            idx1.push_back(i);
        }
    }

    vector<bool> ans(N, false);
    vector<ll> X(M, -1);
    REP(i, p1.size()) {
        if (bit[p1[i][0]] && bit[p1[i][1]]) {
            ans[idx1[i]] = false;
            continue;
        }
        {
            ll t = X[p1[i][0]];
            if (t == -1 || (p1[t][0] < p1[i][0] || (p1[t][0] == p1[i][0] && p1[t][1] < p1[i][1])))
                X[p1[i][0]] = i;
        }
        {
            ll t = X[p1[i][1]];
            if (t == -1 || (p1[t][0] < p1[i][0] || (p1[t][0] == p1[i][0] && p1[t][1] < p1[i][1])))
                X[p1[i][1]] = i;
        }
    }
    REP(i, idx0.size()) {
        ans[idx0[i]] = true;
    }
    REP(i, M) {
        if (X[i] >= 0)
            ans[idx1[X[i]]] = true;
    }
    ll num = 0;
    REP(i, N) {
        if (ans[i])
            num++;
    }

    ll cnt = 1;
    REP(i, num) {
        cnt = (cnt * 2LL) % MOD;
    }
    cout << cnt << " " << num << endl;
    REP(i, N) {
        if (ans[i])
            cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}