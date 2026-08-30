class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n = len(nums)

        min_val = nums[0]
        max_val = nums[0]
        min_index = 0
        max_index = 0

        for i in range(n):
            if nums[i] < min_val:
                min_val = nums[i]
                min_index = i

            if nums[i] > max_val:
                max_val = nums[i]
                max_index = i

        if min_index == max_index:
            answer = 1

        else:
            if min_index < max_index:
                left = min_index
                right = max_index
            else:
                left = max_index
                right = min_index

            from_front = right + 1
            from_back = n - left
            both_sides = (left + 1) + (n - right)

            answer = from_front

            if from_back < answer:
                answer = from_back

            if both_sides < answer:
                answer = both_sides

        return answer