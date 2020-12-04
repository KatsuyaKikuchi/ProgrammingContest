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
    ll N;
    cin >> N;
    vector<ll> v;
    REP(i, N) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    REP(i, N) {
        A[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
    }

    ll cnt = 0;
    REP(i, N) {
        if (i % 2 != A[i] % 2)
            cnt++;
    }
    cout << cnt / 2 << endl;
    return 0;
}