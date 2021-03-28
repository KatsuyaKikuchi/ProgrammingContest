#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;


struct TestCase {
    TestCase() {
        std::random_device rnd;
        mMt = std::mt19937(rnd());
    }

    int get(int low, int height) {
        if (low > height)
            swap(low, height);
        int d = height - low;
        if (d == 0)
            return low;
        std::uniform_int_distribution<> rand(0, d);
        return low + rand(mMt);
    }

    std::mt19937 mMt;
};

ll solve() {
    ll N = 100;
    ll M = 10000;
    vector<string> S(N);
    vector<ll> C(N, 0);
    vector<ll> T(M, 0);
    REP(i, N) {
        cin >> S[i];
        REP(j, M) {
            C[i] += S[i][j] - '0';
        }
    }

    REP(i, M) {
        REP(j, N) {
            T[i] += S[j][i] - '0';
        }
    }
    vector<pll> v;
    REP(i, N) {
        if (C[i] < M / 2) {
            continue;
        }
        ll s = 0;
        REP(j, M) {
            if (S[i][j] == '1')
                s += T[j];
        }
        v.push_back(pll(s, i));
    }
    sort(v.begin(), v.end());
    if (v.size() == 0)
        return 0;
    return v[0].second + 1;
#if false
    vector<ll> v;
    REP(i, N) {
        if (enable[i])
            v.push_back(i);
    }


    TestCase tst;
    if (v.size() == 0) {
        v.push_back(tst.get(0, N - 1));
    }
    ll idx = tst.get(0, v.size() - 1);
    return v[idx] + 1;
#endif
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q, P;
    cin >> Q >> P;
    REP(i, Q) {
        cout << "Case #" << i + 1 << ": " << solve() << endl;
    }
    return 0;
}