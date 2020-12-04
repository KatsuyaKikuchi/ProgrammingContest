#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, K;
    cin >> N >> K;
    priority_queue<ll, vector<ll>, greater<ll>> A;
    priority_queue<ll> B;
    REP(i, N) {
        ll a;
        cin >> a;
        A.push(a);
    }
    REP(i, N) {
        ll b;
        cin >> b;
        B.push(b);
    }


    REP(i, K) {
        ll a = A.top();
        A.pop();
        ll b = B.top();
        B.pop();
        if (a < b)
            swap(a, b);
        A.push(a);
        B.push(b);
    }

    ll ret = 0;
    while (!A.empty()) {
        ll t = A.top();
        A.pop();
        ret += t;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << solve() << endl;
    }
    return 0;
}