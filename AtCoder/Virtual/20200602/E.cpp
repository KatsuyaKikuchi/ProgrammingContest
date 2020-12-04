#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    ll mx = 0, mn = 0;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, N) {
        if (A[i] > A[mx])
            mx = i;
        if (A[i] < A[mn])
            mn = i;
    }

    vector<pll> v;
    if (abs(A[mx]) >= abs(A[mn])) {
        v.push_back(pll(mx + 1, 2));
        v.push_back(pll(2, 2));
        v.push_back(pll(2, 2));
        for (ll i = 3; i <= N; ++i) {
            v.push_back(pll(i - 1, i));
            v.push_back(pll(i, i));
        }
    }
    else {
        v.push_back(pll(mn + 1, N - 1));
        v.push_back(pll(N - 1, N - 1));
        v.push_back(pll(N - 1, N - 1));
        for (ll i = N - 2; i > 0; --i) {
            v.push_back(pll(i + 1, i));
            v.push_back(pll(i, i));
        }
    }

    cout << v.size() << endl;
    REP(i, v.size()) {
        cout << v[i].first << " " << v[i].second << endl;
    }
    return 0;
}