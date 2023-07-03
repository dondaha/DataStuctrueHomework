# 第1关：线性表填空
## 任务描述
已知如下代码的功能是在带头结点单链表中查找第一个值在[min, max]间的元素位置，则空白处的代码分别是？假设首结点的位置为0
```c++
    struct node
    {
        float data;
        float *next;
    };
    int findInDomain(float min, float max, node *head)
    {
        int i = 0;
        node *p = ______;
        while(p)
        {
            if(______)
                return i;
            i++;
            p = p->next;
        }
        return -1;
    }
```
# 第2关：最大子数组和
## 任务描述
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

## 测试说明
- 输入的第一行是一个整数 N, 代表数组的大小
- 输入的第二行是 N 个整数

【示例1】
```
测试输入：
9
-2 1 -3 4 -1 2 1 -5 4
预期输出：
6
解释:连续子数组 [4,-1,2,1] 的和最大，为 6 。
```
【示例2】
```
测试输入：
1
1
预期输出：
1
```
【提示】
```
1 <= N <= 10000
-105 <= nums[i] <= 105
```