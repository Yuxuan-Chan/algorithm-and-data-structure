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


class OrderedList:
    def __init__(self):
        self.head = None

    def add(self, item):
        current = self.head
        previous = None
        stop = False
        while current is not None and not stop:
            if current.get_data() > item:
                stop = True
            else:
                previous = current
                current = current.get_next()

        temp = Node(item)
        if previous is None:
            temp.set_next(self.head)  # 将结点放在头部，先将temp结点指向后面的结点
            self.head = temp  # 然后再将头指针指向temp结点
        else:
            temp.set_next(current)
            previous.set_next(temp)

    def remove(self, item):
        # 前提条件:假设item在链表中的 1. 先要找到 2. 找到后分头结点和在链表中两种情况
        previous = None
        current = self.head
        found = False
        stop = False
        while current is not None and not found and not stop:
            if current.get_data() == item:
                found = True
            else:
                if current.get_data() > item:
                    stop = True
                else:
                    previous = current
                    current = current.get_next()

        if previous is None:
            # 如果是头结点要被移除
            self.head = current.get_next()
        else:
            previous.set_next(current.get_next())

    def search(self, item):
        current = self.head
        found = False
        stop = False
        while current is not None and not found and not stop:
            if current.get_data() == item:
                found = True
            else:
                if current.get_data() > item:
                    stop = True
                else:
                    current = current.get_next()
        return found

    def is_empty(self):
        current = self.head
        if current.get_next() is None:
            return True
        return False

    def size(self):
        current = self.head
        count = 0
        while current is not None:
            current = current.get_next()
            count += 1
        return count

    def index(self, item):
        # assume the item is in the list
        current = self.head
        found = False
        stop = False
        index = 0
        while current is not None and not found and not stop:
            if current.get_data == item:
                found = True
            else:
                if current.get_data > item:
                    stop = True
                else:
                    current = current.get_next()
                    index += 1
        return index

    def pop(self):
        # 删除并返回最后一个元素
        previous = None
        current = self.head
        while current.get_next() is not None:
            previous = current
            current = current.get_next()
        previous.set_next(None)
        return previous

    def pop_pos(self, pos):
        # 删除并返回指定的元素
        index = 0
        previous = None
        current = self.head
        while index < pos:
            previous = current
            current = current.get_next()
            index += 1
        previous.set_next(current.get_next())
        return current
