#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string T[3] = {"Sunny", "Cloudy", "Rainy"};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    REP(i, 3) {
        if (S == T[i]) {
            cout << T[(i + 1) % 3] << endl;
            break;
        }
    }
    return 0;
}