#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[30];
char C[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S, T;
    cin >> S >> T;
    ll N = S.length();

    REP(i, 30) {
        C[i] = (char) ('a' + i);
    }

    memset(U, 0, sizeof(U));
    bool e = true;
    REP(i, N) {
        S[i] = C[S[i] - 'a'];
        if (T[i] != S[i]) {
            if (U[S[i] - 'a'] || U[T[i] - 'a']) {
                e = false;
                break;
            }
            swap(C[S[i] - 'a'], C[T[i] - 'a']);
            S[i] = T[i];
        }
        U[S[i] - 'a'] = true;
    }
    cout << S << endl;
    cout << T << endl;
    REP(i, 30) {
        cout << C[i] << " ";
    }
    cout << endl;

    if (e)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}