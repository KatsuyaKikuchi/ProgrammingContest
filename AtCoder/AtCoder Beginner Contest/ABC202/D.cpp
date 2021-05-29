#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

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

ll comb(ll n, ll r) {
    if (r == 0)
        return 1;
    if (n < r)
        return 0;
    vector<ll> v;
    vector<ll> t;
    for (ll i = 1; i <= r; ++i) {
        t.push_back(i);
        v.push_back(n - i + 1);
    }
    ll ret = 1;
    REP(i, v.size()) {
        REP(j, t.size()) {
            ll g = gcd(v[i], t[j]);
            v[i] /= g;
            t[j] /= g;
        }
    }

    REP(i, v.size()) {
        ret *= v[i];
    }
    return ret;
}

ll Vals[70][70];

ll calc(ll a, ll b) {
    return Vals[a][b];
}

string solve(ll A, ll B, ll K) {
    string ans = "";
    ll N = A + B;
    REP(i, N) {
        if (A == 0 || B == 0) {
            REP(_, A) {
                ans.push_back('a');
            }
            REP(_, B) {
                ans.push_back('b');
            }
            break;
        }
        ll count = calc(B + A - 1, A - 1);
        //cout << count << " " << K << endl;
        if (count >= K) {
            ans.push_back('a');
            A--;
        }
        else {
            K -= count;
            ans.push_back('b');
            B--;
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
#if false
    ll A = 5, B = 5;
    string s = "aaaaabbbbb";
    ll index = 1;
    for (ll n = 0; n <= A + B + 5; n++) {
        for (ll r = 0; r <= n; ++r) {
            Vals[n][r] = comb(n, r);
        }
    }
    do {
        string t = solve(A, B, index);
        if (s != t) {
            cout << index << endl;
            cout << s << " " << t << endl;
            break;
        }
        index++;
    } while (next_permutation(s.begin(), s.end()));
    cout << "end" << endl;
#else
    ll A, B, K;
    cin >> A >> B >> K;
    for (ll n = 0; n <= A + B + 5; n++) {
        for (ll r = 0; r <= n; ++r) {
            Vals[n][r] = comb(n, r);
        }
    }

    cout << solve(A, B, K) << endl;
#endif
    return 0;
}