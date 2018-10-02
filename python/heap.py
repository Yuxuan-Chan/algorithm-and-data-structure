#! python3
# -*- coding: utf-8 -*-


class BinHeap:
    def __init__(self):
        self.heapList = [0]  # 第一个元素从1开始
        self.currentSize = 0

    def percUp(self, i):
        while i // 2:
            if self.heapList[i] < self.heapList[i//2]:
                temp = self.heapList[i//2]
                self.heapList[i//2] = self.heapList[i]
                self.heapList[i] = temp
            i // 2

    def insert(self, k):
        self.heapList.append(k)
        self.currentSize += 1
        self.percUp(self.currentSize)

    def percDown(self, i):
        while (2*i) <= self.currentSize:
            mc = self.minChild(i)
            if self.heapList[i] > self.heapList[mc]:
                temp = self.heapList[i]
                self.heapList[i] = self.heapList[mc]
                self.heapList[mc] = temp
            i = mc

    def minChild(self, i):
        # 比较子结点哪个结点比较小
        if i * 2 + 1 > self.currentSize:
            return i * 2
        else:
            if self.heapList[i*2] < self.heapList[i*2+1]:
                return i*2
            else:
                return i*2+1

    def delMin(self):
        # 堆次序要求根节点是树中最小的元素，因此很容易找到最小项
        #
        retval = self.heapList[1]
        print(self.heapList)
        self.heapList[1] = self.heapList[self.currentSize]
        print(self.heapList)
        self.currentSize -= 1
        self.heapList.pop()
        print(self.heapList)
        self.percDown(1)
        print(self.heapList)
        return retval

    def buildHeap(self, alist):
        i = len(alist) // 2
        self.currentSize = len(alist)
        self.heapList = [0] + alist[:]
        while i > 0:
            self.percDown(i)
            i = i - 1


if __name__ == '__main__':
    # bh = BinHeap()
    # bh.buildHeap([9, 5, 6, 2, 3])
    # print(bh.heapList)
    # print(bh.delMin())
    # print(bh.heapList)

