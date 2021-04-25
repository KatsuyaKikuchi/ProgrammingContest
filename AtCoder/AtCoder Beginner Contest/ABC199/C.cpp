#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    string S;
    ll Q;
    cin >> N >> S >> Q;
    vector<ll> T(S.length());
    REP(i, S.length()) {
        T[i] = i;
    }
    bool flip = false;
    REP(_, Q) {
        ll t, a, b;
        cin >> t >> a >> b;
        a--;
        b--;
        if (t == 1) {
            if (flip) {
                a = (a + N) % (2 * N);
                b = (b + N) % (2 * N);
            }
            swap(T[a], T[b]);
        }
        else {
            flip = !flip;
        }
    }

    REP(i, N) {
        if (flip) {
            swap(T[i], T[i + N]);
        }
    }
    REP(i, S.length()) {
        cout << S[T[i]];
    }
    cout << endl;
    return 0;
}