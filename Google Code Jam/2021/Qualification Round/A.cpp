#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N;
    cin >> N;
    vector<ll> L(N);
    REP(i, N) {
        cin >> L[i];
        L[i]--;
    }
    ll ret = 0;
    REP(i, N - 1) {
        FOR(j, N, i) {
            if (L[j] != i) {
                continue;
            }
            ret += j - i + 1;
            REP(n, (j - i + 1) / 2) {
                swap(L[i + n], L[j - n]);
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(i, Q) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}