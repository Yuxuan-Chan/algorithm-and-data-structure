#! python3
# -*- coding: utf-8 -*-


class Node:
    def __init__(self, init_data):
        self.data = init_data
        self.next = None

    def get_data(self):
        return self.data

    def get_next(self):
        return self.next

    def set_data(self, new_data):
        self.data = new_data

    def set_next(self, new_next):
        self.next = new_next


class UnorderedList:
    def __init__(self):
        self.head = None

    def is_empty(self):
        """
        判断head指针有没有指向下一个元素
        :return:
        """
        return self.head is None

    def add(self, item):
        temp = Node(item)
        temp.set_next(self.head)
        self.head = temp

    def size(self):
        current = self.head
        count = 0
        while current is not None:
            count += 1
            current = current.get_next()
        return count

    def search(self, item):
        current = self.head
        found = False
        while current is not None and not found:
            if current.get_data() == item:
                found = True
            else:
                current = current.get_next()
        return found

    def remove(self, item):
        current = self.head
        previous = None
        found = False
        while not found:
            if current.get_data() == item:
                found = True
            else:
                previous = current
                current = current.get_next()

        if previous is None:
            self.head = current.get_next()
        else:
            previous.set_next(current.get_next())

    def append(self, item):
        temp = Node(item)
        previous = None
        current = self.head
        if current is None:
            # 说明整个链表都是空的
            current.set_next(temp)
        else:
            # 说明整个链表还是有元素的，要遍历到最后一个元素，再append
            while current is not None:
                previous = current
                current = current.get_next()
            previous.set_next(temp)

    def index(self, item):
        index = 0
        current = self.head
        while current is not None:
            if current.get_data == item:
                return index
            else:
                current = current.get_next()
                index += 1

    def insert(self, pos, item):
        index = 0
        previous = None
        current = self.head
        temp = Node(item)
        while index < pos:
            previous = current
            current = current.get_next()
            index += 1
        temp.set_next(previous.get_next())
        previous.set_next(temp)

    def pop(self):
        # 返回最后一个元素
        previous = None
        current = self.head
        while current is not None:
            previous = current
            current = current.get_next()
        return previous

    def pop_pos(self, pos):
        index = 0
        current = self.head
        while index < pos:
            current = current.get_next()
            index += 1
        return current
