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
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> v;
    {
        ll s = 0;
        v.push_back(0);
        REP(i, N) {
            s += A[i];
            v.push_back(s - K * (i + 1));
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
    seg.init(v.size() + 5);
    {
        ll idx = lower_bound(v.begin(), v.end(), 0) - v.begin();
        seg.set(idx, 1);
    }
    ll ans = 0;
    {
        ll s = 0;
        REP(i, N) {
            s += A[i];
            ll t = s - (i + 1) * K;
            ll idx = lower_bound(v.begin(), v.end(), t) - v.begin();
            ll val = seg.get(0, idx);
            ans += val;
            ll x = seg.get(idx, idx);
            seg.set(idx, x + 1);
            cout << ans << " ";
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}