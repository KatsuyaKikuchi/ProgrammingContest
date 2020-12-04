#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, Q;
bool F[105][105];
bool C[105][105];

void single(ll a, ll b) {
    F[a][b] = true;
}

void all(ll a) {
    REP(i, N) {
        if (F[i][a])
            F[a][i] = true;
    }
}

void follow(ll a) {
    REP(i, N) {
        REP(j, N) {
            C[i][j] = F[i][j];
        }
    }
    REP(i, N) {
        if (!C[a][i])
            continue;
        REP(j, N) {
            if (j == a)
                continue;
            if (C[i][j])
                F[a][j] = true;
        }
    }
}

int main() {
    cin >> N >> Q;
    memset(F, 0, sizeof(F));
    REP(q, Q) {
        ll t, a, b;
        cin >> t;
        if (t == 1) {
            cin >> a >> b;
            single(a - 1, b - 1);
        }
        else if (t == 2) {
            cin >> a;
            all(a - 1);
        }
        else if (t == 3) {
            cin >> a;
            follow(a - 1);
        }
    }

    REP(i, N) {
        REP(j, N) {
            if (F[i][j])
                cout << "Y";
            else
                cout << "N";
        }
        cout << endl;
    }
    return 0;
}