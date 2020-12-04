#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve(vector<ll> &A, vector<ll> &P) {
    ll N = A.size(), M = P.size();
    while (true) {
        bool swap = false;
        REP(i, M) {
            ll index = P[i];
            if (A[index] > A[index + 1]) {
                std::swap(A[index], A[index + 1]);
                swap = true;
            }
        }
        if (!swap)
            break;
    }

    REP(i, N - 1) {
        if (A[i] > A[i + 1])
            return "NO";
    }
    return "YES";
}

int main() {
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N, M;
        cin >> N >> M;
        vector<ll> A(N), P(M);
        REP(i, N) {
            cin >> A[i];
        }
        REP(i, M) {
            cin >> P[i];
            P[i]--;
        }
        sort(P.begin(), P.end());
        cout << solve(A, P) << endl;
    }
    return 0;
}