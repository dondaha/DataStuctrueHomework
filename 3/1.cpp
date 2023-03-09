#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};


ListNode *reverseList(ListNode *head) {
    if (!head) return head; // 若为空链表，直接返回head节点的指针
    ListNode *p = head, *q = head->next, *r;
    head->next = nullptr;
    while (q) {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    return p;
}


ListNode *createList() {
    int x;
    ListNode head;
    ListNode *p = &head;
    head.next = NULL;
    while (cin >> x) {
        p->next = new ListNode{x, nullptr};
        p = p->next;
    }
    return head.next;
}

void display(ListNode *p) {
    while (p) {
        printf("%d -> ", p->val);
        p = p->next;
    }
    printf("nullptr\n");
}

int main() {
    ListNode *L1 = createList();
    display(L1);
    ListNode *L2 = reverseList(L1);
    display(L2);

    return 0;
}