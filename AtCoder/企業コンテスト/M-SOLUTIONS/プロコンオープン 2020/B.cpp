#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C, K;
    cin >> A >> B >> C >> K;
    REP(i, K) {
        if (A >= B)
            B *= 2LL;
        else if (B >= C)
            C *= 2LL;
    }

    if (A < B && B < C)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;


    return 0;
}