#! python3
# -*- coding: utf-8 -*-


class Solution0:
    """
    Backtracking
    """
    def canJumpFromPosition(self, position, nums):
        if position == len(nums) - 1:
            return True

        furthestJump = min(position+nums[position], len(nums) - 1)
        for nextPosition in range(furthestJump, position, -1):
            if self.canJumpFromPosition(nextPosition, nums):
                return True

        return False

    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return self.canJumpFromPosition(0, nums)


class Solution1:
    """
    Dynamic Programming Top-down
    """
    memo = {}

    def canJumpFromPosition(self, position, nums):
        if self.memo[position] != 'UNKNOWN':
            return self.memo[position] == 'GOOD'
        furthestJump = min(position+nums[position], len(nums)-1)
        for nextPosition in range(position+1, furthestJump+1, 1):
            if self.canJumpFromPosition(nextPosition, nums):
                self.memo[position] = 'GOOD'
                return True
        self.memo[position] = 'BAD'
        return False

    def canJump(self, nums):
        for i in range(len(nums)):
            self.memo[i] = 'UNKNOWN'

        self.memo[len(nums)-1] = 'GOOD'
        return self.canJumpFromPosition(0, nums)


class Solution2:
    """
    Dynamic Programming Bottom-up
    """

    def canJump(self, nums):
        memo = {}
        for i in range(len(nums)):
            memo[i] = 'UNKNOWN'
        memo[len(nums) - 1] = 'GOOD'

        for i in range(len(nums)-2, -1, -1):
            furthestJump = min(i+nums[i], len(nums)-1)
            for j in range(i+1, furthestJump+1):
                if memo[j] == 'GOOD':
                    memo[i] = 'GOOD'
                    break
        return memo[0] == 'GOOD'


class Solution3:
    """
    Greedy
    """
    def canJump(self, nums):
        lastPos = len(nums) - 1
        for i in range(len(nums)-1, -1, -1):
            if i+nums[i] >= lastPos:
                lastPos = i
        return lastPos == 0


if __name__ == '__main__':
    # solution = Solution0()
    # res = solution.canJump([2, 3, 1, 1, 4])
    # print(res)
    # solution = Solution1()
    # res = solution.canJump([2, 3, 1, 1, 4])
    # print(res)
    # solution = Solution2()
    # res = solution.canJump([2, 3, 1, 1, 4])
    # print(res)
    solution = Solution3()
    res = solution.canJump([2, 3, 1, 1, 4])
    print(res)