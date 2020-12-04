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

ll LS[500005];
ll RS[500005];

ll solve(ll N, const vector<ll> &A) {
    vector<ll> v;
    REP(i, N) {
        v.push_back(A[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    memset(LS, 0, sizeof(LS));
    memset(RS, 0, sizeof(RS));

    SegmentTree<ll> segL([](ll a, ll b) { return std::max(a, b); }, -1);
    SegmentTree<ll> segR([](ll a, ll b) { return std::min(a, b); }, N);

    segL.init(N + 1);
    {
        int index = lower_bound(v.begin(), v.end(), A[0]) - v.begin();
        segL.set(index, 0);
    }
    segR.init(N + 1);
    {
        int index = lower_bound(v.begin(), v.end(), A[N - 1]) - v.begin();
        segR.set(index, N - 1);
    }

    LS[0] = A[0];

    FOR(i, N, 1) {
        int index = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        if (A[i] >= A[i - 1]) {
            LS[i] = LS[i - 1] + A[i];
        }
        else {
            ll mi = segL.get(0, index);
            ll base = mi >= 0 ? LS[mi] : 0;
            LS[i] = base + A[i] * ((i - 1) - mi + 1);
        }
        segL.set(index, i);
    }
    RS[N - 1] = A[N - 1];
    for (ll i = N - 2; i >= 0; --i) {
        int index = lower_bound(v.begin(), v.end(), A[i]) - v.begin();
        if (A[i] >= A[i + 1]) {
            RS[i] = RS[i + 1] + A[i];
        }
        else {
            ll mi = segR.get(0, index);
            ll base = mi < N ? RS[mi] : 0;
            RS[i] = base + A[i] * (mi - (i + 1) + 1);
        }
        segR.set(index, i);
    }
    ll maxIndex = 0;
    ll maxSum = 0;
    REP(i, N) {
        ll s = LS[i] + RS[i] - A[i];
        if (maxSum <= s) {
            maxSum = s;
            maxIndex = i;
        }
    }

    vector<ll> ans(N);
    ans[maxIndex] = A[maxIndex];
    for (ll i = maxIndex - 1; i >= 0; --i) {
        ll a = std::min(A[i], ans[i + 1]);
        ans[i] = a;
    }
    for (ll i = maxIndex + 1; i < N; ++i) {
        ll a = std::min(A[i], ans[i - 1]);
        ans[i] = a;
    }

    REP(i, N) {
        cout << ans[i];
        if (i < N - 1)
            cout << " ";
    }
    cout << endl;
    return maxSum;
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }

    ll a = solve(N, A);
    return 0;
}