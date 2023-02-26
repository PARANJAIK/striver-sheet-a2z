 // Q) Majority Element -> https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=majority-element
 
    // Ans) 
    
    // i) Strivers approach (Boyer-Moore Voting Algorithm) : 
       
    int majorityElement(int nums[], int size)
    {
        
        // your code here
        int count = 0;
        int candidate = 0;
        for(auto i = 0;i<size;i++){
            if(count == 0){
                candidate = nums[i];
            }
            if(nums[i] == candidate) count++;
            else count--;
        }
        count = 0;
        for(int i=0;i<size;i++){
            if(nums[i]==candidate) count++;
        }
        if(count > size/2) return candidate;
        else return -1;
    }