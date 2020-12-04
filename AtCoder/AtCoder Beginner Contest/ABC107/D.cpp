#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e9;

ll N;
ll A[100005];

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

bool check(ll m) {
    //! m以下の中央値がnum個以上存在するか？
    ll num = (N * (N + 1) / 2) / 2 + 1;
    vector<ll> v(N);
    ll sum = 0;
    REP(i, N) {
        if (A[i] <= m)
            sum++;
        else
            sum--;
        v[i] = sum;
    }

    SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    v.push_back(INF);
    seg.init(v.size() + 5);
    sum = 0;
    REP(i, N) {
        if (A[i] <= m)
            sum++;
        else
            sum--;
        ll idx = lower_bound(v.begin(), v.end(), sum) - v.begin();
        ll val = seg.get(idx, idx);
        seg.set(idx, val + 1);
    }
    ll p = 1;
    ll count = 0;
    sum = 0;
    REP(i, N) {
        {
            ll idx = lower_bound(v.begin(), v.end(), p) - v.begin();
            count += seg.get(idx, v.size() + 1);
        }
        {
            if (A[i] <= m)
                sum++;
            else
                sum--;
            ll idx = lower_bound(v.begin(), v.end(), sum) - v.begin();
            ll val = seg.get(idx, idx);
            seg.set(idx, val - 1);
        }
        if (A[i] <= m)
            p++;
        else
            p--;
    }

    return count >= num;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }

    ll ans = INF, ng = 0;
    while (abs(ans - ng) > 1) {
        ll mid = (ans + ng) / 2;
        if (check(mid))
            ans = mid;
        else
            ng = mid;
    }
    cout << ans << endl;

    return 0;
}