// n * 2
int mul2(int n) {
    return n << 1;
}

// n / 2
int div2(int n) {
    return n >> 1;
}

// n 是否为奇数
bool isOdd(int n) {
    return n & 1;
}

// 交换 a b
void swap(int &a, int &b) {
    a ^= b ^= a ^= b;
}

// 2 的 n 次幂
int pow2(int n) {
    return 1 << n;
}

// m 对 2 的幂取模，n 为 2 的幂
int getMod(int m, int n) {
	return m & (n - 1);
}

// 判断 n 是否是 2 的幂次
bool isFactorialOf2(int n) {
    return n > 0 ? (n & (n - 1)) == 0 : false;
}

// 获取 n 的 idx 位
int getBit(int n, int idx) {
    return (n >> (idx - 1)) & 1;
}

// 将 n 的 idx 位设定为 1
int setBitTo1(int n, int idx) {
    return n | (1 << (idx - 1));
}

// 将 n 的 idx 位设定为 0
int setBitTo0(int n, int idx) {
	return n & ~(1 << (idx - 1));
}
