#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll xr = 0;
    REP(i, N) {
        cin >> A[i];
        xr ^= A[i];
    }

    if (xr == 0)
        return "DRAW";

    ll bit = 0;
    for (ll i = 50; i >= 0; --i) {
        if (((xr >> i) & 1) == 1) {
            bit = (1LL << i);
            break;
        }
    }

    vector<ll> v;
    REP(i, N) {
        if ((A[i] & bit) != 0)
            v.push_back(A[i]);
    }

    if (v.size() == 1)
        return "WIN";

    ll t = N - v.size();
    if ((v.size() / 2) % 2 == 0) {
        return "WIN";
    }
    else {
        if (t % 2 == 0)
            return "LOSE";
    }
    return "WIN";
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