int Solution::maximalRectangle(vector<vector<int> > &a) {
    int m=a.size();
    int n=a[0].size();
    
    int b[m][n];
    for(int i=0;i<m;i++)
        b[i][n-1]=a[i][n-1];
    for(int i=0;i<m;i++)
    {
        for(int j=n-2;j>=0;j--)
        {
            if(a[i][j]==1)
                b[i][j]=b[i][j+1]+1;
            else
                b[i][j]=0;
        }
    }
/*    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    */
    vector<int> v,maxx;
    for(int i=0;i<n;i++)
    {
        v.clear();
        for(int j=0;j<m;j++)
        {
            v.push_back(b[j][i]);
        }
        vector<int> left(m,0),right(m,0);
        
        for(int i=m-1;i>=0;i--)
        {
            int ct=0;
            for(int k=i;k<=m-1;k++)
              if(v[k]>=v[i])
               ct++;
              else
               break;
            right[i]=ct;
        }
        
        for(int i=0;i<=m-1;i++)
        {
            int ct=0;
            for(int k=i;k>=0;k--)
              if(v[k]>=v[i])
              ct++;
              else
               break;
            left[i]=ct;
        }
        
        int mx=-1;
        for(int i=0;i<=m-1;i++)
        {
            mx=max(mx,(left[i]+right[i]-1)*v[i]);
        }
        
        maxx.push_back(mx);
    }
    
    return *max_element(maxx.begin(),maxx.end());
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
