
class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if sum > 9 * num:
            return ""

        ans = ""

        while num > 0:
            x = min(9, sum)
            ans += str(x)
            sum -= x
            num -= 1

        return ans