#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Data {
    ll a = 0;
    ll b = 0;
};

Data A[200005];

Data parse(const string &s) {
    Data d;
    d.a = 0;
    ll n = s.length() - 1;
    REP(i, s.length()) {
        if (s[i] == '.') {
            n = i;
            break;
        }
        ll x = s[i] - '0';
        d.a = d.a * 10LL + x;
    }
    d.b = 0;
    FOR(i, s.length(), n + 1) {
        d.b = d.b * 10LL + s[i] - '0';
    }

    while (d.b > 0 && d.b % 10 == 0) {
        d.b /= 10;
    }

    return d;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, N) {
        string s;
        cin >> s;
        A[i] = parse(s);
    }

    REP(i, N) {
        cout << A[i].a << "," << A[i].b << endl;
    }
    return 0;
}