#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = 3LL * ((ll) 1e9);

void solve() {
    ll L, R;
    cin >> L >> R;
    ll ans = 0;
    ll n = 0;
    {
        ll ng = INF;
        while (abs(ng - n) > 1) {
            ll mid = (ng + n) / 2;
            if (std::max(L, R) - mid * (mid + 1) / 2 >= std::min(L, R))
                n = mid;
            else
                ng = mid;
        }
    }
    ans += n;
    if (L > R)
        L -= n * (n + 1) / 2;
    else
        R -= n * (n + 1) / 2;
    n++;
    if (n % 2 == 1) {
        if (L >= R) {
            if (L < n) {
                cout << ans << " " << L << " " << R << endl;
                return;
            }
            L -= n;
        }
        else {
            if (R < n) {
                cout << ans << " " << L << " " << R << endl;
                return;
            }
            R -= n;
        }
        n++;
    }

    {
        ll m = n - 1;
        ll ng = INF;
        while (abs(ng - m) > 1) {
            ll mid = (m + ng) / 2;
            ll odd = 0, even = 0;
            if (mid % 2 == 1) {
                odd = ((mid + 1) / 2) * ((mid + 1) / 2) - (n * n / 4);
                even = mid * (mid + 1) / 2 - n * (n - 1) / 2 - odd;
            }
            else {
                odd = (mid / 2) * (mid / 2) - (n * n / 4);
                even = mid * (mid + 1) / 2 - n * (n - 1) / 2 - odd;
            }

            if (L >= R) {
                if (L - even >= 0 && R - odd >= 0)
                    m = mid;
                else
                    ng = mid;
            }
            else {
                if (R - even >= 0 && L - odd >= 0)
                    m = mid;
                else
                    ng = mid;
            }
        }
        ans = m;
        {
            ll odd = 0, even = 0;
            ll mid = m;
            if (mid % 2 == 1) {
                odd = ((mid + 1) / 2) * ((mid + 1) / 2) - (n * n / 4);
                even = mid * (mid + 1) / 2 - n * (n - 1) / 2 - odd;
            }
            else {
                odd = (mid / 2) * (mid / 2) - (n * n / 4);
                even = mid * (mid + 1) / 2 - n * (n - 1) / 2 - odd;
            }
            if (L >= R) {
                L -= even;
                R -= odd;
            }
            else {
                R -= even;
                L -= odd;
            }
        }
    }

    cout << ans << " " << L << " " << R << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}