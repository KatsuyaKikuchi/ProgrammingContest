#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

string solve(string &S) {
    ll N = S.length();
    ll sym = 0;
    string pre = "";
    REP(i, N / 2) {
        if (S[i] != S[N - 1 - i])
            break;
        sym++;
        pre.push_back(S[i]);
    }

    string a = "", b = "";
    {
        ll max = 0;
        FOR(i, N - sym, sym) {
            bool exist = true;
            FOR(j, i + 1, sym) {
                if (S[j] != S[i - (j - sym)]) {
                    exist = false;
                    break;
                }
            }
            if (exist)
                max = std::max(max, i + 1);
        }
        FOR(i, max, sym) {
            a.push_back(S[i]);
        }

    }
    {
        ll min = N;
        for (ll i = N - 1 - sym; i >= sym; --i) {
            bool exist = true;
            for (ll j = 0; j <= N - 1 - sym - i; ++j) {
                if (S[i + j] != S[N - 1 - sym - j]) {
                    exist = false;
                    break;
                }
            }
            if (exist)
                min = std::min(min, i);
        }
        for (ll i = min; i < N - sym; ++i) {
            b.push_back(S[i]);
        }
    }

    string ret = pre;
    if (a.size() > b.size())
        ret += a;
    else
        ret += b;
    reverse(pre.begin(), pre.end());
    ret += pre;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    REP(_, Q) {
        string S;
        cin >> S;
        cout << solve(S) << endl;
    }
    return 0;
}