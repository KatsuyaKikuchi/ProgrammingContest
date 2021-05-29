#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[205];
ll U[205][205];
vector<ll> V[205][205];

bool Print(vector<ll> &B, vector<ll> &C) {
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    {
        ll sb = 0;
        REP(i, B.size()) {
            sb += A[B[i] - 1];
            sb %= 200;
        }
        ll sc = 0;
        REP(i, C.size()) {
            sc += A[C[i] - 1];
            sc %= 200;
        }
        if (sb != sc)
            return false;
    }
    if (B.size() == C.size()) {
        bool e = false;
        REP(i, B.size()) {
            if (B[i] != C[i])
                e = true;
        }
        if (!e)
            return false;
    }
    cout << "Yes" << endl;
    cout << B.size();
    REP(i, B.size()) {
        cout << " " << B[i];
    }
    cout << endl;
    cout << C.size();
    REP(i, C.size()) {
        cout << " " << C[i];
    }
    cout << endl;
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    memset(U, 0, sizeof(U));
    REP(i, N) {
        ll n = A[i] % 200;
        U[i + 1][n] = 1;
        V[i + 1][n].push_back(i + 1);
    }
    FOR(i, N, 0) {
        REP(j, 200) {
            if (U[i][j] == 0)
                continue;
            ll n = (A[i] + j) % 200;
            U[i + 1][n] += U[i][j];
            if ((n == 0 && U[i + 1][n] > 2) || (n > 0 && U[i + 1][n] >= 2)) {
                vector<ll> B = V[i + 1][n];
                vector<ll> C = V[i][j];
                C.push_back(i + 1);
                if (Print(B, C))
                    return 0;

            }
            else {
                V[i + 1][n].clear();
                REP(k, V[i][j].size()) {
                    V[i + 1][n].push_back(V[i][j][k]);
                }
                V[i + 1][n].push_back(i + 1);
            }
            U[i + 1][j] += U[i][j];
            if ((j == 0 && U[i + 1][j] > 2) || (j > 0 && U[i + 1][j] >= 2)) {
                vector<ll> B = V[i + 1][j];
                vector<ll> C = V[i][j];
                if (Print(B, C))
                    return 0;
                else
                    assert(false);

            }
            else {
                if (V[i][j].size() > 0)
                    V[i + 1][j].clear();
                REP(k, V[i][j].size()) {
                    V[i + 1][j].push_back(V[i][j][k]);
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}