#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    priority_queue<ll, vector<ll>> A, B;
    REP(i, N) {
        ll a;
        cin >> a;
        A.push(a);
    }
    REP(i, M) {
        ll b;
        cin >> b;
        B.push(b);
    }

    while (!A.empty() && !B.empty()) {
        ll a = A.top();
        ll b = B.top();
        A.pop();
        B.pop();
        if (a < b) {
            cout << "NO" << endl;
            return 0;
        }
    }

    if (B.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}