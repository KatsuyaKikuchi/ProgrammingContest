#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[100005];
queue<ll> S[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, C;
    cin >> N >> C;
    REP(i, N) {
        cin >> A[i];
        S[A[i] - 1].push(i);
    }
    REP(i, C) {
        S[i].push(N);
    }

    REP(i, C) {
        ll s = (N + 1) * N / 2;
        ll index = -1;
        while (!S[i].empty()) {
            ll t = S[i].front();
            S[i].pop();
            ll n = t - (index + 1);
            s -= n * (n + 1) / 2;
            index = t;
        }
        cout << s << endl;
    }
    return 0;
}