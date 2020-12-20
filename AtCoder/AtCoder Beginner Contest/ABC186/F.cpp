#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

pll A[200005];
ll X[200005];
ll Y[200005];

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
    ll H, W, M;
    cin >> H >> W >> M;
    REP(i, M) {
        cin >> A[i].first >> A[i].second;
    }

    SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
    seg.init(H + 1);
    REP(i, H) {
        X[i] = W;
    }
    REP(i, W) {
        Y[i] = H;
    }
    REP(i, M) {
        X[A[i].first - 1] = std::min(X[A[i].first - 1], A[i].second - 1);
        Y[A[i].second - 1] = std::min(Y[A[i].second - 1], A[i].first - 1);
    }

    REP(i, Y[0]) {
        seg.set(i, 1);
    }

    ll ans = 0;
    vector<pll> XX;
    REP(i, Y[0]) {
        //! x
        ans += X[i];
        XX.push_back(pll(X[i], i));
    }
    sort(XX.begin(), XX.end(), [](pll a, pll b) { return a.first < b.first; });
    queue<pll> q;
    REP(i, XX.size()) {
        q.push(XX[i]);
    }
  //  cout << ans << endl;

    REP(i, X[0]) {
        while (!q.empty()) {
            pll t = q.front();
            if (t.first <= i) {
                q.pop();
                seg.set(t.second, 0);
                continue;
            }
            break;
        }
        ll t = Y[i] - seg.get(0, Y[i]);
  //      cout << Y[i] << " " << t << endl;
        ans += t;
    }
    cout << ans << endl;

    return 0;
}