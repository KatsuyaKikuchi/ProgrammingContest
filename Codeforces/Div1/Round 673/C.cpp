#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

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

    T getPos(ll index) {
        index += offset;
        return node[index];
    }

    void clear() {
        REP(i, node.size()) {
            node[i] = identity;
        }
    }

    T identity;
    F merge;
    vector<T> node;
    int offset;
};

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll A[300005];

ll calc(ll bit) {
    ll ret = (~0);
    REP(i, bit) {
        ret &= (~(1LL << i));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        cin >> A[i];
    }
    ll M = 30;
    vector<ll> B(M, 0);
    vector<ll> v(N);
    REP(j, N) {
        v[j] = A[j];
    }

    v.push_back(INF);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<ll> Index(N);
    REP(i, N) {
        Index[i] = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
    }
    SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
    seg.init(v.size() + 1);
    REP(j, N) {
        REP(i, M) {
            ll b = (1LL << i);

            ll tst = calc(i);
            ll rev = ((~0) ^ tst);
            pll target(A[j] & tst, A[j] | rev);
            target.first ^= b;
            target.second ^= b;

            ll d = 0;
            ll low = lower_bound(v.begin(), v.end(), target.first) - v.begin();
            auto it = upper_bound(v.begin(), v.end(), target.second);
            it--;
            ll hight = it - v.begin();
            if ((A[j] & b) >= 1) {
                //! 増える
                d += seg.get(low, hight);
            }
            else {
                //! 減る
                d -= seg.get(low, hight);
            }
            B[i] += d;
        }
        ll index = Index[j];
        ll p = seg.getPos(index);
        seg.set(index, p + 1);
    }

    ll ans = 0;
    seg.clear();
    REP(i, N) {
        ll index = Index[i];
        ans += seg.get(index + 1, v.size());
        ll p = seg.getPos(index);
        seg.set(index, p + 1);
    }

    ll bit = 0;
    REP(i, M) {
        if (B[i] < 0) {
            bit |= (1LL << i);
            ans += B[i];
        }
    }
    cout << ans << " " << bit << endl;

    return 0;
}