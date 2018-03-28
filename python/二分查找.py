#! python3
# -*- coding: utf-8 -*-


# def binary_search(array, length, x):
#     """
#     按顺序从小到大排列
#     :param array:
#     :param length:
#     :param x:
#     :return:
#     """
#     # position = 0
#     # if array[position] == x:
#     #     return position
#     mid = length // 2
#     if array[mid] == x:
#         return mid
#     elif array[mid] > x:  # 往数组左边寻找
#         binary_search(array[0:mid], mid, x)
#     elif array[mid] < x:
#         binary_search(array[mid+1:length], length - mid, x)


def binary_search(array, left, right, x):
    while left <= right:
        mid = (left + right) // 2
        if array[mid] == x:
            return mid
        elif array[mid] > x:
            right = mid
        elif array[mid] < x:
            left = mid + 1
    return -1


def main():
    res = binary_search([1, 2, 3, 4], 0, 3, 5)
    print(res)


if __name__ == '__main__':
    main()

