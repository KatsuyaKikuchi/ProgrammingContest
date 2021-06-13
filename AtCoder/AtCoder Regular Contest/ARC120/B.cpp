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

ll x[2] = {0, 1};
ll y[2] = {1, 0};

int main() {
    using mint = ModInt<MOD>;
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    REP(i, H) {
        cin >> S[i];
    }
    mint ans = 1;
    vector<vector<bool>> U(H + 5, vector<bool>(W + 5, false));
    queue<pll> q;
    q.push(pll(0, 0));
    while (!q.empty()) {
        queue<pll> nxt;
        bool b = false, r = false, dot = false;
        while (!q.empty()) {
            pll t = q.front();
            q.pop();
            if (S[t.first][t.second] == 'B')
                b = true;
            else if (S[t.first][t.second] == 'R')
                r = true;
            else
                dot = true;
            REP(i, 2) {
                ll nx = t.first + x[i], ny = t.second + y[i];
                if (nx >= H || ny >= W)
                    continue;
                if (U[nx][ny])
                    continue;
                U[nx][ny] = true;
                nxt.push(pll(nx, ny));
            }
        }
        if (b && r) {
            ans = 0;
            break;
        }
        if (dot && !b && !r) {
            ans *= 2LL;
        }
        swap(q, nxt);
    }

    cout << ans.value() << endl;
    return 0;
}