long long Fibonacci(int n) {
	long long k = 0, m = 1, sum = 0;

	for (int i = 2; i <= n; i++)
	{
		sum = k + m;
		k = m;
		m = sum;
	}

	if (n < 2)
		cout << n;
	else
		cout << sum;
}
