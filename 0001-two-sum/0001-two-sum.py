class Solution(object):
    def twoSum(self, nums, target):
       mpp = {}

       for i in range(len(nums)):
           c=target-nums[i]
           if c in mpp:
               return [mpp[c],i]
           else:
               mpp[nums[i]]=i

       return []