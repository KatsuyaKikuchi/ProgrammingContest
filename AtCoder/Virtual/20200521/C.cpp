#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> S[i];
        sort(S[i].begin(), S[i].end());
    }
    sort(S, S + N);
    ll ans = 0;
    ll index = 0;
    REP(i, N) {
        if (S[i] != S[index]) {
            ll n = i - index;
            ans += n * (n - 1) / 2;
            index = i;
        }

        if (i == N - 1) {
            ll n = i - index + 1;
            ans += n * (n - 1) / 2;
        }
    }
    cout << ans << endl;
    return 0;
}