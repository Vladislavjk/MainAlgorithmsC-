class Tree {

    struct node {
        int data;
        int height = 0;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if (t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t)
    {
        if (t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if (x < t->data)
            t->left = insert(x, t->left);
        else if (x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if (t == nullptr)
            return nullptr;
        else if (t->left == nullptr)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if (t == nullptr)
            return nullptr;
        else if (t->right == nullptr)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if (t == nullptr)
            return nullptr;
        else if (x < t->data)
            t->left = remove(x, t->left);
        else if (x > t->data)
            t->right = remove(x, t->right);
        else if (t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if (t->left == nullptr)
                t = t->right;
            else if (t->right == nullptr)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void direct(node* t, ofstream& fout) {
        fout << t->data << endl;
        if (t->left != nullptr) {
            direct(t->left, fout);
        }
        if (t->right != nullptr) {
            direct(t->right, fout);
        }
    }

    node* find(node* t, int x) {
        if (t == nullptr)
            return nullptr;
        else if (x < t->data)
            return find(t->left, x);
        else if (x > t->data)
            return find(t->right, x);
        else
            return t;
    }

    void getHeights(node* t) { // получаем высоту каждой ноды обратным обходом
        //высота = 0 по умолчанию(как бы начальное значение(типо выхода из рекурсии))
        if (t != nullptr) {
            getHeights(t->left);  // получаем самое левое t
            getHeights(t->right); // потом еще до конца идем вправо(если можем)
            if (t->left == nullptr && t->right != nullptr) {
                t->height = t->right->height + 1;
            }
            if (t->left != nullptr && t->right == nullptr) {
                t->height = t->left->height + 1;
            }
            if (t->left != nullptr && t->right != nullptr) {
                t->height = maxx(t->left->height, t->right->height) + 1;
            }
        }
    }

public:
    Tree() {
        root = nullptr;
    }

    ~Tree() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void print(ofstream& fout) {
        direct(root, fout);
    }

    void search(int x) {
        root = find(root, x);
    }

    int getRootData() {
        return root->data;
    }
};
