#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

ll P[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<pll> v;
    ll ans = 0;
    REP(i, N) {
        ll a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            ans++;
            continue;
        }
        else {
            if (a == 0) {
                b = 1;
            }
            else if (b == 0) {
                a = 1;
            }
            else {
                ll g = gcd(abs(a), abs(b));
                a /= g;
                b /= g;
            }
            v.push_back(pll(a, b));
        }
    }

    P[0] = 1;
    REP(i, N + 1) {
        P[i + 1] = P[i] * 2LL % MOD;
    }

    std::map<pll, ll> Map;

    REP(i, v.size()) {
        pll t = v[i];
        if (t.first == 0) {
            Map[pll(0, 1)]++;
        }
        else if (t.second == 0) {
            Map[pll(1, 0)]++;
        }
        else if ((t.first > 0 && t.second < 0) || (t.first < 0 && t.second > 0)) {
            ll n = Map[pll(abs(t.second), abs(t.first))];
            Map[pll(-abs(t.first), -abs(t.second))]++;
        }
        else {
            Map[pll(abs(t.first), abs(t.second))]++;
        }
    }

    map<pll, bool> U;
    vector<pll> u;
    REP(i, v.size()) {
        pll t = v[i];
        if (t.first == 0) {
            if (U[pll(1, 0)])
                continue;
            ll n = Map[pll(1, 0)];
            ll m = Map[pll(0, 1)];
            U[pll(1, 0)] = true;
            U[pll(0, 1)] = true;
            u.push_back(pll(n, m));
        }
        else if (t.second == 0) {
            if (U[pll(0, 1)])
                continue;
            ll n = Map[pll(1, 0)];
            ll m = Map[pll(0, 1)];
            U[pll(1, 0)] = true;
            U[pll(0, 1)] = true;
            u.push_back(pll(n, m));
        }
        else if ((t.first > 0 && t.second < 0) || (t.first < 0 && t.second > 0)) {
            if (U[pll(abs(t.second), abs(t.first))])
                continue;
            ll n = Map[pll(abs(t.second), abs(t.first))];
            ll m = Map[pll(-abs(t.first), -abs(t.second))];
            U[pll(abs(t.second), abs(t.first))] = true;
            U[pll(-abs(t.first), -abs(t.second))] = true;
            u.push_back(pll(n, m));
        }
        else {
            if (U[pll(abs(t.first), abs(t.second))])
                continue;
            ll n = Map[pll(abs(t.first), abs(t.second))];
            ll m = Map[pll(-abs(t.second), -abs(t.first))];
            U[pll(abs(t.first), abs(t.second))] = true;
            U[pll(-abs(t.second), -abs(t.first))] = true;
            u.push_back(pll(n, m));
        }
        //cout << v[i].first << " " << v[i].second << " " << u.size() << endl;
    }


    ll p = 1;
    REP(i, u.size()) {
        ll n = (P[u[i].first] - 1) * p % MOD;
        ll m = (P[u[i].second] - 1) * p % MOD;
        ans = (ans + n + m) % MOD;

        p = p * (P[u[i].first] + P[u[i].second] - 1) % MOD;
    }

    cout << ans << endl;
    return 0;
}