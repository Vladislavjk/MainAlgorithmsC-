int BinarySearch(vector <int> &a, int k) {

    int m, l = 0, r = a.size() - 1;

    while(l <= r) {
        m = (l + r) / 2;
        if(a[m] == k)
            return m;
        if(a[m] > k)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
