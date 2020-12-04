#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, M;
        cin >> N >> M;
        string S;
        cin >> S;
        vector<ll> A(M);
        REP(i, M) {
            cin >> A[i];
        }
        vector<vector<ll>> C(N + 1, vector<ll>(26, 0));
        REP(i, N) {
            C[i][S[i] - 'a']++;
            REP(j, 26) {
                C[i + 1][j] += C[i][j];
            }
        }

        A.push_back(N);
        vector<ll> T(26, 0);
        REP(i, A.size()) {
            ll m = A[i];
            REP(j, 26) {
                T[j] += C[m - 1][j];
            }
        }

        REP(i, 26) {
            cout << T[i] << " ";
        }
        cout << endl;
    }
    return 0;
}