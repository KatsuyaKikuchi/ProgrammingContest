#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void solve(vector<ll> &A) {
    ll N = A.size();


    vector<ll> v(N);
    REP(i, N) {
        v[i] = i % 2 + 1;
    }
    if (N % 2 == 1) {
        REP(i, N - 1) {
            if (A[i] != A[i + 1])
                continue;

            FOR(j, N, i + 1) {
                v[j] = 2 - (j % 2);
            }
        }
        if (A[0] != A[N - 1] && v[0] == v[N - 1])
            v[N - 1] = 3;
    }

    bool same = true;
    REP(i, N - 1) {
        if (A[i] != A[i + 1])
            same = false;
    }
    if (same) {
        REP(i, N) {
            v[i] = 1;
        }
    }

    ll m = 0;
    REP(i, N) {
        m = std::max(m, v[i]);
    }
    cout << m << endl;
    REP(i, N) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        ll N;
        cin >> N;
        vector<ll> A(N);
        REP(i, N) {
            cin >> A[i];
        }

        solve(A);
    }
    return 0;
}