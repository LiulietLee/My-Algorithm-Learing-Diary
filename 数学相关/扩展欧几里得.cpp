/* 可以求 ax + by = gcd(a, b) 中的 x 和 y，也可以用来求逆元 */

#include <iostream>
#include <cstdio>

int exGcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int gcd = exGcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - (a / b) * y;
    return gcd;
}

int main() {
    int a, b, x, y;
    scanf("%d%d%d%d", &a, &b, &x, &y);
    exGcd(a, b, x, y); // 此时 x 为 a 的逆元
    return 0;
}