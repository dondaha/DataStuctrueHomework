#include <iostream>

using namespace std;

struct node {
    node *l, *r;
    int id;

    node() {
        l = r = nullptr;
        id = -1;
    }
};

int f(const int *num, int N, int k);

node *f1(node *a, int *mid, int *post, int left, int right, int root, int N);

node *f2(node *a, int *mid, int *post, int left, int right, int N);

// 查找数据在数组中的下标
int f(const int *num, int N, int k) {
    for (int i = 0; i < N; ++i) {
        if (num[i] == k) return i;
    }
    return -1;
}

// 递归设置根节点左右节点的地址
void f1(node *a, int *mid, int *post, int left, int right, node *root, int N) {
    int r_in_mid = f(mid, N, root->id);
    if (r_in_mid > left) {
        root->l = f2(a, mid, post, left, r_in_mid - 1, N);
        f1(a, mid, post, left, r_in_mid - 1, root->l, N);
    }
    if (r_in_mid < right) {
        root->r = f2(a, mid, post, r_in_mid + 1, right, N);
        f1(a, mid, post, r_in_mid + 1, right, root->r, N);
    }
}

// 返回mid[left]到mid[right]一段节点根节点的地址
node *f2(node *a, int *mid, int *post, int left, int right, int N) {
    if (left == right) return &a[mid[left] - 1];
    int r_in_post = 0;
    for (int i = left; i <= right; ++i) {
        int temp = f(post, N, mid[i]);
        if (temp > r_in_post) r_in_post = temp;
    }
    return &a[post[r_in_post] - 1];
}

// 前序遍历
void preOrder(node n) {
    cout << n.id << ' ';
    if (n.l) preOrder(*n.l);
    if (n.r) preOrder(*n.r);
}

int main() {
    int N;
    node *root;
    cin >> N;
    int *mid = new int[N];
    int *post = new int[N];
    node *a = new node[N];
    for (int i = 0; i < N; ++i) {
        a[i].id = i + 1;
    }
    for (int i = 0; i < N; ++i) {
        cin >> mid[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> post[i];
    }
    root = &a[post[N - 1] - 1];
    f1(a, mid, post, 0, N - 1, root, N);
    preOrder(*root);
    return 0;
}