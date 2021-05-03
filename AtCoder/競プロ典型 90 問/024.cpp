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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll cnt = 0;
    REP(i, N) {
        ll b;
        cin >> b;
        cnt += abs(b - A[i]);
    }

    if (cnt > K || (K - cnt) % 2 == 1)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}