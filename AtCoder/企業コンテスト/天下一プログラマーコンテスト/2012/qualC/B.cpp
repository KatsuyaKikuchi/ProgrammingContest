#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char A[4] = {'S', 'H', 'D', 'C'};
char B[13] = {'1', 'A', 'J', 'Q', 'K', '2', '3', '4', '5', '6', '7', '8', '9'};
ll C[4];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    ll N = S.length();
    ll index = 0;
    vector<pll> v;
    while (index < N) {
        pll c(0, 0);
        char m = S[index];
        char n = S[index + 1];
        if (n == '1')
            index++;
        REP(i, 4) {
            if (m == A[i]) {
                c.first = i;
                break;
            }
        }
        REP(i, 13) {
            if (n == B[i]) {
                c.second = i;
                break;
            }
        }
        index += 2;
        v.push_back(c);
    }

    REP(i, v.size()) {
        pll t = v[i];
        if (t.second < 5)
            C[t.first]++;

        if (C[t.first] != 5)
            continue;

        string s = "";
        REP(j, i) {
            if (t.first == v[j].first && v[j].second < 5)
                continue;
            s.push_back(A[v[j].first]);
            s.push_back(B[v[j].second]);
            if (v[j].second == 0)
                s.push_back('0');
        }
        if (s.length() == 0)
            s.push_back('0');
        cout << s << endl;
        break;
    }
    return 0;
}