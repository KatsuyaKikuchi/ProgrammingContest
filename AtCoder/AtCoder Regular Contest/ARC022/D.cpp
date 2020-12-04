#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 1000000007;
const ll INF = (ll) 1e15;

struct Vec2 {
    Vec2() {}

    Vec2(double x, double y) :
            x(x), y(y) {}

    double x;
    double y;

    Vec2 operator+(const Vec2 &a) const {
        return Vec2(this->x + a.x, this->y + a.y);
    }

    Vec2 operator-(const Vec2 &a) const {
        return Vec2(this->x - a.x, this->y - a.y);
    }

    template<typename T>
    Vec2 operator/(T n) const {
        return Vec2(this->x / n, this->y / n);
    }

    double length() {
        return sqrt(x * x + y * y);
    }

    friend ostream &operator<<(ostream &os, const Vec2 &v);
};

ostream &operator<<(ostream &os, const Vec2 &v) {
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

Vec2 A[100005];
Vec2 B[100005];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    Vec2 c0(0, 0), c1(0, 0);
    REP(i, N) {
        cin >> A[i].x >> A[i].y;
        c0 = c0 + A[i];
    }
    REP(i, N) {
        cin >> B[i].x >> B[i].y;
        c1 = c1 + B[i];
    }

    c0 = c0 / N;
    c1 = c1 / N;
    Vec2 t0(c0.x, c0.y), t1(c1.x, c1.y);
    REP(i, N) {
        if ((t0 - c0).length() < (A[i] - c0).length()) {
            t0 = A[i];
        }
        if ((t1 - c1).length() < (B[i] - c1).length()) {
            t1 = B[i];
        }
    }

    double P = (t1 - c1).length() / (t0 - c0).length();
    cout << OF64 << P << endl;
    return 0;
}