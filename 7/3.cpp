#include <iostream>

using namespace std;


class closeHashTable {
private:
    struct node {
        int data;
        int state; //0,1,2分别代表空、已使用、已删除
        int s = 0; //探查次数
        node() {
            state = 0;
            data = -1;
        }
    };

    node *array;
    int size;
    int p;

    int (*key)(const int &x);

    static int defaultint(const int &x) { return x; }

public:
    closeHashTable(int length, int pp, int (*f)(const int &x) = defaultint) {
        size = length;
        p = pp;
        array = new node[size];
        key = f;
    };

    ~closeHashTable() { delete[] array; }

    void insert(const int &x) {
        int initPos, pos, sum = 1;
        initPos = pos = x % p; //余数法哈希
        do {
            if (array[pos].state != 1) { // 0空或者2已删除，找到空单元，则插入
                array[pos].data = x;
                array[pos].state = 1;
                array[pos].s = sum;
                return;
            }
            pos = (pos + 1) % size; //非空，继续走到下一位置
            ++sum;
        } while (pos != initPos); //直到回到起点
    }

    int view_state(int position) {
        return array[position].data;
    }

    int view_s(int position) {
        return array[position].s;
    }
};

int main() {
    int p, m, n;
    cin >> p >> m >> n;
    closeHashTable t(m, p);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        t.insert(x);
    }
    for (int i = 0; i < m; ++i) {
        cout << i << ' ';
    }
    cout << endl;
    for (int i = 0; i < m; ++i) {
        cout << t.view_state(i) << ' ';
    }
    cout << endl;
    for (int i = 0; i < m; ++i) {
        cout << t.view_s(i) << ' ';
    }
    return 0;
}