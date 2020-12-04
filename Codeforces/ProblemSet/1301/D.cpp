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
    ll n;
    string move;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, K;
    cin >> N >> M >> K;
    if (4 * N * M - 2 * N - 2 * M < K) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<Data> ans;
    REP(i, N - 1) {
        ll c = std::min(K / 3, M - 1);
        if (c > 0)
            ans.push_back(Data{c, "RDU"});
        K -= c * 3;
        ll d = std::min(K, c);
        if (d > 0)
            ans.push_back(Data{d, "L"});
        K -= d;
        if (K > 0) {
            ans.push_back(Data{1, "D"});
            K--;
        }
    }

    {
        ll c = std::min(K, M - 1);
        if (c > 0)
            ans.push_back(Data{c, "R"});
        K -= c;
        ll d = std::min(K, c);
        if (d > 0)
            ans.push_back(Data{d, "L"});
        K -= d;
        ll e = std::min(K, N - 1);
        if (e > 0)
            ans.push_back(Data{e, "U"});
    }

    cout << ans.size() << endl;
    REP(i, ans.size()) {
        cout << ans[i].n << " " << ans[i].move << endl;
    }
    return 0;
}