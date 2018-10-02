#! python3
# -*- coding: utf-8 -*-
import time
import logging


def cache(func):
    storage = {}

    def wrapper(*args):
        if args not in storage.keys():
            storage[args] = func(*args)
        return func(*args)
    return wrapper


def use_logging(level):
    def outter(func):
        def inner(*args, **kwargs):
            if level == 'warning':
                logging.warning('{} is running'.format(func.__name__))
            return func(*args)
        return inner
    return outter

@cache
def fib(n):
    if n == 1 or n == 0:
        return 1
    else:
        return fib(n-1) + fib(n-2)


if __name__ == '__main__':
    start = time.time()
    ttt = [fib(n) for n in range(40)]
    end = time.time()
    print('cost:{}'.format(end-start))


