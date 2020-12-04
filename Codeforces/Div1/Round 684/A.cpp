#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Query {
    pll q[3];
};

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<string> v(N);
    REP(i, N) {
        cin >> v[i];
    }

    vector<Query> ans;
    for (ll i = 0; i < N - 1; i += 2) {
        REP(j, M - 2) {
            ll a = v[i][j] - '0';
            ll b = v[i][j + 1] - '0';
            ll c = v[i + 1][j] - '0';
            ll d = v[i + 1][j + 1] - '0';
            ll s = a + c;
            if (s == 0)
                continue;
            Query q;
            ll count = 0;
            if (a == 1) {
                q.q[count++] = pll(i, j);
                v[i][j] = '0';
            }
            if (c == 1) {
                q.q[count++] = pll(i + 1, j);
                v[i + 1][j] = '0';
            }

            if (count == 2) {
                if (b == 1) {
                    q.q[count++] = pll(i, j + 1);
                    v[i][j + 1] = '0';
                }
                else {
                    q.q[count++] = pll(i + 1, j + 1);
                    v[i + 1][j + 1] = ((d + 1) % 2) + '0';
                }
            }
            else if (count == 1) {
                q.q[count++] = pll(i, j + 1);
                v[i][j + 1] = ((b + 1) % 2) + '0';
                q.q[count++] = pll(i + 1, j + 1);
                v[i + 1][j + 1] = ((d + 1) % 2) + '0';
            }

            if (count == 3)
                ans.push_back(q);
        }
    }
    {
        ll j = M - 2;
        REP(i, N - 2) {
            ll a = v[i][j] - '0';
            ll b = v[i][j + 1] - '0';
            ll c = v[i + 1][j] - '0';
            ll d = v[i + 1][j + 1] - '0';
            ll s = a + b;
            if (s == 0)
                continue;
            Query q;
            ll count = 0;
            if (a == 1) {
                q.q[count++] = pll(i, j);
                v[i][j] = '0';
            }
            if (b == 1) {
                q.q[count++] = pll(i, j + 1);
                v[i][j + 1] = '0';
            }

            if (count == 2) {
                if (c == 1) {
                    q.q[count++] = pll(i + 1, j);
                    v[i + 1][j] = '0';
                }
                else {
                    q.q[count++] = pll(i + 1, j + 1);
                    v[i + 1][j + 1] = ((d + 1) % 2) + '0';
                }
            }
            else if (count == 1) {
                q.q[count++] = pll(i + 1, j);
                v[i + 1][j] = ((c + 1) % 2) + '0';
                q.q[count++] = pll(i + 1, j + 1);
                v[i + 1][j + 1] = ((d + 1) % 2) + '0';
            }

            if (count == 3)
                ans.push_back(q);
        }
    }
    {
        ll i = N - 2;
        REP(j, M - 2) {
            ll a = v[i][j] - '0';
            ll b = v[i][j + 1] - '0';
            ll c = v[i + 1][j] - '0';
            ll d = v[i + 1][j + 1] - '0';
            ll s = a + c;
            if (s == 0)
                continue;
            Query q;
            ll count = 0;
            if (a == 1) {
                q.q[count++] = pll(i, j);
                v[i][j] = '0';
            }
            if (c == 1) {
                q.q[count++] = pll(i + 1, j);
                v[i + 1][j] = '0';
            }

            if (count == 2) {
                if (b == 1) {
                    q.q[count++] = pll(i, j + 1);
                    v[i][j + 1] = '0';
                }
                else {
                    q.q[count++] = pll(i + 1, j + 1);
                    v[i + 1][j + 1] = ((d + 1) % 2) + '0';
                }
            }
            else if (count == 1) {
                q.q[count++] = pll(i, j + 1);
                v[i][j + 1] = ((b + 1) % 2) + '0';
                q.q[count++] = pll(i + 1, j + 1);
                v[i + 1][j + 1] = ((d + 1) % 2) + '0';
            }

            if (count == 3)
                ans.push_back(q);
        }
    }
    while (true) {
        ll i = N - 2;
        ll j = M - 2;
        ll a = v[i][j] - '0';
        ll b = v[i][j + 1] - '0';
        ll c = v[i + 1][j] - '0';
        ll d = v[i + 1][j + 1] - '0';
        ll s = a + b + c + d;
        if (s == 0)
            break;
        Query q;
        if (s == 4) {
            q.q[0] = pll(i, j);
            q.q[1] = pll(i, j + 1);
            q.q[2] = pll(i + 1, j);
            v[i][j] = '0';
            v[i][j + 1] = '0';
            v[i + 1][j] = '0';
        }
        else if (s == 3) {
            ll count = 0;
            if (a == 1) {
                q.q[count++] = pll(i, j);
                v[i][j] = '0';
            }
            if (b == 1) {
                q.q[count++] = pll(i, j + 1);
                v[i][j + 1] = '0';
            }
            if (c == 1) {
                q.q[count++] = pll(i + 1, j);
                v[i + 1][j] = '0';
            }
            if (d == 1) {
                q.q[count++] = pll(i + 1, j + 1);
                v[i + 1][j + 1] = '0';
            }
        }
        else if (s == 2) {
            ll count = 0;
            if (a == 0) {
                q.q[count++] = pll(i, j);
                v[i][j] = '1';
            }
            if (b == 0) {
                q.q[count++] = pll(i, j + 1);
                v[i][j + 1] = '1';
            }
            if (c == 0) {
                q.q[count++] = pll(i + 1, j);
                v[i + 1][j] = '1';
            }
            if (d == 0) {
                q.q[count++] = pll(i + 1, j + 1);
                v[i + 1][j + 1] = '1';
            }

            while (true) {
                if (a == 1) {
                    q.q[count++] = pll(i, j);
                    v[i][j] = '0';
                    break;
                }
                if (b == 1) {
                    q.q[count++] = pll(i, j + 1);
                    v[i][j + 1] = '0';
                    break;
                }
                if (c == 1) {
                    q.q[count++] = pll(i + 1, j);
                    v[i + 1][j] = '0';
                    break;
                }
                if (d == 1) {
                    q.q[count++] = pll(i + 1, j + 1);
                    v[i + 1][j + 1] = '0';
                    break;
                }
            }
        }
        else if (s == 1) {
            ll count = 0;
            if (a == 0 && count < 2) {
                q.q[count++] = pll(i, j);
                v[i][j] = '1';
            }
            if (b == 0 && count < 2) {
                q.q[count++] = pll(i, j + 1);
                v[i][j + 1] = '1';
            }
            if (c == 0 && count < 2) {
                q.q[count++] = pll(i + 1, j);
                v[i + 1][j] = '1';
            }
            if (d == 0 && count < 2) {
                q.q[count++] = pll(i + 1, j + 1);
                v[i + 1][j + 1] = '1';
            }

            while (true) {
                if (a == 1) {
                    q.q[count++] = pll(i, j);
                    v[i][j] = '0';
                    break;
                }
                if (b == 1) {
                    q.q[count++] = pll(i, j + 1);
                    v[i][j + 1] = '0';
                    break;
                }
                if (c == 1) {
                    q.q[count++] = pll(i + 1, j);
                    v[i + 1][j] = '0';
                    break;
                }
                if (d == 1) {
                    q.q[count++] = pll(i + 1, j + 1);
                    v[i + 1][j + 1] = '0';
                    break;
                }
            }
        }
        ans.push_back(q);
    }

#if false
    REP(i, N) {
        cout << v[i] << endl;
    }
#endif
    cout << ans.size() << endl;
    REP(i, ans.size()) {
        REP(j, 3) {
            cout << ans[i].q[j].first + 1 << " " << ans[i].q[j].second + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }
    return 0;
}