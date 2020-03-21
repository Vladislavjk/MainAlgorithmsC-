bool areAnagrams(string a, string b) {
    multiset<char> rA, rB;
    for(int i = 0; i < a.size(); i++) {
        rA.insert(a[i]);
    }

    for (int j = 0; j < b.size(); ++j) {
        rB.insert(b[j]);
    }
    return rA == rB;
}

int maxSequenceLen(string s) {  //  f([1,1,0,1,0,1,1,1]) = 3
    int current = 0, best = 0;
    for (int i = 0; i < s.size(); ++i) {
        if(s[i] == '1') {
            current++;
            best = max(best, current);
        } else {
            current = 0;
        }
    }
    return best;
}
