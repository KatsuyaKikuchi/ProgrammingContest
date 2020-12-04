#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 200005;

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

pll A[200005];
pll B[200005];
map<ll, bool> M[200005];
priority_queue<pll, vector<pll>, function<bool(pll, pll)>> q[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
        A[i].second--;

    }
    REP(i, Q) {
        cin >> B[i].first >> B[i].second;
        B[i].first--;
        B[i].second--;
    }


    REP(i, MAX) {
        q[i] = priority_queue<pll, vector<pll>, function<bool(pll, pll)>>([](pll a,
                                                                             pll b) { return a.first < b.first; });
    }

    SegmentTree<ll> seg([](ll a, ll b) { return std::min(a, b); }, INF);
    seg.init(MAX);
    REP(i, N) {
        M[A[i].second][i] = true;
        q[A[i].second].push(pll(A[i].first, i));
    }

    REP(i, MAX) {
        if (q[i].empty())
            continue;
        seg.set(i, q[i].top().first);
    }

    REP(i, Q) {
        ll chi = B[i].first;
        ll nxt = B[i].second;
        ll p = A[chi].second;
        M[p][chi] = false;
        M[nxt][chi] = true;
        q[nxt].push(pll(A[chi].first, chi));
        A[chi].second = nxt;
        {
            while (!q[p].empty()) {
                pll t = q[p].top();
                if (M[p][t.second])
                    break;
                q[p].pop();
            }
            if (q[p].empty())
                seg.set(p, INF);
            else
                seg.set(p, q[p].top().first);
        }
        {
            while (!q[nxt].empty()) {
                pll t = q[nxt].top();
                if (M[nxt][t.second])
                    break;
                q[nxt].pop();
            }
            seg.set(nxt, q[nxt].top().first);
        }

#if false
        REP(i, MAX) {
            if (q[i].empty())
                continue;
            cout << q[i].top().first << " ";
        }
        cout << endl;
#endif

        cout << seg.get(0, MAX - 1) << endl;
    }
    return 0;
}