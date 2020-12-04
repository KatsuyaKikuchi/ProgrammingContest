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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.first < b.first; });
    REP(i, K) {
        q.push(pll(A[i], i + 1));
    }

    vector<ll> v;
    FOR(i, N + 1, K) {
        while (q.size() > K)
            q.pop();
        v.push_back(q.top().second);
        q.push(pll(A[i], i + 1));
    }

    REP(i, v.size()) {
        cout << v[i] << endl;
    }
    return 0;
}