#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vertex {
    ll nxt;
    ll cost;
    ll value;
};
vector<vector<Vertex>> V;

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

pll dfs(ll idx, ll &count, ll parent = -1) {
    pll ret(0, 0);
    REP(i, V[idx].size()) {
        ll nxt = V[idx][i].nxt;
        if (nxt == parent)
            continue;
        ll cost = V[idx][i].value;
        pll nxt_val = dfs(nxt, count, idx);

        if (cost == 0) {
            nxt_val.first++;
            count += nxt_val.second;
            count += nxt_val.first * ret.second + nxt_val.second * ret.first;
            ret.first += nxt_val.first;
            ret.second += nxt_val.second;
        }
        else {
            swap(nxt_val.first, nxt_val.second);
            nxt_val.second++;
            count += nxt_val.second;
            count += nxt_val.first * ret.second + nxt_val.second * ret.first;
            ret.first += nxt_val.first;
            ret.second += nxt_val.second;
        }
        count %= MOD;
    }
    return ret;
}

int main() {
    using mint = ModInt<MOD>;
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    V.resize(N);
    REP(i, N - 1) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        V[a].push_back(Vertex{b, c, 0});
        V[b].push_back(Vertex{a, c, 0});
    }

    mint ans = 0;
    REP(t, 62) {
        mint v = ((mint) 2).pow(t);
        REP(i, N) {
            REP(j, V[i].size()) {
                if ((V[i][j].cost >> t) & 1)
                    V[i][j].value = 1;
                else
                    V[i][j].value = 0;
            }
        }
        ll count = 0;
        pll tmp = dfs(0, count);
        //cout << tmp.first << " " << tmp.second << endl;
       // cout << count << endl;
        ans += v * count;
    }
    cout << ans.value() << endl;

    return 0;
}