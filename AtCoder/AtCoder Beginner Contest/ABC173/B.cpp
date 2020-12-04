#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[10];
string T[4] = {"AC", "WA", "TLE", "RE"};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        string s;
        cin >> s;
        REP(j, 4) {
            if (s == T[j]) {
                S[j]++;
                break;
            }
        }
    }

    REP(i, 4) {
        cout << T[i] << " x " << S[i] << endl;
    }
    return 0;
}