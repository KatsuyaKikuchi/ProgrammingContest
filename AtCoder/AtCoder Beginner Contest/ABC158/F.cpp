#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

pll A[200005];
ll dp[200005];
ll mi[200005];

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    sort(A, A + N, [](pll a, pll b) { return a.first < b.first; });
    A[N] = pll(INF, INF);
    memset(dp, 0, sizeof(dp));
    SegmentTree<ll> seg([](ll a, ll b) { return std::max(a, b); }, 0);
    seg.init(N + 1);
    dp[N] = 1;
    mi[N] = N;
    seg.set(N, N);

    ll ans = 1;
    for (ll i = N - 1; i >= 0; --i) {
        //! 右からi番目を起動
        pll a = A[i];
        ll t = 0;
        ll ok = N + 1, ng = i;
        while (abs(ok - ng) > 1) {
            ll mid = (ok + ng) / 2;
            if (A[mid].first >= a.first + a.second)
                ok = mid;
            else
                ng = mid;
        }

        ll index = i + 1;
        if (ok - 1 >= index)
            index = seg.get(i + 1, ok - 1);
        t = dp[index];

        ans = (ans + t) % MOD;
        dp[i] = ans;
        seg.set(i, index);
    }
    cout << ans << endl;
    return 0;
}