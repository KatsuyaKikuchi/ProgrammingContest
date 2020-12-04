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
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll s = 1;
    ll p = 0;
    REP(i, N - 1) {
        ll a = A[i + 1] - A[i];
        if (a * p < 0) {
            s++;
            p = 0;
        }
        else if (a != 0) {
            p = a;
        }
    }
    cout << s << endl;
    return 0;
}