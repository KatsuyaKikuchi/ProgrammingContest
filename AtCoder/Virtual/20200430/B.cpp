#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[55];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }

    bool exist = true;
    REP(i, H) {
        REP(j, W) {
            if (S[i][j] == '.')
                continue;
            bool e = false;
            REP(n, 4) {
                ll nx = i + x[n], ny = j + y[n];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                if (S[nx][ny] == '#')
                    e = true;
            }
            if (!e)
                exist = false;
        }
    }

    if (exist)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}