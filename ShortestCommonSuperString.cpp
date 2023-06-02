// Q) Shortest Common SuperString -> https://www.interviewbit.com/problems/shortest-common-superstring/

// Ans) 

// i) Proper approach : 

int findOverlappingPair(string str1, string str2, string &str)
{
// max will store maximum overlap i.e maximum
// length of the matching prefix and suffix
int max = INT_MIN;
int len1 = str1.length();
int len2 = str2.length();

// check suffix of str1 matches with prefix of str2
for (int i = 1; i <= min(len1, len2); i++)
{
    // compare last i characters in str1 with first i
    // characters in str2
    if (str1.compare(len1-i, i, str2, 0, i) == 0)
    {
        if (max < i)
        {
            //update max and str
            max = i;
            str = str1 + str2.substr(i);
        }
    }
}

// check prefix of str1 matches with suffix of str2
for (int i = 1; i <= min(len1, len2); i++)
{
    // compare first i characters in str1 with last i
    // characters in str2
    if (str1.compare(0, i, str2, len2-i, i) == 0)
    {
        if (max <= i)
        {
            //update max and str
            max = i;
            str = str2 + str1.substr(i);
        }
    }
}

return max;

}

int Solution::solve(vector<string> &a) {
        int n=a.size(),len=n,max;
        while(len>1){
            max=INT_MIN;
            int l,r;
            string resstr;
            for(int i=0;i<len;i++){
                for(int j=i+1;j<len;j++){
                    string str;
                    int res = findOverlappingPair(a[i], a[j], str);
                    if(max<res){
                            max=res;
                            l=i;r=j;
                            resstr=str;
                        }
                    }
                }
            if(max==INT_MIN){
                a[0]+=a[len-1];
            }
            else{
                    a[l]=resstr;
                    a[r]=a[len-1];
                }
            len--;
        }
        // cout<<a[0]<<endl;
        return a[0].size();
}

// ii) I tried with return type of overlap as string , but it fails for some test case (DONT KNOW WHY): 

// string overlap(string& a,string& b){
//     string str="";
//     int maxx = INT_MIN;
//     int len1 = a.size();
//     int len2 = b.size();
//     // checking suffix of string a and prefix of string b
//     for(int i=1;i<=min(len1,len2);i++){
//         if(a.compare(len1-i,i,b,0,i) == 0){
//             if(i > maxx){
//                 maxx = i;
//                 str = a + b.substr(i);
//             }
//         }
//     }
//     //checking prefix of string a and suffix of string b
//     for(int i=1;i<=min(len1,len2);i++){
//         if(a.compare(0,i,b,len2-i,i) == 0){
//             if(i >= maxx){
//                 maxx = i;
//                 str = b + a.substr(i);
//             }
//         }
//     }
//     return str;
// }

// int Solution::solve(vector<string> &a){
//     int n = a.size();
//     while(n > 1){
//         int maxx = INT_MIN;
//         string res="";
//         int l,r;
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 string str = overlap(a[i],a[j]);
//                 int size = str.size();
//                 if(size == 0) size = INT_MIN;
//                 if(size > maxx){
//                     maxx = size;
//                     res = str;
//                     l = i;
//                     r = j;
//                 }
//             }
//         }
//         if(maxx == INT_MIN){
//             a[0] = a[0] + a[n-1];
//         }
//         else{
//             a[l] = res;
//             a[r] = a[n-1];
//         }
//         n--;
//     }
//     return a[0].size();
// }

