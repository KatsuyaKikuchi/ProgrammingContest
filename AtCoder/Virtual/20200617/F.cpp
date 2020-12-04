#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll N;
pll A[55];
pll mx(INF, -INF), my(INF, -INF);

double calc(double x, double y) {
    double ret = 0;
    REP(i, N) {
        double a = A[i].first - x;
        double b = A[i].second - y;
        double len = sqrt(a * a + b * b);
        ret = std::max(ret, len);
    }
    return ret;
}

double calcY(double x) {
    double ly = my.first, ry = my.second;
    REP(_, 100) {
        double lly = ly + (ry - ly) / 3.0;
        double rry = lly + (ry - ly) / 3.0;

        if (calc(x, lly) < calc(x, rry))
            ry = rry;
        else
            ly = lly;
    }
    return calc(x, ly);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        mx.first = std::min(mx.first, A[i].first);
        mx.second = std::max(mx.second, A[i].first);
        my.first = std::min(my.first, A[i].second);
        my.second = std::max(my.second, A[i].second);
    }

    double lx = mx.first, rx = mx.second;
    REP(_, 100) {
        double llx = lx + (rx - lx) / 3.0;
        double rrx = llx + (rx - lx) / 3.0;
        //cout << OF64 << llx << "," << rrx << endl;
        if (calcY(llx) < calcY(rrx))
            rx = rrx;
        else
            lx = llx;
    }


    cout << OF64 << calcY(lx) << endl;
    return 0;
}