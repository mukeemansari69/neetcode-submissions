class Solution {
public:
    int helper(int lo, int hi, vector<int>& nums, int target) {
        while(lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        // Find pivot (minimum element index)
        while(low < high) {
            int mid = low + (high - low) / 2;

            if(nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }

        int idx = low;

        int ans = helper(0, idx - 1, nums, target);

        if(ans == -1)
            ans = helper(idx, nums.size() - 1, nums, target);

        return ans;
    }
};