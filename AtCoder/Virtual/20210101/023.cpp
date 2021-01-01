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
    string S;
    cin >> S;
    ll T;
    cin >> T;
    ll x = 0, y = 0;
    ll p = 0;
    REP(i, S.length()) {
        if (S[i] == '?')
            p++;
        else {
            switch (S[i]) {
                case 'D':
                    y--;
                    break;
                case 'U':
                    y++;
                    break;
                case 'L':
                    x--;
                    break;
                case 'R':
                    x++;
                    break;
            }
        }
    }

    if (T == 1) {
        cout << abs(x) + abs(y) + p << endl;
    }
    else {
        ll dx = std::min(abs(x), p);
        p -= dx;
        ll dy = std::min(abs(y), p);
        p -= dy;
        cout << abs(x) + abs(y) - dx - dy + p % 2 << endl;
    }
    return 0;
}