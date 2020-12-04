#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200010];
vector<ll> V[200010];
bool U[200010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
        V[A[i]].push_back(i);
    }
    REP(i, N) {
        if (V[A[i]].back() < INF)
            V[A[i]].push_back(INF);
    }

    vector<ll> v;
    v.push_back(0);
    ll index = 0;
    ll cnt = 1;
    do {
        ll n = A[index];
        ll nxt = upper_bound(V[n].begin(), V[n].end(), index) - V[n].begin();
        if (nxt == V[n].size() - 1) {
            cnt++;
            nxt = 0;
            v.push_back(V[n][nxt] + 1);
        }
        index = V[n][nxt] + 1;
    } while (index < N);
    ll s = v[(cnt - 1 + (K % cnt)) % cnt];
    deque<ll> ans;
    FOR(i, N, s) {
        ll n = A[i];
        if (U[n]) {
            while (!ans.empty()) {
                ll m = ans.back();
                ans.pop_back();
                U[m] = false;
                if (m == n)
                    break;
            }
            continue;
        }
        U[n] = true;
        ans.push_back(n);
    }

    while (!ans.empty()) {
        ll n = ans.front();
        ans.pop_front();
        cout << n << " ";
    }
    cout << endl;
    return 0;
}