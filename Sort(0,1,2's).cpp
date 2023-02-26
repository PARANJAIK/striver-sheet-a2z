//    Q) Sort(0,1,2's) -> https://leetcode.com/problems/sort-colors/description/

    //   Ans)

    // i) My approach : 

    // void sortColors(vector<int>& nums) {
    //     int i = 0,j = nums.size()-1;
    //     int k = -1;
    //     while(i<j){
    //         while(i<nums.size() && nums[i]==0) i++;
    //         while(j>=0 && nums[j]==2) j--;
    //         if(i<j){
    //            if(nums[i]==1 && nums[j]==1){
    //                if(k==-1) k = i+1;
    //                while(nums[k]==1 && k<j) k++;
    //                if(k==j) break;
    //                else{
    //                    if(nums[k]==0) swap(nums[i],nums[k]);
    //                    else swap(nums[k],nums[j]);
    //                }
    //            }
    //            else{
    //              swap(nums[i],nums[j]);
    //            }
    //         }
    //     }
    // }

    // ii) Striver's approach(DUTCH NATIONAL FLAG APPROACH) : 

    // void sortColors(vector<int>& nums){
    //     int lo = 0;
    //     int high = nums.size()-1;
    //     int mid = 0;
    //     while(mid <= high){
    //         switch(nums[mid]){
    //             case 0 : 
    //             swap(nums[lo++],nums[mid++]);
    //             break;
    //             case 1 :
    //             mid++;
    //             break;
    //             case 2 :
    //             swap(nums[mid],nums[high--]);
    //             break;
    //         }
    //     }
    //     return;
    // }