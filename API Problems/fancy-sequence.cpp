class Fancy {
private:
    const long long MOD = 1e9 + 7;
    vector<long long> v;
    long long a = 1;
    long long b = 0;

    // Fast exponentiation to compute (base^exp) % MOD
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    // Modular multiplicative inverse using Fermat's Little Theorem
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {
        
    }
    
    void append(int val) {
        // Roll back current linear transform to store base representation x0
        long long x0 = (val - b + MOD) % MOD;
        x0 = (x0 * modInverse(a)) % MOD;
        v.push_back(x0);
    }
    
    void addAll(int inc) {
        b = (b + inc) % MOD;
    }
    
    void multAll(int m) {
        a = (a * m) % MOD;
        b = (b * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= v.size()) return -1;
        return (a * v[idx] + b) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */