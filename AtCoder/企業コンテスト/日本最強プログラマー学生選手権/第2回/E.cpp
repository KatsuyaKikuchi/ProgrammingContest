#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll solve(vector<string> &S, ll level) {
    ll N = S[0].length();
    if (level == 0) {
        if (N == 1)
            return -1;
        // 全部イコール&&全部回文でないが満たされているような最小値
        if (N == 0)
            return 0;
#if false
        for (const auto &s:S) {
            cout << s << endl;
        }
#endif
        ll sum = 0;
        vector<pll> v;
        string tests = "";
        REP(i, N) {
            vector<ll> counts(30, 0);
            for (const auto &s:S) {
                counts[s[i] - 'a']++;
            }
            ll mx = 0;
            REP(j, counts.size()) {
                if (counts[mx] < counts[j])
                    mx = j;
            }
            tests.push_back('a' + mx);
            if (N % 2 == 0 || N / 2 != i) {
                ll next = 0;
                if (mx == 0)
                    next = 1;
                REP(j, counts.size()) {
                    if (j == mx)
                        continue;
                    if (counts[next] < counts[j])
                        next = j;
                }

                v.push_back(pll(counts[mx], counts[next]));
            }
            sum += S.size() - counts[mx];
        }

       // cout << tests << endl;
       // cout << sum << endl;
        // できたものが回文ならば一つかえる
        bool enable = false;
        REP(i, tests.size()) {
            if (tests[i] != tests[tests.size() - 1 - i])
                enable = true;
        }

        if (!enable) {
            ll min = INF;
            REP(i, v.size()) {
                ll a = S.size() - v[i].first;
                ll b = S.size() - v[i].second;
                min = std::min(min, b - a);
            }
            sum += min;
        }

        return sum;
    }
    if (N == 0)
        return -1;
    vector<string> nxt;
    ll n = N / 2;
    vector<ll> count(30, 0);
    for (const auto &s:S) {
        string ns0 = "", ns1 = "";
        REP(i, n) {
            ns0.push_back(s[i]);
            ns1.push_back(s[N - 1 - i]);
        }
      //  reverse(ns1.begin(), ns1.end());
        nxt.push_back(ns0);
        nxt.push_back(ns1);

        if (N % 2 == 1)
            count[s[n] - 'a']++;
    }
    ll ret = solve(nxt, level - 1);
    if (ret < 0)
        return -1;
    if (N % 2 == 1) {
        ll mx = 0;
        REP(i, count.size()) {
            mx = std::max(mx, count[i]);
        }
        ret += S.size() - mx;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    string S;
    cin >> S;
    vector<string> s;
    s.push_back(S);
    ll ans = solve(s, K);
    if (ans < 0)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}