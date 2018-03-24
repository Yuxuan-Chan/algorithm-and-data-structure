#! python3
# -*- coding: utf-8 -*-
"""https://blog.csdn.net/abnerwang2014/article/details/36027747"""


def max_sub_seq_sum(left, right, array):
    if left == right:  # 递归的基准情形
        return array[left]

    mid = (left + right) // 2  # 求分界点
    max_left_sum = max_sub_seq_sum(left, mid, array)  # 递归，求左半部分子序列的最大子序列和
    max_right_sum = max_sub_seq_sum(mid+1, right, array)  # 递归，求右半部分子序列的最大子序列和

    # 求横跨左半部分和右半部分的最大子序列和
    # 首先是左半部分子序列中包含最后一个元素的最大子序列和
    max_left_border_sum = array[mid]
    left_border_sum = array[mid]
    for i in range(left+1, mid):  # 这里要注意博客里的是错的，横跨左右的部分不能包含左边界的
        # 从left+1到mid-1
        left_border_sum += array[i]
        if left_border_sum > max_left_border_sum:
            max_left_border_sum = left_border_sum

    # 接着是右半部分子序列中包含第一个元素的最大子序列和
    max_right_border_sum = array[mid+1]
    right_border_sum = array[mid+1]
    for i in range(mid+2, right):  # 这里要注意博客里的是错的，横跨左右的部分不能包含右边界的
        # 从mid+2到right-1
        right_border_sum += array[i]
        if right_border_sum > max_right_border_sum:
            max_right_border_sum = right_border_sum

    return max(max_left_sum, max_right_sum, max_left_border_sum+max_right_border_sum)


def main():
    array = [-2, 11, -4, 13, -5, -2]
    res = max_sub_seq_sum(0, 5, array)
    print(res)


if __name__ == '__main__':
    main()