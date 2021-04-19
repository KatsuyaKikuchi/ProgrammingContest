#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e18;

ll N, M, K;
vector<ll> A;
vector<ll> B;
vector<pll> D;

long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long gcd(long long a, long long b) {
    if (a < b)
        swap(a, b);
    long long c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

//! 方程式 ax = b (mod m) の解xを返す。
//! 見つからなかった場合 -1
long long mod_solver(long long a, long long b, long long m) {
    if (a < 0) {
        a = (m - (abs(a) % m)) % m;
    }
    if (b < 0) {
        b = (m - (abs(b) % m)) % m;
    }
    a %= m;
    b %= m;
    if (b == 0)
        return 0;
    if (a == 0)
        return -1;
    long long g0 = gcd(m, gcd(a, b));
    a /= g0;
    b /= g0;
    m /= g0;
    long long x, y;
    long long g1 = extGCD(a, m, x, y);
    if (g1 != 1) {
        return -1;
    }
    if (x < 0)
        x += m;
    return (x * b) % m;
}

vector<pll> C;

bool check(ll mid) {
    ll cnt = mid;
    REP(i, D.size()) {
        if (C[i].first < 0 || C[i].second <= 0) {
            continue;
        }
        //! mid日のうち、D[i].first == D[i].secondとなる日数を調べる
        ll s = C[i].first;
        ll d = C[i].second;
        if (s > mid)
            continue;

        ll x = (mid - s) / d;
        cnt -= x + 1;

    }
    return cnt >= K;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M >> K;
    A.resize(N);
    B.resize(M);
    D.resize(3LL * std::max(N, M) + 5);
    REP(i, D.size()) {
        D[i] = pll(0, 0);
    }
    REP(i, N) {
        cin >> A[i];
        D[A[i]].first = i + 1;
    }
    REP(i, M) {
        cin >> B[i];
        D[B[i]].second = i + 1;
    }

    C.resize(D.size());
    REP(i, D.size()) {
        if (D[i].first == 0 || D[i].second == 0) {
            C[i] = pll(-1, -1);
            continue;
        }
        ll a = M % N;
        ll b = (N + (D[i].first % N) - (D[i].second % N)) % N;
        ll x = mod_solver(a, b, N);
        if (x < 0) {
            C[i] = pll(-1, -1);
        }
        else {
            ll start = M * x + D[i].second; //! 初日
            ll g = N / gcd(N, M) * M;
            C[i].first = start;
            C[i].second = g;
        }
    }

#if false
    REP(i, C.size()) {
        cout << i << ": " << C[i].first << " " << C[i].second << endl;
    }
#endif

    ll ans = INF, ng = 0;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << ans << endl;

    return 0;
}