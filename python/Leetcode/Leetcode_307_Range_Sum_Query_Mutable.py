#! python3
# -*- coding: utf-8 -*-


class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums

    def update(self, i, val):
        """
        :type i: int
        :type val: int
        :rtype: void
        """
        self.nums[i] = val

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return sum(self.nums[i:j+1])

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(i,val)
# param_2 = obj.sumRange(i,j)


if __name__ == '__main__':
    obj = NumArray([1, 3, 5])
    print(obj.sumRange(0, 2))
    obj.update(1, 2)
    print(obj.sumRange(0, 2))
"""
利用线段树来解决
public class NumArray {
    int[] tree;
    int n;
    public NumArray(int[] nums){
        if (nums.length > 0){
            n = nums.length;
            tree = new int[n * 2];
            buildTree(nums);
        }
    }

    /*if some node p holds the sum of [i...j] range,
    * its left and right children hold the sum for range [i...(i+j)/2]
    * and [(i+j)/2+1, j] respectively, therefore to find the sum of node p,
    * we need to calculate the sum of its right and left child in advance
    * we begin from the leaves, initialize them with input array elements a[0, 1, ..., n-1]
    * then we move upward to the higher level to calculate the parents' sum till we get to
    * the root of the segment tree
    * 对于数组中的任意结点i, 其左子结点为2*i, 右子结点为2*i+1, 其母结点为i/2
    * */
    private void buildTree(int[] nums){
        for (int i = n, j = 0; i < 2 * n; i++, j++)
            tree[i] = nums[j];
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    void update(int pos, int val){
        pos += n;
        tree[pos] = val;
        while (pos > 0){
            int left = pos;
            int right = pos;
            if (pos % 2 == 0){
                right = pos + 1;
            }
            else{
                left = pos - 1;
            }
            // parent is updated after child is updated
            tree[pos / 2] = tree[left] + tree[right];
            pos /= 2;
        }
    }

    public int sumRange(int l, int r){
        l += n;
        r += n;
        int sum = 0;
        while (l <= r){
            if ((l % 2) == 1){
                sum += tree[l];
                l++;
            }
            if ((r % 2) == 0){
                sum += tree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        }
        return sum;
    }

    public static void main(String[] args){
        int[] tree = {1, 3, 5};
        NumArray object = new NumArray(tree);
        int sum0 = object.sumRange(0, 2);
        object.update(1, 2);
        int sum1 = object.sumRange(0, 2);
        System.out.println(sum0);
        System.out.println(sum1);
    }
}

"""