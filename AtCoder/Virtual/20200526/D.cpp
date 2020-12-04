#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[505][505];

struct Data {
    pll a, b;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    REP(i, H) {
        REP(j, W) {
            cin >> A[i][j];
        }
    }

    vector<Data> v;
    REP(i, H) {
        REP(j, W) {
            if (A[i][j] % 2 == 0)
                continue;
            pll nxt = pll(i + 1, j + 2);
            if (nxt.second > W)
                nxt = pll(i + 2, j + 1);
            if (nxt.first > H)
                break;
            Data d;
            d.a = pll(i + 1, j + 1);
            d.b = nxt;
            v.push_back(d);
            A[nxt.first - 1][nxt.second - 1]++;
        }
    }
    cout << v.size() << endl;
    REP(i, v.size()) {
        cout << v[i].a.first << " " << v[i].a.second << " " << v[i].b.first << " " << v[i].b.second << endl;
    }
    return 0;
}