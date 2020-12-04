#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W, N;
    cin >> H >> W >> N;
    pll s;
    cin >> s.first >> s.second;
    string S, T;
    cin >> S >> T;

    bool out = false;
    {
        ll x = s.second;
        vector<ll> v(N);
        REP(i, N) {
            if (S[i] == 'R')
                x++;
            v[i] = x;
        }

        ll l = 0;
        ll d = 0;
        REP(i, N) {
            if (S[i] == 'L')
                l++;
            else if (S[i] == 'R')
                l = 0;
            if (T[i] == 'L')
                d++;

            if (v[i] - d > W || v[i] - d - l <= 0)
                out = true;
        }
    }
    {
        ll x = s.second;
        vector<ll> v(N);
        REP(i, N) {
            if (S[i] == 'L')
                x--;
            v[i] = x;
        }

        ll r = 0;
        ll d = 0;
        REP(i, N) {
            if (S[i] == 'R')
                r++;
            else if (S[i] == 'L')
                r = 0;
            if (T[i] == 'R')
                d++;

            if (v[i] + d <= 0 || v[i] - d + r > W)
                out = true;
        }
    }

    {
        ll x = s.first;
        vector<ll> v(N);
        REP(i, N) {
            if (S[i] == 'D')
                x++;
            v[i] = x;
        }

        ll u = 0;
        ll d = 0;
        REP(i, N) {
            if (S[i] == 'U')
                u++;
            else if (S[i] == 'D')
                u = 0;
            if (T[i] == 'U')
                d++;

            if (v[i] - d > H || v[i] - d - u <= 0)
                out = true;
        }
    }
    {
        ll x = s.first;
        vector<ll> v(N);
        REP(i, N) {
            if (S[i] == 'U')
                x--;
            v[i] = x;
        }

        ll u = 0;
        ll d = 0;
        REP(i, N) {
            if (S[i] == 'D')
                u++;
            else if (S[i] == 'U')
                u = 0;
            if (T[i] == 'D')
                d++;

            if (v[i] + d <= 0 || v[i] - d + u > H)
                out = true;
        }
    }

    if (out)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}