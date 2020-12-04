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

using mint = ModInt<MOD>;

ll solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) {
        cin >> A[i];
    }
    vector<ll> B(K);
    REP(i, K) {
        cin >> B[i];
    }

    mint ans = 1;
    vector<ll> U(N, -1);
    std::map<ll, ll> mp;
    REP(i, K) {
        mp[B[i]] = i + 1;
    }
    ll cnt = 0;
    REP(i, N) {
        ll val = mp[A[i]];
        if (val == 0)
            continue;
        U[i] = val - 1;
        cnt++;
    }

    if (cnt != K)
        return 0;

    REP(i, N) {
        if (U[i] < 0)
            continue;
        ll num = 0;
        if (i > 0 && U[i - 1] < U[i])
            num++;
        if (i < N - 1 && U[i + 1] < U[i])
            num++;
        ans *= num;
    }

    return ans.value();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        cout << solve() << endl;
    }
    return 0;
}