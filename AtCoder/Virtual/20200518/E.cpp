#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[55][1005];
bool U[1000005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        REP(j, K) {
            cin >> A[i][j];
        }
    }

    vector<vector<ll>> v(N);
    queue<ll> q[1005];
    ll cnt = 0;
    REP(i, N) {
        REP(j, K) {
            ll d = (N - 1 - i) * j;
            q[j].push(A[i][j]);
            if (cnt + d >= K)
                continue;
            while (!q[j].empty() && cnt + d < K) {
                ll t = q[j].front();
                q[j].pop();
                if (U[t])
                    continue;
                v[i].push_back(t);
                U[t] = true;
                cnt++;
            }
        }
    }
    REP(i, N) {
        sort(v[i].begin(), v[i].end());
        REP(j, v[i].size()) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}