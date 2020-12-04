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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<ll> v;
    REP(i, N) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    if (v.size() > 1 && K == 1)
        return -1;
    ll k = 1;
    ll ret = 1;
    FOR(i, N, 1) {
        if (A[i] != A[i - 1])
            k++;
        if (k > K) {
            k = 2;
            ret++;
        }
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