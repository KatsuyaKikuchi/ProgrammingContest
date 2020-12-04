#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

char win(char a, char b) {
    if (a == 'P') {
        if (b == 'S')
            return b;
        return a;
    }
    else if (a == 'S') {
        if (b == 'R')
            return b;
        return a;
    }
    else {
        if (b == 'P')
            return b;
        return a;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

#if false
    string T = S;
    if (T.length() % 2 == 1)
        T += S;
    //cout << S << endl;

    while (T.length() > 1) {
        string t;
        for (ll i = 0; i < T.length(); i += 2) {
            char a = T[2 * i];
            char b = T[2 * i + 1];
            t.push_back(win(a, b));
        }
        T = t;
    }
    if (K < 0) {
        ll p = pow(2LL, K);
        vector<char> v;
        REP(i, p) {
            v.push_back(S[i % N]);
        }
        while (p > 1) {
            vector<char> t;
            for (ll i = 0; i < p; i += 2) {
                t.push_back(win(v[2 * i], v[2 * i + 1]));
            }
            v = t;
            p /= 2;
        }
        cout << v[0] << endl;
        return 0;
    }

    {
        if (N % 2 == 1) {
            N += N;
            S += S;
        }
        ll p = 1;
        REP(i, K) {
            p = (p * 2LL) % N;
        }
        vector<char> v;
        REP(i, p) {
            v.push_back(S[i]);
        }
        while (v.size() > 1) {
            vector<char> t;
            for (ll i = 0; i < v.size(); i += 2) {
                t.push_back(win(v[2 * i], v[2 * i + 1]));
            }
            v = t;
        }
        if (v.size() == 0) {
            cout << T << endl;
        }
        else {
            cout << win(T[0], v[0]) << endl;
        }
    }
#endif
    string T = S;
    REP(_, K) {
        if (T.length() % 2 == 1)
            T += T;
        string t;
        //cout << T << endl;
        for (ll i = 0; i < T.length(); i += 2) {
            t.push_back(win(T[i], T[i + 1]));
        }
        T = t;
        //cout << t << " " << T << endl;
    }
    cout << T[0] << endl;
    return 0;
}