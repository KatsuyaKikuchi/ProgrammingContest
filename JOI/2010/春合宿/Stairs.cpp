#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1234567;
const ll INF = (ll) 1e15;

template<typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    SegmentTree(F func, T id)
            : merge(func), identity(id) {}

    void init(ll n) {
        offset = 1;
        while (offset < n)
            offset <<= 1;
        node.assign(offset << 1, identity);
    }

    void build(const vector<T> &v) {
        int n = static_cast<int>(v.size());
        init(n);
        for (int i = 0; i < n; ++i) {
            node[offset + i] = v[i];
        }
        for (int i = offset - 1; i >= 0; --i) {
            node[i] = merge(node[(1 << i) | 0], node[(1 << i) | 1]);
        }
    }

    void set(int index, T value) {
        index += offset;
        node[index] = value;
        while (index >>= 1) {
            node[index] = merge(node[(index << 1) | 0], node[(index << 1) | 1]);
        }
    }

    //! [left, right]
    T get(int left, int right) {
        left += offset;
        right += offset + 1;

        T val = identity;
        while (left < right) {
            if (left & 1)
                val = merge(val, node[left++]);
            if (right & 1)
                val = merge(val, node[--right]);

            left >>= 1;
            right >>= 1;
        }
        return val;
    }

    T identity;
    F merge;
    vector<T> node;
    int offset;
};

ll A[500005];
ll S[500005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, P;
    cin >> N >> P;
    memset(S, 0, sizeof(S));
    REP(i, N) {
        cin >> A[i];
        S[i + 1] = (S[i] + A[i]);
    }
    SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
    seg.init(N + 1);
    seg.set(0, 1);
    REP(i, N) {
        ll ok = i + 1, ng = -1;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            ll s = S[i + 1] - S[mid];
            if (s <= P)
                ok = mid;
            else
                ng = mid;
        }
        ll sum = seg.get(ok, i + 1) % MOD;
        seg.set(i + 1, sum);
    }

    cout << seg.get(N, N) << endl;

    return 0;
}