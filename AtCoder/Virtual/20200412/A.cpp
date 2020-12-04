#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool U[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    ll a = 0, b = 0;
    REP(i, N) {
        if (S[i] == 'a' && a + b < A + B) {
            U[i] = true;
            a++;
        }
        else if (S[i] == 'b' && a + b < A + B && b < B) {
            U[i] = true;
            b++;
        }
    }

    REP(i, N) {
        if (U[i])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}