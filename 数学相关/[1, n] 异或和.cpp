int xorSum(int n) {
    switch (n % 4) {
    case 0: return n; break;
    case 1: return 1; break;
    case 2: return n + 1; break;
    default: return 0; break;
    }
}
