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
    ll N = S.length();
    stack<ll> s;
    s.push(S[0] - '0');
    FOR(i, N, 1) {

        ll n = S[i] - '0';
        if (!s.empty()) {
            ll t = s.top();
            if (t != n) {
                s.pop();
                continue;
            }
        }

        s.push(n);

    }

    cout << N - s.size() << endl;
    return 0;
}