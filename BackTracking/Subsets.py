class Solution:
    def backTrack(seft, first, curr, nums):
        seft.output.append(curr[:])

        for i in range (first, seft.n):
            curr.append(nums[i])
            backTrack(i + 1, curr, nums)
            curr.pop()

    def subsets(seft, nums):
        seft.output = []
        seft.n = len(nums)
        seft.backTrack(0, [], nums)
        return seft.output

