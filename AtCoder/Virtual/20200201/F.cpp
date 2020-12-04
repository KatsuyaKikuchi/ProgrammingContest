#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
ll A[300005];
ll B[300005];
vector<ll> v;

ll solve(ll n) {
    if (v.size() < n)
        return 0;

    ll ret = INF;
    REP(i, n) {
        ll m = i;
        ll s = 0;
        ll t = 0;
        while (m < v.size()) {
            s += v[m];
            if (t % 2 == 0)
                m += (n - 1 - i) * 2 + 1;
            else
                m += i * 2 + 1;
            t++;
        }
        ret = std::min(ret, s);
    }
    return ret;
}

int main() {
    cin >> N;
    REP(i, N) {
        cin >> A[i];
        B[A[i] - 1]++;
    }

    v.clear();
    REP(i, N) {
        if (B[i] > 0)
            v.push_back(B[i]);
    }
    sort(v.begin(), v.end(), [](ll a, ll b) { return a > b; });

    REP(i, N) {
        cout << solve(i + 1) << endl;
    }
    return 0;
}