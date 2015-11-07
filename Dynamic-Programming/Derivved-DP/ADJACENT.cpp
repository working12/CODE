int Solution::adjacent(vector<vector<int> > &a) {
    int game[a[0].size()];
    int n=a[0].size();
    if(n==1)
      return max(0,max(a[0][0],a[1][0]));
    
    game[n-1]=max(max(a[0][n-1],a[1][n-1]),0);
    game[n-2]=max(max(a[0][n-2],max(a[1][n-2],game[n-1])),game[n-1]);
    for(int i=n-3;i>=0;i--)
    {
        game[i]=max(game[i+2]+max(a[0][i],a[1][i]),game[i+1]);
    }
    return *max_element(game,game+n);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
