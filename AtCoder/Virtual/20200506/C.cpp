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
    S.push_back('+');
    ll N = S.length();

    ll ans = 0;
    stack<ll> s;
    REP(i, N) {
        if (S[i] == '+') {
            ll t = s.top();
            if (t > 0)
                ans++;
            s.pop();
        }
        else if (S[i] != '*') {
            ll n = 1;
            if (s.size() != 0) {
                n = s.top();
                s.pop();
            }
            n *= std::min((ll) (S[i] - '0'), 1LL);
            s.push(n);
        }
    }
    cout << ans << endl;
    return 0;
}