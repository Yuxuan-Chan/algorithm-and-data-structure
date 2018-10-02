#! python3
# -*- coding: utf-8 -*-


class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        res = []
        for index, num in enumerate(nums):
            diff = target - num
            if diff in nums:
                diff_index = nums.index(diff)
                if index != diff_index:
                    res.append(diff_index)
                    res.append(index)
                    break
            else:
                continue
        res.sort()
        return res
