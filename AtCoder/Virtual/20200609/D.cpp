#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll dp[100005];

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
            node[i] = merge(node[(i << 1) | 0], node[(i << 1) | 1]);
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    string S;
    cin >> N >> M;
    cin >> S;
    SegmentTree<ll> seg([](ll a, ll b) { return std::min(a, b); }, INF);
    seg.init(N + 1);
    seg.set(N, 0);
    for (ll i = N; i >= 0; --i) {
        if (S[i] == '1')
            continue;
        seg.set(i, 1 + seg.get(i, std::min(i + M, N)));
        dp[i] = seg.get(i, i);
    }

    if (dp[0] == INF) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> v;
    ll num = dp[0] - 1;
    ll index = 0;
    REP(i, N + 1) {
        if (num != dp[i])
            continue;
        v.push_back(i - index);
        num--;
        index = i;
    }

    REP(i, v.size()) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}