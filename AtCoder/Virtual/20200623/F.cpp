#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    vector<ll> node;
};

ll N, M;
Vertex V[705];

//! 頂点を n : N-nに分けられるか？
bool check(ll n) {

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    for (ll i = N / 2; i >= 0; --i) {
        if (check(i)) {
            cout << i * (i - 1) / 2 + (N - i) * (N - i - 1) / 2 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}