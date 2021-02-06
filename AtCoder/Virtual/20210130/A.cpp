#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 50;

ll A[200005];
ll D[200005][55];
ll F[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    memset(F, -1, sizeof(F));
    REP(i, N) {
        cin >> A[i];
        if (F[A[i]] < 0)
            F[A[i]] = i;
    }

    for (ll i = N - 1; i >= 0; --i) {
        ll nxt = F[A[i]];
        if (nxt > i && nxt != N - 1)
            nxt = D[nxt + 1][0];
        D[i][0] = nxt;
        F[A[i]] = i;
    }

    REP(i, MAX) {
        REP(j, N) {
            D[j][i + 1] = D[(D[j][i] + 1) % N][i];
        }
    }

#if false
    REP(i, N) {
        REP(j, 3) {
            cout << D[i][j] << " ";
        }
        cout << endl;
    }
#endif

    ll start = 0;
    REP(bit, MAX) {
        if (((K - 1) >> bit) & 1)
            start = D[start % N][bit] + 1;
    }
    if (start == N) {
        //cout << endl;
        //return 0;
    }
    vector<bool> used(200005, false);
    deque<ll> q;
    FOR(i, N, start % N) {
        if (used[A[i]]) {
            while (used[A[i]]) {
                used[q.back()] = false;
                q.pop_back();
            }
        }
        else {
            used[A[i]] = true;
            q.push_back(A[i]);
        }
    }

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << endl;

    return 0;
}