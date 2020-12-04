#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

class Prime {
public:
    Prime(ll n) {
        mPrimeTbl.clear();
        vector<bool> u(n, false);
        for (ll i = 2; i <= n; ++i) {
            if (u[i])
                continue;
            mPrimeTbl.push_back(i);
            for (ll p = i; p <= n; p += i)
                u[p] = true;
        }
    }

    ~Prime() {}

    ll num() {
        return static_cast<ll>(mPrimeTbl.size());
    }

    ll get(ll index) {
        return mPrimeTbl[index];
    }

private:
    vector<ll> mPrimeTbl;
};

Prime prime(100005);

void solve() {
    ll N;
    cin >> N;
    vector<ll> B;
    B.push_back(N);
    ll num = 2;
    while (num * num <= N) {
        if (N % num == 0) {
            B.push_back(num);
            if (N / num != num)
                B.push_back(N / num);
        }
        num++;
    }
    vector<pll> A;
    REP(i, prime.num()) {
        ll p = prime.get(i);
        if (p * p > N)
            break;
        ll num = 0;
        while (N % p == 0) {
            N /= p;
            num++;
        }
        if (num > 0)
            A.push_back(pll(p, num));
    }
    if (N > 1)
        A.push_back(pll(N, 1));
    sort(A.begin(), A.end(), [](pll a, pll b) { return a.second > b.second; });
    deque<ll> q;
    REP(i, A.size()) {
        if (i % 2 == 0)
            q.push_back(i);
        else
            q.push_front(i);
    }
    vector<pll> P;
    while (!q.empty()) {
        ll t = q.front();
        q.pop_front();
        P.push_back(A[t]);
    }

    vector<vector<ll>> tmp(A.size());
    std::set<ll> s;
    REP(i, P.size()) {
        ll p = P[i].first;
        REP(j, P[i].second) {
            tmp[i].push_back(p);
            s.insert(p);
            p *= P[i].first;
        }
    }

    REP(i, B.size()) {
        if (s.find(B[i]) != s.end())
            continue;
        bool e = false;
        REP(j, P.size()) {
            ll p = P[j].first * P[(j + 1) % P.size()].first;
            if (B[i] % p == 0) {
                tmp[j].push_back(B[i]);
                e = true;
                break;
            }
        }
        if (e)
            continue;

        REP(j, P.size()) {
            if (B[i] % P[j].first) {
                tmp[j].push_back(B[i]);
                break;
            }
        }
    }

    vector<ll> ans;
    REP(i, tmp.size()) {
        REP(j, tmp[i].size()) {
            ans.push_back(tmp[i][j]);
        }
    }

    ll nums = 0;
    REP(i, ans.size()) {
        cout << ans[i] << " ";
        if (gcd(ans[i], ans[(i + 1) % ans.size()]) == 1)
            nums++;
    }
    cout << endl;
    cout << nums << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll Q;
    cin >> Q;
    REP(_, Q) {
        solve();
    }

    return 0;
}