#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[1000010];

ll solve(string &S) {
    ll N = S.length();
    vector<ll> v(N);
    vector<ll> cnt(3, 0);
    REP(i, N) {
        v[i] = S[i] - '1';
        cnt[v[i]]++;
    }

    P[0] = 0;
    REP(i, N + 1) {
        P[i + 1] = P[i];
        ll x = i + 1;
        while (x % 2 == 0) {
            P[i + 1]++;
            x /= 2;
        }
    }
    if (cnt[1] == 0 && cnt[0] > 0 && cnt[2] > 0) {
        ll ret = 0;
        REP(i, N) {
            if (v[i] == 0)
                continue;
            ll a = P[N - 1];
            ll b = P[i] + P[N - 1 - i];
            if (a != b)
                continue;
            ret ^= 1;
        }
        return ret * 2;
    }

    ll ans = 0;
    REP(i, N) {
        if (v[i] % 2 == 0)
            continue;
        ll a = P[N - 1];
        ll b = P[i] + P[N - 1 - i];
        if (a != b)
            continue;
        ans ^= 1;
    }
    return ans % 2;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    cout << solve(S) << endl;
    return 0;
}