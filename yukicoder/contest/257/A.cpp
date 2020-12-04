#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B;
    cin >> A >> B;
    ll X = gcd(A, B);

    ll ok = 1, ng = 1000000005;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (mid * mid > X)
            ng = mid;
        else
            ok = mid;
    }

    if (ok*ok==X)
        cout << "Odd" << endl;
    else
        cout << "Even" << endl;

    return 0;
}