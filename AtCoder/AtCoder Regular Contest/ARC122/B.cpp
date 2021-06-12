#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
vector<ll> A;
ll S = 0;

double calc(pdd range, ll n, double s) {
    double ret = (double) S / (double) N - s / (double) N;
    //! f(x) = (1-2n/N)x +ret;
    double p = (1.0 - 2.0 * (N - n) / N);
    return std::min(range.first * p + ret, range.second * p + ret);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    A.resize(N);
    S = 0;
    REP(i, N) {
        cin >> A[i];
        S += A[i];
    }
    sort(A.begin(), A.end());
    A.push_back(INF);
    double ans = INF;
    double p = 0;
    double s = 0;
    REP(i, N) {
        pdd r(p, A[i] * 0.5);
        ans = std::min(ans, calc(r, i, s));
        // cout << OF64 << ans << endl;
        s += A[i];
        p = A[i] * 0.5;
    }
    cout << OF64 << ans << endl;
    return 0;
}