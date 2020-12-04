#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];

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
    vector<ll> node;
    ll mN;
    ll mPow;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<ll> v;
    ll s = 0;
    REP(i, N) {
        cin >> A[i];
        s += A[i];
        v.push_back(s - (i + 1) * K);
    }
    v.push_back(0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    BinaryIndexTree bit(v.size() + 5);
    ll ans = 0;
    bit.add((lower_bound(v.begin(), v.end(), 0) - v.begin()) + 1, 1);
    s = 0;
    REP(i, N) {
        s += A[i];
        ll n = s - K * (i + 1);
        ll index = lower_bound(v.begin(), v.end(), n) - v.begin();

        ans += bit.sum(index + 1);
        bit.add(index + 1, 1);
    }
    cout << ans << endl;
    return 0;
}