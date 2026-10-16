
class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        MOD = 1000000007
        n = len(nums)

        sm = [0] * (4 * n)
        sq = [0] * (4 * n)
        lazy = [0] * (4 * n)

        def apply(node, l, r, x):
            length = r - l + 1

            sq[node] = (
                sq[node]
                + 2 * x * sm[node]
                + length * x * x
            ) % MOD

            sm[node] = (
                sm[node]
                + length * x
            ) % MOD

            lazy[node] += x

        def push(node, l, r):
            if lazy[node] == 0 or l == r:
                return

            mid = (l + r) // 2
            x = lazy[node]

            apply(node * 2, l, mid, x)
            apply(node * 2 + 1, mid + 1, r, x)

            lazy[node] = 0

        def update(node, l, r, ql, qr):
            if ql <= l and r <= qr:
                apply(node, l, r, 1)
                return

            push(node, l, r)

            mid = (l + r) // 2

            if ql <= mid:
                update(node * 2, l, mid, ql, qr)

            if qr > mid:
                update(node * 2 + 1, mid + 1, r, ql, qr)

            sm[node] = (
                sm[node * 2] + sm[node * 2 + 1]
            ) % MOD

            sq[node] = (
                sq[node * 2] + sq[node * 2 + 1]
            ) % MOD

        last = {}
        ans = 0

        for r in range(n):
            x = nums[r]

            left = last.get(x, -1) + 1

            update(1, 0, n - 1, left, r)

            ans = (ans + sq[1]) % MOD

            last[x] = r

        return ans
