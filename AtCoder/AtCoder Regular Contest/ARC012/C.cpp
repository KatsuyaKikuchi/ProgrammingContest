#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 19;

string S[20];
pll x[4] = {pll(-1, 0), pll(-1, -1), pll(0, -1), pll(1, -1)};
pll y[4] = {pll(1, 0), pll(1, 1), pll(0, 1), pll(-1, 1)};

ll check(pll g, char c) {
    ll ret = 0;
    REP(i, 4) {
        ll m0 = 0;
        {
            ll nx = g.first, ny = g.second;
            while (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && S[nx][ny] == c) {
                m0++;
                nx += x[i].first;
                ny += x[i].second;
            }
        }
        if (m0 > 5)
            return INF;

        ll m1 = 0;
        {
            ll nx = g.first, ny = g.second;
            while (nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && S[nx][ny] == c) {
                m1++;
                nx += y[i].first;
                ny += y[i].second;
            }
        }
        if (m1 > 5)
            return INF;

        if (m1 + m0 - 1 >= 5)
            ret++;
    }
    return ret;
}

void calc(pll g, function<pll(pll a)> f, bool fin, ll &m, ll &bl, ll &bw, ll &wl, ll &ww) {
    pll p = f(g);
    if (S[g.first][g.second] == S[p.first][p.second])
        m++;

    if (S[g.first][g.second] != S[p.first][p.second] || fin) {
        if (S[p.first][p.second] == 'o') {
            bl = std::max(m, bl);
            if (m >= 5)
                bw++;
        }
        else if (S[p.first][p.second] == 'x') {
            wl = std::max(m, wl);
            if (m >= 5)
                ww++;
        }
        m = 1;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    REP(i, MAX) {
        cin >> S[i];
    }
    ll bn = 0, wn = 0;
    REP(i, MAX) {
        REP(j, MAX) {
            if (S[i][j] == 'o')
                bn++;
            if (S[i][j] == 'x')
                wn++;
        }
    }

    ll bw = 0, ww = 0, bl = 0, wl = 0;
    REP(i, MAX) {
        ll m = 1;
        {
            ll m = 1;
            FOR(j, MAX, 1) {
                calc(pll(i, j), [](pll a) { return pll(a.first, a.second - 1); },
                     j == MAX - 1, m, bl, bw, wl, ww);
            }
        }
        {
            ll m = 1;
            FOR(j, MAX, 1) {
                calc(pll(j, i), [](pll a) { return pll(a.first - 1, a.second); },
                     j == MAX - 1, m, bl, bw, wl, ww);
            }
        }
        {
            ll m = 1;
            FOR(j, MAX, 1) {
                if (i + j >= MAX)
                    break;
                calc(pll(i + j, j), [](pll a) { return pll(a.first - 1, a.second - 1); },
                     j == MAX - 1 || i + j == MAX - 1, m, bl, bw, wl, ww);
            }
        }
        if (i > 0) {
            ll m = 1;
            FOR(j, MAX, 1) {
                if (i + j >= MAX)
                    break;
                calc(pll(j, i + j), [](pll a) { return pll(a.first - 1, a.second - 1); },
                     j == MAX - 1 || i + j == MAX - 1, m, bl, bw, wl, ww);
            }
        }
        {
            ll m = 1;
            FOR(j, MAX, 1) {
                if (i - j < 0)
                    break;
                calc(pll(i - j, j), [](pll a) { return pll(a.first + 1, a.second - 1); },
                     j == MAX - 1 || i - j == 0, m, bl, bw, wl, ww);
            }
        }
        if (i > 0) {
            ll m = 1;
            FOR(j, MAX, 1) {
                if (i + j >= MAX)
                    break;
                calc(pll(MAX - 1 - j, i + j), [](pll a) { return pll(a.first + 1, a.second - 1); },
                     j == MAX - 1 || i + j == MAX - 1, m, bl, bw, wl, ww);
            }
        }
    }
    //cout << bl << " " << bw << "," << wl << " " << ww << endl;

    if (bw > 0 && ww > 0) {
        cout << "NO" << endl;
        return 0;
    }
    if (bl >= 10 || wl >= 10) {
        cout << "NO" << endl;
        return 0;
    }
    ll n = bn - wn;
    if (n < 0 || n > 1 || (ww > 0 && n != 0) || (bw > 0 && n != 1)) {
        cout << "NO" << endl;
        return 0;
    }

    if (bw > 0) {
        bool e = false;
        REP(i, MAX) {
            REP(j, MAX) {
                if (S[i][j] != 'o')
                    continue;
                //! (i,j)に最後に置く
                if (check(pll(i, j), S[i][j]) == bw) {
                    e = true;
                }
            }
        }
        if (!e) {
            cout << "NO" << endl;
            return 0;
        }
    }
    else if (ww > 0) {
        bool e = false;
        REP(i, MAX) {
            REP(j, MAX) {
                if (S[i][j] != 'x')
                    continue;
                //! (i,j)に最後に置く
                ll ret = check(pll(i, j), S[i][j]);
                //cout << ret << endl;
                if (ret == ww) {
                    e = true;
                }
            }
        }
        if (!e) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}