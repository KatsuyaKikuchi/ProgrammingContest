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
    string S;
    cin >> S;
    ll N = S.length();
    ll n = 0;
    REP(i, N) {
        if (S[i] == '1')
            n++;
    }
    ll ans = 0;
    REP(i, n / 2) {
        ans += i + 1;
    }
    ans *= 2;
    if (n % 2 == 1)
        ans += (n + 1) / 2;
    ll t = n % 2;
    string T = "";
    {
        ll s = 0;
        REP(i, N) {
            if (S[i] == '1') {
                T.push_back('1');
                n--;
                if (T.length() % 2 == 1)
                    s++;
                continue;
            }
            if (T.length() % 2 == 0)
                continue;
            T.push_back('0');
            ans += s + (n + 1) / 2;
        }
    }
    {
        ll odd = 0, even = 0;
        REP(i, T.length()) {
            if (T[i] != '1')
                continue;
            if (i % 2 == 0)
                odd++;
            else
                even++;
        }

        ll s = 0;
        ll index = T.length() - 1;
        ll odd2 = 0, even2 = 0;
        ll m = 1;

        // cout << ans << endl;
        for (ll i = N - 1; i >= 0; --i) {
            if (S[i] == '1') {
                if (index % 2 == 0) {
                    odd2++;
                }
                else {
                    even2++;
                }
                if (m % 2 != t)
                    even--;
                else
                    odd--;
                m++;
            }
            if (S[i] == T[index]) {
                index--;
                continue;
            }

            if (abs(index) % 2 == 1)
                swap(odd2, even2);
            ans += odd + odd2;
        }
    }

    cout << ans << endl;
    return 0;
}