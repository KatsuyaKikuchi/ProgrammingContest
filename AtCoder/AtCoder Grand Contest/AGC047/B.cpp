#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll mod[] = {999999937LL, 1000000007LL}, base = 9973;
const ll INF = (ll) 1e15;

unordered_map<ll, int> mp[26];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<string> S(N);
    vector<bool> len(1000000, false);
    REP(i, N) {
        cin >> S[i];
    }
    sort(S.begin(), S.end(), [](string &a, string &b) { return a.length() < b.length(); });
    ll ans = 0;
    REP(i, N) {
        vector<ll> num(26, 0);
        REP(j, S[i].length()) {
            num[S[i][j] - 'a']++;
        }
        pll hash(0, 0);
        pll b(1, 1);
        for (ll j = S[i].length() - 1; j >= 0; --j) {
            if (len[S[i].length() - 1 - j]) {
                ll h = hash.first * hash.second;
                REP(k, 26) {
                    if (num[k] > 0)
                        ans += mp[k][h];
                }
            }
            if (j > 0) {
                hash.first = (hash.first + (S[i][j] - 'a' + 1) * b.first) % mod[0];
                hash.second = (hash.second + (S[i][j] - 'a' + 1) * b.second) % mod[1];
                b.first = (b.first * base) % mod[0];
                b.second = (b.second * base) % mod[1];
                num[S[i][j] - 'a']--;
            }
        }
        mp[S[i][0] - 'a'][hash.first * hash.second]++;
        len[S[i].length() - 1] = true;
    }
    cout << ans << endl;
    return 0;
}