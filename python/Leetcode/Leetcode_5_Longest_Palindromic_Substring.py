#! python3
# -*- coding: utf-8 -*-


# class Solution:
#     def longestPalindrome(self, s):
#         """
#         :type s: str
#         :rtype: str
#         1. 暴力遍历
#         2. 中心枚举
#         3. Manacher's Algorithm
#         4. 动态规划
#         """
#         l = len(s)
#         max_length = 0
#         palindromic = ''
#         for i in range(l):
#             # 奇数情况
#             x = 1
#             while i - x >= 0 and i + x < l:
#                 if s[i - x] == s[i + x]:
#                     x += 1
#                 else:
#                     break
#             x -= 1
#             if 2 * x + 1 > max_length:
#                 max_length = 2 * x + 1
#                 palindromic = s[i-x:i+x+1]
#             # 偶数情况
#             x = 0
#             if i + 1 < l:
#                 while i - x >= 0 and i + x + 1 < l:
#                     if s[i - x] == s[i + x + 1]:
#                         x += 1
#                     else:
#                         break
#             x -= 1
#             if 2 * x + 2 > max_length:
#                 max_length = 2 * x + 2
#                 palindromic = s[i-x:i+x+2]
#         if palindromic == '':
#             palindromic = s[0]
#         return palindromic


class Solution:
    def getlongestpalindrome(self, s, l, r):
        while l >= 0 and r <= len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l+1:r]

    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        palindrome = ''
        for i in range(len(s)):
            len1 = len(self.getlongestpalindrome(s, i, i))
            if len1 > len(palindrome):
                palindrome = self.getlongestpalindrome(s, i, i)
            len2 = len(self.getlongestpalindrome(s, i, i+1))
            if len2 > len(palindrome):
                palindrome = self.getlongestpalindrome(s, i, i+1)
        return palindrome



# class Solution:
#     def longestPalindrome(self, s):
#         """
#         DP
#         :param s:
#         :return:
#         """
#         if len(s) == 1:
#             return s
#         n = len(s)
#         start, end, maxL = 0, 0, 0
#         dp = [[0] * n for _ in range(n)]
#         for i in range(n):
#             for j in range(i):
#                 dp[j][i] = (s[j] == s[i] and (i - j < 2 or dp[j+1][i-1]))
#                 if dp[j][i] and maxL < i - j + 1:
#                     maxL = i - j + 1
#                     start = j
#                     end = i
#             dp[i][i] = 1
#         return s[start: end + 1]


if __name__ == '__main__':
    s = Solution()
    res = s.longestPalindrome("babad")
    print(res)
