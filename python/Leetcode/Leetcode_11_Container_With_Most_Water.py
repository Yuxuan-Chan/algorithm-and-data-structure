#! python3
# -*- coding: utf-8 -*-


class Solution:
    def maxArea(self, height):
        """
        利用左右指针
        :type height: List[int]
        :rtype: int
        """
        max_area = 0
        l = 0
        r = len(height) - 1
        while l < r:
            max_area = max(max_area, min(height[l], height[r]) * (r - l))
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1
        return max_area
