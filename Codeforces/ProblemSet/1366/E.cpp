#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

ll A[200005];
ll B[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i];
    }

    ll ans = 1;
    ll fst = -1;
    ll index = M - 1;
    for (ll i = N - 1; i >= 0; --i) {
        if (A[i] < B[index]) {
            ll n = std::max(0LL, fst - i);
            ans = (ans * n) % MOD;
            fst = -1;
            index--;
            if (index < 0)
                break;
        }
        if (A[i] < B[index])
            break;
        if (fst == -1 && A[i] == B[index])
            fst = i;
    }
    if (fst == -1 || index != 0)
        ans = 0;

    cout << ans << endl;
    return 0;
}