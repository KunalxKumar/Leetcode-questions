class Solution:
    def groupAnagrams(self, strs):
        mp = {}

        for s in strs:
            freq = [0] * 26

            for ch in s:
                freq[ord(ch) - ord('a')] += 1

            key = tuple(freq)

            if key not in mp:
                mp[key] = []

            mp[key].append(s)

        return list(mp.values())