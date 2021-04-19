#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

bool check(pll a, pll b) {
    return a.first != b.first && a.second != b.first && a.second != b.first && a.second != b.second;
}


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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
#if true
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<pll> V(5000005, pll(-1, -1));
    REP(i, N) {
        cin >> A[i];
    }
#else
    TestCase tst;
    ll N = 200000;
    vector<ll> A(N);
    vector<pll> V(5000005, pll(-1, -1));
    REP(i, N) {
        A[i] = tst.get(1, 2000000);
    }
#endif

    REP(i, N) {
        FOR(j, N, i + 1) {
            ll s = A[i] + A[j];
            pll &t = V[s];
            pll x = pll(i + 1, j + 1);
            if (t.first >= 0 && check(t, x)) {
                cout << "YES" << endl;
                cout << t.first << " " << t.second << " " << x.first << " " << x.second << endl;
                return 0;
            }
            V[s] = x;
        }
    }
    cout << "NO" << endl;
    return 0;
}