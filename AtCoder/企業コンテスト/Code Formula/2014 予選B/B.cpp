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
    string S;
    cin >> S;
    ll odd = 0, even = 0;
    REP(i, S.length()) {
        if (i % 2 == 0)
            even += (S[i] - '0');
        else
            odd += (S[i] - '0');
    }
    if (S.length() % 2 == 1)
        swap(odd, even);
    cout << even << " " << odd << endl;
    return 0;
}