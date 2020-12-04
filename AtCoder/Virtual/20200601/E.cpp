#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[105];
pll A[105];
pll B[105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    REP(i, N) {
        cin >> B[i].first >> B[i].second;
    }
    sort(B, B + N, [](pll a, pll b) { return a.first < b.first; });
    ll ans = 0;
    REP(i, N) {
        pll b = B[i];
        ll index = -1;
        REP(j, N) {
            if (U[j])
                continue;
            if (A[j].first > b.first || A[j].second > b.second)
                continue;

            if (index < 0 || A[index].second < A[j].second)
                index = j;
        }

        if (index < 0)
            continue;
        U[index] = true;
        ans++;
    }
    cout << ans << endl;
    return 0;
}