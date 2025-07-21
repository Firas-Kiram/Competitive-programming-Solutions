# problem : Top K Frequent Elements - https://leetcode.com/problems/top-k-frequent-elements/
from heapq import heappush , heappop 
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        a = [0] * (20001)

        for x in nums :
            a[x + 10000] += 1
        heap = []
        for i in range(20001):
            heappush(heap , (a[i] , i - 10000))
            if len(heap) > k : heappop(heap)

        return [x[1] for x in heap]
        
