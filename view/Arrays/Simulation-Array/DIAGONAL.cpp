vector<vector<int> > Solution::diagonal(vector<vector<int> > &a) {
    int n=a.size();
    vector<vector<int> > v;
    for(int i=0;i<n;i++)
    {
        int r=0,c=i;
        vector<int> z;
        while(r>=0 && r<=n-1 && c<=n-1 && c>=0)
        {
            z.push_back(a[r][c]);
            r++;
            c--;
        }
        v.push_back(z);
    }
    for(int i=1;i<n;i++)
    {
        int r=i,c=n-1;
        vector<int> z;
        while(r>=0 && r<=n-1 && c<=n-1 && c>=0)
        {
            z.push_back(a[r][c]);
            r++;
            c--;
        }
        v.push_back(z);
    }
    return v;
}
