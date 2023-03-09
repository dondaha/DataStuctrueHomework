#include<iostream>

using namespace std;

int max(const int nums[], int left, int right) {
    int maxSum = 0, thisSum = 0;
    if (right==left) return nums[left];
    for (int i = left; i <= right; ++i) {
        thisSum += nums[i];
        if (thisSum <= 0) {
            thisSum = 0;
        } else if (thisSum > maxSum) {
            maxSum = thisSum;
        }
    }
    return maxSum;
}

//int maxSubsequenceSum(int a[],int size){
//    int maxSum,starttmp,thisSum,start,end;
//    start=end=maxSum=starttmp=thisSum=0;
//    for (int j = 0; j < size; ++j) {
//        thisSum+=a[j];
//    }
//}

int main() {
    int n;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout<<max(nums,0,n-1);
    return 0;
}