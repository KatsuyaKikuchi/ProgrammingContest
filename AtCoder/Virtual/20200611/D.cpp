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

pll A[1005];
pdd B[1005];
bool U[1005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + N, [](pll a, pll b) { return a.second > b.second; });
    REP(i, N) {
        B[i].first = A[i].first * A[i].second * 0.01;
        B[i].second = A[i].first;
    }

    pdd t = B[0];
    U[0] = true;

    REP(i, K - 1) {
        ll index = -1;
        REP(j, N) {
            if (U[j])
                continue;
            if (index == -1)
                index = j;
            else {
                double p = (t.first + B[index].first) * (t.second + B[j].second);
                double q = (t.second + B[index].second) * (t.first + B[j].first);
                if (p < q)
                    index = j;
            }
        }
        U[index] = true;
        t.first += B[index].first;
        t.second += B[index].second;
    }

    cout << OF64 << t.first * 100.0 / t.second << endl;

    return 0;
}