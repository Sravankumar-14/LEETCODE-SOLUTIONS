class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        b = len(nums) -1
        a = 0
        while(a <= b):
            if nums[b] == val : 
                b -= 1
                continue
            if nums[a] != val:
                a += 1
                continue
            if nums[a] == val :
                nums[a] , nums[b] = nums[b] , nums[a]
                a += 1
                b -= 1
        return a
            
