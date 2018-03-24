#! python3
# -*- coding: utf-8 -*-


def max_sub_seq_sum(length, array):
    """
    :param length: 队列长度
    :param array:  队列
    :return: 最大子列和
    """
    max_sum = 0
    for i in range(length):
        this_sum = 0
        for j in range(i, length):
            this_sum += array[j]
            if this_sum > max_sum:
                max_sum = this_sum
    return max_sum


def main():
    """
    输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。
    在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。
    :return:
    """
    # print("输入正整数K: ", end="")
    # k = int(input())
    # print("输入K个整数: ", end="")
    # array = list(map(eval, input().split()))
    k = 6
    array = [-2, 11, -4, 13, -5, -2]
    res = max_sub_seq_sum(k, array)
    print(res)


if __name__ == '__main__':
    main()