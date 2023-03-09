#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node *createList(int n) {
    if (!n) return nullptr;
    Node *head = new Node{1, nullptr}, *p = head;
    for (int i = 2; i <= n; ++i) {
        p->next = new Node{i, nullptr};
        p = p->next;
    }
    p->next = head;
    return head;
}

int remove(Node *head, int m, int n) {
    Node *p = head, *q;
    while (p->next != p) {
        for (int i = 0; i < m - 2; ++i) {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        p = q->next;
        delete q;
    }
    return p->data;
}

int main()
{
    int n, m;
    cin >> n >> m;
    Node* L1 = createList(n);
    cout << remove(L1, m, n) << endl;
    return 0;
}