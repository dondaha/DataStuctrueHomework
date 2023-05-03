#include <iostream>

using namespace std;

struct task {
    int priority;
    int id;
};

template<class elemType>
class seqQueue {
protected:
    elemType *elem;
    int maxSize;
    int Front, Rear;

    void doubleSpace();

public:
    seqQueue(int Size = 100);

    ~seqQueue();

    bool isEmpty();

    void enQueue(elemType &x);

    elemType deQueue();

    elemType getHead();
};

template<class elemType>
seqQueue<elemType>::seqQueue(int Size) {
    elem = new elemType[Size];
    maxSize = Size;
    Front = Rear = 0;
}

template<class elemType>
seqQueue<elemType>::~seqQueue() {
    delete[] elem;
}

template<class elemType>
bool seqQueue<elemType>::isEmpty() {
    return Front == Rear;
}

template<class elemType>
void seqQueue<elemType>::enQueue(elemType &x) {
    if ((Rear + 1) % maxSize == Front) doubleSpace();
    Rear = (Rear + 1) % maxSize;
    elem[Rear] = x;
}

template<class elemType>
elemType seqQueue<elemType>::deQueue() {
    Front = (Front + 1) % maxSize;
    return elem[Front];
}

template<class elemType>
elemType seqQueue<elemType>::getHead() {
    return elem[(Front + 1) % maxSize];
}

template<class elemType>
void seqQueue<elemType>::doubleSpace() {
    elemType *tmp = elem;
    elem = new elemType[2 * maxSize];
    for (int i = 1; i < maxSize; ++i) {
        elem[i] = tmp[(Front + i) % maxSize];
    }
    Front = 0;
    Rear = maxSize - 1;
    maxSize *= 2;
    delete tmp;
}

class Task_SeqQueue : public seqQueue<task> {
public:
    int show_highest_priority() {
        int max = -1;
        for (int i = Front + 1; i != (Rear + 1) % maxSize; i = (i + 1) % maxSize) {
            if (elem[i].priority > max) max = elem[i].priority;
        }
        return max;
    }
};

int main() {
    int n, l, x;
    task temp_task{}; // use a struct to record task id and its priority
    cin >> n;
    auto *print_q = new Task_SeqQueue[n];
    int *id_list = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> l >> id_list[i];
        for (int j = 0; j < l; ++j) {
            cin >> x;
            temp_task = {x, j};
            print_q[i].enQueue(temp_task);
        }
    }
    for (int i = 0; i < n; ++i) {
        int step_sum = 0, out_id = -1;
        while (out_id != id_list[i]) {
            temp_task = print_q[i].deQueue();
            if (temp_task.priority >= print_q[i].show_highest_priority()) {
                out_id = temp_task.id;
                ++step_sum;
            } else print_q[i].enQueue(temp_task);
        }
        cout << step_sum << endl;
    }
    delete [] print_q;
    delete [] id_list;
    return 0;
}