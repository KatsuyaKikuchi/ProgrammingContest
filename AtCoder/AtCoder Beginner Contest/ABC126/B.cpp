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
    string S;
    cin >> S;
    ll a = (S[0] - '0') * 10 + (S[1] - '0');
    ll b = (S[2] - '0') * 10 + (S[3] - '0');

    if (a > 12 || a <= 0) {
        if (b <= 0 || b > 12)
            cout << "NA" << endl;
        else
            cout << "YYMM" << endl;
    }
    else {
        if (b > 12 || b <= 0)
            cout << "MMYY" << endl;
        else
            cout << "AMBIGUOUS" << endl;
    }
    return 0;
}