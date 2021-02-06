#include <bits/stdc++.h>

using namespace std;

typedef __int128 ll;
//typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

ll parse(string t) {
    ll ret = 0;
    ll idx = 4;
    bool f = false;
    REP(i, t.size()) {
        if (t[i] == '.') {
            f = true;
            continue;
        }
        if (f)
            idx--;
        ret = ret * 10LL + t[i] - '0';
    }
    while (idx-- > 0) {
        ret *= 10LL;
    }
    return ret;
}

ll mysqrt(ll d) {
    ll ng = 200000000LL, ok = 0;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (mid * mid <= d)
            ok = mid;
        else
            ng = mid;
    }
    return ok;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string tX, tY, tR;
    cin >> tX >> tY >> tR;
    ll X = parse(tX);
    ll Y = parse(tY);
    ll R = parse(tR);
    //cout << X << " " << Y << " " << R << endl;

    ll height = (Y + R);
    if (height > 0 || height % 10000LL == 0) {
        height /= 10000LL;
    }
    else {
        height /= 10000LL;
        height--;
    };
    ll bottom = (Y - R);
    if (bottom < 0 || bottom % 10000LL == 0) {
        bottom /= 10000LL;
    }
    else {
        bottom /= 10000LL;
        bottom++;
    }
  //  cout << height << " " << bottom << endl;

    long long int ans = 0;
    for (ll y = bottom; y <= height; ++y) {
        ll right = X - 1;
        {
            ll ng = X + R + 1;
            while (abs(ng - right) > 1) {
                ll mid = (ng + right) / 2;
                ll t = (X - mid) * (X - mid) + (Y - y * 10000LL) * (Y - y * 10000LL);
                if (t <= R * R)
                    right = mid;
                else
                    ng = mid;
            }
        }
        ll left = X + 1;
        {
            ll ng = X - R - 1;
            while (abs(ng - left) > 1) {
                ll mid = (ng + left) / 2;
                ll t = (X - mid) * (X - mid) + (Y - y * 10000LL) * (Y - y * 10000LL);
                if (t <= R * R)
                    left = mid;
                else
                    ng = mid;
            }
        }
        if (left > right)
            continue;
        if (right >= 0 || right % 10000LL == 0) {
            right /= 10000LL;
        }
        else {
            right /= 10000LL;
            right--;
        }
        if (left <= 0 || left % 10000LL == 0) {
            left /= 10000LL;
        }
        else {
            left /= 10000LL;
            left++;
        }
        ans += (right - left + 1);
#if false
        long double x0 = sqrt(d) + X;
        long double x1 = -sqrt(d) + X;
        ll left = (ll) ceil(x1);
        ll right = (ll) floor(x0);
        //cout << left << " " << right << endl;
        if (left > right)
            continue;
        ans += right - left + 1;
#endif
    }
    cout << ans << endl;
    return 0;
}