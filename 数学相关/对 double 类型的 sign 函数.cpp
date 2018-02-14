// 虽然并不难写但是留一个备份还是好的
// 有时候不加个这个就是会玄学 WA（笑

#define EPS 0.000001

int sign(double x) {
    if (fabs(x) < EPS) return 0;
    return x < 0 ? -1 : 1;
} 