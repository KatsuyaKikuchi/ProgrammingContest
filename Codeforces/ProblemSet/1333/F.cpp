#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[500005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    memset(P, 0, sizeof(P));
    for (ll i = 2; i <= N; ++i) {
        if (P[i] > 0)
            continue;
        for (ll j = i; j <= N; j += i) {
            if (P[j] == 0)
                P[j] = i;
        }
    }

    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (ll i = 2; i <= N; ++i) {
        q.push(i / P[i]);
    }

    while (!q.empty()) {
        ll t = q.top();
        q.pop();
        cout << t << " ";
    }
    cout << endl;
    return 0;
}