#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

void reverse(string &s) {
    ll n = s.length();
    REP(i, (n + 1) / 2) {
        swap(s[i], s[n - 1 - i]);
    }
}

void flip(string &s) {
    ll n = s.length();
    REP(i, n) {
        ll m = s[i] - '0';
        s[i] = (char) (((m + 1) % 2) + '0');
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T, B;
    cin >> T >> B;
    REP(_, T) {
        string S = "";
        REP(i, B) {
            S.push_back('0');
        }

        ll same = -1, diff = -1;
        ll num = 1;
        ll index = 0;
        REP(j, 5) {
            {
                cout << j + 1 << endl;
                char ret;
                cin >> ret;
                S[j] = ret;
                num++;
            }
            {
                cout << B - j << endl;
                char ret;
                cin >> ret;
                S[B - 1 - j] = ret;
                num++;
            }

            if (S[j] == S[B - 1 - j])
                same = j;
            if (S[j] != S[B - 1 - j])
                diff = j;

            index = j + 1;
            if (index > B - 1 - index)
                break;
        }

        while (num <= 150 && index <= B - 1 - index) {
            if (num % 10 == 1) {
                bool flp = false, rev = false;
                if (same >= 0) {
                    cout << same + 1 << endl;
                    char ret;
                    cin >> ret;
                    if (S[same] != ret)
                        flp = true;
                }
                else {
                    cout << 1 << endl;
                    char ret;
                    cin >> ret;
                }
                num++;
                if (diff >= 0) {
                    cout << diff + 1 << endl;
                    char ret;
                    cin >> ret;
                    if (S[diff] != ret)
                        rev = true;
                }
                else {
                    cout << 1 << endl;
                    char ret;
                    cin >> ret;
                }
                num++;

                if (flp && rev)
                    flip(S);
                if (!flp && rev)
                    reverse(S);
                if (flp && !rev) {
                    flip(S);
                    reverse(S);
                }
                continue;
            }

            {
                cout << index + 1 << endl;
                char ret;
                cin >> ret;
                S[index] = ret;
                num++;
            }
            {
                cout << B - index << endl;
                char ret;
                cin >> ret;
                S[B - 1 - index] = ret;
                num++;
            }
            if (S[index] == S[B - 1 - index])
                same = index;
            if (S[index] != S[B - 1 - index])
                diff = index;
            index++;
        }

        cout << S << endl;
        string ans;
        cin >> ans;
        if (ans == "N")
            break;
    }
    return 0;
}