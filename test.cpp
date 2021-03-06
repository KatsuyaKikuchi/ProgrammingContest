#include <iostream>
#include <vector>

using u64 = uint64_t;

template<typename T>
std::vector<T> divisor(T n) {
    std::vector<T> res1;
    std::vector<T> res2;

    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res1.push_back(i);
            if (i != n / i) {
                res2.push_back(n / i);
            }

        }
    }
    for (u64 i = res2.size(); i > 0; --i) {
        res1.push_back(res2[i - 1]);
    }
    return res1;
}

//*
u64 mul(u64 a, u64 b) { // a*b mod 2^61-1
    const u64 m30 = (1ull << 30) - 1;
    const u64 m31 = (1ull << 31) - 1;
    u64 au = a >> 31;
    u64 ad = a & m31;
    u64 bu = b >> 31;
    u64 bd = b & m31;
    u64 mid = ad * bu + au * bd;
    u64 midu = mid >> 30;
    u64 midd = mid & m30;
    u64 res = au * bu * 2 + midu + (midd << 31) + ad * bd;
    return res;
}

/*/
//*
constexpr u64 p = 998244353;

u64 mul(u64 a, u64 b) {
	return ((a % p) * (b % p)) % p;
}
//*/
u64 powmod(u64 base, u64 exp) { // base^exp mod MOD
    if (exp == 0) {
        return 1;
    }
    else if (exp % 2 == 0) {
        u64 t = powmod(base, exp / 2);
        return mul(t, t);
    }
    else {
        return mul(base, powmod(base, exp - 1));
    }
}

int main() {
    constexpr u64 p = (1ull << 61) - 1;
    auto div = divisor(p - 1);
    u64 primitiveRoot = 0;
    for (u64 i = 1; i < p; i++) {
        bool isPrimitiveRoot = true;
        for (auto &&v : div) {
            auto r = powmod(i, v);
            if (r == 1 && v != p - 1) {
                isPrimitiveRoot = false;
                break;
            }
        }
        if (isPrimitiveRoot) {
            std::cout << i << std::endl;
            //primitiveRoot = i;
            isPrimitiveRoot = false;
            // break;
        }
    }
    std::cout << primitiveRoot << std::endl;
    return 0;
}