#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[200005];
ll T[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    vector<ll> H(N), W(M);
    REP(i, N) {
        cin >> H[i];
    }
    sort(H.begin(), H.end());
    REP(i, M) {
        cin >> W[i];
    }
    sort(W.begin(), W.end());
    memset(S, 0, sizeof(S));
    memset(T, 0, sizeof(T));
    FOR(i, N, 1) {
        S[i] += S[i - 1];
        if (i % 2 == 1)
            S[i] += abs(H[i] - H[i - 1]);
    }
    for (ll i = N - 1; i >= 0; --i) {
        T[i] += T[i + 1];
        if (i % 2 == 1)
            T[i] += abs(H[i + 1] - H[i]);
    }
    H.push_back(INF);

    ll ans = INF;
    ll index = 0;
    REP(i, M) {
        while (W[i] > H[index])
            index++;
        if (index % 2 == 0) {
            ll s = 0;
            if (index > 0)
                s += S[index - 1];
            s += T[index + 1];
            s += abs(H[index] - W[i]);
            ans = std::min(ans, s);
        }
        else {
            ll s = 0;
            s += T[index];
            if (index > 1)
                s += S[index - 2];
            s += abs(H[index - 1] - W[i]);
            ans = std::min(ans, s);
        }
    }

    cout << ans << endl;
    return 0;
}