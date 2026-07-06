class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:

        res = []

        for i in range(len(intervals)):
            curr_interval = intervals[i]

            #Current interval is completely before newInterval
            if curr_interval[1] < newInterval[0]:
                res.append(curr_interval)

            #Current interval is completely after newInterval
            elif curr_interval[0] > newInterval[1]:
                res.append(newInterval)
                newInterval = curr_interval

            #Overlapping
            else:
                newInterval[0] = min(curr_interval[0], newInterval[0])
                newInterval[1] = max(curr_interval[1], newInterval[1])

        res.append(newInterval)

        return res


