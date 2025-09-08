class Solution {
public:
    int search(vector<int>& nums, int target) {
        int p = 0, mid;
        int n = nums.size();

        if(n <=2){
            for(int i = 0;i<n;i++){
                if(nums[i] == target){
                    return i;
                }
            }
            return -1;
        }

        for(int i= 0;i < n-1;i++){
            if(nums[i] > nums[i+1]){
                p = i;
                break;
            }
        }
        if (p == 0){
            int left=0, right = n-1;
            
            while(left <= right){
                if( left == right){
                    if(nums[left] != target) return -1;
                    else return left;
                }
                mid = (left + right) /2;
                if ( target == nums[mid]){
                    return mid;
                }else if(target < nums[mid]){
                    right = mid;
                }else{
                    left = mid + 1;
                }
            }
            return -1;
        }else{
            int left=0, right = n-1;
            if ( target == nums[0]){
                return  0;
            }else if( target < nums[0]){ // 
                left = p+1;
                while(left <= right){
                    if( left == right){
                        if(nums[left] != target) return -1;
                        else return left;
                    }
                    mid = (left + right)/2;
                    if(nums[mid] == target){
                        return mid;
                    }else if ( nums[mid] > target){
                        right = mid;
                    }else{
                        left = mid + 1;
                    }
                }
            }else{
                right = p;
                while(left <= right){
                    if( left == right){
                        if(nums[left] != target) return -1;
                        else return left;
                    }
                    mid = (left + right)/2;
                    if(nums[mid] == target){
                        return mid;
                    }else if ( nums[mid] > target){
                        right = mid;
                    }else{
                        left = mid + 1;
                    }
                }
            }
        }
        

        return -1;        
    }
};
