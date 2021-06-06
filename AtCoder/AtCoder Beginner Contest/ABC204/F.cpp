#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pll;

#define FOR(i, n, m) for(ll (i)=(m);(i)<(n);++(i))
#define REP(i, n) FOR(i,n,0)
#define OF64 std::setprecision(40)

const ll MOD = 998244353;
const ll INF = (ll) 1e15;

class Matrix {
public:
    Matrix(int r, int c, long long int id = 0)
            : mR(r), mC(c) {
        init(id);
    }

    void init(long long int id) {
        mMat.resize(mR, vector<long long int>(mC, id));
    }

    static Matrix Identity(int r, int c) {
        Matrix mat(r, c);
        for (int i = 0; i < std::min(r, c); ++i) {
            mat[i][i] = 1;
        }
        return mat;
    };

    void draw() {
        for (ll r = 0; r < mR; ++r) {
            for (ll c = 0; c < mC; c++) {
                cout << mMat[r][c] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &obj) {
        assert(this->mR == obj.mR);
        assert(this->mC == obj.mC);
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = this->mMat[r][c] + obj.mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator-(const Matrix &obj) {
        assert(this->mR == obj.mR);
        assert(this->mC == obj.mC);
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = this->mMat[r][c] - obj.mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator-() {
        Matrix ret(this->mR, this->mC);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                ret.mMat[r][c] = -this->mMat[r][c];
            }
        }
        return ret;
    }

    Matrix operator*(const Matrix &obj) {
        assert(this->mC == obj.mR);
        Matrix ret(this->mR, obj.mC);
        for (int r = 0; r < ret.mR; ++r) {
            for (int c = 0; c < ret.mC; ++c) {
                for (int i = 0; i < this->mC; ++i) {
                    ret.mMat[r][c] += this->mMat[r][i] * obj.mMat[i][c] % MOD;
                }
                ret.mMat[r][c] %= MOD;
            }
        }
        return ret;
    }

    Matrix &operator=(const Matrix &obj) {
        this->mR = obj.mR;
        this->mC = obj.mC;
        init(0);
        for (int r = 0; r < this->mR; ++r) {
            for (int c = 0; c < this->mC; ++c) {
                this->mMat[r][c] = obj.mMat[r][c];
            }
        }
        return *this;
    }

    vector<long long int> &operator[](int r) {
        assert(r < mR);
        return mMat[r];
    }

    int mR;
    int mC;
    vector<vector<long long int>> mMat;
};

ll P[7] = {1, 1, 2, 3, 5, 8, 13};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    ll b = pow(2LL, H);
    Matrix mat(b, b);

    REP(i, b) {
        REP(j, b) {
            if ((i & j) > 0)
                continue;
            ll p = (i | j);
            vector<ll> v;
            ll count = 0;
            REP(k, H) {
                if ((p >> k) & 1) {
                    if (count > 0)
                        v.push_back(count);
                    count = 0;
                }
                else {
                    count++;
                }
            }
            if (count > 0)
                v.push_back(count);

            ll x = 1;
            REP(k, v.size()) {
                x *= P[v[k]];
            }
            mat[i][j] = x % MOD;
        }
    }

    Matrix m = Matrix::Identity(b, b);
    while (W > 0) {
        if (W & 1) {
            m = m * mat;
        }
        W /= 2;
        mat = mat * mat;
    }

    Matrix v(b, 1);
    v[0][0] = 1;
    auto ans = m * v;
    cout << ans[0][0] << endl;
    return 0;
}