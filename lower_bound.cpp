int my_lower_bound(vector<int> &a, int key) {
	int l = 0, r = a.size();
	int m;

	while (l < r) {
		m = (l + r) / 2;

		if (key <= a[m]) {
			r = m;
		}
		
		if (a[m] < key) {
			l = m + 1;
		}
	}
	return r;
}

