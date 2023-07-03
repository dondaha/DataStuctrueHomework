# 第1关：打印机队列

## 任务描述
打印机要承担多个任务。每个任务分配 1 到 9 之间的优先级（其中 9 为最高优先级，1 为最低），打印机的操作如下：

将队列中的第一个任务J从队列中取出。
如果队列中的某些任务具有比任务J更高的优先级，则将J移动到队列的末尾而不打印它。
否则，打印任务J。
## 编程要求
请您编写一个程序计算打印到你想打印的任务 `your_task_id` 打印完成所需要花费的时间。为了简化问题，我们假设每个打印任务始终只花费一分钟，并且从队列中添加和删除任务是即时的。

注意：右侧编辑器中已经给你了一个队列的模板，你可以实现它并完成任务要求，也可以完全弃用按照你自己的方式完成任务。
## 测试说明
【测试输入】
第一行是一个整数，代表打印机队列的数量（最多100个）。对于第二行开始的每个打印机队列：

一行包含两个整数 N 和 P，其中 N 是队列中的任务数（1≤N≤100）， P 是你想打印的任务 `your_task_id` 的位置（0≤P<N）。队列中的第一个位置是数字 0，第二个是数字 1，依此类推。
一行 包含N 个整数，给出了队列中每个任务的优先级（从1到9）。
【测试输出】
对于每个打印机队列，输出一个整数，代表打印到你想打印的任务 `your_task_id` 打印完成所需要花费的时间。

【样例输入】
```
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1
```
【样例输出】
```
1
2
5
```
样例说明：

第一个队列包含1个任务，想打印的任务位于第0个位置，每个任务的优先级分别为：5。打印完成这个任务需要1分钟；
第二个队列包含4个任务，想打印的任务位于第2个位置，每个任务的优先级分别为：1,2,3,4。打印完成这个任务需要2分钟；
第三个队列包含6个任务，想打印的任务位于第0个位置，每个任务的优先级分别为：1,1,9,1,1,1。打印完成这个任务需要5分钟。

# 第2关：排队与插队

## 任务描述
春节前后的寒假开始总是交通高峰期的开始。如果您这时候尝试购买火车票，就会目睹每个售票窗口前无尽的排队。如果一个人在队列中见过他的朋友，那么这个幸运的人很可能会直接去找他的朋友求情。这称为“插队”。对于排队的其他人来说，这是不公平的，但这就是生活。

## 编程要求
您的任务是编写一个程序，模拟一个这样的队列，人们不时地排队与插队。队伍中如果存在自己的小团体，则会插在这个小团体末尾。否则正常排队，排在整条队伍末尾。

注意：右侧编辑器中已经给你了一个队列的模板，你可以实现它并完成任务要求，也可以完全弃用按照你自己的方式完成任务。
## 测试说明
【测试输入】
第一行是一个数 N，表示参与排队的人的个数。
第二行将会读入 N 个非负整数，第 i 个整数表示第 i 个人所属的团体的编号 。这些编号的范围是 1 ~ 9。
第三行是一个数 Q ，代表可能的事件数。
第四行是 Q 个数字，每个数字代表一种可能的事件。
0:插入一个新人。如果所有人都入过队列，你应当忽略这个操作。
1:队首的人离开，请输出这个人是第几个插入的。如果队列空，你应当输出 -1。
【测试输出】
对于每一个询问类事件，输出对应的答案或者是 -1。

【样例输入】
```
7
1 2 1 2 2 1 1
7
1 0 0 0 0 1 1
```
【样例输出】
```
-1
1
3
```
开始你的任务吧，祝你成功！

【限制】
对于100%的数据，N,Q≤4000