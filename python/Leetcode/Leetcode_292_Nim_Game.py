#! python3
# -*- coding: utf-8 -*-


class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return n % 4 != 0
"""
这题概述的其实有点问题，
If there are 8 stones,
I can pick 3
Opponent can pick 3
I can pick 2 stones .
I win. So how is this solution valid.

In this question, both of you and your friend are very clever and have optimal strategies for the game.
So if you pick 3, the opponent will pick 2 then you will lose.
 
这里其实别人解释了游戏双方每次都会选择最优解，所以并不会出现上面说的你的对手故意让你赢的情况 
"""