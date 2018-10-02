#! python3
# -*- coding: utf-8 -*-


class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class Solution:
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals.sort(key=lambda x: x.start)

        merged = []
        for interval in intervals:
            if not merged or merged[-1].start > interval.end:
                merged.append(interval)
            else:
                merged[-1].end = max(interval.end, merged[-1].end)
        return merged


def merge(intervals):
    """
    :type intervals: List[Interval]
    :rtype: List[Interval]
    """
    length = len(intervals)
    res = []
    for i, j in zip(range(0, length-1), range(1, length)):
        prev_list = intervals[i]
        later_list = intervals[j]
        prev_max = max(prev_list)
        later_min = min(later_list)
        if prev_max >= later_min:
            prev_min = min(prev_list)
            later_max = max(later_list)
            new_list = [prev_min, later_max]
            res.append(new_list)
        else:
            res.append(later_list)
    print(res)
    return res


if __name__ == '__main__':
    merge([[1, 3], [2, 6], [8, 10], [15, 18]])
    merge([[1, 4], [4, 5]])
