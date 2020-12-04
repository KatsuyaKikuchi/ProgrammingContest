#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

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

struct Data {
    ll l;
    ll r;
    vector<ll> v;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    vector<Data> D(3);
    if (N > 1) {
        D[0].l = 0;
        D[0].r = N - 2;
        REP(i, N - 1) {
            ll x, y;
            extGCD(N, N - 1, x, y);
            D[0].v.push_back(-y * (N - 1) * A[i]);
            A[i] -= y * (N - 1) * A[i];
        }
    }
    else {
        D[0].l = 0;
        D[0].r = 0;
        D[0].v.push_back(0);
    }
#if false
    cout << "------ " << endl;
    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
#endif
    D[1].l = 0;
    D[1].r = N - 1;
    REP(i, N) {
        if (abs(A[i]) % N == 0) {
            D[1].v.push_back(-A[i]);
            A[i] = 0;
        }
        else {
            D[1].v.push_back(0);
        }
    }

    D[2].l = N - 1;
    D[2].r = N - 1;
    D[2].v.push_back(-A[N - 1]);
    A[N - 1] -= A[N - 1];

#if false
    cout << "------ " << endl;
    REP(i, N) {
        cout << A[i] << " ";
    }
    cout << endl;
#endif
    REP(i, D.size()) {
        cout << D[i].l + 1 << " " << D[i].r + 1 << endl;
        REP(j, D[i].v.size()) {
            cout << D[i].v[j] << " ";
        }
        cout << endl;
    }

    return 0;
}