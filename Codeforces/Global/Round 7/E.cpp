#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll B[300005];
ll P[300005];

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
    vector<ll> A(N + 1);
    SegmentTree<ll> seg([](ll a, ll b) { return std::min(a, b); }, INF);
    seg.init(N + 1);
    REP(i, N) {
        cin >> A[i];
        P[A[i]] = i;
        seg.set(i, A[i]);
    }
    vector<ll> ans(N + 1);
    ans[0] = N;

    REP(i, N) {
        cin >> B[i];
    }

    ll max = 0;
    ll min = N;

    priority_queue<ll, vector<ll>, function<bool(ll, ll)>> q([](ll a, ll b) { return a > b; });
    REP(i, N - 1) {
        ll b = B[N - 1 - i];
        ll n = seg.get(b - 1, b - 1);
        if (n != INF)
            q.push(n);
        min = std::min(b - 1, min);
        ll m = seg.get(b - 1, N - 1);
        if (m == INF) {
            while (m == INF) {
                m = q.top();
                q.pop();
                m = seg.get(P[m], N - 1);
            }
        }
        max = std::max(max, m);
        seg.set(P[m], INF);
        ans[N - 1 - i] = max;
    }

    REP(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}