#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[1000005];

int main() {
    ll M, K;
    cin >> M >> K;
    if (M == 0) {
        if (K == 0)
            cout << "0 0" << endl;
        else
            cout << -1 << endl;
        return 0;
    }
    ll p = pow(2LL, M);
    if (p <= K) {
        cout << -1 << endl;
        return 0;
    }

    if (M == 1 && K == 0) {
        cout << "0 0 1 1" << endl;
        return 0;
    }
    if (M == 1 && K == 1) {
        cout << -1 << endl;
        return 0;
    }

    if (K == 0) {
        REP(i, p) {
            cout << i << " ";
        }
        REP(i, p) {
            cout << p - 1 - i << " ";
        }
        cout << endl;
        return 0;
    }

    memset(U, 0, sizeof(U));
    vector<vector<ll>> v;
    REP(i, p) {
        if (U[i])
            continue;
        ll k = (K ^ i);
        U[i] = U[k] = true;
        vector<ll> t;
        t.push_back(i);
        t.push_back(k);
        v.push_back(t);
    }

    vector<ll> ans;
    for (ll i = 0; i < v.size(); i += 2) {
        auto a = v[i];
        auto b = v[i + 1];
        ans.push_back(a[0]);
        ans.push_back(a[1]);
        ans.push_back(b[0]);
        ans.push_back(b[1]);
        ans.push_back(a[1]);
        ans.push_back(a[0]);
        ans.push_back(b[1]);
        ans.push_back(b[0]);
    }

    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
