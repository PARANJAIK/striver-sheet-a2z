// Q) 3SumClosest -> https://practice.geeksforgeeks.org/problems/3-sum-closest/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=3-sum-closest

    // Ans) 
    
    // i) My approach : simple sort the array and use two pointer approach as like we do for the normal 3 sum problem, its just a small modification inside the low<high while loop.
    
    int closest3Sum(int nums[], int n, int x)
    {
        // code here
        sort(nums,nums+n);
        int ans;
        int diff = INT_MAX;
        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                int low = i+1,high = n-1;
                while(low<high){
                    int sum = nums[low] + nums[high];
                    if(sum + nums[i] == x){
                        ans = x;
                        return ans;
                    }
                    else if(sum + nums[i] > x){
                        if(sum + nums[i] - x < diff){
                            diff = sum + nums[i] - x;
                            ans = sum + nums[i];
                        }
                        high--;
                    }
                    else{
                        if(x - sum - nums[i] < diff){
                            diff = x - sum - nums[i];
                            ans = sum + nums[i];
                        }
                        low++;
                    }
                }
            }
        }
        return ans;
    }