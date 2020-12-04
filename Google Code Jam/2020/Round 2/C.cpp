#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = 2LL * ((ll) 1e9) + 10000LL;

//! a->b
pll getVec(pll a, pll b) {
    return pll(b.first - a.first, b.second - a.second);
}

ll next(vector<pll> &p, ll index) {
    REP(i, p.size()) {
        if (p[i].first == index)
            return p[i].second;
        if (p[i].second == index)
            return p[i].first;
    }
    return -1;
}

ll len(pll vec) {
    return vec.first * vec.first + vec.second * vec.second;
}

bool check(pll v0, pll v1) {
    if (v0.first * v1.second != v0.second * v1.first)
        return false;

    return v0.first * v1.first >= 0 && v0.second * v1.second >= 0;
}

ll MAX = 100;

vector<bool> simulation(vector<pll> &p, ll start, pll vec, vector<pll> &A) {
    ll index = start;
    ll N = A.size();
    vector<bool> ret(N, false);
    ll cnt = 0;
    while (cnt < MAX) {
        ret[index] = true;
        pll nxVec(INF, INF);
        ll nxt = -1;
        REP(i, N) {
            if (i == index)
                continue;
            pll v = getVec(A[index], A[i]);
            if (!check(vec, v))
                continue;
            if (len(nxVec) > len(v)) {
                nxVec = v;
                nxt = i;
            }
        }

        if (nxt < 0)
            break;
        ret[nxt] = true;
        ll warp = next(p, nxt);
        if (warp == nxt || warp < 0)
            break;
        index = warp;
        cnt++;
    }
    return ret;
}

void solve() {
    ll N;
    cin >> N;
    vector<pll> A(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    if (N <= 3) {
        cout << N << endl;
        return;
    }

    REP(i, N) {
        REP(j, N) {
            if (i == j)
                continue;
            pll vec = getVec(A[i], A[j]);
            REP(s, N) {
                REP(w, N) {
                    if (s == w)
                        continue;
                }
            }
        }
    }

#if false
    vector<ll> v;
    REP(i, N) {
        v.push_back(i);
    }

    ll ans = 2;
    do {
        vector<pll> p;
        for (ll i = 0; i < N; i += 2) {
            if (i + 1 >= N)
                break;
            p.push_back(pll(v[i], v[i + 1]));
        }
        ll sum = 1;
        REP(i, N) {
            ll nxt = next(p, i);
            if (nxt < 0)
                break;
            REP(j, N) {
                if (j == nxt)
                    continue;
                pll vec = getVec(A[nxt], A[j]);
#if false
                bool e = false;
                REP(k, N) {
                    if (k == nxt || j == k)
                        continue;
                    pll vec2 = getVec(A[nxt], A[k]);
                    if (!check(vec2, vec))
                        continue;
                    if (len(vec2) < len(vec)) {
                        e = true;
                        break;
                    }
                }
                if (e)
                    continue;
#endif
                auto u = simulation(p, nxt, vec, A);
                u[i] = true;
                u[nxt] = true;
                ll s = 0;
                REP(i, N) {
                    if (u[i])
                        s++;
                }
                sum = std::max(s, sum);
            }
        }
        ans = std::max(ans, sum);
    } while (next_permutation(v.begin(), v.end()));

    cout << ans << endl;
#endif
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(i, T) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}