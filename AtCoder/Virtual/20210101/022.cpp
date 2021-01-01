#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        cin >> A[i];
        A[i]--;
    }
    vector<bool> seen(N, false);
    vector<ll> ans;
    for (ll i = M - 1; i >= 0; --i) {
        if (seen[A[i]])
            continue;
        seen[A[i]] = true;
        ans.push_back(A[i]);
    }
    REP(i, N) {
        if (seen[i])
            continue;
        ans.push_back(i);
    }
    REP(i, N) {
        cout << ans[i] + 1 << endl;
    }
    return 0;
}