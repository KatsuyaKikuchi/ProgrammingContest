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
    ll N;
    cin >> N;
    ll ans = 1;
    REP(i, N) {
        cin >> A[i];
    }

    ll s = 0;
    ll index = 0;
    ll n = 1;
    FOR(i, N, 1) {
        ll a = abs(A[i] - A[index]);
        ll b = abs(A[i - 1] - A[index]);

        if (a < b) {
            s += b;
            index = i - 1;
            n++;
        }
    }
    s += abs(A[N - 1] - A[index]);
    n++;

    if (s == 0)
        n = 0;
    cout << n << endl;
    return 0;
}