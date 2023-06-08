// Q) Evaluate Expression To True -> https://www.interviewbit.com/problems/evaluate-expression-to-true/

// i) Similar approach , proper implementation : 

int dp[151][151][2];

    int solve(string str, int i, int j, int istrue)

    {

        if(i>j)return 0;

        if(i==j)

        {

            if(istrue)return str[i]=='T';

            else return str[i]=='F';

        }

        if(dp[i][j][istrue]!=-1)

        return dp[i][j][istrue];

        

        int ans=0;

        

        for(int k=i+1;k<=j-1;k=k+2)

        {

            int leftT,leftF,rightT,rightF;

            

            leftT=solve(str,i,k-1,1);

            leftF=solve(str,i,k-1,0);

            rightT=solve(str,k+1,j,1);

            rightF=solve(str,k+1,j,0);

            

            if(str[k]=='^')

            {

                if(istrue)

                ans+=(leftT*rightF) + (leftF*rightT);

                else ans+=(leftT*rightT) + (leftF*rightF) ;

            }

            else if(str[k]=='&')

            {

                if(istrue)

                ans+=(leftT*rightT);

                else ans+=(leftT*rightF) + (leftF*rightT) + (leftF*rightF);

            }

            else if(str[k]=='|')

            {

                if(istrue)

                ans+=(leftT*rightF) + (leftF*rightT) + (leftT*rightT);

                else ans+=(leftF*rightF) ;

            }

            dp[i][j][istrue]=ans%1003;

        }

        return ans%1003;

    }


int Solution::cnttrue(string A) {

    memset(dp,-1,sizeof(dp));

    return solve(A,0,A.size()-1,1);

}


// ii) My initial approach : (FAILS , MAY BE BECAUSE OF THE TEMP VECTOR)

// int M = 1e3 + 3;

// int solve(int start,int end,vector<vector<int>>& memo,string& a,vector<int>& temp){
//     if(end == start) return (a[start] == 'T') ? 1 : 0;
//     if(end-start == 2){
//         char op = a[start+1];
//         bool st = (a[start] == 'T') ? true : false;
//         bool en = (a[end] == 'T') ? true : false;
//         if(op == '|'){
//             if(st|en) return 1;
//             else return 0;
//         }
//         if(op == '&'){
//             if(st&en) return 1;
//             else return 0;
//         }
//         if(op == '^'){
//             if(st^en) return 1;
//             else return 0;
//         }
//     }
//     if(memo[start][end] != -1) return memo[start][end];
//     int ans = 0;
//     for(int i=start+1;i < end;i += 2){
//         int x = solve(start,i-1,memo,a,temp);
//         int y = solve(i+1,end,memo,a,temp);
//         char op = a[i];
//         int operleft = (i-1-start-1)/2;
//         int operright = (end-i-1-1)/2;
//         if(op == '|'){
//             ans = (ans + (x*(temp[operright]%M-y)%M)%M)%M;
//             ans = (ans + (y*(temp[operleft]%M-x)%M)%M)%M;
//             ans = (ans + (x*y)%M)%M;
//         }
//         if(op == '&'){
//             ans = (ans + (x*y)%M)%M;
//         }
//         if(op == '^'){
//             // ans = (ans + x)%M;
//             ans = (ans + (x*(temp[operright]%M-y)%M)%M)%M;
//             // ans = (ans + y)%M;
//             ans = (ans + (y*(temp[operleft]%M-x)%M)%M)%M;
//         }
//     }
//     return memo[start][end] = ans%M;
// }

// int Solution::cnttrue(string a){
//     int n = a.size();
//     vector<vector<int>> memo(n,vector<int> (n,-1));
//     int oper = (n-1)/2;
//     vector<int> temp(oper+1,0);
//     temp[0] = 1;
//     temp[1] = 1;
//     temp[2] = 2;
//     for(int i=3;i<=oper;i++){
//         for(int j=0;j<i;j++){
//             temp[i] += (temp[j]*temp[i-1-j]);
//         }
//     }
//     return solve(0,n-1,memo,a,temp);
// }
