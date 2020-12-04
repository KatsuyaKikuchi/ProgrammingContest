#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];
ll x[3] = {1, 1, 0};
ll y[3] = {0, 1, 1};
bool A[105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    memset(A, 0, sizeof(A));
    for (ll h = H - 1; h >= 0; --h) {
        for (ll w = W - 1; w >= 0; --w) {
            if (S[h][w] == '#')
                continue;
            bool e = false;
            REP(i, 3) {
                ll nx = x[i] + h, ny = y[i] + w;
                if (nx >= H || ny >= W)
                    continue;
                if (S[nx][ny] == '#')
                    continue;
                if (!A[nx][ny])
                    e = true;
            }
            A[h][w] = e;
        }
    }

    if (A[0][0])
        cout << "First" << endl;
    else
        cout << "Second" << endl;
    return 0;
}