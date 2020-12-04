#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K, Q;
    cin >> N >> K >> Q;
    vector<ll> v;
    REP(i, N) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    ll ans = INF;
    REP(i, v.size()) {
        priority_queue<ll, vector<ll>, greater<ll>> q;
        vector<ll> u;
        REP(j, N) {
            if (A[j] < v[i]) {
                while (!q.empty()) {
                    ll t = q.top();
                    q.pop();
                    if (q.size() >= K - 1)
                        u.push_back(t);
                }
                continue;
            }
            q.push(A[j]);
        }
        while (q.size() >= K) {
            ll t = q.top();
            q.pop();
            u.push_back(t);
        }
        if (u.size() < Q)
            break;
        sort(u.begin(), u.end());

        ans = std::min(ans, u[Q - 1] - u[0]);
    }
    cout << ans << endl;
    return 0;
}