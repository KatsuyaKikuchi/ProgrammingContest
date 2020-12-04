#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<tuple<ll, ll, ll>> C;
vector<vector<tuple<ll, ll, ll>>> D;
vector<vector<ll>> S;
ll T;
vector<pll> A;
vector<pll> B;

ll solve(ll a, ll b) {
    ll s = 0;
    ll ok = -1, ng = C.size();
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (get<0>(C[mid]) < a)
            ok = mid;
        else
            ng = mid;
    }

    ll si = 0;
    REP(i, D.size()) {
        si += D[i].size();
        if (si > ok) {
            for (ll j = si - D[i].size(); j <= ok; ++j) {
                if (get<1>(C[j]) < b)
                    s += get<2>(C[j]);
            }
            break;
        }

        ll ok2 = -1, ng2 = D[i].size();
        while (abs(ok2 - ng2) > 1) {
            ll mid = (ok2 + ng2) / 2;
            if (get<1>(D[i][mid]) < b)
                ok2 = mid;
            else
                ng2 = mid;
        }

        if (ok2 >= 0)
            s += S[i][ok2];
    }
    return s;
}

bool check(ll p) {
    ll ok = -INF, ng = INF;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        ll sum = 0;
        REP(i, A.size()) {
        }
    }
    return ok <= p;
}

int main() {
    ll N, M, P;
    cin >> N >> M >> P;
    A.resize(N);
    REP(i, N) {
        cin >> A[i].first >> A[i].second;
    }
    B.resize(M);
    REP(i, M) {
        cin >> B[i].first >> B[i].second;
    }
    C.resize(P);
    REP(i, P) {
        ll x, y, z;
        cin >> x >> y >> z;
        C[i] = make_tuple(x, y, z);
    }
    sort(C.begin(), C.end(), [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) { return get<0>(a) < get<0>(b); });
    vector<vector<tuple<ll, ll, ll>>> D;
    vector<vector<ll>> S;
    T = (ll) (sqrt(P));
    for (ll i = 0; i < P;) {
        vector<tuple<ll, ll, ll>> v;
        for (ll j = 0; j <= T && i < N; ++i) {
            v.push_back(C[i]);
        }
        sort(v.begin(), v.end(), [](tuple<ll, ll, ll> a, tuple<ll, ll, ll> b) { return get<1>(a) < get<1>(b); });
        vector<ll> s(v.size());
        REP(j, s.size()) {
            s[j] = get<2>(v[j]);
            if (j > 0)
                s[j] += s[j - 1];
        }
        D.push_back(v);
        S.push_back(s);
    }

    sort(A.begin(), A.end(), [](pll a, pll b) { return a.first < b.first; });
    sort(B.begin(), B.end(), [](pll a, pll b) { return a.first < b.first; });
    for (ll i = N - 2; i >= 0; --i) {
        A[i].second = std::min(A[i].second, A[i + 1].second);
    }
    for (ll i = M - 2; i >= 0; --i) {
        B[i].second = std::min(B[i].second, B[i + 1].second);
    }

    ll ok = INF, ng = INF;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (check(mid))
            ok = mid;
        else
            ng = mid;
    }
    cout << ok << endl;
    return 0;
}