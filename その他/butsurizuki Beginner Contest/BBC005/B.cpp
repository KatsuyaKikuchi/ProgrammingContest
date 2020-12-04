
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string T[12] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII"};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    ll N;
    cin >> S >> N;
    REP(i, 12) {
        if (S == T[i]) {
            ll t = (i + N) % 12;
            cout << T[t] << endl;
            return 0;
        }
    }

    return 0;
}