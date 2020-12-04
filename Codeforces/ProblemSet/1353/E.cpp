#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll calc(string &S) {
    while (S.length() > 0) {
        if (S.back() == '1')
            break;
        S.pop_back();
    }
    reverse(S.begin(), S.end());
    while (S.length() > 0) {
        if (S.back() == '1')
            break;
        S.pop_back();
    }
    ll N = S.length();
    if (N == 0)
        return 0;
    vector<ll> L(N), R(N);
    {
        ll s = 0, z = 0;
        ll mn = 0;
        REP(i, N) {
            if (S[i] == '0') {
                z++;
            }
            else {
                mn = std::min(mn + z, s);
                z = 0;
                s++;
            }
            L[i] = mn;
        }
    }
    {
        ll s = 0, z = 0;
        ll mn = 0;
        for (ll i = N - 1; i >= 0; --i) {
            if (S[i] == '0') {
                z++;
            }
            else {
                mn = std::min(mn + z, s);
                z = 0;
                s++;
            }
            R[i] = mn;
        }
    }
    ll ret = INF;
    REP(i, N) {
        if (S[i] == '0')
            continue;
        ret = std::min(L[i] + R[i], ret);
    }
    return ret;
}

ll solve() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    ll sum = 0;
    REP(i, N) {
        if (S[i] == '1')
            sum++;
    }

    ll ret = INF;
    REP(i, K) {
        string s = "";
        ll t = 0;
        for (ll j = i; j < N; j += K) {
            s.push_back(S[j]);
            if (S[j] == '1')
                t++;
        }
        ret = std::min(ret, sum - t + calc(s));
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    REP(_, T) {
        cout << solve() << endl;
    }
    return 0;
}