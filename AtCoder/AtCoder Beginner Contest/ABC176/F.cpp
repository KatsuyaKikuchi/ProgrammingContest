#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

ll A[10005];
ll G[2005][2005];
Vertex V[2005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
        A[i]--;
    }
    REP(i, N) {
        REP(j, N) {
            G[i][j] = -1;
        }
    }
    G[A[3 * N - 1]][A[3 * N - 1]] = N;
    ll d = 0;
    for (ll i = 3 * N - 4; i >= 2; i -= 3) {
        ll a = std::min({A[i], A[i + 1], A[i + 2]});
        ll c = std::max({A[i], A[i + 1], A[i + 2]});
        ll b = A[i] + A[i + 1] + A[i + 2] - a + c;
        if (a == b && b == c) {
            d++;
            continue;
        }

        ll index = (i + 1) / 3;
        if (a == b) {
            if()
        }
        else if (b == c) {

        }
        else {

        }
    }

    ll ans = 0;
    priority_queue<pll, vector<pll>>

    cout << -ans + d << endl;
    return 0;
}