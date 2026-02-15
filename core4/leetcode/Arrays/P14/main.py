class Solution:

    def bubble_sort(self, strs):
        n = len(strs)
        for i in range(n):
            for j in range(0, n - i - 1):
                if strs[j] > strs[j + 1]:
                    strs[j], strs[j + 1] = strs[j + 1], strs[j]

    def longest_common_prefix(self, strs):
        if not strs:
            return ""

        # Sort using bubble sort (as in your C++ version)
        self.bubble_sort(strs)

        first = strs[0]
        last = strs[-1]

        i = 0
        while i < len(first) and i < len(last) and first[i] == last[i]:
            i += 1

        result = ""
        for k in range(i):
            result += first[k]

        return result


if __name__ == "__main__":
    strs = ["flower", "flow", "flight"]

    solver = Solution()
    print("Longest Common Prefix:", solver.longest_common_prefix(strs))

