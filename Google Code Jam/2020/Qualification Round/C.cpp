#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll from;
    ll to;
    ll index;
};
Data A[1005];
char C[1005];

string solve(ll N) {
    sort(A, A + N, [](Data a, Data b) { return a.from < b.from; });

    ll c = 0, j = 0;
    REP(i, N) {
        ll from = A[i].from;
        ll to = A[i].to;
        if (c <= from) {
            c = to;
            C[A[i].index] = 'C';
            continue;
        }
        if (j <= from) {
            j = to;
            C[A[i].index] = 'J';
            continue;
        }
        return "IMPOSSIBLE";
    }
    string T = "";
    REP(i, N) {
        T.push_back(C[i]);
    }
    return T;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(q, Q) {
        ll N;
        cin >> N;
        REP(i, N) {
            cin >> A[i].from >> A[i].to;
            A[i].index = i;
        }
        cout << "Case #" << q + 1 << ": ";
        cout << solve(N) << endl;
    }
    return 0;
}