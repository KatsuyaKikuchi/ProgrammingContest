#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[5005], G[5005], C[5005], T[5005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    memset(A, 0, sizeof(A));
    memset(G, 0, sizeof(G));
    memset(C, 0, sizeof(C));
    memset(T, 0, sizeof(T));
    REP(i, N) {
        switch (S[i]) {
            case 'A':
                A[i + 1]++;
                break;
            case 'G':
                G[i + 1]++;
                break;
            case 'C':
                C[i + 1]++;
                break;
            case 'T':
                T[i + 1]++;
                break;
        }
        A[i + 2] += A[i + 1];
        T[i + 2] += T[i + 1];
        C[i + 2] += C[i + 1];
        G[i + 2] += G[i + 1];
    }
    ll ans = 0;
    REP(i, N) {
        FOR(j, N, i) {
            ll a = A[j + 1] - A[i];
            ll g = G[j + 1] - G[i];
            ll t = T[j + 1] - T[i];
            ll c = C[j + 1] - C[i];
            if (a == t && c == g)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}