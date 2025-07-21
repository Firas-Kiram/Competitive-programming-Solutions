# Problem: Find K Pairs with Smallest Sums - https://leetcode.com/problems/find-k-pairs-with-smallest-sums
class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        heap = []
        for i in range(int(len(nums1))):
            for j in range(i , int(len(nums2))):
                x = (-nums1[i] - nums2[j] , nums1[i] , nums2[j])
                heappush(heap , x)
                if len(heap) == k + 1:
                    if x == heap[0]:
                        heappop(heap)
                        break
                    heappop(heap)
        for i in range(int(len(nums2))):
            for j in range( i + 1 , int(len(nums1))):
                x = (-nums2[i] - nums1[j] , nums1[j] , nums2[i])
                heappush(heap , x)
                if len(heap) == k + 1:
                    if x == heap[0]:
                        heappop(heap)
                        break
                    heappop(heap)
        return [[x[1] , x[2]] for x in heap]
