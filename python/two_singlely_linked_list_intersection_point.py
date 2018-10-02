#! python3
# -*- coding: utf-8 -*-


class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


def solution(l1, l2):
    l1_length, l2_length = 0, 0
    while l1.next:
        l1 = l1.next
        l1_length += 1
    while l2.next:
        l2 = l2.next
        l2_length += 1

    if l1.next == l2.next:
        if l1_length > l2_length:
            for _ in range(l1_length - l2_length):
                l1 = l1.next
            return l1
        else:
            for _ in range(l2_length - l1_length):
                l2 = l2.next
            return l2
    else:
        return
