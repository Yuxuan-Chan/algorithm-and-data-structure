#! python3
# -*- coding: utf-8 -*-


def max_sub_seq_sum_method_0(length, queue):
    """
    :param length: 队列长度
    :param queue:  队列
    :return: 最大子列和
    """
    this_sum = 0
    max_sum = 0
    flag = 0
    for i in range(length):
        if queue[i] >= 0:
            flag = 1
        this_sum += queue[i]
        if this_sum > max_sum:
            max_sum = this_sum
        elif this_sum < 0:
            this_sum = 0
    if flag == 0:
        return 0
    return max_sum


def main():
    """
    输入第1行给出正整数K (≤100000)；第2行给出K个整数，其间以空格分隔。
    在一行中输出最大子列和。如果序列中所有整数皆为负数，则输出0。
    :return:
    """
    print("输入正整数K: ", end="")
    k = int(input())
    print(k)
    print("输入K个整数: ", end="")
    queue = list(map(eval, input().split()))
    print(queue)
    res = max_sub_seq_sum_method_0(k, queue)
    print(res)


if __name__ == '__main__':
    main()
    # k = int(input("输入K: "))
    # print(k)
    # queue = []
    # for i in range(k):
    #     element = int(input("输入元素: "))
    #     print(element)
    #     queue.append(element)
    # print(queue)
    # queue = list(map(eval, input().split()))
    # print(queue)
    # print(queue[0])
    # print(type(queue[0]))
