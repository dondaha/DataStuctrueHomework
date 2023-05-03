#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    struct node {
        int l;
        int r;

        node() { l = r = 0; }
    };
    node *a = new node[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i].l >> a[i].r;
    }
    for (int i = 0; i < N; ++i) {
        if (a[i].l != 0 && a[i].r != 0) {
            if (2 * i - N + 1 != a[i].l || 2 * i - N != a[i].r) {
                cout << 'N';
                return 0;
            }
        } else if (a[i].l == 0 && a[i].r != 0) {
            cout << 'N';
            return 0;
        } else if (a[i].l != 0 && a[i].r == 0) {
            if (2 * i - N + 1 != a[i].l) {
                cout << 'N';
                return 0;
            }
        }
    }
    cout << 'Y';
    delete[] a;
    return 0;
}