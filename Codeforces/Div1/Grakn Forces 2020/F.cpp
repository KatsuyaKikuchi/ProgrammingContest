#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<pll> query;

    ll bit = N;
    ll num = 0;
    vector<vector<ll>> v;
    REP(i, 20) {
        if ((bit >> i) & 1) {
            ll p = pow(2LL, i);
            vector<ll> t;
            REP(j, p) {
                t.push_back(num++);
            }
            v.push_back(t);
        }
    }
    {
        ll x = v.size() - 1;
        ll diff = 1;
        ll n = v[x].size();
        while (diff < n) {
            for (ll i = 0; i < n; i += 2LL * diff) {
                REP(j, diff) {
                    ll index = i + j;
                    if (index + diff >= n)
                        break;
                    query.push_back(pll(v[x][index], v[x][index + diff]));
                }
            }
            diff *= 2;
        }
    }
    vector<ll> y;
    REP(i, v.size() - 1) {
        REP(j, v[i].size()) {
            y.push_back(v[i][j]);
        }
    }
    ll in = 0;
    while (y.size() != v[v.size() - 1].size()) {
        y.push_back(v[v.size() - 1][in++]);
    }
    {
        ll diff = 1;
        ll n = y.size();
        while (diff < n) {
            for (ll i = 0; i < n; i += 2LL * diff) {
                REP(j, diff) {
                    ll index = i + j;
                    if (index + diff >= n)
                        break;
                    query.push_back(pll(y[index], y[index + diff]));
                }
            }
            diff *= 2;
        }
    }

    cout << query.size() << endl;
    REP(i, query.size()) {
        cout << query[i].first + 1 << " " << query[i].second + 1 << endl;
    }
    return 0;
}