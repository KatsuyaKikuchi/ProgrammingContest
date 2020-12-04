#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string A;
ll B;
ll K;
vector<vector<ll>> V;
bool U[10];

void dfs(vector<ll> t, ll s = 0) {
    if (t.size() > 0 && t.size() <= K) {
        V.push_back(t);
    }
    if (t.size() == K)
        return;
    FOR(i, 10, s) {
        t.push_back(i);
        dfs(t, i + 1);
        t.pop_back();
    }
}

ll calc(const vector<ll> &v) {
    memset(U, 0, sizeof(U));
    ll mx = 0, mn = 9;
    REP(i, v.size()) {
        U[v[i]] = true;
        mx = std::max(v[i], mx);
        mn = std::min(v[i], mn);
    }

    vector<ll> t;
    ll N = A.length();
    {
        ll n = 0;
        REP(i, N - 1) {
            n = n * 10LL + mx;
        }
        t.push_back(n);
    }
    {
        ll n = 0;
        REP(i, N) {
            n = n * 10LL + mn;
        }
        t.push_back(n);
    }

    {
        ll n = 0;
        REP(i, N) {
            ll m = A[i] - '0';
            for (ll j = m - 1; j >= 0; --j) {
                if (!U[j])
                    continue;
                ll x = n * 10LL + j;
                REP(k, N - (i + 1)) {
                    x = x * 10LL + mx;
                }
                t.push_back(x);
                break;
            }

            FOR(j, 10, m + 1) {
                if (!U[j])
                    continue;
                ll x = n * 10LL + j;
                REP(k, N - (i + 1)) {
                    x = x * 10LL + mn;
                }
                t.push_back(x);
                break;
            }
            if (!U[m])
                break;
            n = n * 10LL + m;
            if (i == N - 1)
                t.push_back(n);
        }
    }

    ll ret = INF;
#if false
    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
    REP(i, t.size()) {
        cout << t[i] << " ";
    }
    cout << endl;
    cout << "----------------------------------" << endl;
#endif
    REP(i, t.size()) {
        ret = std::min(ret, abs(B - t[i]));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> A >> K;
    B = 0;
    REP(i, A.length()) {
        B = B * 10LL + A[i] - '0';
    }

    dfs(vector<ll>());
    ll ans = INF;
    REP(i, V.size()) {
        ans = std::min(ans, calc(V[i]));
    }
    cout << ans << endl;

    return 0;
}