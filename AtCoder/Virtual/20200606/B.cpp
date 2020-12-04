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
    ll N = S.length();
    stack<ll> s;
    REP(i, N) {
        if (s.size() > 0 && s.top() != S[i])
            s.pop();
        else
            s.push(S[i]);
    }

    cout << N - s.size() << endl;

    return 0;
}