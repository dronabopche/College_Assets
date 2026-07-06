class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))

        res = []
        res.append(intervals[0])

        for i in range(1, len(intervals)):
            last = res[-1]
            curr = intervals[i]

            if last[0] <= curr[0] and last[1] >= curr[1]:
                continue
            else:
                res.append(curr)

        return len(res)