#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll test(string &S) {
    ll N = S.length();
    string T = S;
    ll ret = 0;
    REP(i, N) {
        ll c = S[N - 1 - i];
        FOR(j, N, i) {
            if (c != T[j]) {
                continue;
            }
            for (ll k = j; k > i; --k) {
                T[k] = T[k - 1];
            }
            T[i] = c;
            ret += j - i;
            break;
        }
    }
    return ret;
}

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
    ll N;
    cin >> N;
    string S;
    cin >> S;

    queue<ll> q[30];
    REP(i, N) {
        ll t = S[i] - 'a';
        q[t].push(i);
    }

    SegmentTree<ll> seg([](ll a, ll b) { return a + b; }, 0);
    seg.init(N + 5);

    ll ans = 0;
    REP(i, N) {
        ll c = S[N - 1 - i] - 'a';
        ll t = q[c].front();
        q[c].pop();

        ll p = seg.get(t + 1, N + 3);
        seg.set(t, 1);

        ans += t + p - i;
    }
    cout << ans << endl;

    return 0;
}