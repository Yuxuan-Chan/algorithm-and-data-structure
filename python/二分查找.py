#! python3
# -*- coding: utf-8 -*-


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


def binary_search_recursive(array, left, right, x):
    # 递归版本，递归首先想退出条件
    mid = (left + right) // 2
    if array[mid] == x:
        return mid
    else:
        if left > right:
            return -1
        if array[mid] > x:
            return binary_search_recursive(array, left, mid-1, x)
        elif array[mid] < x:
            return binary_search_recursive(array, mid+1, right, x)


def main():
    # res = binary_search([1, 2, 3, 4], 0, 3, 5)
    # print(res)
    res = binary_search_recursive([1, 2, 3, 4], 0, 3, 4)
    print(res)


if __name__ == '__main__':
    main()

