#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve(ll N) {
    if (N == 1)
        return "-1";
    string s;
    ll sum = 0;
    REP(i, N - 2) {
        sum += 2;
        s.push_back('2');
    }
    if ((sum + 2) % 3 == 0)
        s.push_back('4');
    else
        s.push_back('2');
    s.push_back('3');
    return s;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        cout << solve(N) << endl;
    }
    return 0;
}