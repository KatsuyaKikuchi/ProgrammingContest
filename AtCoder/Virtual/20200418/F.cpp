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
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    B = abs(B - A);
    ll u = D * (N - 1);
    ll d = C * (N - 1);
    REP(i, N) {
        if (d <= B && B <= u) {
            cout << "YES" << endl;
            return 0;
        }
        u -= (C + D);
        d -= (C + D);
    }
    cout << "NO" << endl;
    return 0;
}