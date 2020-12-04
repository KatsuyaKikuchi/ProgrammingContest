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
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a < b; });
    ll ans = 0;
    ll p = 0;
    for (ll i = N - 1; i >= 0; --i) {
        q.push(A[i]);
        if (p == 0) {
            p += q.top();
            q.pop();
            ans++;
        }
        p--;
    }
    cout << ans << endl;
    return 0;
}