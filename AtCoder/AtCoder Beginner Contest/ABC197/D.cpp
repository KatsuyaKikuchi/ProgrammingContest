#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    pll a, b;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    double dx = (b.first - a.first) * 0.5, dy = (b.second - a.second) * 0.5;
    double cx = a.first + dx, cy = a.second + dy;
    complex<double> dir(-dx, -dy);
    double pi = ((360.0 / N) / 180.0) * M_PI;
    complex<double> rot(cos(pi), sin(pi));
    auto dir2 = dir * rot;
    cout << OF64 << cx + dir2.real() << " " << cy + dir2.imag() << endl;
    return 0;
}