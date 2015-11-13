void Solution::rotate(vector<vector<int> > &a) {
    int n=a.size();
    for(int i=0;i<n;i++)
    for(int j=i+1;j<n;j++)
    {
        swap(a[i][j],a[j][i]);
    }
    for(int i=0;i<n;i++)
    reverse(a[i].begin(),a[i].end());
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
