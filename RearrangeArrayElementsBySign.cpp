// Q) Rearrange Array Elements By sign -> https://leetcode.com/problems/rearrange-array-elements-by-sign/

    // Ans)

    // i) My approach : 

    vector<int> rearrangeArray(vector<int>& arr) {
        int N = arr.size();
        queue<int> p,n;
	    for(int i=0;i<N;i++){
	        if(arr[i]>=0) p.push(arr[i]);
	        else n.push(arr[i]);
	    }
	    bool flag = true;
	    for(int i=0;i<N;i++){
	        if(flag){
	            if(p.size()!=0){
	                arr[i] = p.front();
	                p.pop();
	            }
	            else{
	                arr[i] = n.front();
	                n.pop();
	            }
	            flag = false;
	        }
	        else{
	            if(n.size()!=0){
	                arr[i] = n.front();
	                n.pop();
	            }
	            else{
	                arr[i] = p.front();
	                p.pop();
	            }
	            flag = true;
	        }
	    }
        return arr;
	}

    // ii) Other person's approach : 

    // vector<int> rearrangeArray(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> ans(n, 0);
    //     int positiveElementIndex = 0, negativeElementIndex = 1;

    //     for(auto num : nums){
    //         if(num > 0){
    //             ans[positiveElementIndex] = num;
    //             positiveElementIndex += 2;
    //         }
    //         else if(num < 0){
    //             ans[negativeElementIndex] = num;
    //             negativeElementIndex += 2;
    //         }
    //     }
    //     return ans;
    // }