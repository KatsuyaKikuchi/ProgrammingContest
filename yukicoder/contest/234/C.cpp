#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string S[2005];
ll M[2005][2005];
ll T[2005][2005];
ll x[2] = {0, 1};
ll y[2] = {1, 0};

struct Data {
    pll g;
    ll c;
};

int main() {
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        cin >> S[i];
    }
    REP(i, H) {
        REP(j, W) {
            M[i][j] = INF;
            T[i][j] = INF;
        }
    }
    {
        T[0][0] = 0;
        queue<Data> q;
        q.push(Data{pll(0, 0), 0});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            REP(i, 2) {
                ll nx = x[i] + t.g.first, ny = y[i] + t.g.second;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                ll cost = t.c + 1;
                if (T[nx][ny] <= cost)
                    continue;
                T[nx][ny] = cost;
                q.push(Data{pll(nx, ny), cost});
            }
        }
    }
    {
        M[0][0] = 0;
        priority_queue<Data, vector<Data>, function<bool(Data, Data)>> q([](Data a, Data b) { return a.c > b.c; });
        q.push(Data{pll(0, 0), 0});
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            REP(i, 2) {
                ll nx = x[i] + t.g.first, ny = y[i] + t.g.second;
                if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                    continue;
                ll cost = t.c + 1;
                if (S[nx][ny] == 'k')
                    cost += T[nx][ny];
                if (M[nx][ny] <= cost)
                    continue;
                M[nx][ny] = cost;
                q.push(Data{pll(nx, ny), cost});
            }
        }
    }
    cout << M[H - 1][W - 1] << endl;
    return 0;
}