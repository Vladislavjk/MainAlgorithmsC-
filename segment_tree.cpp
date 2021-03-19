#include <bits/stdc++.h>
using namespace std;

void buildTree(vector<int> &tree, const vector<int> &data, int v, int l, int r) {
    if(l == r) {
        tree[v] = data[l];
        return;
    }
    int mid = (l + r) / 2;
    buildTree(tree, data, 2 * v + 1, l, mid);
    buildTree(tree, data, 2 * v + 2, mid + 1, r);
    tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
}

int rsq(const vector<int> &tree, int v, int tl, int tr, int l, int r) {
    if(tl > r || tr < l) return 0; // выход из рекурсии

    if(tl >= l && tr <= r) {  //отрезок полностью входит в запрос
        return tree[v];
    }

    int mid = (tl + tr) / 2;
    return rsq(tree, 2 * v + 1, tl, mid, l, r) + rsq(tree, 2 * v + 2, mid + 1, tr, l, r);
}

int main() {
    vector<int> data = {1, 2, 3, 4, 5};
    vector<int> tree(2 * data.size());
    buildTree(tree, data, 0, 0, data.size() - 1);

    for(auto var : tree) {
        cout << var << ' ';
    }

    cout << rsq(tree, 0, 0, data.size() - 1, 2, 4);
}
