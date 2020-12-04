#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;


string solve2(string &S) {
    vector<ll> R(S.length(), 0);
    int i = 0, j = 0;
    while (i < S.size()) {
        while (i - j >= 0 && i + j < S.size() && S[i - j] == S[i + j])
            ++j;
        R[i] = j;
        int k = 1;
        while (i - k >= 0 && i + k < S.size() && k + R[i - k] < j)
            R[i + k] = R[i - k], ++k;
        i += k;
        j -= k;
    }

    //! preb
    ll pre = 0;
    REP(i, S.length()) {
        if (R[i] == i + 1)
            pre = i + 1;
    }
    ll suf = 0;
    REP(i, S.length()) {
        if (R[S.length() - 1 - i] == i + 1)
            suf = i + 1;
    }
    string p = "";
    if (pre > suf) {
        REP(i, pre * 2 - 1) {
            if (S[i] == '$')
                continue;
            p.push_back(S[i]);
        }
    }
    else {
        REP(i, suf * 2 - 1) {
            if (S[S.length() - 1 - i] == '$')
                continue;
            p.push_back(S[S.length() - 1 - i]);
        }
    }
    return p;
}

string solve(string &S) {
    ll N = S.length();
    string pre = "";
    REP(i, N / 2) {
        if (S[i] != S[N - 1 - i])
            break;
        pre.push_back(S[i]);
    }
    string s = "";
    FOR(i, N - pre.size(), pre.size()) {
        s.push_back(S[i]);
    }

    string ret = pre;
    string t0 = solve2(s);
    string t1 = "";
    REP(i, s.length()) {
        if (i > 0)
            t1.push_back('$');
        t1.push_back(s[i]);
    }

    string t2 = solve2(t1);
    if (t0.size() > t2.size())
        ret += t0;
    else
        ret += t2;
    reverse(pre.begin(), pre.end());
    return ret + pre;
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