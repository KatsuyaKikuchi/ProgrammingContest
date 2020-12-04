#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
ll B[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }

    REP(_, K) {
        memset(B, 0, sizeof(B));
        REP(i, N) {
            ll l = std::max(i - A[i], 0LL);
            ll r = std::min(i + A[i], N - 1);
            B[l]++;
            B[r + 1]--;
        }
        REP(i, N) {
            B[i + 1] += B[i];
            A[i] = B[i];
        }
        swap(A, B);

        bool e = true;
        REP(i, N) {
            if (A[i] < N)
                e = false;
        }
        if (e)
            break;
    }

    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}