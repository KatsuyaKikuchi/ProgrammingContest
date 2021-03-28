#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(vector<ll> &v) {
    ll ret = 0;
    for (ll i = 0; i < v.size(); i += 2) {
        if (v[i] + v[i + 1] == 10 && v[i] != 10)
            ret++;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    vector<ll> v;
    vector<ll> A = {10, 0, 9, 1, 8, 1, 7, 3, 6, 2, 5, 5, 4, 5, 2, 8, 2, 3, 1, 8};
    v.push_back(solve(A));
    vector<ll> B = {5, 5, 4, 4, 3, 7, 6, 4, 7, 3, 9, 1, 5, 2, 1, 1, 0, 0, 9, 0};
    v.push_back(solve(B));
    vector<ll> C = {0, 10, 1, 9, 10, 0, 10, 0, 2, 8, 0, 10, 1, 9, 9, 0, 1, 8, 2, 2};
    v.push_back(solve(C));

    REP(i, v.size()) {
        cout << v[i];
        if (i < v.size() - 1)
            cout << ",";
    }
    cout << endl;

    return 0;
}