#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1000004;

struct BinaryIndexTree {
public:
    BinaryIndexTree(int n)
            : mN(n) {
        mPow = 1;
        while (mPow < n)
            mPow <<= 1;
        node.resize(n + 1);
        REP(i, n + 1) {
            node[i] = 0;
        }
    }

    ~BinaryIndexTree() {
        node.resize(0);
    }

    //! 1-index get
    ll sum(int index) {
        ll sum = 0;
        for (int i = index; i > 0; i -= i & (-i))
            sum += node[i];
        return sum;
    }

    //! 1-index add
    void add(int index, ll value) {
        for (int i = index; i <= mN; i += i & (-i))
            node[i] += value;
    }

    int lowerBound(ll value) {
        if (value <= 0)
            return 0;
        int x = 0;
        for (int k = mPow; k > 0; k >>= 1) {
            if (x + k <= mN && node[x + k] < value) {
                value -= node[x + k];
                x += k;
            }
        }
        return x + 1;
    }

private:
    vector<int> node;
    int mN;
    int mPow;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, Q;
    cin >> N >> Q;
    BinaryIndexTree bit(1000005);
    bit.add(INF, 1);
    REP(i, N) {
        ll a;
        cin >> a;
        bit.add(a, 1);
    }

    REP(_, Q) {

        ll k;
        cin >> k;
        if (k > 0) {
            bit.add(k, 1);
            continue;
        }

        ll index = bit.lowerBound(abs(k));
        bit.add(index, -1);
    }

    ll ans = bit.lowerBound(1);
    if (ans == INF)
        ans = 0;
    cout << ans << endl;
    return 0;
}