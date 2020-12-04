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
vector<ll> X[25];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, 25) {
        REP(j, N) {
            X[i].push_back(0);
        }
    }
    REP(i, N) {
        ll index = 0;
        while (A[i] > 0) {
            X[index++][i] = A[i] % 2;
            A[i] /= 2;
        }
    }
    REP(i, 25) {
        sort(X[i].begin(), X[i].end());
    }

    vector<ll> v(N);
    REP(i, N) {
        ll index = 0;
        while (index < 25) {
            if (X[index][i] == 1)
                v[i] += (1LL << index);
            index++;
        }
    }

    ll ans = 0;
    REP(i, N) {
        ans += v[i] * v[i];
    }
    cout << ans << endl;
    return 0;
}