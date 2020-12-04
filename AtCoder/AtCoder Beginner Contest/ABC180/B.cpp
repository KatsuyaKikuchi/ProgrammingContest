#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

double X[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    double B = 0;
    ll A = 0, C = -INF;
    REP(i, N) {
        ll x;
        cin >> x;
        A += abs(x);
        B += x * x;
        C = std::max(C, abs(x));
    }

    cout << A << endl;
    cout << OF64 << sqrt(B) << endl;
    cout << C << endl;


    return 0;
}