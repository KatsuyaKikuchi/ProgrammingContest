#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool solve() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    if (N % 2 == 1) {
        //! コインの取り出しは後攻から->移し終わった後にxor==0ならば先行、xor!=0ならば後攻の勝ち
        return false;
    }
    sort(A.begin(), A.end());
    for (ll i = 0; i < N; i += 2) {
        if (A[i] != A[i + 1])
            return true;
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        if (solve())
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
    return 0;
}