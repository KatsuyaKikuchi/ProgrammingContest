#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[2][2];

/* 0
 * o
 * o o
 * 1
 * o o
 * o
 * 2
 *   o
 * o o
 * 3
 * o o
 *   o
 */
ll getType(pll a, pll b, pll c) {
    memset(U, 0, sizeof(U));
#if false
    a = pll(pll(abs(a.first), abs(a.second)));
    b = pll(pll(abs(b.first), abs(b.second)));
    c = pll(pll(abs(c.first), abs(c.second)));
#endif
    ll mx = std::min({a.first, b.first, c.first});
    ll my = std::min({a.second, b.second, c.second});
    U[a.first - mx][a.second - my] = true;
    U[b.first - mx][b.second - my] = true;
    U[c.first - mx][c.second - my] = true;

    if (!U[0][0])
        return 3;
    if (!U[0][1])
        return 2;
    if (!U[1][0])
        return 1;
    return 0;
}

ll calc(ll t0, ll t1) {
    if (t0 == t1)
        return 0;
    return 1;
}

ll solve() {
    pll a, b, c;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
    pll a0(0, 0), b0(1, 0), c0(0, 1);
    {
        ll mx = std::min({a.first, b.first, c.first});
        ll my = std::min({a.second, b.second, c.second});
        if (mx < 0)
            b0 = pll(-1, 0);
        if (my < 0)
            c0 = pll(0, -1);
    }
#if false
    vector<vector<ll>> v(20, vector<ll>(20, 0));
    v[a.first + 10][a.second + 10] = 1;
    v[b.first + 10][b.second + 10] = 1;
    v[c.first + 10][c.second + 10] = 1;
    v[0 + 10][0 + 10] = -1;
    v[0 + 10][1 + 10] = -1;
    v[1 + 10][0 + 10] = -1;
    REP(i, v.size()) {
        REP(j, v[i].size()) {
            if (v[j][v.size() - 1 - i] == 1)
                cout << "X";
            else if (v[j][v.size() - 1 - i] == -1)
                cout << "o";
            else
                cout << " ";
        }
        cout << endl;
    }
#endif

    a = pll(pll(abs(a.first), abs(a.second)));
    b = pll(pll(abs(b.first), abs(b.second)));
    c = pll(pll(abs(c.first), abs(c.second)));
    ll t1 = getType(a, b, c);
    ll t0 = getType(a0, b0, c0);
    //cout << t0 << " " << t1 << endl;
    if (t0 == 1) {
        a.second++;
        b.second++;
        c.second++;
    }
    if (t0 == 2) {
        a.first++;
        b.first++;
        c.first++;
    }
    if (t0 == 3) {
        a.first++;
        b.first++;
        c.first++;
        a.second++;
        b.second++;
        c.second++;
    }

    ll ret = 0;
    {
        ll mx = std::min({a.first, b.first, c.first});
        ll my = std::min({a.second, b.second, c.second});
        ll m0 = std::min(mx, my);
        ll m1 = std::max(mx, my);
        vector<ll> v;
        switch (t0) {
            case 0:
                if (m1 == 0) {
                    v.push_back(0);
                }
                else {
                    if (m0 != 0) {
                        ret = m0 * 2LL + 1;
                        if (m1 != m0)
                            ret += (m1 - m0) * 2LL - 1;
                    }
                    else {
                        ret = m1 * 2LL;
                    }
                    if (mx < my) {
                        v.push_back(2);
                        v.push_back(0);
                    }
                    else if (mx > my) {
                        v.push_back(0);
                        v.push_back(1);
                    }
                    else {
                        v.push_back(0);
                        v.push_back(1);
                        v.push_back(2);
                    }
                }
                break;
            case 1:
                ret = m0 * 2LL;
                if (mx < my) {
                    ret += (m1 - m0) * 2LL - 1;
                    v.push_back(0);
                    v.push_back(2);
                }
                else if (mx > my) {
                    ret += (m1 - m0) * 2LL;
                    v.push_back(0);
                    v.push_back(1);
                }
                else {
                    v.push_back(0);
                    v.push_back(1);
                }
                break;
            case 2:
                ret = m0 * 2LL;
                if (mx < my) {
                    ret += (m1 - m0) * 2LL;
                    v.push_back(2);
                    v.push_back(0);
                }
                else if (mx > my) {
                    ret += (m1 - m0) * 2LL - 1;
                    v.push_back(0);
                    v.push_back(1);
                }
                else {
                    v.push_back(0);
                    v.push_back(2);
                }
                break;
            case 3:
                ret = m0 * 2LL;
                if (mx < my) {
                    ret += (m1 - m0) * 2LL - 1;
                    v.push_back(2);
                    v.push_back(0);
                }
                else if (mx > my) {
                    ret += (m1 - m0) * 2LL - 1;
                    v.push_back(0);
                    v.push_back(1);
                }
                else {
                    v.push_back(0);
                    v.push_back(1);
                    v.push_back(2);
                }
                break;
        }
        ll mn = INF;
        REP(i, v.size()) {
            mn = std::min(mn, calc(t1, v[i]));
        }
        ret += mn;
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}