
class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        maxi = 0
        first = values[0] + 0
        for j in range(1, len(values)):
            second = values[j] - j
            maxi = max(maxi , first + second)
            first = max(first , values[j] + j)
        return maxi