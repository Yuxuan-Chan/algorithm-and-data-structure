#! python3
# -*- coding: utf-8 -*-


class Solution:
    def combine_two_list(self, current_letters, next_letters):
        res = []
        for i in range(len(current_letters)):
            for j in range(len(next_letters)):
                res.append(current_letters[i]+next_letters[j])
        return res

    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        digit_letter_map = {'2': ['a', 'b', 'c'],
                            '3': ['d', 'e', 'f'],
                            '4': ['g', 'h', 'i'],
                            '5': ['j', 'k', 'l'],
                            '6': ['m', 'n', 'o'],
                            '7': ['p', 'q', 'r', 's'],
                            '8': ['t', 'u', 'v'],
                            '9': ['w', 'x', 'y', 'z']}
        res = []
        digits_length = len(digits)
        for i in range(digits_length):
            current_letters = digit_letter_map[digits[i]]
            if len(res) == 0:
                res.extend(current_letters)
            else:
                res = self.combine_two_list(res, current_letters)
        return res

