#include <iostream>
#include <cstring>

using namespace std;

struct node {
    node *l, *r;
    int id;

    node() {
        l = r = nullptr;
        id = -1;
    }
};

void preOrder(node n) {
    cout << n.id << ' ';
    if (n.l) preOrder(*n.l);
    if (n.r) preOrder(*n.r);
}

void midOrder(node n) {
    if (n.l) midOrder(*n.l);
    cout << n.id << ' ';
    if (n.r) midOrder(*n.r);
}

void postOrder(node n) {
    if (n.l) postOrder(*n.l);
    if (n.r) postOrder(*n.r);
    cout << n.id << ' ';
}

void levelOrder(node n, int N) {
    node **queue = new node *[N];
    queue[0] = &n;
    int s = 1;
    for (int i = 0; i < N; ++i) {
        if (queue[i]->l) {
            queue[s] = queue[i]->l;
            ++s;
        }
        if (queue[i]->r) {
            queue[s] = queue[i]->r;
            ++s;
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << queue[i]->id << ' ';
    }
    delete [] queue;
}

int main() {
    int N;
    cin >> N;

    node *a = new node[N];
    int root = 0;
    int *a1 = new int[N];
    memset(a1, 0, 4 * N);

    for (int i = 0; i < N; ++i) {
        int l, r;
        cin >> l >> r;
        a[i].id = i + 1;
        a[i].l = l ? &a[l - 1] : nullptr;
        a[i].r = r ? &a[r - 1] : nullptr;
    }
    for (int i = 0; i < N; ++i) {
        if (a[i].l) a1[a[i].l - a] = 1;
        if (a[i].r) a1[a[i].r - a] = 1;
    }
    for (int i = 0; i < N; ++i) {
        if (a1[i] == 0) {
            root = i;
            break;
        }
    }
    preOrder(a[root]);
    cout << endl;
    midOrder(a[root]);
    cout << endl;
    postOrder(a[root]);
    cout << endl;
    levelOrder(a[root], N);
    delete[] a;
    return 0;
}