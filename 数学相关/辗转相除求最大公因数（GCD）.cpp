int gcd(int a, int b) {
	if (b == 0) { return a; }
	return gcd(b, a % b);
}

double gcd(double a, double b) {
	if (fabs(a) < EPS) return b;
	if (fabs(b) < EPS) return a;
	return gcd(b, fmod(a, b));
}
