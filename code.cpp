//https://leetcode.com/problems/median-of-two-sorted-arrays/description/

// the solution of binary search is too complecated since there are 2 different sorted arrays.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> maxHeap;

        for (int n1 : nums1) {
            maxHeap.push(n1);
        }

        for (int n2 : nums2) {
            maxHeap.push(n2);
        }

        int totalSize = nums1.size() + nums2.size();
        int totalPops = totalSize/2 - 1;
        while (totalPops > 0) {
            maxHeap.pop();
            --totalPops;
        }

        if (totalSize%2 == 0) {           
            int right = maxHeap.top();
            maxHeap.pop();
            int left = maxHeap.top();
            return (double)((double)(right + left)/2);
        } 

        maxHeap.pop();
        
        return (double)(maxHeap.top());
    
    }
};
