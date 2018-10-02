#! python3
# -*- coding: utf-8 -*-
import collections
from functools import reduce


class Solution(object):
    def longestWord(self, words):
        potential_answers = []
        for word in words:
            word_length = len(word)
            start = 1
            while start <= word_length:
                prefix = word[:start]
                if prefix not in words:
                    break
                start += 1
            else:
                # 如果没有break循环退出
                potential_answers.append(word)
        print(potential_answers)
        max_length = len(max(potential_answers))
        equal_max_length_answers = []
        for potential_answer in potential_answers:
            if len(potential_answer) == max_length:
                equal_max_length_answers.append(potential_answer)
        print(equal_max_length_answers)
        if len(equal_max_length_answers) == 0:
            return equal_max_length_answers[0]
        else:
            equal_max_length_answers.sort()
            return equal_max_length_answers[0]


class Solution0(object):
    def logestWord(self, words):
        wordset = set(words)
        words.sort(key=lambda c: (-len(c), c))
        for word in words:
            if all(word[:k] in wordset for k in range(1, len(word))):
                # all() 函数用于判断给定的可迭代参数iterable中的所有参数是否都为True, 如果是返回True, 否则返回False
                return word
        return ""

"""
private:
    struct node {
        char letter;
        bool isWord;
        node *children[26];
    };
    node *root;
    
containsWord?
    Trace path, check isWord, O(length)
containsPrefix?
    Trace path O(length)
add?
    Trace path, add new nodes as needed O(length)
space usage?
    per-node = 106
空间换时间
O(length) not dependent on num words?

private:
    struct node {
        char letter;
        bool inWord;
        node **children;
        int mChildren;
    };
    node *root; 
"""
class Node(object):
    def __init__(self):
        # Note that using dictionary for children (as in this implementation) would not allow lexicographic sorting mentioned in the next section (Sorting),
        # because ordinary dictionary would not preserve the order of the keys
        self.children = []
        self.value = None

    def find(self, node, key):
        for char in key:
            if char in node.children:
                node = node.children[char]
            else:
                return False

        return node.value

    def insert(self, root, string, value):
        node = root
        index_last_char = None
        for index_char, char in enumerate(string):
            if char in node.children:
                node = node.children[char]
            else:
                index_last_char = index_char
                break

        # append new nodes for the remaining characters, if nay
        if index_last_char is not None:
            for char in string[index_last_char:]:
                node.children[char] = Node()
                node = node.children[char]

        # store value in the terminal node
        node.value = value


class Solution1(object):
    """
    As prefixes of strings are involved, this is usually a natural fit for a trie (a prefix tree.)
    Put every word in a trie, then depth-first-search from the start of the trie, only searching nodes that ended a word
    关于函数式编程的reduce用法:
    基础用法:
    def add(x, y):
        return x+y
    reduce(add, range(1, 11)) = 1+2+3+4+5+6+7+8+9+10
    reduce(add, range(1, 11), 20) = 1+2+3+4+5+6+7+8+9+10+20

    reduce(list.__add__, [[1, 2, 3], [4, 5], [6, 7, 8]], []) = [1, 2, 3, 4, 5, 6, 7, 8]

    d = {"a": {"b": {"c": 4}}}
    l = ["a", "b", "c"]
    for x in l:
        d = d[x]
    print (d) # 4

    reduce(dict.__getitem__, l, d)
    """
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """


class TrieNode(object):
    def __init__(self):
        self.word = ""
        self.links = [None] * 26

    def insert(self, s):
        curNode = self
        for i in range(len(s)):
            index = ord(s[i]) - 97  # 'a' == 0 'b' == 1
            if curNode.links[index] is None:
                curNode.links[index] = TrieNode()
            curNode = curNode.links[index]
        curNode.word = s


class Solution2(object):
    def longestWord(self, words):
        root = TrieNode()
        root.word = "-"
        for word in words:
            root.insert(word)
        return self.dfs(root, "")

    def dfs(self, node, accum):
        if node is None or len(node.word) == 0:
            return accum
        res = ""
        if node.word != "-":
            accum = node.word
        for child in node.links:
            curRes = self.dfs(child, accum)
            if len(curRes) > len(res) or (len(curRes) == len(res) and curRes < res):
                print("res %s" % res)
                print("curRes %s" % curRes)
                res = curRes
        return res


if __name__ == '__main__':
    # solution = Solution()
    # res0 = solution.longestWord(["w", "wo", "wor", "worl", "world"])
    # res1 = solution.longestWord(["a", "banana", "app", "appl", "ap", "apply", "apple"])
    # print(res0)
    # print(res1)
    # res2 = solution.longestWord(["b","br","bre","brea","break","breakf","breakfa","breakfas","breakfast"])
    # print(res2)
    # solution = Solution1()
    # solution.longestWord(["w", "wo", "wor", "worl", "world"])
    solution = Solution2()
    # res0 = solution.longestWord(["w", "wo", "wor", "worl", "world"])
    res1 = solution.longestWord(["a", "banana", "app", "appl", "ap", "apply", "apple"])
    # print(res0)
    print('$$$$')
    print(res1)
