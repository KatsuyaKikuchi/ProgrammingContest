#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll X, Y, Z, K;
ll A[1005];
ll B[1005];
ll C[1005];

vector<ll> v;

int main() {
    cin >> X >> Y >> Z >> K;
    REP(i, X) {
        cin >> A[i];
    }
    REP(i, Y) {
        cin >> B[i];
    }
    REP(i, Z) {
        cin >> C[i];
    }
    sort(A, A + X, [](ll a, ll b) { return a > b; });
    sort(B, B + Y, [](ll a, ll b) { return a > b; });
    sort(C, C + Z, [](ll a, ll b) { return a > b; });

    vector<ll> vv;
    REP(i, X) {
        REP(j, Y) {
            vv.push_back(A[i] + B[j]);
        }
    }
    sort(vv.begin(), vv.end(), [](ll a, ll b) { return a > b; });
    REP(i, std::min(K, (ll) vv.size())) {
        REP(j, Z) {
            v.push_back(vv[i] + C[j]);
        }
    }
    sort(v.begin(), v.end(), [](ll a, ll b) { return a > b; });
    REP(i, K) {
        cout << v[i] << endl;
    }
    return 0;
}