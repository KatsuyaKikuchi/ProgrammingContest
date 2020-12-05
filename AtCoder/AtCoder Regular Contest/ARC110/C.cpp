#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
ll P[200005];
ll T[200005];
vector<ll> ans;

bool solve() {
    ans.clear();
    REP(i, N) {
        T[P[i]] = i;
    }
    ll t = -1;
    REP(i, N) {
        if (T[i] == i)
            continue;
        ll q = -1;
        while (T[i] != i) {
            ll x = T[i];
            if (x - 1 <= t)
                return false;
            ans.push_back(x - 1);
            q = std::max(x - 1, q);
            //ans.push_back(x - 1);
            T[P[x]] = x - 1;
            T[P[x - 1]] = x;
            swap(P[x], P[x - 1]);
#if false
            REP(j, N) {
                cout << P[j] << " ";
            }
            cout << endl;
#endif
        }
        t = std::max(t, q);
    }

    REP(i, N) {
        if (P[i] != i)
            return false;
    }
    if (ans.size() != N - 1)
        return false;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    REP(i, N) {
        cin >> P[i];
        P[i]--;
    }

    if (solve()) {
        REP(i, ans.size()) {
            cout << ans[i] + 1 << endl;
        }
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}