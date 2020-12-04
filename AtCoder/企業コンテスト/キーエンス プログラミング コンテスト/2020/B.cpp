#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[100005];

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
    ll N;
    cin >> N;
    vector<ll> v;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        v.push_back(A[i].first + A[i].second);
    }
    v.push_back(-INF);
    v.push_back(INF);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    sort(A, A + N, [](pll a, pll b) { return a.first < b.first; });

    SegmentTree<ll> seg([](ll a, ll b) { return std::max(a, b); }, 0);
    seg.init(v.size());

    ll ans = 0;
    vector<ll> dp(v.size(), 0);
    REP(i, N) {
        ll ri = lower_bound(v.begin(), v.end(), A[i].first + A[i].second) - v.begin();
        ll x = A[i].first - A[i].second;
#if true
        ll li = 0, ng = v.size();
        while (abs(li - ng) > 1) {
            ll mid = (li + ng) / 2;
            if (v[mid] <= x)
                li = mid;
            else
                ng = mid;
        }
#endif
        //      ll li = lower_bound(v.begin(), v.end(), x) - v.begin();
        ll m = seg.get(0, li) + 1;
        ans = std::max(ans, m);
        // dp[ri] = std::max(dp[ri], m);
        seg.set(ri, std::max(m, seg.get(ri, ri)));
    }

    cout << ans << endl;

    return 0;
}