long long gcd(long long a, long long b) {
    while(a * b) {
        if(a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return (a + b);
}

long long gcdRec(long long a, long long b) {
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if(a > b) {
        return (gcdRec(a % b, b));
    } else {
        return gcdRec(a, b % a);
    }

}
