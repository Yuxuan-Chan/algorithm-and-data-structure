#! python3
# -*- coding: utf-8 -*-


class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        char array 代表任务 A-Z不同的字母代表不同的任务
        任务可以不用原来的顺序去完成
        每个任务可以在一个间隔的时间内完成，对于每个间隔，cpu可以完成一个任务或者什么事情都不干
        但是，有一个非负的冷却间隔n, 意味着在两个相同的任务之间，必须至少有n个间隔，cpu在做不同的任务或者闲置
        Input: tasks = ["A","A","A","B","B","B"], n = 2
        Output: 8
        Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.  是不是A -> B -> idle -> A 本来A做完第一个，然后再做A时
        要有两个间隔，但B占用了一个，所以就只要一个了，这样的话，结果就是8
        策略：先统计数组中各个任务出现的次数。优先安排次数最多的任务。次数最多的任务安排完成之后所需的时间间隔为（max(次数)-1）*（n+1）+1。其余任务直接插空即可。
        """
        output = [0] * 26
        for i in tasks:
            output[ord(i) - ord('A')] += 1

        count = 0
        max_o = max(output)
        for i in output:
            if i == max_o:
                count += 1
        print(max_o)  # 3
        print(count)  # 2
        return max(len(tasks), (max_o-1)*(n+1)+count)
        # (max_o -1)*(n+1) 间隔时间
        # count 剩下的最后一个元素的时间
        # A__A__A 对于这种情况，先计算间隔时间，也就是A__A__ 即（3-1)*(2+1) 还要包括本身的元素A的时间
        # 然后再加上最后一个A, 那么如果添加B之后呢？前面的间隔时间并不会因此改变，变成这样， AB_AB_
        # 最后还要加上1个B, AB_AB_AB, 所以最后结果就很清楚了，当然如果n是1的话，就不需要这么计算，直接取队列的长度即可


if __name__ == '__main__':
    s = Solution()
    s.leastInterval(tasks = ["A","A","A","B","B","B"], n=2)
