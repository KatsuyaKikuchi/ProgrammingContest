#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll S[1005][1005];

template<typename T>
struct Imos2D {
    Imos2D(int h, int w)
            : mH(h), mW(w) {
    }

    void init(vector<vector<T>> v) {
        for (int i = 0; i < static_cast<int>(mMap.size()); ++i) {
            mMap[i].clear();
        }
        mMap.clear();
        mMap.resize(mH, vector<T>(mW, 0));

        for (int i = 0; i < mH; ++i) {
            for (int j = 0; j < mW; ++j) {
                mMap[i][j] += v[i][j];
                if (j > 0)
                    mMap[i][j] += mMap[i][j - 1];
            }
        }
        for (int j = 0; j < mW; ++j) {
            for (int i = 1; i < mH; ++i) {
                mMap[i][j] += mMap[i - 1][j];
            }
        }
    }

    //! 0-index
    T get(pair<int, int> l, pair<int, int> r) {
        T s = mMap[r.first][r.second];
        if (l.first > 0)
            s -= mMap[l.first - 1][r.second];
        if (l.second > 0)
            s -= mMap[r.first][l.second - 1];
        if (l.first > 0 && l.second > 0)
            s += mMap[l.first - 1][l.second - 1];
        return s;
    }

    int mH;
    int mW;
    vector<vector<T>> mMap;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M;
    cin >> M >> N;
    ll H, W;
    cin >> W >> H;
    vector<vector<ll>> v0(N), v1(N);
    REP(i, N) {
        REP(j, M) {
            cin >> S[i][j];
            v0[i].push_back(std::max(0LL, S[i][j]));
            v1[i].push_back(std::min(0LL, S[i][j]));
        }
    }

    Imos2D<ll> A(N, M), B(N, M);
    A.init(v0);
    B.init(v1);

    ll ans = INF;
    REP(i, N) {
        REP(j, M) {
            pll l(i, j), r(i + H - 1, j + W - 1);
            if (r.first >= N || r.second >= M)
                break;
            if (B.get(l, r) < 0)
                continue;
            ans = std::min(ans, A.get(l, r));
        }
    }
    cout << ans << endl;

    return 0;
}