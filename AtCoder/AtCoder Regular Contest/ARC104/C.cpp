#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[105];
ll T[205];
bool dp[205][105];

bool solve(ll N) {
    //! 明らかに間違っているものはのぞいておく
    memset(T, -1, sizeof(T));
    REP(i, N) {
        if (A[i].first >= 0) {
            if (T[A[i].first] >= 0)
                return false;
            T[A[i].first] = i;
        }
        if (A[i].second >= 0) {
            if (T[A[i].second] >= 0)
                return false;
            T[A[i].second] = i;
        }
        if (A[i].first >= 0 && A[i].second >= 0) {
            if (A[i].first >= A[i].second)
                return false;
        }
    }
    ll d = 0;
    REP(i, N) {
        if (A[i].first < 0 && A[i].second < 0)
            d++;
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = true;
    for (ll i = 2; i <= 2 * N; i += 2) {
        REP(dd, d + 1) {
            for (ll n = 1; n <= N; n++) {
                ll t = i - 2 * n;
                if (t < 0 || !dp[t][dd])
                    continue;

                bool exist = true;
                ll count = 0;
                REP(xx, n) {
                    ll p = t + 1 + xx;
                    ll q = t + 1 + n + xx;
                    bool e = false;
                    ll num = 0;
                    ll m = 0;
                    REP(j, N) {
                        bool f = A[j].first < 0 || A[j].first == p;
                        bool l = A[j].second < 0 || A[j].second == q;
                        if (A[j].first < 0 && T[p] >= 0)
                            continue;
                        if (A[j].second < 0 && T[q] >= 0)
                            continue;
                        if (f && l) {
                            e = true;
                            if (A[j].first < 0 && A[j].second < 0) {
                                m++;
                            }
                            num++;
                        }
                    }

                    if ((num - m) > 1) {
                        exist = false;
                    }
                    else if (m == 0) {
                        exist &= e;
                    }
                    else {
                        if ((num - m) == 0) {
                            count++;
                        }
                        exist &= e;
                    }

                    if (!exist)
                        break;
                }

                if (dd + count > d)
                    continue;
                if (exist) {
                    dp[i][dd + count] = true;
                }
            }
        }
    }

    if (dp[2 * N][d] == true)
        return true;
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }

    if (solve(N))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}