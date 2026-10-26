class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1 , j = m + n - 1 , k = n - 1 ;
        while ( k >= 0 ) {
            if (i >= 0 && nums1[i] > nums2[k]) {
                nums1[j--] = nums1[i--];
            } else {
                nums1[j--] = nums2[k--];
            }
        }
    }
};