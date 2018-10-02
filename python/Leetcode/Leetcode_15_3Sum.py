#! python3
# -*- coding: utf-8 -*-


class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = set()
        for n in range(len(nums)):
            target = -nums[n]
            left = n + 1
            right = len(nums) - 1
            while left < right:
                if nums[left] + nums[right] < target:
                    left += 1
                elif nums[left] + nums[right] > target:
                    right -= 1
                elif nums[left] + nums[right] == target:
                    res.add((nums[n], nums[left], nums[right]))
                    left += 1
                    right -= 1
        return [list(x) for x in res]


if __name__ == '__main__':
    s = Solution()
    res = s.threeSum([1, 2, -2, -1])
    print(res)
