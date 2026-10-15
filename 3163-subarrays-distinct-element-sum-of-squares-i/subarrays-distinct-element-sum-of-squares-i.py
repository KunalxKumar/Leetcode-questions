
class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)

        for i in range(n):
            s = set()

            for j in range(i, n):
                s.add(nums[j])
                x = len(s)
                ans += x * x

        return ans