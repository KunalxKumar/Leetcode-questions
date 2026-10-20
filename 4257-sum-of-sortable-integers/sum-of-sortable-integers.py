class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)
        target = sorted(nums)

        # Find all divisors of n
        divisors = []
        d = 1

        while d * d <= n:
            if n % d == 0:
                divisors.append(d)

                if d * d != n:
                    divisors.append(n // d)

            d += 1

        def works(k):
            # Check every block of size k
            for left in range(0, n, k):

                # Find the "break" in the cyclically sorted block.
                # Example:
                # [3, 4, 1, 2]
                #       ^
                # break occurs between 4 and 1

                breaks = 0
                start = 0

                for i in range(left, left + k - 1):
                    if nums[i] > nums[i + 1]:
                        breaks += 1
                        start = i + 1 - left

                        if breaks > 1:
                            return False

                # Compare the rotated block with its
                # corresponding part in the sorted array.
                for j in range(k):
                    idx = left + (start + j) % k

                    if nums[idx] != target[left + j]:
                        return False

            return True

        answer = 0

        for k in divisors:
            if works(k):
                answer += k

        return answer