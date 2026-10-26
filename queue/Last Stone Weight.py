import heapq
class Solution:
    def lastStoneWeight(self, stones):
        q = [-stone for stone in stones]
        heapq.heapify(q)

        while len(q) > 1:
            y = -heapq.heappop(q)
            x = -heapq.heappop(q)

            if x != y:
                heapq.heappush(q, -(y - x))

        if len(q) == 0:
            return 0
        else: 
            return -q[0]
