#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll check(ll a, ll b, ll c) {
    if (a < b && b > c)
        return 1;
    if (a > b && b < c)
        return -1;
    return 0;
}

ll solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    if (N <= 2) {
        return 0;
    }
    ll a = 0, b = 0;
    FOR(i, N - 1, 1) {
        if (check(A[i - 1], A[i], A[i + 1]) > 0) {
            a++;
        }
        else if (check(A[i - 1], A[i], A[i + 1]) < 0) {
            b++;
        }
    }
    ll ret = a + b;
    REP(i, N) {
        if (i == 0) {
            if (check(A[0], A[1], A[2]) != 0)
                ret = std::min(ret, a + b - 1);
        }
        else if (i == N - 1) {
            if (check(A[i - 2], A[i - 1], A[i]) != 0)
                ret = std::min(ret, a + b - 1);
        }
        else {
            ll m = 0;
            if (check(A[i - 1], A[i], A[i + 1]) != 0)
                m++;
            if (i > 1 && check(A[i - 2], A[i - 1], A[i]) != 0)
                m++;
            if (i + 2 <= N - 1 && check(A[i], A[i + 1], A[i + 2]) != 0)
                m++;

            ll t = A[i];
            {
                A[i] = A[i - 1];
                ll x = 0;
                if (check(A[i - 1], A[i], A[i + 1]) != 0)
                    x++;
                if (i > 1 && check(A[i - 2], A[i - 1], A[i]) != 0)
                    x++;
                if (i + 2 <= N - 1 && check(A[i], A[i + 1], A[i + 2]) != 0)
                    x++;
                ret = std::min(ret, a + b - m + x);
            }
            {
                A[i] = A[i + 1];
                ll x = 0;
                if (check(A[i - 1], A[i], A[i + 1]) != 0)
                    x++;
                if (i > 1 && check(A[i - 2], A[i - 1], A[i]) != 0)
                    x++;
                if (i + 2 <= N - 1 && check(A[i], A[i + 1], A[i + 2]) != 0)
                    x++;
                ret = std::min(ret, a + b - m + x);
            }
            A[i] = t;
        }
    }

    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}