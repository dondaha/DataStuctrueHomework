#include <iostream>

using namespace std;

class priorityQueue {
private:
    int *array;
    int currentSize;
    int maxSize;

    void doubleSpace() {
        int *tmp = array;
        array = new int[maxSize * 2];
        for (int i = 1; i <= currentSize; ++i) {
            array[i] = tmp[i];
        }
        delete[] tmp;
    }//扩容
    void buildHeap() {
        for (int i = currentSize / 2; i > 0; --i) {
            percolateDown(i);
        }
    }//建堆
    void percolateDown(int hole) {
        int tmp = array[hole];
        int child;
        for (; hole * 2 <= currentSize; hole = child) {
            child = 2 * hole;
            if (child != currentSize && array[child + 1] < array[child]) {
                child++;
            }
            if (array[hole] > array[child]) {
                array[hole] = array[child];
            } else break;
        }
        array[hole] = tmp;
    }//向下过滤
public:
    priorityQueue(int capacity = 100) {
        array = new int[capacity];
        maxSize = capacity;
        currentSize = 0;
    }

    priorityQueue(int *data, int size) {
        array = new int[size + 10];
        for (int i = 0; i < size; ++i) {
            array[i + 1] = data[i];
        }
        currentSize = size;
        buildHeap();
    };

    ~priorityQueue() { delete[]array; }

    bool isEmpty() { return array == NULL; }

    int getHead() { return array[1]; }

    void enQueue(const int &x) {
        if (currentSize == maxSize - 1) doubleSpace();
        int hole = ++currentSize;
        for (; hole > 1 && x < array[hole / 2]; hole /= 2) {
            array[hole] = array[hole / 2];
        }
        array[hole] = x;
    }//入队
    int deQueue() {
        int minItem = array[1];
        array[1] = array[currentSize--];
        percolateDown(1);
        return minItem;
    }//出队
};

int main() {
    int N;
    cin >> N;
    int sum = 0;
    priorityQueue q(N);
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        sum += x;
        q.enQueue(x);
    }
    int consumption_sum = 0;
    while (q.getHead() < sum) {
        int a = 0;
        a = q.deQueue() + q.deQueue();
        consumption_sum += a;
        q.enQueue(a);
    }
    cout << consumption_sum;
    return 0;
}