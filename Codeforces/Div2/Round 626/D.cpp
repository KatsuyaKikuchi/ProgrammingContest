#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 25;

ll A[400005];
ll P[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;

    REP(i, N) {
        cin >> A[i];
    }

    REP(i, MAX) {
        ll mask = (1LL << (i + 1)) - 1;
        vector<ll> v(N);
        REP(j, N) {
            v[j] = (A[j] & mask);
        }
        sort(v.begin(), v.end());
        ll b0 = 1LL << i, t0 = (1LL << (i + 1)) - 1;
        ll b1 = (1LL << (i + 1)) + b0, t1 = (1LL << (i + 1)) + t0;
        pll p0(N - 1, N - 1), p1(N - 1, N - 1);
        REP(j, N) {
            {
                ll b = std::max(0LL, b0 - v[j]), t = t0 - v[j];
                while (p0.first >= j && v[p0.first] >= b)
                    p0.first--;
                while (p0.second >= j && v[p0.second] > t)
                    p0.second--;
                ll s = std::max(p0.second - std::max(p0.first + 1, j + 1) + 1, 0LL);
                P[i] += s;
            }
            {
                ll b = std::max(0LL, b1 - v[j]), t = t1 - v[j];
                while (p1.first >= j && v[p1.first] >= b)
                    p1.first--;
                while (p1.second >= j && v[p1.second] > t)
                    p1.second--;
                ll s = std::max(p1.second - std::max(p1.first + 1, j + 1) + 1, 0LL);
                P[i] += s;
            }
        }
    }

    ll ans = 0;
    REP(i, MAX) {
        ans |= ((P[i] % 2) << i);
    }
    cout << ans << endl;

    return 0;
}
