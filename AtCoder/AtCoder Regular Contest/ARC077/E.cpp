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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<ll> S(2 * M + 10, 0), C(2 * M + 10, 0);
    ll sum = 0;
    REP(i, N - 1) {
        ll d = (A[i + 1] - A[i] + M) % M;
        sum += d;
        if (A[i] < A[i + 1]) {
            C[A[i] + 1]++;
            C[A[i + 1]]--;
            S[A[i + 1]] -= d - 1;
        }
        else {
            C[A[i] + 1]++;
            C[A[i + 1] + M]--;
            S[A[i + 1] + M] -= d - 1;
        }
    }
    ll s = 0;
    REP(i, S.size() - 1) {
        s += C[i];
        S[i] += s;
        S[i + 1] += S[i];
    }
    ll ans = sum;
    REP(i, M) {
        ans = std::min(ans, sum - (S[i] + S[i + M]));
    }
    cout << ans << endl;
    return 0;
}