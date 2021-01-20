#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N, X;
pll A[100005];

bool check(ll time) {
    ll sum = 0;
    ll idx = 0;
    priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q([](pll a, pll b) { return a.second < b.second; });
    while (time > 0 && (idx < N || !q.empty())) {
        while (idx < N && A[idx].first + 1 > time) {
            q.push(A[idx++]);
        }
        while (!q.empty()) {
            pll t = q.top();
            if (t.first + 1 > time)
                break;
            q.pop();
        }
        if (!q.empty()) {
            pll t = q.top();
            q.pop();
            sum += t.second;
        }
        time--;
    }
    return sum >= X;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> X;
    REP(i, N) {
        cin >> A[i].first;
    }
    REP(i, N) {
        cin >> A[i].second;
    }
    sort(A, A + N, [](pll a, pll b) { return a.first > b.first; });
    ll ans = N + 5, ng = 0;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    if (ans == N + 5)
        ans = -1;
    cout << ans << endl;
    return 0;
}