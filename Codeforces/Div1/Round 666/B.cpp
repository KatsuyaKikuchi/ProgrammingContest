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
    ll s = 0;
    REP(i, N) {
        cin >> A[i];
        s += A[i];
    }
#if false
    if (N == 1)
        return "T";
    if (N == 2) {
        if (A[0] == A[1])
            return "HL";
        return "T";
    }
#endif

    ll last = -1;
    ll cnt = 0;
    while (true) {
        ll mi = -1;
        REP(i, N) {
            if (i == last)
                continue;
            if (mi < 0 || A[mi] < A[i])
                mi = i;
        }

        if (mi < 0 || A[mi] == 0)
            break;
        A[mi]--;
        last = mi;
        cnt++;
    }

    if (cnt % 2 == 0)
        return "HL";
    return "T";
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