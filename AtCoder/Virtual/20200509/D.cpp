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
    ll N;
    cin >> N;
    cout << 0 << endl;
    string b;
    cin >> b;
    if (b == "Vacant") {
        return 0;
    }
    ll bi = 0;
    ll ng = N;
    while (true) {
        ll mid = (bi + ng) / 2;
        cout << mid << endl;
        string s;
        cin >> s;
        if (s == "Vacant")
            break;

        ll n = mid - bi + 1;
        if (n % 2 == 0) {
            if (b == s)
                ng = mid;
            else {
                bi = mid;
                b = s;
            }
        }
        else {
            if (b != s)
                ng = mid;
            else {
                bi = mid;
                b = s;
            }
        }
    }
    return 0;
}