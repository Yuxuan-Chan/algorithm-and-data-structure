#! python3
# -*- coding: utf-8 -*-


class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


def reverse(link):
    prev = link
    current = link.next
    link.next = None  # 让原来的头指针变成最后一个节点指向空
    while current:
        temp = current.next
        current.next = prev  # 指针反转
        prev = current
        current = temp


