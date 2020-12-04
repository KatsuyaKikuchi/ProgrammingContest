#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

double solve() {
    ll N;
    double L;
    cin >> N >> L;
    vector<double> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    double ret = L, ng = 0;
    REP(_, 100) {
        double mid = (ret + ng) * 0.5;
        double x0 = 0, x1 = L;
        double v0 = 1, v1 = 1;
        {
            double t = mid;
            REP(i, N) {
                if (v0 * t + x0 < A[i]) {
                    x0 += v0 * t;
                    t = 0;
                    break;
                }
                double d = A[i] - x0;
                t -= d / v0;
                x0 = A[i];
                v0 += 1.0;
            }
            x0 += v0 * t;
        }
        {
            double t = mid;
            for (ll i = N - 1; i >= 0; --i) {
                if (x1 - v1 * t > A[i]) {
                    x1 -= v1 * t;
                    t = 0;
                    break;
                }
                double d = x1 - A[i];
                t -= d / v1;
                x1 = A[i];
                v1 += 1.0;
            }
            x1 -= v1 * t;
        }
        if (x0 >= x1)
            ret = mid;
        else
            ng = mid;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll Q;
    cin >> Q;
    REP(i, Q) {
        cout << OF64 << solve() << endl;
    }
    return 0;
}