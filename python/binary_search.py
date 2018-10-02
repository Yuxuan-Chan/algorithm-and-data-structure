#! python3
# -*- coding: utf-8 -*-


def search(input_list, target):
    low = 0
    high = len(input_list) - 1
    while low <= high:
        mid = (low + high) // 2
        guess = input_list[mid]
        if guess < target:
            high = mid + 1
        elif guess > target:
            low = mid - 1
        elif guess == target:
            return mid
    return None


if __name__ == '__main__':
    res = search([1, 2, 3, 4], 2)
    print(res)