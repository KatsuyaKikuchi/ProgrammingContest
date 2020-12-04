#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> H[i];
    }

    stack<ll> s;
    s.push(INF);
    REP(i, N) {
        cout << s.size() - 1 << endl;
        while (s.top() < H[i])
            s.pop();
        s.push(H[i]);
    }
    return 0;
}