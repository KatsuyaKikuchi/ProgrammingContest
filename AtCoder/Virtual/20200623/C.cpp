#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    pll nxt[4];
    pll pos;
};
ll x[4] = {0, 1, 0, -1};
ll y[4] = {1, 0, -1, 0};
char C[4] = {'U', 'R', 'D', 'L'};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;

    Data now;
    now.pos = pll(0, 0);
    REP(i, 4) {
        now.nxt[i] = pll(0, 0);
    }

    std::map<pll, Data> D;
    D[pll(0, 0)] = now;
    REP(i, N) {
        pll nxt(0, 0);
        ll p;
        REP(j, 4) {
            if (S[i] == C[j]) {
                nxt = now.nxt[j];
                p = j;
                break;
            }
        }
        Data newData;
        {
            auto &d = D[nxt];
            newData.pos = pll(d.pos.first + x[p], d.pos.second + y[p]);
        }
        REP(j, 4) {
            pll g = pll(newData.pos.first + x[j], newData.pos.second + y[j]);
            auto d = D.find(g);
            if (d == D.end()) {
                newData.nxt[j] = newData.pos;
            }
            else {
                newData.nxt[j] = d->second.nxt[j];
            }
        }
        REP(j, 4) {
            pll g = pll(newData.pos.first + x[j], newData.pos.second + y[j]);
            auto d = D.find(g);
            if (d == D.end())
                continue;
            D[d->second.nxt[j]].nxt[(j + 2) % 4] = newData.nxt[(j + 2) % 4];
        }
        D[newData.pos] = newData;
        now = newData;
        //cout << newData.pos.first << " " << newData.pos.second << endl;
    }

    cout << now.pos.first << " " << now.pos.second << endl;
    return 0;
}