#! python3
# -*- coding: utf-8 -*-


class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype:
        """
        MAX_INT = 2147483647
        sign = 1 if (dividend > 0 and divisor > 0) or (dividend < 0 and divisor < 0) else -1
        quotient = 0
        dividend, divisor = abs(dividend), abs(divisor)
        while dividend >= divisor:
            temp, i = divisor, 1
            while dividend >= temp:
                dividend -= temp
                quotient += i
                temp <<= 1
                i <<= 1
        quotient = sign * quotient
        if quotient > MAX_INT:
            quotient = MAX_INT
        return quotient


if __name__ == '__main__':
    s = Solution()
    res = s.divide(10, 3)
    print(res)