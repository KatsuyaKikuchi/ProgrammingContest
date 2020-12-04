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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    SegmentTree<pll> seg([](pll a, pll b) {
        if (a.first < b.first)
            return a;
        if (a.first == b.first && a.second < b.second)
            return a;
        return b;
    }, pll(INF, INF));
    seg.init(N);
    vector<ll> v;
    REP(i, N) {
        ll a;
        cin >> a;
        seg.set(i, pll(a, i));
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    ll ans = 0;
    ll index = 0;
    ll count = 0;
    while (count < N) {
        pll t = seg.get(index, N - 1);
        if (t.first != v[count]) {
            t = seg.get(0, index);
            ans++;
        }
        //cout << t.first << " " << t.second << endl;
        index = t.second;
        seg.set(index, pll(INF, INF));
        count++;
    }
    if (index != 0)
        ans++;
    cout << ans << endl;
    return 0;
}