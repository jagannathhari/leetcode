class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        n = len(nums)
        k = -1
        for i in range(n-2,-1,-1):
            if nums[i] < nums[i+1]:
                k = i
                break
        if k == -1:
            nums.sort()
            return
        l = k+1
        for i in range(k+1,n):
            if nums[k] < nums[i]:
                l = i
        nums[k] , nums[l] = nums[l] , nums[k]
        left = k+1
        right = n-1
        while left<=right:
            nums[left] , nums[right] = nums[right] , nums[left]
            left += 1
            right-=1
