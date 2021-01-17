#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll MAX = 10;

ll parse(string s) {
    ll cnt = MAX;
    REP(i, s.length() - 1) {
        if (s[i] == '.') {
            cnt--;
            swap(s[i], s[i + 1]);
        }
        if (cnt == 0)
            break;
    }
    ll ret = 0;
    REP(i, s.length()) {
        if (s[i] == '.')
            break;
        ret = ret * 10LL + s[i] - '0';
    }
    if (cnt < MAX) {
        for (ll i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '.')
                break;
            if (s[i] != '0')
                return 0;
        }
    }
    while (cnt-- > 0) {
        ret *= 10LL;
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
    ll N;
    cin >> N;
    vector<ll> v;
    REP(i, N) {
        string s;
        cin >> s;
        ll n = parse(s);
        if (n > 0)
            v.push_back(n);
    }
    vector<vector<ll>> S(MAX * 2 + 1, vector<ll>(MAX * 2 + 1, 0));
    ll ans = 0;
    REP(i, v.size()) {
        ll a = 0, b = 0;
        ll x = v[i];
        while (x % 2 == 0) {
            a++;
            x /= 2;
        }
        while (x % 5 == 0) {
            b++;
            x /= 5;
        }
        a = std::min(a, MAX * 2);
        b = std::min(b, MAX * 2);
        ans += S[MAX * 2 - a][MAX * 2 - b];
        for (ll j = a; j >= 0; --j) {
            for (ll k = b; k >= 0; --k) {
                S[j][k]++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}