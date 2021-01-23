#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[100];
ll C[100][2];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
    }
    memset(C, 0, sizeof(C));
    C[0][0] = C[0][1] = 1;
    REP(i, N) {
        if (S[i] == "AND") {
            C[i + 1][1] = C[i][1];
            C[i + 1][0] = C[i][0] + C[i][1] + C[i][0];
        }
        else {
            C[i + 1][1] = C[i][0] + C[i][1] + C[i][1];
            C[i + 1][0] = C[i][0];
        }
    }
    cout << C[N][1] << endl;
    return 0;
}