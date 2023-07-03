# 第1关：反转链表
## 任务描述
反转一个链表。

## 编程要求
你需要正确地实现反转链表函数`reverseList`，并补全相应的创建链表函数`createList()`
`reverseList`函数接受一个链表的头指针作为参数，返回一个链表指针。返回的链表与传入的链表刚好是逆序的。

`createList()`函数通过输入的变量`x`不断地创建一个链表。

`display`函数输出传入的链表，我们已经帮你实现。

main函数我们已经帮你写好。它的功能是将输入的一串数字构造为单链表，然后测试你书写的`reverseList`函数和`createList()`函数。

## 测试说明
平台会对你编写的代码进行测试：

测试输入：`1 2 3 4 5`；
测试输出：
```
1->2->3->4->5->nullptr
5->4->3->2->1->nullptr
```
---
开始你的任务吧，祝你成功！

# 第2关：约瑟夫环
## 任务描述
约瑟夫问题（有时也称为约瑟夫斯置换），是一个出现在计算机科学和数学中的问题。在计算机编程的算法中，类似问题又称为约瑟夫环。

人们站在一个等待被处决的圈子里。 计数从圆圈中的指定点开始，并沿指定方向围绕圆圈进行。 在跳过指定数量的人之后，执行下一个人。 对剩下的人重复该过程，从下一个人开始，朝同一方向跳过相同数量的人，直到只剩下一个人，并被释放。

问题即，1,2,...,n 这 n 个数字排成一个圆圈，从数字1开始，每次从这个圆圈里删除第m个数字。求出这个圆圈里剩下的最后一个数字。

## 编程要求
根据提示，在右侧编辑器补充代码，输出这个圆圈里剩下的最后一个数字。

注意：编辑器中已经给出了`main`函数和前置代码，你只需要补充相关函数

`createList`函数：输入`n`，创建链表
`remove`函数：输入一个链表、`m`和`n`，输出一个数字

## 测试说明
平台会对你编写的代码进行测试：

样例输入：`5 3`；
预期输出：
`4`

样例说明：1、2、3、4、5这5个数字组成一个圆圈，从数字1开始每次删除第3个数字，则删除的前4个数字依次是3、1、5、2，因此最后剩下的数字是4。

---
开始你的任务吧，祝你成功！