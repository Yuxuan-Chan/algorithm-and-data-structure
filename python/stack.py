#! python3
# -*- coding: utf-8 -*-


class Stack(object):
    def __init__(self):
        self.stack = []

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        self.stack.pop()

    def peek(self):
        return self.stack[-1]

    def is_empty(self):
        return self.stack == []

    def size(self):
        return len(self.stack)


def par_checker(symbol_string):
    par_stack = Stack()
    balanced = False
    for item in symbol_string:
        if item == '(':
            par_stack.push(item)
        else:
            if par_stack.is_empty():
                break
            else:
                par_stack.pop()
    if par_stack.is_empty():
        balanced = True
    return balanced


if __name__ == '__main__':
    res = par_checker('(()')
    print(res)