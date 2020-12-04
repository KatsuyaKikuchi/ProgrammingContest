#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char A[4] = {'A', 'C', 'G', 'T'};
char B[4] = {'T', 'G', 'C', 'A'};

int main() {
    char b;
    cin >> b;
    REP(i, b) {
        if (A[i] == b) {
            cout << B[i] << endl;
            break;
        }
    }
    return 0;
}