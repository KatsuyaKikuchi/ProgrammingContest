#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    ll p = 1;
    ll s = 0;
    ll ans = 1;
    REP(i, A.size()) {
        s = (s + (A[i] % 10) * p) % MOD;
        p = p * 10 % MOD;

        if (A[i] <= 9) {
            ans = (ans * (s + 1)) % MOD;
            p = 1;
            s = 0;
            continue;
        }
        ll n = A[i] / 10;
        if (A.size() == i + 1)
            A.push_back(0);
        A[i + 1] += n;
    }
    cout << (MOD + ans - 1) % MOD << endl;
    return 0;
}