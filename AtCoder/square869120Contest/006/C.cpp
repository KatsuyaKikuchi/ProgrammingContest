#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[105];
bool U[105][105];
bool C[105][105];
ll x[2] = {0, 1};
ll y[2] = {1, 0};

int main() {
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    memset(C, 0, sizeof(C));
    REP(i, H) {
        if (S[i][0] == '#')
            continue;
        memset(U, 0, sizeof(U));
        queue<pll> q;
        q.push(pll(i, 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            if (t.second == W - 1)
                C[i][t.first] = true;
            REP(j, 2) {
                ll nx = t.first + x[j], ny = t.second + y[j];
                if (nx >= H || ny >= W)
                    continue;
                if (S[nx][ny] == '#')
                    continue;
                if (U[nx][ny])
                    continue;
                U[nx][ny] = true;
                q.push(pll(nx, ny));
            }
        }
    }

    {
        vector<ll> v;
        v.push_back(0);
        while (true) {
            bool update = false;
            vector<ll> vt;
            REP(i, v.size()) {
                ll t = v[i];
                FOR(j, H, t) {
                    if (S[j][0] == '#')
                        continue;
                    if (C[t][j])
                        vt.push_back(j);
                }
            }

            sort(vt.begin(), vt.end());
            vt.erase(unique(vt.begin(), vt.end()), vt.end());
            if (v.size() == vt.size()) {
                REP(i, v.size()) {
                    if (v[i] != vt[i]) {
                        update = true;
                        break;
                    }
                }
            }
            else {
                update = true;
            }
            if (!update)
                break;
            v.swap(vt);
        }

        REP(i, v.size()) {
            if (C[v[i]][H - 1]) {
                cout << "Yay!" << endl;
                return 0;
            }
        }
    }

    cout << ":(" << endl;
    return 0;
}