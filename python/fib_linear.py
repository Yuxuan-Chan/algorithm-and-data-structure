#! python3
# -*- coding: utf-8 -*-


def fib(n):
    x, y = 0, 1
    while n:
        x, y, n = y, x+y, n
        n -= 1
    return x
