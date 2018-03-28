#! python3
# -*- coding: utf-8 -*-


def max_sub_seq_sum(k, array):
    this_sum = 0
    max_sum = 0
    for i in range(k):
        this_sum += array[i]
        if this_sum > max_sum:
            max_sum = this_sum
        elif this_sum < 0:
            this_sum = 0
    return max_sum


def max_sub_seq_sum_improve(k, array):
    this_sum = 0
    max_sum = 0
    end = 0
    flag = 0
    for i in range(k):
        if array[i] > 0:
            flag = 1
        this_sum += array[i]
        if this_sum > max_sum:
            max_sum = this_sum
            end = i  # 终点有可能就是大于最大和的位置
        elif this_sum < 0:
            this_sum = 0
    # print(end)  # 通过终点反推起点
    if flag == 0:  # 如果全是负数
        start = 0
        end = k - 1
        max_sum = 0
    else:
        temp_sum = 0
        temp_index = end
        while temp_sum != max_sum:
            temp_sum += array[temp_index]
            temp_index -= 1
            if temp_index == 1:  # debug, 当index移动到1的时候，结果加起来只是9，而不是10
                print(temp_sum)
        start = temp_index + 1  # 多减了一个，所以要加1
    return max_sum, start, end


def main():
    # k = 10
    test_k = 10
    test = [-10, 1, 2, 3, 4, -5, -23, 3, 7, -21]
    max_sum, start, end = max_sub_seq_sum_improve(test_k, test)
    print(max_sum, start, end)
    # array = [-10, 1, 2, 3, 4, -5, -23, 3, 7, -21]


if __name__ == '__main__':
    main()
