#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
ll S = 100000005;

ll N, M;
ll W[10];
ll L[100000005];

//! w以上の耐荷重を持つ最小のLを取得
ll get(ll w) {
    ll ok = S + 1, ng = -1;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (L[mid] >= w)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}

ll T[10][10];

ll calc(const vector<ll> &v) {
    REP(i, N + 1) {
        REP(j, N + 1) {
            T[i][j] = INF;
        }
        T[i][i] = 0;
    }
    FOR(l, N, 1) {
        REP(i, N) {
            if (i + l >= N)
                break;

            ll w = 0;
            REP(j, l + 1) {
                ll index = v[i + j];
                w += W[index];
            }

            ll len = get(w);
            T[i][i + l - 1] = len - 1;
            REP(j, l - 1) {
                T[i][i + l - 1] = std::max(T[i][i + l - 1], T[i][i + j] + T[i + j + 1][i + l - 1]);
            }
        }
    }

#if false
    REP(i, N) {
        FOR(j, N, i) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
#endif

    return T[0][N - 2];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    REP(i, N) {
        cin >> W[i];
    }
    ll mn = INF;
    REP(i, S) {
        L[i] = INF;
    }
    ll mx = 0;
    REP(i, M) {
        ll l, v;
        cin >> l >> v;
        mn = std::min(mn, v);
        L[l] = std::min(L[l], v);
        mx = std::max(l, mx);
    }
    S = mx;

    REP(i, N) {
        if (W[i] > mn) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (ll i = mx; i >= 0; --i) {
        L[i] = std::min(L[i], L[i + 1]);
    }

    vector<ll> v;
    REP(i, N) {
        v.push_back(i);
    }

    ll ans = INF;
    do {
        ans = std::min(calc(v), ans);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
    return 0;
}