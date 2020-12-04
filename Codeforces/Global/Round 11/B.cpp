#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    ll ret = 0;
    vector<ll> B;
    pll x(0, 0);
    ll p = 0;
    REP(i, N) {
        if (S[i] == 'W') {
            if (p > 0) {
                if (p == i)
                    x.first = p;
                else
                    B.push_back(p);
            }
            p = 0;
            if (i == 0 || S[i - 1] == 'L')
                ret++;
            else
                ret += 2;
            continue;
        }
        p++;
    }
    if (p > 0)
        x.second = p;

    if (x.second == N) {
        return std::max(2 * K - 1, 0LL);
    }
    sort(B.begin(), B.end());
    REP(i, B.size()) {
        if (K >= B[i]) {
            K -= B[i];
            ret += 2 * B[i] + 1;
            continue;
        }
        ret += 2 * K;
        K = 0;
    }

    ret += std::min(K, (x.first + x.second)) * 2;

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