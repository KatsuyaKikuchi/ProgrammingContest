#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll T[3][4005][4005];
ll M[3][4005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    memset(T, 0, sizeof(T));
    memset(M, 0, sizeof(M));
    REP(i, N) {
        REP(j, i) {
            if (S[i] == S[j])
                continue;

            ll m = -1;
            if (S[i] == 'R') {
                if (S[j] == 'G')
                    m = 2;
                else if (S[j] == 'B')
                    m = 1;
            }
            else if (S[i] == 'G') {
                if (S[j] == 'R')
                    m = 2;
                else if (S[j] == 'B')
                    m = 0;
            }
            else if (S[i] == 'B') {
                if (S[j] == 'R')
                    m = 1;
                else if (S[j] == 'G')
                    m = 0;
            }

            T[m][i][i - j]++;
            M[m][i]++;
        }
    }
    ll ans = 0;
    REP(i, N) {
        REP(j, 3) {
            M[j][i + 1] += M[j][i];
        }
    }

    for (ll i = 2; i < N; ++i) {
        ll m = 2;
        if (S[i] == 'R')
            m = 0;
        else if (S[i] == 'G')
            m = 1;
        ans += M[m][i - 1];
        REP(j, i) {
            ll n = i - j;
            if (j - n < 0)
                continue;
            if (S[i] != S[j] && S[j] != S[j - n] && S[i] != S[j - n])
                ans--;
        }
    }
    cout << ans << endl;
    return 0;
}