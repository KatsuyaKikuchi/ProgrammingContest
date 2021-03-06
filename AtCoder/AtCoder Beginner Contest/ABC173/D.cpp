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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    sort(A, A + N, greater<ll>());
    priority_queue<ll, vector<ll>> q;
    ll ans = 0;
    q.push(A[0]);
    FOR(i, N, 1) {
        ll t = q.top();
        q.pop();
        ans += t;
        q.push(A[i]);
        q.push(A[i]);
    }

    cout << ans << endl;

    return 0;
}