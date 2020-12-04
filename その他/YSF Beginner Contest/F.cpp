#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> S;
    ll s = 0;
    REP(i, K) {
        s += A[i];
    }
    S.push_back(s);
    FOR(i, N, K) {
        s += A[i] - A[i - K];
        S.push_back(s);
    }
    S.push_back(-INF);
    sort(S.begin(), S.end());

    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll x;
        cin >> x;
        ll index = upper_bound(S.begin(), S.end(), x) - S.begin() - 1;
        cout << index << endl;
    }
    return 0;
}