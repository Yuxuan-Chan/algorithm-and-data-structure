#! python3
# -*- coding: utf-8 -*-


class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        max_length = 0
        hash_map = {}
        start = 0
        for i in range(length):
            if s[i] in hash_map.keys():
                start = max(start, hash_map[s[i]])
            # print(start, i)
            max_length = max(max_length, i - start + 1)
            hash_map[s[i]] = i + 1
        # print(max_length)
        return max_length


if __name__ == '__main__':
    # lengthOfLongestSubstring('abcabcbb')
    # lengthOfLongestSubstring('ah')
    s = Solution()
    res = s.lengthOfLongestSubstring('dvdf')
    print(res)
    # lengthOfLongestSubstring('abba')
