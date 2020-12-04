#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    memset(A, 0, sizeof(A));
    {
        ll s = 0;
        REP(i, S.length()) {
            if (S[i] == 'R') {
                s++;
                continue;
            }
            A[i - 1] += (s + 1) / 2;
            A[i] += s / 2;
            s = 0;
        }
    }
    {
        ll s = 0;
        for (ll i = S.length() - 1; i >= 0; --i) {
            if (S[i] == 'L') {
                s++;
                continue;
            }
            A[i] += s / 2;
            A[i + 1] += (s + 1) / 2;
            s = 0;
        }
    }

    REP(i, S.length()) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}