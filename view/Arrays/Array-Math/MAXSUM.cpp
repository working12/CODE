// here [-500] test case ouput is -500...
int Solution::maxSubArray(const vector<int> &a) {
    int n=a.size();
    int INF=-10000000;
    vector<int> dp(n,0);
    dp[0]=a[0];
    for(int i=1;i<=n-1;i++)
    {
        dp[i]=max(dp[i-1]+a[i],a[i]);
    }
    int ret= *max_element(dp.begin(),dp.end());
  return ret;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
