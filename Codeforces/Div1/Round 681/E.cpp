#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 998244353;
const ll INF = (ll) 1e18;
const ll MAX = 30;

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

struct Vertex {
    vector<ll> to;
    vector<ll> from;
};

struct Data {
    pll cost;
    ll index;
};

Vertex V[200005];
pll D[200005][MAX + 5];
ll P[MAX + 10];

ll calcCost(pll t) {
    if (t.first > MAX)
        return 2LL * INF;
    return t.second + P[t.first] - 1LL;
}

bool isFast(pll target, pll base, bool equal = false) {
    if (target.first >= MAX || base.first >= MAX) {
        if (target.first == base.first) {
            if (equal)
                return target.second <= base.second;
            else
                target.second < base.second;
        }
        if (equal)
            return target.first <= base.first;
        else
            return target.first < base.first;
    }

    ll cost0 = calcCost(target);
    ll cost1 = calcCost(base);
    if (equal)
        return cost0 <= cost1;
    else
        return cost0 < cost1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    P[0] = 1;
    FOR(i, MAX + 5, 1) {
        P[i] = P[i - 1] * 2LL;
    }
    REP(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        V[a].to.push_back(b);
        V[b].from.push_back(a);
    }

    REP(i, N) {
        REP(j, MAX + 2) {
            D[i][j] = pll(INF, INF);
        }
    }

    priority_queue<Data, vector<Data>, function<bool(Data, Data)> > q([](Data a, Data b) {
#if true
        if (a.cost.first == b.cost.first)
            return a.cost.second > b.cost.second;
        return a.cost.first > b.cost.first;
#else
        return isFast(b.cost, a.cost);
#endif
    });
    D[0][0] = pll(0, 0);

    q.push(Data{pll(0, 0), 0});

    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        ll d = std::min(t.cost.first, MAX);
#if false
        if (!isFast(t.cost, D[t.index][d], true))
            continue;
#endif
        {
            ll nxt = t.index;
            pll cost(t.cost.first + 1, t.cost.second);
            if (isFast(cost, D[nxt][std::min(d + 1, MAX)])) {
                D[nxt][std::min(d + 1, MAX)] = cost;
                q.push(Data{cost, nxt});
            }
        }
        if (t.cost.first % 2 == 0) {
            //! to
            REP(i, V[t.index].to.size()) {
                ll nxt = V[t.index].to[i];
                pll cost(t.cost.first, t.cost.second + 1);
                if (!isFast(cost, D[nxt][d]))
                    continue;
                D[nxt][d] = cost;
                q.push(Data{cost, nxt});
            }
            REP(i, V[t.index].from.size()) {
                ll nxt = V[t.index].from[i];
                pll cost(t.cost.first + 1, t.cost.second + 1);
                if (!isFast(cost, D[nxt][std::min(d + 1, MAX)]))
                    continue;
                D[nxt][std::min(d + 1, MAX)] = cost;
                q.push(Data{cost, nxt});
            }
        }
        else {
            //! from
            REP(i, V[t.index].from.size()) {
                ll nxt = V[t.index].from[i];
                pll cost(t.cost.first, t.cost.second + 1);
                if (!isFast(cost, D[nxt][d]))
                    continue;
                D[nxt][d] = cost;
                q.push(Data{cost, nxt});
            }
            REP(i, V[t.index].to.size()) {
                ll nxt = V[t.index].to[i];
                pll cost(t.cost.first + 1, t.cost.second + 1);
                if (!isFast(cost, D[nxt][std::min(d + 1, MAX)]))
                    continue;
                D[nxt][std::min(d + 1, MAX)] = cost;
                q.push(Data{cost, nxt});
            }
        }
    }

#if false
    REP(i, N) {
        REP(j, MAX + 1) {
            cout << D[i][j].first << " " << D[i][j].second << endl;
        }
    }
#endif

    {
        {
            ll p = INF;
            REP(i, MAX) {
                p = std::min(p, calcCost(D[N - 1][i]));
            }
            if (p < INF) {
                cout << (p % MOD) << endl;
                return 0;
            }
        }
        {
            pll cost = D[N - 1][MAX];
            mint ans = D[N - 1][MAX].second;
            ll p = 1LL;
            REP(i, cost.first) {
                p = (p * 2LL) % MOD;
            }
            p = (MOD + p - 1) % MOD;
            ans += p;
            cout << ans.value() << endl;
        }
    }

    return 0;
}