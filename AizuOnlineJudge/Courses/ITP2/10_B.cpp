#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string bit(unsigned int x) {
    string ret = "";
    while (ret.size() < 32) {
        ret.push_back('0' + (x & 1));
        x /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    unsigned int a, b;
    cin >> a >> b;
    cout << bit(a & b) << endl;
    cout << bit(a | b) << endl;
    cout << bit(a ^ b) << endl;
    return 0;
}