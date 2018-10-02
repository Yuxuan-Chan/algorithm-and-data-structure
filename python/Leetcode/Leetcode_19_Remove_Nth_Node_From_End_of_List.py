#! python3
# -*- coding: utf-8 -*-


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :param n: int
        :rtype: ListNode
        """
        dummy = ListNode(0)
        dummy.next = head
        length = 0
        while head.next:
            length += 1
            head = head.next
        length -= n + 1
        head = dummy
        while length >= 0:
            length -= 1
            head = head.next
        head.next = head.next.next
        return dummy.next


# if __name__ == '__main__':
#     dummy = ListNode(0)
#     first = ListNode(1)
#     second = ListNode(2)
#     third = ListNode(3)
#     fourth = ListNode(4)
#     dummy.next = first
#     first.next = second
#     second.next = third
#     third.next = fourth
#     while dummy.next:
#         print(dummy.val)
#         dummy = dummy.next
#     print(dummy.val)
