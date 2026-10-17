class Solution:
    def minSwaps(self, nums: List[int]) -> int:
        def digit_sum(x):
            total = 0
            while x:
                total += x % 10
                x //= 10
            return total

        n = len(nums)

        # Sorted target array
        target = sorted(nums, key=lambda x: (digit_sum(x), x))

        # Map each value to its current index
        pos = {nums[i]: i for i in range(n)}

        swaps = 0

        for i in range(n):
            # Already in correct position
            if nums[i] == target[i]:
                continue

            # Index where target[i] currently is
            j = pos[target[i]]

            # Swap
            nums[i], nums[j] = nums[j], nums[i]

            # Update positions
            pos[nums[j]] = j
            pos[nums[i]] = i

            swaps += 1

        return swaps