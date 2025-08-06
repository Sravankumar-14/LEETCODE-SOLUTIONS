from collections import defaultdict 
class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:



        l=[[]]
        d=defaultdict(int)
        d[0]=1
        s=0
        c=0
        for i in range(len(nums)):
            s+=nums[i]
            s=s%k
            if d[s]!=0:
                c+=d[s]
            d[s]+=1
           
           
        return c
        #[5], [5, 0], [0],[5, 0, -2, -3],  [0, -2, -3], [-2, -3]
        #[4, 5, 0, -2, -3, 1],
            

            


        return c-1



        