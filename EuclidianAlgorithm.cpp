long long EuclidianAlgorithm(long long a, long long b) {
    while(a * b) {
        if(a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return (a + b);
}

long long rec(long long a, long long b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if(a > b) {
        return (rec(a % b, b));
    } else {
        return rec(a, b % a);
    }

}
