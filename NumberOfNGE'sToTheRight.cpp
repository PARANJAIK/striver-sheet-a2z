// Q) Number of NGE's to the right -> https://practice.geeksforgeeks.org/problems/number-of-nges-to-the-right/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-nges-to-the-right
 
    // Ans)
    
    // NOTE : TO FIND THE ANS IN ONE PASS : (BUT USEFUL ONLY WHEN WE WANT THE NO.OF NGE's TO THE RIGHT OF ALL INDICES):
    // SAME LIKE THE APPROACH OF FINDING NGE, BUT THE DIFFERENCE IS THAT WHEN THE ST.TOP() IS LESS WE POP IT AND STORE IT UNTIL WE REACH AN ELEMENT WHICH IS GREATER OR STACK GOES EMPTY, THEN BASICALLY WE ARE GOING TO PUSH THE CURRENT ELEMENT IN THE STACK AND THEN WE PUSH ALL POPPED ELEMENTS AGAIN INTO THE STACK.
    // BASICALLY WE MAINTAIN AN ASCENDING ORDER OF ELEMENTS IN THE STACK FROM TOP TO BOTTOM. 

    // vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
    //     //write your code here
    //     vector<int> ans;
    //     for(int i=0;i<queries;i++){
    //         int index= indices[i];
    //         int cnt = 0;
    //         for(int j = index+1;j<n;j++){
    //             if(arr[j] > arr[index]) cnt++;
    //         }
    //         ans.push_back(cnt);
    //     }
    //     return ans;
    // }