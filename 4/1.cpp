#include <iostream>

using namespace std;

template<class T>
class Stack {
private:
    struct Node {
        T data;
        Node *next;
    };
    Node *head;
    int length;

public:
    Stack() {
        head = NULL;
        length = 0;
    }

    void push(T n) {
        head = new Node{n, head};
        ++length;
    }//入栈
    T pop() {
        T r = head->data;
        Node *tmp = head->next;
        delete head;
        head = tmp;
        --length;
        return r;
    }//出栈并且将出栈的元素返回
    int size() {
        return length;
    }//返回元素个数
    T top() {
        if (head) return head->data;
        return 0;
    }//返回栈顶元素
    bool isEmpty() {
        return length == 0;
    }//判断栈是不是空的
    void clear() {
        Node *p = head, *q;
        head = nullptr;
        while (p) {
            q = p->next;
            delete p;
            p = q;
        }
        length = 0;
    }//清空栈中的所有元素
    bool checkMatch() {
        if (length == 0) return true;
        Stack<T> s0;
        Node *p = head;
        T tmp1, tmp2;
        while (p) {
            tmp1 = s0.top();
            tmp2 = p->data;
            if (tmp1 - tmp2 == 1 || tmp1 - tmp2 == 2) {
                s0.pop();
            } else {
                s0.push(p->data);
            }
            p = p->next;
        }
        return s0.length == 0;
    }//检测括号是否匹配
};

int main() {
    Stack<char> s;
    int n, choice;
    char x;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> x;
                s.push(x);
                break;
            case 2:
                if (s.size() > 0) s.pop();
                break;
            case 3:
                if (s.size() > 0) cout << s.top() << endl;
                break;
            case 4:
                cout << (s.checkMatch() ? "YES" : "NO") << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}