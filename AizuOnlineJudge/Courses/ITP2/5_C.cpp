#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    {
        ll B[15];
        REP(i, N) {
            B[i] = A[i];
        }
        for (ll i = N - 2; i >= 0; --i) {
            if (A[i] < A[i + 1])
                continue;
            ll m = -1;
            FOR(j, N, i + 1) {
                if (A[i] > A[j]) {
                    if (m == -1 || A[m] < A[j])
                        m = j;
                }
            }
            swap(B[m], B[i]);
            FOR(j, N, i + 1) {
                ll t = j;
                FOR(k, N, j) {
                    if (B[t] < B[k])
                        t = k;
                }
                swap(B[t], B[j]);
            }
            REP(j, N) {
                cout << B[j];
                if (j < N - 1)
                    cout << " ";
            }
            cout << endl;
            break;
        }
    }
    REP(i, N) {
        cout << A[i];
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;
    {
        ll B[15];
        REP(i, N) {
            B[i] = A[i];
        }
        for (ll i = N - 1; i >= 0; --i) {
            ll m = -1;
            FOR(j, N, i + 1) {
                if (A[i] < A[j])
                    if (m == -1 || A[m] > A[j])
                        m = j;
            }
            if (m < 0)
                continue;
            swap(B[i], B[m]);
            FOR(j, N, i + 1) {
                ll m = j;
                FOR(k, N, j) {
                    if (B[m] > B[k])
                        m = k;
                }
                swap(B[m], B[j]);
            }

            REP(j, N) {
                cout << B[j];
                if (j < N - 1)
                    cout << " ";
            }
            cout << endl;
            break;
        }
    }
    return 0;
}