#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Card {
    char M;
    ll N = 0;
};
char M[4] = {'S', 'H', 'D', 'C'};

string i2c(ll n) {
    string ret = "";
    switch (n) {
        case 14:
            ret = "A";
            break;
        case 13:
            ret = "K";
            break;
        case 12:
            ret = "Q";
            break;
        case 11:
            ret = "J";
            break;
        default:
            while (n > 0) {
                ret.push_back('0' + n % 10);
                n /= 10;
            }
            reverse(ret.begin(), ret.end());
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    cin >> S;
    vector<Card> C;
    REP(i, S.length()) {
        bool e = false;
        REP(j, 4) {
            if (S[i] == M[j]) {
                C.push_back(Card{S[i], 0});
                e = true;
            }
        }
        if (e)
            continue;
        ll n = C[C.size() - 1].N;
        if (S[i] == 'J')
            n = 11;
        else if (S[i] == 'Q')
            n = 12;
        else if (S[i] == 'K')
            n = 13;
        else if (S[i] == 'A')
            n = 14;
        else
            n = n * 10 + S[i] - '0';

        C[C.size() - 1].N = n;
    }
    vector<Card> trash(C.size() + 1);
    REP(i, 4) {
        ll n = 0;
        vector<Card> t;
        REP(j, C.size()) {
            if (C[j].M != M[i] || C[j].N < 10)
                t.push_back(C[j]);
            else
                n++;
            if (n == 5)
                break;
        }
        if (t.size() < trash.size()) {
            trash = t;
        }
    }

    if (trash.size() == 0) {
        cout << 0 << endl;
    }
    else {
        REP(i, trash.size()) {
            cout << trash[i].M << i2c(trash[i].N);
        }
        cout << endl;
    }
    return 0;
}