#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll mod[] = {999999937LL, 1000000007LL}, base = 9973;
const ll INF = (ll) 1e15;

std::map<pll, ll> M[27][27];
ll X[27];
bool U[27];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<string> v(N);
    REP(i, N) {
        cin >> v[i];
    }

    ll ans = 0;
    sort(v.begin(), v.end(), [](string a, string b) { return a.length() > b.length(); });
    REP(i, v.size()) {
        if (v[i].size() == 1)
            break;
        ll a = v[i][0] - 'a';
        ll b = v[i][1] - 'a';
        pll h(0, 0);
        for (ll j = v[i].size() - 1; j >= 2; --j) {
            ll x = v[i][j] - 'a' + 1;
            h.first = (h.first * base + x) % mod[0];
            h.second = (h.second * base + x) % mod[1];
        }
        ans += M[a][b][h];
        memset(X, 0, sizeof(X));
        pll hsh(0, 0);
        REP(j, v[i].size()) {
            X[v[i][j] - 'a']++;
        }
        for (ll j = v[i].length() - 1; j >= 0; --j) {
            ll t = v[i][j] - 'a';
            X[t]--;
            REP(x, 26) {
                if (X[x] == 0)
                    continue;
                M[x][t][hsh]++;
            }
            hsh.first = (hsh.first * base + t + 1) % mod[0];
            hsh.second = (hsh.second * base + t + 1) % mod[1];
        }
    }

    memset(X, 0, sizeof(X));
    REP(i, v.size()) {
        if (v[i].size() == 1)
            break;
        memset(U, 0, sizeof(U));
        REP(j, v[i].size()) {
            ll t = v[i][j] - 'a';
            if (U[t])
                continue;
            U[t] = true;
            X[t]++;
        }
    }
    REP(i, v.size()) {
        if (v[i].size() > 1)
            continue;
        ll t = v[i][0] - 'a';
        ans += X[t];
        X[t]++;
    }

    cout << ans << endl;

    return 0;
}