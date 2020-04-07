class List {
public:
	void push_back() {}
	void push_front() {}
	void pop_back() {}
	void pop_front() {}
};

class Queqe : private List {
public:
	void push() {
		push_back();
	}
	void pop() {
		pop_front();
	}
};

bool isPalindrome(vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != a[a.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

int find(string s, string subs) {
	int pos = -1;

	for (int i = 0; i <= s.size() - subs.size(); i++) {
		bool flag = true;
		for (int j = 0; j < subs.size(); j++) {
			if (subs[j] != s[i + j]) {
				flag = false;
				break;
			}
		}
		if (flag == true) {
			pos = i;
			break;
		}
	}
	return pos;
}
