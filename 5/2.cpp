#include <iostream>

using namespace std;

template<class elemtype>

class linkQueue {
protected:

    struct node {
        elemtype data;
        node *next;

        explicit node(elemtype &x, node *N = NULL) {
            data = x;
            next = N;
        }

        node() : next(NULL) {}

        ~node() = default;
    };

    node *Front, *Rear;

public:

    linkQueue() { Front = Rear = NULL; }

    ~linkQueue() {
        node *tmp;
        while (Front != NULL) {
            tmp = Front;
            Front = Front->next;
            delete tmp;
        }
    }

    bool isEmpty() {
        return Rear == NULL;
    }

    elemtype getHead() {
        return Front->data;
    }

    void enQueue(elemtype &x) {
        if (Rear == NULL) {
            Front = Rear = new node(x);
        } else {
            Rear = Rear->next = new node(x);
        }
    }

    elemtype deQueue() {
        node *temp = Front;
        elemtype value = Front->data;
        Front = Front->next;
        if (Front == NULL) Rear = NULL;
        delete temp;
        return value;
    }

};

struct people {
    int id;
    int group;
};

class ticket_linkQueue : public linkQueue<people> {
public:
    void g_enqueue(people &x) {
        if (isEmpty()) {
            enQueue(x);
        } else {
            node *temp = Front;
            while (temp) {
                if (temp->data.group == x.group) // when x is at the end of its group
                {
                    if (temp->next && temp->next->data.group != x.group) {
                        temp->next = new node{x, temp->next};
                        break;
                    }
                    if (!temp->next) {
                        temp->next = new node{x, NULL};
                        break;
                    }
                }
                if (!temp->next) {
                    temp->next = new node{x, NULL};
                    break;
                }
                temp = temp->next;
            }
        }
    }
};

int main() {
    int n, p;
    cin >> n;
    auto *people_list = new people[n];
    for (int i = 0; i < n; ++i) {
        cin >> people_list[i].group;
        people_list[i].id = i + 1;
    }
    cin >> p;
    int number = 0;
    ticket_linkQueue queue = ticket_linkQueue();
    for (int i = 0; i < p; ++i) {
        int task;
        cin >> task;
        switch (task) {
            case 1:
                if (queue.isEmpty()) cout << -1 << endl;
                else {
                    cout << queue.deQueue().id << endl;
                }
                break;
            case 0:
                if (number >= n) break;
                queue.g_enqueue(people_list[number++]);
                break;
            default:
                break;
        }
    }
    delete[] people_list;
    return 0;
}