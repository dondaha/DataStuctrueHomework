#include <iostream>

using namespace std;

template<class elemType>
class binarySearchTree {
private:
    struct node {
        elemType id;
        node *left;
        node *right;

        node(int n, node *l = nullptr, node *r = nullptr) : id(n), left(l), right(r) {}
    };

    node *root;

    void insert(const elemType &x, node *&t) {
        // 如果树为空
        if (!t) {
            t = new node(x, nullptr, nullptr);
            t->id = x;
            return;
        }
        // 如果已存在
        if (t->id == x) return;
        if (t->id > x) {
            insert(x, t->left);
        } else {
            insert(x, t->right);
        }
    }

    elemType search_father(const elemType &x, node *r) {
        if (!r || root->id == x) return -1;
        if (x < r->id) {
            if (r->left->id == x) return r->id;
            else search_father(x, r->left);
        } else {
            if (r->right->id == x) return r->id;
            else search_father(x, r->right);
        }
    }

    void clear_all(node *r) {
        if (r->left) clear_all(r->left);
        if (r->right) clear_all(r->right);
        delete r;
        r = nullptr;
    }

public:
    void insert(const elemType &x) {
        return insert(x, root);
    }

    elemType search_father(const elemType &x) {
        return search_father(x, root);
    }

    binarySearchTree() { root = nullptr; }

    ~binarySearchTree() {
        clear_all(root);
    } // 析构函数怎么写啊啊啊
};

int main() {
    int N;
    cin >> N;
    binarySearchTree<int> tree;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        tree.insert(x);
        cout << tree.search_father(x) << endl;
    }
    return 0;
}