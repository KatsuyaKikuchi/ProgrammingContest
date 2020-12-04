#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
map<ll, ll> M;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
        M[A[i]]++;
    }
    sort(A, A + N);
    ll ans = 0;
    for (ll i = N - 1; i >= 0; --i) {
        if (M[A[i]]-- < 0)
            continue;
        ll p = 1;
        while (p < A[i])
            p <<= 1LL;
        if (p == A[i]) {
            if (M[A[i]]-- > 0)
                ans++;
        }
        else if (M[p - A[i]]-- > 0)
            ans++;

    }

    cout << ans << endl;
    return 0;
}