#! python3
# -*- coding: utf-8 -*-


class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        Given array nums = [1, 0, -1, 0, -2, 2]
        target = 0
        A solution set is:
        [
            [-1, 0, 0, 1],
            [-2, -1, 1, 2],
            [-2, 0, 0, 2]
        ]
        通过哈希表进行空间换时间
        """
        nums_length, res, cache = len(nums), set(), {}
        if nums_length < 4:
            return []
        nums.sort()
        for i in range(nums_length):
            for j in range(i+1, nums_length):
                two_sum = nums[i] + nums[j]
                if two_sum in cache.keys():
                    cache[two_sum].append((i, j))
                else:
                    cache[two_sum] = [(i, j)]
        for i in range(nums_length):
            for j in range(i+1, nums_length):
                difference = target - nums[i] - nums[j]
                if difference in cache.keys():
                    for item in cache[difference]:
                        if item[0] > j:
                            res.add((nums[i], nums[j], nums[item[0]], nums[item[1]]))
        return [list(x) for x in res]


if __name__ == '__main__':
    s = Solution()
    result = s.fourSum([1, 0, -1, 0, -2, 2], 0)
    print(result)