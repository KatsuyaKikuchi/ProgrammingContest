#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(10)
//#define TEST

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;
const ll DIV = 5;

ll sign[2] = {1, -1};

pll testCenter;

string test(ll x, ll y) {
    cout << x << " " << y << endl;
    if (x == testCenter.first && y == testCenter.second) {
        cout << "CENTER" << endl;
        return "CENTER";
    }
    ll d = pow(testCenter.first - x, 2) + pow(testCenter.second - y, 2);
    if (d <= (ll) (5e8) * (ll) (5e8)) {
        cout << "HIT" << endl;
        return "HIT";
    }

    cout << "MISS" << endl;
    return "MISS";
}

pll calc() {
    ll d = 1e9 / DIV;
    REP(i, DIV) {
        REP(j, DIV) {
            REP(n, 2) {
                REP(m, 2) {
                    ll x = sign[n] * (d / 2 + d * i);
                    ll y = sign[m] * (d / 2 + d * j);

#ifdef TEST
                    string s = test(x, y);
#else
                    cout << x << " " << y << endl;
                    string s;
                    cin >> s;
#endif
                    if (s == "MISS")
                        continue;

                    return pll(x, y);
                }
            }
        }
    }
    return pll(0, 0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll Q, A, B;
    cin >> Q >> A >> B;
    REP(_, Q) {
#ifdef TEST
        cin >> testCenter.first >> testCenter.second;
#endif

        pll hit = calc();
        ll left = hit.first, right = hit.first;
        {
            ll ng = -(1e9 + 1);
            while (abs(left - ng) > 1) {
                ll mid = (left + ng) / 2;
#ifdef TEST
                string s = test(mid, hit.second);
#else
                cout << mid << " " << hit.second << endl;
                string s;
                cin >> s;
#endif
                if (s == "MISS")
                    ng = mid;
                else
                    left = mid;
            }
        }
        {
            ll ng = 1e9 + 1;
            while (abs(right - ng) > 1) {
                ll mid = (right + ng) / 2;
#ifdef TEST
                string s = test(mid, hit.second);
#else
                cout << mid << " " << hit.second << endl;
                string s;
                cin >> s;
#endif
                if (s == "MISS")
                    ng = mid;
                else
                    right = mid;
            }
        }
        ll bottom = hit.second, top = hit.second;
        {
            ll ng = -(1e9 + 1);
            while (abs(bottom - ng) > 1) {
                ll mid = (bottom + ng) / 2;
#ifdef TEST
                string s = test(hit.first, mid);
#else
                cout << hit.first << " " << mid << endl;
                string s;
                cin >> s;
#endif
                if (s == "MISS")
                    ng = mid;
                else
                    bottom = mid;
            }
        }
        {
            ll ng = 1e9 + 1;
            while (abs(top - ng) > 1) {
                ll mid = (top + ng) / 2;
#ifdef TEST
                string s = test(hit.first, mid);
#else
                cout << hit.first << " " << mid << endl;
                string s;
                cin >> s;
#endif
                if (s == "MISS")
                    ng = mid;
                else
                    top = mid;
            }
        }

        ll x = (left + right) / 2;
        ll y = (top + bottom) / 2;
#ifdef TEST
        string s = test(x, y);
#else
        cout << x << " " << y << endl;
        string s;
        cin >> s;
#endif
        if (s != "CENTER")
            break;
    }
    return 0;
}