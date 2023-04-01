// Q) Two Numbers with odd occurrences -> https://practice.geeksforgeeks.org/problems/two-numbers-with-odd-occurrences5846/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Two-numbers-with-odd-occurrences

    // Ans) 
    
    // i) My approach : (COOL PROBLEM)
    
    vector<long long int> twoOddNum(long long int arr[], long long int n)  
    {
        // code here
        long long int xor1 = 0;
        for(int i=0;i<n;i++){
            xor1 = xor1^arr[i];
        }
        int index;
        for(int i=0;i<=30;i++){
            if(xor1&(1<<i)){
                index = i;
                break;
            }
        }
        int xor2 = 0,xor3 = 0;
        for(int i=0;i<n;i++){
            if(arr[i]&(1<<index)){
                xor2 ^= arr[i];
            }
            else{
                xor3 ^= arr[i];
            }
        }
        vector<long long int> ans;
        ans.push_back(max(xor2,xor3));
        ans.push_back(min(xor2,xor3));
        return ans;
    }