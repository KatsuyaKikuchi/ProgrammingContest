#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[200005];
pll C[200005];
struct Vertex {
    vector<ll> node;
};
Vertex V[200005];

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
    ll N, M, K;
    cin >> N >> M >> K;
    REP(i, K) {
        cin >> A[i];
        A[i]--;
    }
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].node.push_back(b);
        V[b].node.push_back(a);
    }

    REP(i, N) {
        C[i] = pll(INF, INF);
    }
    {
        C[0].first = 0;
        queue<pll> q;
        q.push(pll(0, 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            REP(i, V[t.first].node.size()) {
                ll n = V[t.first].node[i];
                if (C[n].first <= cost)
                    continue;
                C[n].first = cost;
                q.push(pll(n, cost));
            }
        }
    }
    {
        C[N - 1].second = 0;
        queue<pll> q;
        q.push(pll(N - 1, 0));
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            ll cost = t.second + 1;
            REP(i, V[t.first].node.size()) {
                ll n = V[t.first].node[i];
                if (C[n].second <= cost)
                    continue;
                C[n].second = cost;
                q.push(pll(n, cost));
            }
        }
    }

    sort(A, A + K, [](ll a, ll b) { return C[a] < C[b]; });
    SegmentTree<ll> seg([](ll a, ll b) { return std::max(a, b); }, 0);
    seg.init(K);
    REP(i, K) {
        seg.set(i, C[A[i]].second);
    }
    ll ans = 0;
    REP(i, K - 1) {
        ll c0 = C[A[i]].first;
        ll c1 = seg.get(i + 1, K - 1);
        ans = std::max(std::min(c0 + c1 + 1, C[N - 1].first), ans);
    }
    cout << ans << endl;
    return 0;
}