#! python3
# -*- coding: utf-8 -*-
from collections import defaultdict


class Solution(object):
    count = 0
    possible_result = defaultdict(list)

    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        找寻最长的增长路径
        可以向4个方向移动，左，右，上，下， 不能对角线移动
        """
        if len(matrix) == 0:
            return 0
        memoization = defaultdict(list)  # 选择周围有比当前元素大的起始元素 (x, y) [可能路径], 遍历的同时一旦发现不满足条件的元素，立刻舍弃
        row_length = len(matrix)
        col_length = len(matrix[0])
        for row_index, row in enumerate(matrix):
            x = row_index
            for col_index, element in enumerate(row):
                y = col_index
                four_direction_coordinates = [(x-1, y), (x, y-1), (x+1, y), (x, y+1)]
                valid_coordinates = []
                for coordinate in four_direction_coordinates:
                    # 去除周围可能越界的坐标
                    if 0 <= coordinate[0] < row_length and 0 <= coordinate[1] < col_length:
                        valid_coordinates.append((coordinate[0], coordinate[1]))
                for coordinate in valid_coordinates:
                    # 只要有周围有一个元素值比当前值大就是合法的
                    if element < matrix[coordinate[0]][coordinate[1]]:
                        memoization[(x, y)].append((coordinate[0], coordinate[1]))
                    else:
                        continue
        print(memoization)
        def countIncreasingPath(start_coordinate):
            if start_coordinate in memoization.keys():
                for possible_path in memoization[start_coordinate]:
                    count = 0
                    countIncreasingPath((possible_path[0], possible_path[1]))

            return self.count

        print(countIncreasingPath((1, 0)))
        print(self.possible_result)
        # result = []
        # for key, value in memoization.items():
        #     result.append(countIncreasingPath(key))
        #     self.count = 0
        # print(result)
        # if len(result) == 0:
        #     return 1
        # return max(result) + 1


class Solution0(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        memory = [[None] * len(matrix[0]) for i in range(len(matrix))]
        res = 0
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                res = max(res, self.helper(i, j, matrix, memory))
        return res

    def helper(self, i, j, matrix, memory):
        if memory[i][j]:
            return memory[i][j]
        count = 0
        if i - 1 >= 0 and matrix[i - 1][j] > matrix[i][j]:
            count = max(count, self.helper(i - 1, j, matrix, memory))
        if j - 1 >= 0 and matrix[i][j - 1] > matrix[i][j]:
            count = max(count, self.helper(i, j - 1, matrix, memory))
        if i + 1 < len(matrix) and matrix[i + 1][j] > matrix[i][j]:
            count = max(count, self.helper(i + 1, j, matrix, memory))
        if j + 1 < len(matrix[0]) and matrix[i][j + 1] > matrix[i][j]:
            count = max(count, self.helper(i, j + 1, matrix, memory))
        memory[i][j] = count + 1
        return count + 1


if __name__ == '__main__':
    solution = Solution0()
    # solution.longestIncreasingPath([[9,9,4],[6,6,8],[2,1,1]])
    # solution.longestIncreasingPath([[1]])
    print(solution.longestIncreasingPath([[9,9,4],[6,6,8],[2,1,1]]))