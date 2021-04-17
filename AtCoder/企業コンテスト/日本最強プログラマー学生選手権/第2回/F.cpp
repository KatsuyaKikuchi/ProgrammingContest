#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

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
            offset *= 2LL;
        node.resize(offset * 2LL);
        //        node.assign(offset * 2LL, identity);
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
    ll offset;
};

struct Query {
    ll t, x, y;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, Q;
    cin >> N >> M >> Q;

    vector<Query> query(Q);
    vector<ll> v;
    v.push_back(0);
    REP(i, Q) {
        cin >> query[i].t >> query[i].x >> query[i].y;
        query[i].x--;
        v.push_back(query[i].y);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    SegmentTree<ll> segA_sum([](ll a, ll b) { return a + b; }, 0);
    SegmentTree<ll> segB_sum([](ll a, ll b) { return a + b; }, 0);
    SegmentTree<ll> segA_count([](ll a, ll b) { return a + b; }, 0);
    SegmentTree<ll> segB_count([](ll a, ll b) { return a + b; }, 0);
    const ll MAX = v.size() + 5;

    segA_sum.init(MAX);
    segB_sum.init(MAX);
    segA_count.init(MAX);
    segB_count.init(MAX);
#if true
    segA_count.set(0, N);
    segB_count.set(0, M);
#endif
    vector<ll> A(N, 0);
    vector<ll> B(M, 0);

    ll ans = 0;
    REP(i, Q) {
        ll t = query[i].t;
        ll x = query[i].x;
        ll y = query[i].y;
        if (t == 1) {
            ll a = A[x];
            ll index_a = lower_bound(v.begin(), v.end(), a) - v.begin();
            ll index_y = lower_bound(v.begin(), v.end(), y) - v.begin();
            {
                ll sum_b = segB_sum.get(index_a + 1, MAX);
                ll count_b = segB_count.get(0, index_a);
                ans -= sum_b + count_b * a;
            }
            {
                ll sum_b = segB_sum.get(index_y + 1, MAX);
                ll count_b = segB_count.get(0, index_y);
                ans += sum_b + count_b * y;
            }
            // 後処理
            {
                ll sum_a = segA_sum.get(index_a, index_a);
                ll count_a = segA_count.get(index_a, index_a);
                segA_sum.set(index_a, sum_a - a);
                segA_count.set(index_a, count_a - 1);
            }
            {
                ll sum_a = segA_sum.get(index_y, index_y);
                ll count_a = segA_count.get(index_y, index_y);
                segA_sum.set(index_y, sum_a + y);
                segA_count.set(index_y, count_a + 1);
            }
            A[x] = y;
        }
        else {
            ll b = B[x];
            ll index_b = lower_bound(v.begin(), v.end(), b) - v.begin();
            ll index_y = lower_bound(v.begin(), v.end(), y) - v.begin();
            {
                ll sum_a = segA_sum.get(index_b + 1, MAX);
                ll count_a = segA_count.get(0, index_b);
                ans -= sum_a + count_a * b;
            }
            {
                ll sum_a = segA_sum.get(index_y + 1, MAX);
                ll count_a = segA_count.get(0, index_y);
                ans += sum_a + count_a * y;
            }
            // 後処理
            {
                ll sum_b = segB_sum.get(index_b, index_b);
                ll count_b = segB_count.get(index_b, index_b);
                segB_sum.set(index_b, sum_b - b);
                segB_count.set(index_b, count_b - 1);
            }
            {
                ll sum_b = segB_sum.get(index_y, index_y);
                ll count_b = segB_count.get(index_y, index_y);
                segB_sum.set(index_y, sum_b + y);
                segB_count.set(index_y, count_b + 1);
            }
            B[x] = y;
        }
        cout << ans << endl;
    }

    return 0;
}