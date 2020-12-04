#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[30];
//! [r,c]に[メモリの数字]で[方向]で行けるか？
bool U[30][30][20][4];
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};

struct Data {
    pll g;
    ll n;
    ll d;
};

int main() {
    ll R, C;
    cin >> R >> C;
    REP(i, R) {
        cin >> S[i];
    }
    memset(U, 0, sizeof(U));
    queue<Data> q;
    q.push(Data{pll(0, 0), 0, 0});
    U[0][0][0][0] = true;
    while (!q.empty()) {
        auto d = q.front();
        q.pop();

        char c = S[d.g.first][d.g.second];
        switch (c) {
            case '@': {
                cout << "YES" << endl;
                return 0;
            }
            case '?': {
                REP(i, 4) {
                    ll nx = d.g.first + x[i], ny = d.g.second + y[i];
                    nx = (R + nx) % R;
                    ny = (C + ny) % C;
                    if (U[nx][ny][d.n][i])
                        continue;
                    U[nx][ny][d.n][i] = true;
                    q.push(Data{pll(nx, ny), d.n, i});
                }
                continue;
            }
            case '<':
                d.d = 2;
                break;
            case '>':
                d.d = 0;
                break;
            case '^':
                d.d = 3;
                break;
            case 'v':
                d.d = 1;
                break;
            case '_':
                d.d = d.n == 0 ? 0 : 2;
                break;
            case '|':
                d.d = d.n == 0 ? 1 : 3;
                break;
            case '+':
                d.n = (d.n + 1) % 16;
                break;
            case '-':
                d.n = (d.n - 1 + 16) % 16;
            case '.':
                break;
            default:
                d.n = c - '0';
                break;
        }
        {
            ll nx = d.g.first + x[d.d], ny = d.g.second + y[d.d];
            nx = (R + nx) % R;
            ny = (C + ny) % C;
            if (U[nx][ny][d.n][d.d])
                continue;
            U[nx][ny][d.n][d.d] = true;
            q.push(Data{pll(nx, ny), d.n, d.d});
        }
    }
    cout << "NO" << endl;
    return 0;
}