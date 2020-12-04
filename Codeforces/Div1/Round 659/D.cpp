#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[300][300];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        REP(j, M) {
            cin >> A[i][j];
        }
    }

    vector<ll> R(N), C(M);
    REP(i, N) {
        ll mx = 0;
        REP(j, M) {
            mx = std::max(mx, A[i][j]);
        }
        R[i] = mx;
    }
    REP(j, M) {
        ll mx = 0;
        REP(i, N) {
            mx = std::max(A[i][j], mx);
        }
        C[j] = mx;
    }
    sort(R.begin(), R.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());
    REP(i, N) {
        REP(j, M) {
            A[i][j] = -1;
        }
    }

    REP(i, N) {
        REP(j, M) {
            if (R[i] > C[j])
                break;

            A[i][j] = R[i];
            break;
        }
    }
    REP(j, M) {
        REP(i, M) {
            if (C[j] > R[i])
                break;
            A[i][j] = C[j];
            break;
        }
    }

    priority_queue<ll> q;

    bool e = true;
    REP(i, N) {
        REP(j, M) {
            if (A[i][j] <= 0)
                e = false;
        }
    }
    if (e) {
        cout << -1 <<
             endl;
        return 0;
    }
    REP(i, N) {
        REP(j, M) {
            cout << A[i][j] << " ";
        }
        cout <<
             endl;
    }

    return 0;
}