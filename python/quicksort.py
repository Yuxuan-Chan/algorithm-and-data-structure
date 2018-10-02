#! python3
# -*- coding: utf-8 -*-


def quick_sort(input_list):
    if len(input_list) < 2:
        return input_list
    else:
        pivot = input_list[0]
        left_pivot_list = [i for i in input_list[1:] if i <= pivot]
        right_pivot_list = [i for i in input_list[1:] if i > pivot]
        sorted_list = quick_sort(left_pivot_list) + [pivot] + quick_sort(right_pivot_list)
        return sorted_list


if __name__ == '__main__':
    res = quick_sort([1, 4, 3, 2])
    print(res)