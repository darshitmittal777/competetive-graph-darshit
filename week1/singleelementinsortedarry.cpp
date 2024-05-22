class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid = s + (e-s)/2;
        while(s<e)
        {
            if((nums[mid]==nums[mid-1]&&(mid-s+1)%2==0))
            {
                s=mid+1;
            }
            else if((nums[mid]==nums[mid+1]&&(e-mid+1)%2==1))
            {
                s=mid;
            }
            else if((nums[mid]==nums[mid-1]&&(mid-s+1)%2==1))
            {
                e=mid;
            }
            else if((nums[mid]==nums[mid+1]&&(e-mid+1)%2==0))
            {
                e = mid-1;
            }
            else
            {
                return nums[mid];
            }
            mid = s + (e-s)/2;
        }
        return nums[mid];
    }
};