#! python3
# -*- coding: utf-8 -*-


class Solution:
    def subsets(self, nums):
        def dfs(start, depth, valuelist):
            res.append(valuelist)
            if depth == len(nums):
                return
            else:
                for i in range(start, len(nums)):
                    dfs(i+1, depth+1, valuelist+[nums[i]])

        nums.sort()
        res = []
        dfs(0, 0, [])
        return res


class Solution0:
    # https://www.mathsisfun.com/sets/power-set.html
    def subsets(self, nums):
        result = []
        i, count = 0, 1 << len(nums)
        nums.sort()

        while i < count:
            cur = []
            for j in range(len(nums)):
                test = i & 1 << j
                if i & 1 << j:
                    cur.append(nums[j])
            if cur not in result:
                result.append(cur)
            i += 1
        return result


class Solution1:
    def subsets(self, nums):
        # 先把输出的东西摆上去
        result = []
        nums.sort()
        # 排除corner case, 就是返回一空的
        if len(nums) == 0:
            return result
        # 这个就是用来搜集每个子集的
        list = []
        self.dfs(result, list, 0, nums)
        return result

    def dfs(self, result, list, start, nums):
        # 先把当前的子集加上
        result.append([]+list)
        # 注意这里要从start位置开始循环，否则就是stackoverflow
        for i in range(start, len(nums)):
            # 添加start位置的数字
            list.append(nums[i])
            # 开始递归，比如把1加上去之后, 就稳住1, 找后面的比如2
            self.dfs(result, list, i+1, nums)
            # backtrack, 就是把之前加上的去掉，相当于往回走，比如之前加到1，2，3
            # 就把3去掉，然后再找
            list.pop()


if __name__ == '__main__':
    # solution = Solution()
    # res = solution.subsets([1, 2, 3])
    # print(res)
    # solution = Solution0()
    # solution.subsets([1, 2, 3])
    solution = Solution1()
    res = solution.subsets([1, 2, 3])
    print(res)