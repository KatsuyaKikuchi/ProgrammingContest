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

ll N;
ll Index[200005];
SegmentTree<ll> seg_e([](ll a, ll b) { return std::min(a, b); }, INF);
SegmentTree<ll> seg_o([](ll a, ll b) { return std::min(a, b); }, INF);

pll get(pll range) {
    ll mo, me, index;
    if (range.first % 2 == 0) {
        auto &odd = seg_o;
        auto &even = seg_e;
        mo = odd.get(range.first, range.second);
        index = Index[mo];
        me = even.get(index, range.second);
    }
    else {
        auto &odd = seg_e;
        auto &even = seg_o;
        mo = odd.get(range.first, range.second);
        index = Index[mo];
        me = even.get(index, range.second);
    }
    return pll(mo, me);
}

struct Vertex {
    pll range;
    pll value;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    seg_e.init(N + 5);
    seg_o.init(N + 5);
    REP(i, N) {
        ll p;
        cin >> p;
        if (i % 2 == 0)
            seg_o.set(i, p);
        else
            seg_e.set(i, p);
        Index[p] = i;
    }

    priority_queue<Vertex, vector<Vertex>, function<bool(Vertex, Vertex)>> q([](Vertex a, Vertex b) {
        return a.value.first > b.value.first;
    });
    q.push(Vertex{pll(0, N - 1), get(pll(0, N - 1))});
    vector<pll> ans;

    while (!q.empty()) {
        auto v = q.top();
        q.pop();
        ans.push_back(v.value);
        ll index0 = Index[v.value.first];
        ll index1 = Index[v.value.second];
        {
            pll range(v.range.first, index0 - 1);
            if (range.first < range.second) {
                Vertex t{range, get(range)};
                q.push(t);
            }
        }
        {
            pll range(index0 + 1, index1 - 1);
            if (range.first < range.second) {
                Vertex t{range, get(range)};
                q.push(t);
            }
        }
        {
            pll range(index1 + 1, v.range.second);
            if (range.first < range.second) {
                Vertex t{range, get(range)};
                q.push(t);
            }
        }
    }

    REP(i, ans.size()) {
        pll p = ans[i];
        cout << p.first << " " << p.second << " ";
    }
    cout << endl;
    return 0;
}