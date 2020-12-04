#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    string S;
    cin >> S;
    ll N = S.length();
    vector<ll> A(N, 0);
    ll mx = 0;
    ll max = 0;
    REP(i, N) {
        if (S[i] == '+')
            mx--;
        else
            mx++;
        A[i] = std::max(max, A[i]);
        max = std::max(max, mx);
    }

    ll ret = 0;
    REP(i, N) {
        ret += max - A[i] + 1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}