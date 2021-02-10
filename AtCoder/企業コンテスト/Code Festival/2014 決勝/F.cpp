#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> B(N);
    REP(i, N) {
        cin >> B[i];
    }
    vector<ll> A(N);
    REP(i, N) {
        ll a = B[i];
        ll b = B[(i - 1 + N) % N];
        A[i] = a * b / gcd(a, b);
    }
    vector<ll> B0(N);
    REP(i, N) {
        ll a = A[i];
        ll b = A[(i + 1) % N];
        B0[i] = gcd(a, b);
    }

    ll ans = INF;
    REP(s, 3) {
        vector<ll> tmp(B0);
        ll sum = 0;
        REP(j, N) {
            ll i = (s + j) % N;
            if (B[i] != tmp[i]) {
                sum++;
                ll n = (i + 1) % N;
                ll nn = (i + 2) % N;
                tmp[n] = B[n];
                tmp[nn] = B[nn];
            }
        }
        ans = std::min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}