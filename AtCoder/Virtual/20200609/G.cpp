#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
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

struct Vertex {
    vector<ll> node;
};

Vertex V[100005];
ll C[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }
    if (M % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    SegmentTree<pll> seg([](pll a, pll b) {
        if (a.first < b.first)
            return a;
        return b;
    }, pll(INF, INF));
    seg.init(N);
    REP(i, N) {
        seg.set(i, pll(V[i].node.size(), i));
    }

    memset(C, 0, sizeof(C));
    vector<pll> ans;
    while (ans.size() < M) {
        pll t = seg.get(0, N - 1);
        vector<pll> v;
        REP(i, V[t.second].node.size()) {
            ll n = V[t.second].node[i];
            pll value = seg.get(n, n);
            if (value.first == INF)
                continue;
            v.push_back(pll(t.second, n));
        }

        ll m = C[t.second] % 2;
        REP(i, v.size()) {
            pll value = seg.get(v[i].second, v[i].second);
            if (i < m)
                ans.push_back(pll(v[i].first, v[i].second));
            else {
                ans.push_back(pll(v[i].second, v[i].first));
                C[v[i].second]++;
            }
            value.first--;
            if (value.first == 0)
                seg.set(v[i].second, pll(INF, INF));
            else
                seg.set(v[i].second, value);
        }
        seg.set(t.second, pll(INF, INF));
    }

    REP(i, ans.size()) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
    return 0;
}