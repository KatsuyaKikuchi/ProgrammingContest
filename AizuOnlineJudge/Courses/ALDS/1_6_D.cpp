#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[1005];
ll B[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
        B[i] = A[i];
    }
    sort(B, B + N);
    ll index = -1;
    REP(i, N) {
        if (A[i] == B[i])
            continue;
        if (index < 0 || A[index] > A[i])
            index = i;
    }

    ll ans = 0;
    if (index >= 0) {
        while (true) {
            ll cnt = 0;
            while (A[index] != B[index]) {
                REP(i, N) {
                    if (B[index] == A[i]) {
                        ans += A[i];
                        cnt++;
                        swap(A[index], A[i]);
                        index = i;
                        break;
                    }
                }
            }

            ans += std::min(A[index] * cnt, B[0] * cnt + 2 * (B[0] + A[index]));

            index = -1;
            REP(i, N) {
                if (A[i] == B[i])
                    continue;
                if (index < 0 || A[index] > A[i])
                    index = i;
            }
            if (index < 0)
                break;
        }
    }
    cout << ans << endl;
    return 0;
}