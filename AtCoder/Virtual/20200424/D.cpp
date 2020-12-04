#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[10005];
ll M[105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, N;
    cin >> H >> W >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll index = 0;
    pll g(0, 0);
    while (g.first < H) {
        M[g.first][g.second] = index + 1;
        if (--A[index] <= 0)
            index++;

        if (g.first % 2 == 0)
            g.second++;
        else
            g.second--;

        if (g.second < 0) {
            g.first++;
            g.second = 0;
        }
        else if (g.second >= W) {
            g.first++;
            g.second = W - 1;
        }
    }

    REP(i, H) {
        REP(j, W) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}