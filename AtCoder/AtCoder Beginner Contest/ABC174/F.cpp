#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Query {
    ll L;
    ll R;
    ll index;
};

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

ll C[500005];
Query A[500005];
ll T[500005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;

    REP(i, N) {
        cin >> C[i];
        C[i]--;
    }
    REP(i, Q) {
        cin >> A[i].L >> A[i].R;
        A[i].index = i;
    }

    BinaryIndexTree bit(500005);
    sort(A, A + Q, [](Query a, Query b) { return a.R < b.R; });
    memset(T, -1, sizeof(T));

    vector<ll> ans(Q);
    ll index = 0;
    REP(i, Q) {
        while (index < A[i].R) {
            if (T[C[index]] > 0)
                bit.add(T[C[index]], -1);
            T[C[index]] = index + 1;
            index++;
            bit.add(index, 1);
        }
        ans[A[i].index] = bit.sum(A[i].R) - bit.sum(A[i].L - 1);
    }

    REP(i, Q) {
        cout << ans[i] << endl;
    }
    return 0;
}