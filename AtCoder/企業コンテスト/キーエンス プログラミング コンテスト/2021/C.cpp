#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

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

int main() {
    using mint = ModInt<MOD>;
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, K;
    cin >> H >> W >> K;
    bool swp = false;
    if (H > W) {
        swap(H, W);
        swp = true;
    }
    vector<vector<ll>> V(H, vector<ll>(W, 0));
    REP(_, K) {
        ll h, w;
        char c;
        cin >> h >> w >> c;
        h--;
        w--;
        if (swp)
            swap(h, w);
        if (swp && c == 'R')
            c = 'D';
        else if (swp && c == 'D')
            c = 'R';
        if (c == 'X')
            V[h][w] = 1;
        if (c == 'D')
            V[h][w] = 2;
        if (c == 'R')
            V[h][w] = 3;
    }

    vector<vector<ll>> S(H, vector<ll>(W, 0));
    REP(j, W) {
        ll s = 0;
        REP(i, H) {
            ll w = j - i;
            ll h = i;
            if (w < 0 || w >= W || h < 0 || h >= H)
                continue;
            if (V[h][w] == 0)
                s++;
        }
        REP(i, H) {
            ll w = j - i;
            ll h = i;
            if (w < 0 || w >= W || h < 0 || h >= H)
                continue;
            S[h][w] = s;
        }
    }
    REP(j, W) {
        ll s = 0;
        for (ll i = H - 1; i >= 0; --i) {
            ll w = j + (H - 1 - i);
            ll h = i;
            if (w < 0 || w >= W || h < 0 || h >= H)
                continue;
            if (V[h][w] == 0)
                s++;
        }
        for (ll i = H - 1; i >= 0; --i) {
            ll w = j + (H - 1 - i);
            ll h = i;
            if (w < 0 || w >= W || h < 0 || h >= H)
                continue;
            S[h][w] = s;
        }
    }
    vector<ll> P(10000, 0);
    P[0] = 1;
    FOR(i, P.size(), 1) {
        P[i] = (P[i - 1] * 3LL) % MOD;
    }

#if false
    REP(i, H) {
        REP(j, W) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
#endif

    vector<vector<mint>> ans(H, vector<mint>(W, 0));
    ans[0][0] = 1;
    REP(i, H) {
        REP(j, W) {
            if (i == H - 1 && j == W - 1)
                break;
            switch (V[i][j]) {
                case 0:
                    if (i + 1 < H) {
                        mint t = ans[i][j];
                        //mint x = 3;
                        ll n = S[i + 1][j];
                        if (V[i + 1][j] == 0)
                            n--;
                        t *= P[n];
                        t *= 2LL;
                        ans[i + 1][j] += t.value();
                    }
                    if (j + 1 < W) {
                        mint t = ans[i][j];
                        ll n = S[i][j + 1];
                        if (V[i][j + 1] == 0)
                            n--;
                        t *= P[n];
                        t *= 2LL;
                        ans[i][j + 1] += t.value();
                    }
                    break;
                case 1:
                    // X
                    if (i + 1 < H) {
                        mint t = ans[i][j];

                        ll n = S[i + 1][j];
                        if (V[i + 1][j] == 0)
                            n--;
                        t *= P[n];
                        ans[i + 1][j] += t.value();
                    }
                    if (j + 1 < W) {
                        mint t = ans[i][j];
                        //  mint x = 3;
                        ll n = S[i][j + 1];
                        if (V[i][j + 1] == 0)
                            n--;
                        t *= P[n];
                        ans[i][j + 1] += t.value();
                    }
                    break;
                case 2:
                    // D
                    if (i + 1 < H) {
                        mint t = ans[i][j];
                        // mint x = 3;
                        ll n = S[i + 1][j];
                        if (V[i + 1][j] == 0)
                            n--;
                        t *= P[n];
                        ans[i + 1][j] += t.value();
                    }
                    break;
                case 3:
                    // R
                    if (j + 1 < W) {
                        mint t = ans[i][j];
                        // mint x = 3;
                        ll n = S[i][j + 1];
                        if (V[i][j + 1] == 0)
                            n--;
                        t *= P[n];
                        ans[i][j + 1] += t.value();
                    }
                    break;
            }
        }
    }
#if false
    REP(i, H) {
        REP(j, W) {
            cout << ans[i][j].value() << " ";
        }
        cout << endl;
    }
#endif

    mint ret = ans[H - 1][W - 1];
    if (V[H - 1][W - 1] == 0)
        ret *= 3LL;
    cout << (ret.value() % MOD) << endl;

    return 0;
}