#! python3
# -*- coding: utf-8 -*-
import re


class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        try:
            str = str.strip()
            str = re.search('(^[\+\-]?\d+)', str).group()
            number = int(str)
            number = number if number <= INT_MAX else INT_MAX
            number = number if number >= INT_MIN else INT_MIN
            return number
        except Exception as err:
            return 0


