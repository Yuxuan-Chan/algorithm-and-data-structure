#! python3
# -*- coding: utf-8 -*-
import math


class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        nums1 = [1, 3]
        nums2 = [2]
        The median is 2.0

        nums1 = [1, 2]
        nums2 = [3, 4]
        The median is (2 + 3)/2 = 2.5

        :type nums1:
        :type nums2:
        :rtype: float
        """
        merged_list = nums1 + nums2

        def quick_sort(input_list):
            if len(input_list) < 2:
                return input_list
            else:
                pivot = input_list[0]
                left_pivot_list = [x for x in input_list[1:] if x <= pivot]
                right_pivot_list = [x for x in input_list[1:] if x > pivot]
                sorted_list = quick_sort(left_pivot_list) + [pivot] + quick_sort(right_pivot_list)
                return sorted_list

        after_sorted_list = quick_sort(merged_list)
        median = 0
        length = len(after_sorted_list)
        if length == 1:
            median = float(after_sorted_list[0])
        elif length == 2:
            median = sum(after_sorted_list) / 2
        elif length > 2:
            if length % 2 == 0:
                prev = int(length / 2) - 1
                current = int(length / 2)
                median = (after_sorted_list[prev] + after_sorted_list[current]) / 2
            elif length % 2 != 0:
                current = math.floor(length / 2)
                median = float(after_sorted_list[current])
        return median


if __name__ == '__main__':
    s = Solution()
    res1 = s.findMedianSortedArrays([1, 3], [2])
    res2 = s.findMedianSortedArrays([1, 2], [3, 4])
    res3 = s.findMedianSortedArrays([2], [])
    res4 = s.findMedianSortedArrays([1], [2])
    print(res1)
    print(res2)
    print(res3)
    print(res4)