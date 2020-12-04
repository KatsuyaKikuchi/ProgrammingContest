#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char C[3] = {'R', 'P', 'S'};

string solve() {
    string S;
    cin >> S;
    ll N = S.length();
    vector<ll> A(3, 0);
    REP(i, N) {
        REP(j, 3) {
            if (S[i] == C[j]) {
                A[j]++;
                break;
            }
        }
    }
    ll mx = 0;
    REP(j, 3) {
        if (A[j] > A[mx])
            mx = j;
    }
    string ret = "";
    REP(i, N) {
        ret.push_back(C[(mx + 1) % 3]);
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