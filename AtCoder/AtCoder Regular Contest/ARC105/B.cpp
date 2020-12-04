#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

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

    std::set<ll> st;
    ll mn = INF;
    REP(i, N) {
        mn = std::min(mn, A[i]);
        st.insert(A[i]);
    }

    while (true) {
        auto it = st.rbegin();
        ll mx = *it;

        if (mn == mx) {
            break;
        }
        st.erase(mx);
        mx = mx - mn;
        mn = std::min(mn, mx);
        st.insert(mx);
    }
    cout << mn << endl;
    return 0;
}