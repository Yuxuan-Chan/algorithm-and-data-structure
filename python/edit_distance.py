#! python3
# -*- coding: utf-8 -*-
import numpy as np


def edit_distance(a, b, i, j):
    """
    :param a: 字符串a
    :param b: 字符串b
    :param i: 字符串a的长度
    :param j: 字符串b的长度
    :return:
    """
    if i == 0:
        return j
    elif j == 0:
        return i
    elif a[i-1] == b[j-1]:
        return edit_distance(a, b, i-1, j-1)
    elif a[i-1] != b[j-1]:
        condition_0 = edit_distance(a, b, i-1, j) + 1
        condition_1 = edit_distance(a, b, i, j-1) + 1
        condition_2 = edit_distance(a, b, i-1, j-1) + 1
        return min([condition_0, condition_1, condition_2])
    elif i == 0 and j == 0:
        return 0


def dynamic_edit_distance(a, b):
    """
    :param a: 字符串a
    :param b: 字符串b
    :return:
    """
    a_length = len(a)
    b_length = len(b)
    x = np.zeros(shape=(a_length+1, b_length+1), dtype='int32')
    print(x)
    print(type(x))

    for i in range(a_length+1):
        x[i][0] = i

    for j in range(b_length+1):
        x[0][j] = j

    print(x)

    for i in range(1, a_length+1):
        for j in range(1, b_length+1):
            if a[i-1] == b[j-1]:
                x[i][j] = x[i-1][j-1]
            else:
                x[i][j] = min([x[i-1][j]+1, x[i][j-1]+1, x[i-1][j-1]+1])

    return x[a_length][b_length]


def main():
    """
    测试数据
    :return:
    """
    # res = edit_distance('abc', 'abc', 3, 3)
    # print(res)
    res = dynamic_edit_distance('abc', 'abcde')
    print(res)


if __name__ == '__main__':
    main()

