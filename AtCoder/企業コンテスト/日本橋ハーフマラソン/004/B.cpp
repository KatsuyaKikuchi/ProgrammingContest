#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[55][55];
ll G[55][55];
char C0[4] = {'D', 'D', 'U', 'U'};
char C1[4] = {'R', 'L', 'R', 'L'};

char C[4] = {'D', 'R', 'U', 'L'};
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};
ll N, M;

pll getPos0(ll n) {
    pll g(0, 0);
    if (n % 4 == 0) {
        g.first = 5 * (n / 4);
    }
    if (n % 4 == 1) {
        g.first = 5 * (n / 4);
        g.second = N - 1;
    }
    if (n % 4 == 2) {
        g.first = N - 1 - 5 * (n / 4);
    }
    if (n % 4 == 3) {
        g.first = N - 1 - 5 * (n / 4);
        g.second = N - 1;
    }
    return g;
}

pll getPos1(ll n) {
    pll g(0, 0);
    ll p = ((n - ((N / 2) / 5) * 4) / 4) % 25;
    ll q = ((n - ((N / 2) / 5) * 4) / 4) / 25;

    if (n % 4 == 0) {
        g.first = p;
        g.second = 5 * q;
    }
    if (n % 4 == 1) {
        g.first = p;
        g.second = N - 1 - 5 * q;
    }
    if (n % 4 == 2) {
        g.first = N - 1 - p;
        g.second = 5 * q;
    }
    if (n % 4 == 3) {
        g.first = N - 1 - p;
        g.second = N - 1 - 5 * q;
    }
    return g;
}

bool simulation(pll g, char c, ll p) {
    if (p != G[g.first][g.second]) {
        //cout << "ERROR!" << endl;
        return false;
    }

    ll d = 0;
    REP(i, 4) {
        if (C[i] == c) {
            d = i;
            break;
        }
    }

    ll nx = g.first, ny = g.second;
    REP(i, 5) {
        nx += y[d], ny += x[d];
        G[nx][ny] = p;
    }
    return true;
}

int main() {
    cin >> N >> M;
#if false
    REP(i, N) {
        REP(j, N) {
            cin >> A[i][j];
        }
    }
#endif
    memset(G, -1, sizeof(G));
    G[0][0] = 0;
    G[0][N - 1] = 1;
    G[N - 1][0] = 2;
    G[N - 1][N - 1] = 3;
    REP(i, M) {
        char c = 'U';
        pll g(0, 0);
        if (i < ((N / 2) / 5) * 4) {
            c = C0[i % 4];
            g = getPos0(i);
        }
        else {
            c = C1[i % 4];
            g = getPos1(i);
        }
        if (simulation(g, c, i % 4))
            cout << g.first << " " << g.second << " " << c << endl;
        else
            cout << -1 << endl;
    }

#if true
    REP(i, N) {
        REP(j, N) {
            cout << G[i][j] << " ";
        }
        cout << endl;
    }
#endif
    return 0;
}