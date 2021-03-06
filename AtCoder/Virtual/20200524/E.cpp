#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
bool U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = 1;
    memset(U, 0, sizeof(U));
    queue<ll> q;
    REP(i, N) {
        if (U[A[i]]) {
            ans = std::max(ans, (ll) q.size());
            while (U[A[i]]) {
                ll t = q.front();
                q.pop();
                U[t] = false;
            }
        }
        q.push(A[i]);
        U[A[i]] = true;
    }
    ans = std::max(ans, (ll) q.size());
    cout << ans << endl;

    return 0;
}