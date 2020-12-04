#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct BinaryIndexTree {
public:
    BinaryIndexTree() {}

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

BinaryIndexTree bit[30];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    string S;
    cin >> S;
    REP(i, 27) {
        bit[i] = BinaryIndexTree(N + 5);
    }
    REP(i, N) {
        ll n = S[i] - 'a';
        bit[n].add(i + 1, 1);
    }
    ll Q;
    cin >> Q;
    REP(i, Q) {
        ll t;
        cin >> t;
        if (t == 1) {
            ll n;
            char c;
            cin >> n >> c;
            ll m = S[n - 1] - 'a';
            S[n - 1] = c;
            ll k = c - 'a';
            bit[m].add(n, -1);
            bit[k].add(n, 1);
        }
        else {
            ll l, r;
            cin >> l >> r;
            ll sum = 0;
            REP(j, 27) {
                ll s = bit[j].sum(r) - bit[j].sum(l - 1);
                if (s > 0)
                    sum++;
            }
            cout << sum << endl;
        }
    }
    return 0;
}