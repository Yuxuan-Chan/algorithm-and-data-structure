#! python3
# -*- coding: utf-8 -*-


class Solution:
    def max_heapify(self, heap, heapsize, root):
        left = 2*root+1
        right = left+1
        larger = root
        if left < heapsize and heap[larger] < heap[left]:
            larger = left
        if right < heapsize and heap[larger] < heap[right]:
            larger = right
        if root != larger:
            heap[root], heap[larger] = heap[larger], heap[root]
            self.max_heapify(heap, heapsize, larger)

    def build_max_heap(self, heap):
        heapsize = len(heap)
        for i in range((heapsize-2)//2, -1, -1):
            self.max_heapify(heap, heapsize, i)

    def heap_sort(self, heap):
        self.build_max_heap(heap)
        for i in range(len(heap) - 1, -1, -1):
            heap[0], heap[i] = heap[i], heap[0]
            self.max_heapify(heap, i, 0)
        return heap

    def findKthLargest(self, nums, k):
        sorted_nums = self.heap_sort(nums)
        return sorted_nums[::-1][k-1]


if __name__ == '__main__':
    solution = Solution()
    result1 = solution.heap_sort([3, 2, 1, 5, 6, 4])
    print(result1)
    print(result1[::-1])
    result2 = solution.heap_sort([3, 2, 3, 1, 2, 4, 5, 5, 6])
    print(result2)
