#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll H[300005];
ll dp[300005];

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

    ll N;
    cin >> N;
    REP(i, N) {
        cin >> H[i];
    }
    REP(i, N) {
        dp[i] = INF;
    }
    dp[0] = 0;
    vector<ll> top, btm;
    top.push_back(H[0]);
    btm.push_back(H[0]);

    SegmentTree<ll> top_seg([](ll a, ll b) { return std::min(a, b); }, INF);
    SegmentTree<ll> btm_seg([](ll a, ll b) { return std::min(a, b); }, INF);

    top_seg.init(N + 5);
    btm_seg.init(N + 5);
    top_seg.set(0, 0);
    btm_seg.set(0, 0);
    FOR(i, N, 1) {
        dp[i] = dp[i - 1] + 1;
        if (H[i] > H[i - 1]) {
            ll index = top.size() - 1, ng = -1;
            while (abs(index - ng) > 1) {
                ll mid = (index + ng) / 2;
                if (top[mid] < H[i])
                    index = mid;
                else
                    ng = mid;
            }

            index = std::max(0LL, index - 1);
            ll mn = top_seg.get(index, top.size() + 1);
            dp[i] = std::min(dp[i], mn + 1);
        }
        else if (H[i] < H[i - 1]) {
            ll index = btm.size() - 1, ng = -1;
            while (abs(index - ng) > 1) {
                ll mid = (index + ng) / 2;
                if (btm[mid] > H[i])
                    index = mid;
                else
                    ng = mid;
            }
            index = std::max(0LL, index - 1);
            ll mn = btm_seg.get(index, btm.size() + 1);
            dp[i] = std::min(dp[i], mn + 1);
        }
        while (top.size() > 0 && top.back() <= H[i]) {
            top.pop_back();
            top_seg.set(top.size(), INF);
        }
        top_seg.set(top.size(), dp[i]);
        top.push_back(H[i]);
        while (btm.size() > 0 && btm.back() >= H[i]) {
            btm.pop_back();
            btm_seg.set(btm.size(), INF);
        }
        btm_seg.set(btm.size(), dp[i]);
        btm.push_back(H[i]);
    }

    cout << dp[N - 1] << endl;
    return 0;
}