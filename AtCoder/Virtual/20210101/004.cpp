#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll n = N % 2;
    vector<ll> ans;
    for (ll i = N - 1; i >= 0; --i) {
        if (i % 2 != n)
            ans.push_back(A[i]);
    }
    REP(i, N) {
        if (i % 2 == n)
            ans.push_back(A[i]);
    }

    REP(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}