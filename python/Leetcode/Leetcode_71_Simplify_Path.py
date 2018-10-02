#! python3
# -*- coding: utf-8 -*-


# class Solution:
#     def simplifyPath(self, path):
#         """
#         :type path: str
#         :rtype: str
#         """
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


# def simplifyPath(path):
#     """
#     在两个斜杠之间的是非点的字母是一个字母元素
#     /home/ => home
#     /a/ => a
#     /b/ => b
#     遇到..弹栈
#     遇到.不操作
#     其它情况下压栈
#     :param path:
#     :return:
#     """
#     stack = []
#     i = 0
#     res = ''
#     while i < len(path):
#         end = i + 1
#         while end < len(path) and path[end] != '/':
#             end += 1
#         sub = path[i+1:end]
#         if len(sub) > 0:
#             if sub == '..':
#                 if stack != []:
#                     stack.pop()
#             elif sub != '.':
#                 stack.append(sub)
#         i = end
#     if stack == []:
#         return '/'
#     for i in stack:
#         res += '/' + i
#     return res


def simplifyPath(path):
    stack = []
    i = 0
    res = ''
    while i < len(path):
        end = i + 1
        while end < len(path) and path[end] != "/":
            end += 1
        sub = path[i + 1:end]
        print(sub)
        if len(sub) > 0:
            if sub == "..":
                if stack != []: stack.pop()
            elif sub != ".":
                stack.append(sub)
        i = end
    if stack == []: return "/"
    for i in stack:
        res += "/" + i
    return res


def another(path):
    split_by_slash = path.split('/')
    stack = []
    for i in split_by_slash:
        if not i or i == '.':
            continue
        elif i == '..':
            if len(stack) > 0:
                stack.pop()
        else:
            stack.append(i)
    return '/' + '/'.join(stack)


if __name__ == '__main__':
    # stack = Stack()
    # stack.push("abc")
    # stack.push(2)
    # stack.push(3)
    # print(stack.stack)
    # print(simplifyPath('/home//foo/'))
    print('/home/'.split('/'))
    print('/a/./b/../../c/'.split('/'))
    print(another('/a/./b/../../c/'))
    print(another('/home/'))
    "/..."
    "/"
    "/..."
