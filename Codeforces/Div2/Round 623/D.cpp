#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[200005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first;
    }
    REP(i, N) {
        cin >> A[i].second;
    }

    vector<ll> v;
    REP(i, N) {
        v.push_back(A[i].first);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    sort(A, A + N, [](pll a, pll b) { return a.first < b.first; });
    ll ans = 0;

    ll s = A[0].second;
    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a < b; });
    q.push(A[0].second);
    FOR(i, N, 1) {
        ll a = A[i].first;
        ll p = A[i - 1].first;
        while (a > p && !q.empty()) {
            ll t = q.top();
            q.pop();
            s -= t;
            ans += s;
            p++;
        }

        s += A[i].second;
        q.push(A[i].second);
    }

    while (!q.empty()) {
        ll t = q.top();
        q.pop();
        s -= t;
        ans += s;
    }
    cout << ans << endl;

    return 0;
}