#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

typedef ll ll;
#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

vector<string> split(string S) {
    vector<string> ret;
    string s;
    REP(i, S.length()) {
        if (S[i] == '/') {
            ret.push_back(s);
            s.clear();
            continue;
        }
        s.push_back(S[i]);
    }
    if (s.length() > 0)
        ret.push_back(s);
    return ret;
}

ll str2long(string s) {
    ll ret = 0;
    REP(i, s.length()) {
        ret = ret * 10LL + s[i] - '0';
    }
    return ret;
}

ll gcd(ll a, ll b) {
    if (a < b)
        swap(a, b);
    ll c = a % b;
    if (c == 0)
        return b;
    return gcd(b, c);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    auto v = split(S);
    ll X = 2LL * str2long(v[0]);
    ll Y = str2long(v[1]);
    ll g = gcd(X, Y);
    X /= g;
    Y /= g;
    if (Y > X) {
        cout << "Impossible" << endl;
        return 0;
    }
    ll k = ((X - Y) / (Y * Y));
    if ((X - Y) % (Y * Y) == 0)
        k++;
    ll t = Y * (k * Y + 1) - X;
    vector<pll> ans;
    while (true) {
        ll N = Y * k;
        ll M = k * (Y * (Y * k + 1) - X);
        k++;
        if (2LL * N < M)
            break;
        if (M % 2 == 1) {
            continue;
        }
        if (N > 0 && M > 0)
            ans.push_back(pll(N, M / 2));
    }
    sort(ans.begin(), ans.end(), [](pll a, pll b) { return a.first < b.first; });
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    if (ans.size() == 0) {
        cout << "Impossible" << endl;
        return 0;
    }
    REP(i, ans.size()) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}