#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 1000005;

queue<ll> q[1005];
bool U[1000005];
vector<ll> v[55];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;

    ll d = K;
    REP(i, N) {
        REP(j, K) {
            ll p;
            cin >> p;
            q[j].push(p);
        }
        ll m = 0;
        ll n = 0;
        REP(j, K) {
            while (!q[j].empty() && m < d) {
                ll t = q[j].front();
                q[j].pop();
                if (U[t])
                    continue;
                U[t] = true;
                m++;
                n++;
                v[i].push_back(t);
            }
            m += N - 1 - i;
        }
        d -= n;
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