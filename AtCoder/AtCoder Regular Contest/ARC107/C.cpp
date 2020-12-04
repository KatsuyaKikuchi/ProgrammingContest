#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

template<std::uint_fast64_t Modulus>
class ModInt {
    using u64 = std::uint_fast64_t;
public:
    constexpr ModInt(u64 value = 0) noexcept:
            mValue(value % Modulus) {}

    u64 &value() { return mValue; }

    constexpr ModInt &operator+=(ModInt v) noexcept {
        mValue += v.mValue;
        if (mValue >= Modulus)
            mValue -= Modulus;
        return *this;
    }

    constexpr ModInt &operator-=(ModInt v) noexcept {
        if (mValue < v.mValue)
            mValue += Modulus;
        mValue -= v.mValue;
        return *this;
    }

    constexpr ModInt &operator*=(ModInt v) noexcept {
        mValue = (mValue * v.mValue) % Modulus;
        return *this;
    }

    constexpr ModInt &operator/=(ModInt v) noexcept {
        *this *= v.pow(Modulus - 2);
        return *this;
    }

    constexpr ModInt operator+(ModInt v) noexcept {
        return ModInt(*this) += v;
    }

    constexpr ModInt operator-(ModInt v) noexcept {
        return ModInt(*this) -= v;
    }

    constexpr ModInt operator*(ModInt v) noexcept {
        return ModInt(*this) *= v;
    }

    constexpr ModInt operator/(ModInt v) noexcept {
        return ModInt(*this) /= v;
    }

    ModInt pow(u64 r) {
        u64 p = mValue;
        ModInt ret(1);
        while (r > 0) {
            if (r & 1)
                ret *= p;
            r >>= 1;
            p = (p * p) % Modulus;
        }
        return ret;
    }

private:
    u64 mValue;
};

ll A[55][55];

struct UnionFind {
    UnionFind(int n) {
        rank.assign(n, 0);
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    void unit(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y)
            return;

        if (rank[x] < rank[y]) {
            parent[x] = y;
        }
        else {
            parent[y] = x;
            if (rank[x] == rank[y])
                rank[x]++;
        }
    }

    vector<int> rank;
    vector<int> parent;
};

int main() {
    using mint = ModInt<MOD>;
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    REP(i, N) {
        REP(j, N) {
            cin >> A[i][j];
        }
    }

    UnionFind W(N), H(N);

    REP(i, N) {
        FOR(j, N, i + 1) {
            bool can = true;
            REP(h, N) {
                if (A[h][i] + A[h][j] > K)
                    can = false;
            }
            if (can)
                W.unit(i, j);
        }
    }
    REP(i, N) {
        FOR(j, N, i + 1) {
            bool can = true;
            REP(w, N) {
                if (A[i][w] + A[j][w] > K)
                    can = false;
            }
            if (can)
                H.unit(i, j);
        }
    }
    mint ans = 1;
    vector<ll> hn(N, 0), wn(N, 0);
    REP(i, N) {
        hn[H.find(i)]++;
        wn[W.find(i)]++;
    }

    REP(i, N) {
        REP(j, hn[i]) {
            ans *= (j + 1);
        }
    }
    REP(i, N) {
        REP(j, wn[i]) {
            ans *= (j + 1);
        }
    }

    cout << ans.value() << endl;
    return 0;
}