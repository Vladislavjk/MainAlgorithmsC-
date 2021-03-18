long long deg (long long a, int n) {
	long long res = 1;
	while (n) {
		if (n & 1)
			res = res * a % p;
		a = a * a % p;
		n >>= 1;
	}
	return res;
}
