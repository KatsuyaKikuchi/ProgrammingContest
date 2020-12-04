#include <bits/stdc++.h>

using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
pll A[1005][1005];
char B[1005][1005];
bool U[1005][1005];
ll x[4] = {1, 0, -1, 0};
ll y[4] = {0, 1, 0, -1};
char C0[4] = {'U', 'L', 'D', 'R'};
char C1[4] = {'D', 'R', 'U', 'L'};

ll cnt = 0;

inline bool dfs0(ll h, ll w) {
    if (U[h][w])
        return true;
    B[h][w] = 'X';
    U[h][w] = true;
    queue<pll> q;
    q.push(pll(h, w));
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        cnt++;
        REP(i, 4) {
            ll nx = t.first + x[i], ny = t.second + y[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (U[nx][ny])
                continue;
            if (A[nx][ny].first != h || A[nx][ny].second != w) {
                continue;
            }

            U[nx][ny] = true;
            B[nx][ny] = C0[i];
            q.push(pll(nx, ny));
        }
    }
    return true;
}

inline bool dfs1(ll h, ll w) {
    if (U[h][w])
        return true;
    U[h][w] = true;
    queue<pll> q;
    q.push(pll(h, w));
    while (!q.empty()) {
        pll t = q.front();
        q.pop();
        bool exist = false;
        cnt++;
        REP(i, 4) {
            ll nx = t.first + x[i], ny = t.second + y[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (A[nx][ny].first != -1) {
                continue;
            }
            B[t.first][t.second] = C1[i];
            exist = true;
            if (U[nx][ny])
                continue;
            U[nx][ny] = true;
            q.push(pll(nx, ny));
        }
        if (!exist)
            return false;
    }
    return true;
}

inline bool solve() {
    memset(U, 0, sizeof(U));
    queue<pll> q0, q1;
    REP(i, N) {
        REP(j, N) {
            if (i == A[i][j].first && j == A[i][j].second) {
                q0.push(pll(i, j));
            }
            else if (A[i][j].first == -1) {
                q1.push(pll(i, j));
            }
        }
    }

    while (!q1.empty()) {
        pll t = q1.front();
        q1.pop();
        if (!dfs1(t.first, t.second)) {
            return false;
        }
    }
    while (!q0.empty()) {
        pll t = q0.front();
        q0.pop();
        dfs0(t.first, t.second);
    }

    REP(i, N) {
        REP(j, N) {
            if (!U[i][j])
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    //scanf("%d", &N);
    cin >> N;
    REP(i, N) {
        REP(j, N) {
            //scanf("%d", &A[i][j].first);
            //scanf("%d", &A[i][j].second);
            cin >> A[i][j].first >> A[i][j].second;
            if (A[i][j].first > 0)
                A[i][j].first--;
            if (A[i][j].second > 0)
                A[i][j].second--;
        }
    }

    if (solve()) {
        cout << "VALID" << '\n';
        //printf("VALID\n");
        REP(i, N) {
            //string s = "";
            REP(j, N) {
             //   s.push_back(B[i][j]);
                //printf("%c", B[i][j]);
                cout << B[i][j];
            }
            //cout << s;
            cout << '\n';
        }
    }
    else {
        cout << "INVALID" << endl;
    }
    return 0;
}