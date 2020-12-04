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

ll A[100005];
pll B[200005];
bool U[200005];

vector<ll> V[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    REP(i, N) {
        cin >> A[i];
    }
    REP(i, M) {
        cin >> B[i].first >> B[i].second;
        B[i].first--;
        B[i].second--;
        if (B[i].first > B[i].second)
            swap(B[i].first, B[i].second);
        V[B[i].first].push_back(i);
        V[B[i].second].push_back(i);

        A[B[i].first]--;
        A[B[i].second]--;
    }

    SegmentTree<pll> seg([](pll a, pll b) {
        if (a.first > b.first)
            return a;
        return b;
    }, pll(-INF, -INF));
    seg.init(N + 5);
    REP(i, N) {
        seg.set(i, pll(A[i], i));
    }

    memset(U, 0, sizeof(U));
    vector<ll> ans;
    REP(_, N) {
        pll m = seg.get(0, N);
        if (m.first < 0) {
            cout << "DEAD" << endl;
            return 0;
        }
        REP(j, V[m.second].size()) {
            ll idx = V[m.second][j];
            if (U[idx])
                continue;
            U[idx] = true;
            ll n = B[idx].first;
            ans.push_back(idx + 1);
            if (n == m.second)
                n = B[idx].second;
            seg.set(n, pll(seg.get(n, n).first + 1, n));
        }

        seg.set(m.second, pll(-INF, -INF));
    }

    reverse(ans.begin(), ans.end());
    cout << "ALIVE" << endl;
    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}