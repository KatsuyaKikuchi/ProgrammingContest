#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[200005];
bool D[200005];

int main() {
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    memset(D, 0, sizeof(D));

    ll index = 0;
    REP(i, N) {
        if (A[i].first * A[i].second > A[index].first * A[index].second)
            index = i;
    }
    REP(i, N) {
        if (index == i)
            continue;
        pll a = A[index];
        pll b = A[i];

        ll na = (b.first + a.second - 1) / a.second;
        ll nb = (a.first + b.second - 1) / b.second;
        if (na == nb) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << index + 1 << endl;
    return 0;
}