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
    ll N;
    cin >> N;
    vector<ll> v;
    REP(i, N) {
        cin >> A[i];
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end(), [](ll a, ll b) { return a > b; });

    REP(i, N) {
        ll ok = N - 1, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (v[mid] <= A[i])
                ok = mid;
            else
                ng = mid;
        }
        cout << ok + 1 << endl;
    }
    return 0;
}