#! python3
# -*- coding: utf-8 -*-


# 插入排序
# 始终将整个序列视作并切分为两部分，有序的前缀，无序的后缀，通过迭代，反复的将后缀的首元素转移至前缀中，由此看出插入排序的不变性。
def insertionSort(alist):
    for index in range(1, len(alist)):
        currentvalue = alist[index]
        position = index

        while position > 0 and alist[position-1] > currentvalue:
            alist[position] = alist[position-1]
            position -= 1
        alist[position] = currentvalue
    return alist

