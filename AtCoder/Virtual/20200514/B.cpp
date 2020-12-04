#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll P[15];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B;
    cin >> A >> B;
    REP(i, A) {
        ll n;
        cin >> n;
        P[(10 + n - 1) % 10] = 1;
    }
    REP(i, B) {
        ll n;
        cin >> n;
        P[(10 + n - 1) % 10] = 2;
    }
    ll index = 0;
    vector<string> v;
    REP(i, 4) {
        string s = "";
        REP(j, 3 - i) {
            s.push_back(' ');
        }
        REP(j, i + 1) {
            if (P[index] == 0)
                s.push_back('x');
            else if (P[index] == 1)
                s.push_back('.');
            else if (P[index] == 2)
                s.push_back('o');
            s.push_back(' ');
            index++;
        }
        v.push_back(s);
    }
    reverse(v.begin(), v.end());
    REP(i, v.size()) {
        cout << v[i] << endl;
    }


    return 0;
}