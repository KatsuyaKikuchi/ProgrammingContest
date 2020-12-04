#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool check(vector<string> v, ll n) {
    //! 縦
    REP(i, 9) {
        ll s = 0;
        REP(j, 9) {
            if (v[i][j] == '.')
                s++;
            if (v[i][j] == '#')
                s = 0;
            if (s >= n)
                return false;
        }
    }
    //! 横
    REP(i, 9) {
        ll s = 0;
        REP(j, 9) {
            if (v[j][i] == '.')
                s++;
            if (v[j][i] == '#')
                s = 0;
            if (s >= n)
                return false;
        }
    }

    //! 斜め
    REP(i, 9) {
        ll a = 0, b = 0;
        REP(j, 9) {
            if (i + j >= 9)
                break;

            if (v[j][i + j] == '.')
                a++;
            else if (v[j][i + j] == '#')
                a = 0;
            if (a >= n)
                return false;

            if (v[i + j][j] == '.')
                b++;
            else
                b = 0;
            if (b >= n)
                return false;
        }
    }

    REP(i, 9) {
        ll a = 0, b = 0;
        REP(j, 9) {
            if (i + j >= 9)
                break;
            if (v[j][8 - (i + j)] == '.')
                a++;
            else
                a = 0;
            if (a >= n)
                return false;

            if (v[i + j][8 - j] == '.')
                b++;
            else
                b = 0;
            if (b >= n)
                return false;
        }
    }
    return true;
}

vector<string> build(vector<ll> v) {
    vector<string> t;
    REP(i, 9) {
        t.push_back(".........");
    }

    REP(i, v.size()) {
        ll h = v[i] / 9;
        ll w = v[i] % 9;
        t[h][w] = '#';
    }
    return t;
}

vector<vector<ll>> vv;

void dfs(vector<ll> v) {
    if (v.size() == 9) {
        vv.push_back(v);
        return;
    }

    REP(i, 9) {
        bool exist = false;
        REP(j, v.size()) {
            if (v[j] == i)
                exist = true;
        }
        if (exist)
            continue;
        v.push_back(i);
        dfs(v);
        v.pop_back();
    }
    return;
}

int main() {

    vector<ll> v;
    dfs(v);

    FOR(i, vv.size(), 200000) {
        vector<ll> t;
        if (i % 10000 == 0)
            cout << i << endl;
        REP(j, 9) {
            t.push_back(vv[i][j] + 9 * j);
        }
        REP(a, 81) {
            t.push_back(a);
            FOR(b, 81, a + 1) {
                t.push_back(b);
                vector<string> s = build(t);
                if (check(s, 7)) {
                    REP(j, 9) {
                        cout << s[j] << endl;
                    }
                    return 0;
                }
                t.pop_back();
            }
            t.pop_back();
        }
    }
    cout << "finish" << endl;
    return 0;
}