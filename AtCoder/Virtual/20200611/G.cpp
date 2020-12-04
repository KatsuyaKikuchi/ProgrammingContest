#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    ll ans = 0;
    {
        ll s = O;
        ll i = I, j = J, l = L;
        s += (i / 2) * 2;
        i %= 2;
        if (i > 0 && j > 0 && l > 0) {
            s += 3;
            i--;
            j--;
            l--;
        }
        s += (j / 2) * 2 + (l / 2) * 2;
        ans = std::max(s, ans);
    }
    {
        ll s = O;
        ll i = I, j = J, l = L;
        s += (i / 2) * 2 + (j / 2) * 2 + (l / 2) * 2;
        ans = std::max(s, ans);
    }
    {
        ll s = O;
        ll i = I, j = J, l = L;
        if (i > 0 && j > 0 && l > 0) {
            s += 3;
            i--;
            j--;
            l--;
        }
        s += (j / 2) * 2 + (l / 2) * 2;
        s += (i / 2) * 2;
        ans = std::max(s, ans);
    }

    cout << ans << endl;

    return 0;
}