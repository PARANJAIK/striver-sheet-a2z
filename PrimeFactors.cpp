// 	Q) Prime Factors -> https://practice.geeksforgeeks.org/problems/prime-factors5052/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Prime-Factors

    // Ans) My approach :
	
	vector<int> AllPrimeFactors(int n) {
	    // Code here
	    vector<int> ans;
	    int i = 2;
	    while(n > 1){
	        if(n%i == 0) ans.push_back(i);
	        while(n%i == 0) n = n/i;
	        i++;
	    }
	    return ans;
	}