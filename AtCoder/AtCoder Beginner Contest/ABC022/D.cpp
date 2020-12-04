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

double length(pdd v) {
    return sqrt(v.first * v.first + v.second * v.second);
}

pdd A[100005];
pdd B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    pdd c0(0, 0);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        c0.first += A[i].first;
        c0.second += A[i].second;
    }

    c0.first /= N;
    c0.second /= N;
    pdd c1(0, 0);
    REP(i, N) {
        cin >> B[i].first >> B[i].second;
        c1.first += B[i].first;
        c1.second += B[i].second;
    }
    c1.first /= N;
    c1.second /= N;

    REP(i, N) {
        A[i].first -= c0.first;
        A[i].second -= c0.second;
        B[i].first -= c1.first;
        B[i].second -= c1.second;
    }

    sort(A, A + N, [](pdd a, pdd b) { return atan2l(a.second, a.first) < atan2l(b.second, b.first); });
    sort(B, B + N, [](pdd a, pdd b) { return atan2l(a.second, a.first) < atan2l(b.second, b.first); });

    REP(i, N) {
        double len = length(B[i]) / length(A[0]);
        cout << OF64 << len << endl;
        bool e = true;
        REP(j, N) {
            double t = length(B[(i + j) % N]) / length(A[j]);
            if (abs(t - len) > 1) {
                e = false;
                break;
            }
        }
        if (e) {
            cout << OF64 << len << endl;
            break;
        }
    }
    return 0;
}