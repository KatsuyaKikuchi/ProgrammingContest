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
ll B[1000005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    memset(B, 0, sizeof(B));
    REP(i, N) {
        cin >> A[i];
        B[A[i]]++;
    }

    ll ans = N;
    REP(i, N) {
        if (B[A[i]] > 1) {
            ans--;
            continue;
        }

        ll n = 1;
        while (n * n <= A[i]) {
            bool e = false;
            if (A[i] % n == 0) {
                ll x = n;
                ll y = A[i] / n;
                if (B[x] > 0 && A[i] != x)
                    e = true;
                if (B[y] > 0 && y != A[i])
                    e = true;
            }

            if (e) {
                ans--;
                break;
            }
            n++;
        }
    }
    cout << ans << endl;
    return 0;
}