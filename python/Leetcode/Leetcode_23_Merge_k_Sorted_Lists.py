#! python3
# -*- coding: utf-8 -*-


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def mergetTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        h = ListNode(0)
        cur = h

        cur1 = l1
        cur2 = l2
        while cur1 is not None and cur2 is not None:
            if cur1.val < cur2.val:
                cur.next = cur1
                cur1 = cur1.next
            else:
                cur.next = cur2
                cur2 = cur2.next
            cur = cur.next

        if cur1 is not None:
            cur.next = cur1

        if cur2 is not None:
            cur.next = cur2

        return h.next

    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        # 两两合并
        """
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.mergetTwoLists(lists[i], lists[i+interval])
            interval *= 2
        return lists[0] if amount > 0 else lists


if __name__ == '__main__':
    for i in range(0, 10, 2):
        print(i)