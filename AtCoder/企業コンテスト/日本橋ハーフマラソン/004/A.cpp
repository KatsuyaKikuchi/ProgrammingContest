#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll HEIGHT = 1001;
const ll THRESHHOLD = 4;
pll A[1005];
ll B[10];
ll H[10];
pll G[HEIGHT][10];
ll N, W, K, V;

ll majority() {
    ll m = -1;
    ll ms = 0;
    REP(c, K) {
        ll s = 0;
        REP(i, W) {
            if (G[B[i]][i].first == c) {
                s += G[B[i]][i].second;
            }
        }
        if (s > ms) {
            ms = s;
            m = c;
        }
    }
    return m;
}

ll space() {
    REP(i, W) {
        if (G[B[i]][i].first == -1) {
            return i;
        }
    }
    return 0;
}

ll simulate(pll mm, ll w) {
    G[H[w]][w] = mm;
    H[w] = (H[w] + 1) % HEIGHT;
    ll max = 0;
    REP(c, K) {
        ll m = 0;
        REP(i, W) {
            if (G[B[i]][i].second < 0) {
                m = 0;
                break;
            }
            if (G[B[i]][i].first == c) {
                m += G[B[i]][i].second;
            }
        }
        max = std::max(m, max);
    }
    if (max > 0) {
        REP(i, W) {
            G[B[i]][i] = pll(-1, -1);
            B[i] = (B[i] + 1) % HEIGHT;
        }
    }
    return max;
}

int main() {
    cin >> N >> W >> K >> V;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    std::random_device rnd;
    std::mt19937 mt(rnd());
    std::uniform_int_distribution<> rand(0, 7);

    ll max = 0;
    vector<ll> ans(N, 0);
    FOR(th, V, 6) {
        REP(_, 3000) {
            memset(G, -1, sizeof(G));
            REP(i, W) {
                B[i] = H[i] = 0;
            }
            vector<ll> v(N);
            ll sum = 0;
            REP(i, N) {
                ll w = rand(mt);
                if (A[i].second > th) {
                    w = 0;
                }
                if (A[i].first == majority()) {
                    w = space();
                }
                sum += simulate(A[i], w);
                v[i] = w;
            }
            if (sum > max) {
                max = sum;
                ans.swap(v);
            }
        }
    }

    REP(i, N) {
        cout << ans[i] << endl;
    }
    return 0;
}