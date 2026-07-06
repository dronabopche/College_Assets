class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0]) # sorting

        res = []
        res.append(intervals[0])

        for i in range(1,len(intervals)):
            last = res[-1]
            curr = intervals[i]

            if last[1] >= curr[0]:
                last[0] = min(curr[0],last[0])
                last[1] = max(curr[1],last[1])

            else:
                res.append(curr)

        return res


