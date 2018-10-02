#! python3
# -*- coding: utf-8 -*-


class Solution:
    """
    First, check the four border of the matrix, if there is a element is 'O', alter it and all its
    neighbor 'O' elements to '1'
    Then, alter all the 'O' to 'X'
    At last, alter all the '1' to 'O'
    """

    def dfs(self, x, y, matrix):
        if x < 0 or x > len(matrix) - 1 or y < 0 or y > len(matrix[0]) - 1 or matrix[x][y] != 'O':
            return
        matrix[x][y] = '#'
        self.dfs(x - 1, y, matrix)
        self.dfs(x, y - 1, matrix)
        self.dfs(x + 1, y, matrix)
        self.dfs(x, y + 1, matrix)

    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        if len(board) > 0:
            m, n = 0, 0
            for n in range(len(board[0])):
                print(m, n)
                if board[m][n] == 'O':
                    self.dfs(m, n, board)
            for m in range(len(board)):
                print(m, n)
                if board[m][n] == 'O':
                    self.dfs(m, n, board)
            for n in range(len(board[0]) - 2, -1, -1):
                print(m, n)
                if board[m][n] == 'O':
                    self.dfs(m, n, board)
            for m in range(len(board) - 2, 0, -1):
                print(m, n)
                if board[m][n] == 'O':
                    self.dfs(m, n, board)
            for i in range(len(board)):
                for j in range(len(board[0])):
                    if board[i][j] == '#':
                        board[i][j] = 'O'
                    else:
                        board[i][j] = 'X'

from functools import wraps
import logging


def cache(func):
    storage = {}
    @wraps(func)
    def wrapper(*args):
        if args not in storage.keys():
            storage[args] = func(args)
        return func(*args)
    return wrapper


@cache
def fib(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)


def use_logging(level):
    def outter(func):
        def inner(*args, **kwargs):
            if level == 'warning':
                logging.warning('{} is running'.format(func.__name__))
            return func(*args, **kwargs)
        return inner
    return outter



if __name__ == '__main__':
    # solution = Solution()
    # solution.solve([['X', 'X', 'X', 'X'], ['X', 'O', 'O', 'X'], ['X', 'X', 'O', 'X'], ['X', 'O', 'X', 'X']])

