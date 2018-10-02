#! python3
# -*- coding: utf-8 -*-


class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead
        """
        zero_num, one_num, two_num = 0, 0, 0
        for i in nums:
            if i == 0:
                zero_num += 1
            elif i == 1:
                one_num += 1
            elif i == 2:
                two_num += 1
        for i in range(zero_num):
            nums[i] = 0
        for i in range(one_num):
            nums[zero_num+i] = 1
        for i in range(two_num):
            nums[zero_num+one_num+i] = 2
        return nums


class Solution0:
    def sortColors(self, nums):
        n0, n1, n2 = -1, -1, -1
        for i in range(len(nums)):
            if nums[i] == 0:
                n2 += 1
                nums[n2] = 2
                n1 += 1
                nums[n1] = 1
                n0 += 1
                nums[n0] = 0
            elif nums[i] == 1:
                n2 += 1
                nums[n2] = 2
                n1 += 1
                nums[n1] = 1
            elif nums[i] == 2:
                n2 += 1
                nums[n2] = 2
        print(nums)


if __name__ == '__main__':
    # solution = Solution()
    # res = solution.sortColors([2,0,2,1,1,0])
    # print(res)
    solution0 = Solution0()
    solution0.sortColors([2, 0, 2, 1, 1, 0])
