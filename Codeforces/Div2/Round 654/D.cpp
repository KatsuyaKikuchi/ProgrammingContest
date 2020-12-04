#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll calc(vector<string> &S) {
    ll ret = 0;
    pll c(-INF, INF), r(-INF, INF);
    ll N = S.size();
    REP(i, N) {
        ll s = 0;
        REP(j, N) {
            if (S[i][j] == '1')
                s++;
        }
        r.first = std::max(s, r.first);
        r.second = std::min(s, r.second);
    }
    REP(j, N) {
        ll s = 0;
        REP(i, N) {
            if (S[i][j] == '1')
                s++;
        }
        c.first = std::max(s, c.first);
        c.second = std::min(s, c.second);
    }
    ret = pow(c.first - c.second, 2) + pow(r.first - r.second, 2);
    return ret;
}

void solve() {
    ll N, K;
    cin >> N >> K;
    ll A = K / N;
    ll B = K % N;
    vector<string> S(N);
    ll m = 0;
    REP(i, N) {
        string s = "";
        REP(j, N) {
            s.push_back('0');
        }
        S[i] = s;
    }

    REP(j, N) {
        ll n = A;
        if (j < B)
            n++;
        REP(i, n) {
            ll h = (j + i) % N;
        }
    }


    cout << calc(S) << endl;
    REP(i, N) {
        cout << S[i] << endl;
    }
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