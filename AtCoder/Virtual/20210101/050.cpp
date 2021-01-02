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

bool solve() {
    ll a = 0, b = 0;
    {
        ll x = 1;
        while (x <= N) {
            a++;
            x = x * 2LL;
        }
    }
    {
        ll x = 1;
        while (x <= N) {
            b++;
            x = x * 2LL + 1;
        }
    }
    if (a == b) {
        if (a % 2 == 0)
            return true;
        else
            return false;
    }

    ll n = 0;
    if (a % 2 == 0) {
        ll x = 1;
        while (x <= N) {
            if (n % 2 == 0)
                x = x * 2LL;
            else
                x = x * 2LL + 1;
            n++;
        }
    }
    else {
        ll x = 1;
        while (x <= N) {
            if (n % 2 == 1)
                x = x * 2LL;
            else
                x = x * 2LL + 1;
            n++;
        }
    }
    if (n % 2 == 0)
        return true;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    if (solve())
        cout << "Takahashi" << endl;
    else
        cout << "Aoki" << endl;
    return 0;
}