#include<iostream>

using namespace std;

template<class T>
void quicksort(T *list, int start, int end) {
    if (start > end) return;
    int base = list[start];
    int i = start, j = end;
    while (i < j) {
        while (list[j] <= base && j > i) --j;
        while (list[i] >= base && j > i) ++i;
        if (j > i) {
            int tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
            ++i;
            --j;
        }
    }
    list[start] = list[i];
    list[i] = base;
    quicksort(list, start, i - 1);
    quicksort(list, i + 1, end);
}

int main() {
    int n, k;
    cin >> n >> k;
    int *l = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    quicksort(l, 0, n - 1);
    cout << l[k - 1];
    return 0;
}