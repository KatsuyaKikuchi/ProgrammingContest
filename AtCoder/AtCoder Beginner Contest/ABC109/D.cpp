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
    pll a;
    pll b;
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

            ll ny = j + 1, nx = i;
            if (ny >= W) {
                ny = j;
                nx = i + 1;
            }
            if (nx >= H)
                break;

            A[i][j]--;
            A[nx][ny]++;
            v.push_back(Data{pll(i + 1, j + 1), pll(nx + 1, ny + 1)});
        }
    }

    cout << v.size() << endl;
    REP(i, v.size()) {
        cout << v[i].a.first << " " << v[i].a.second << " " << v[i].b.first << " " << v[i].b.second << endl;
    }

    return 0;
}