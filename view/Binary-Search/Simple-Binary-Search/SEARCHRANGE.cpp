vector<int> Solution::searchRange(const vector<int> &a, int b) {
    
    int l=0,r=a.size()-1;
    bool found=false;
    while(l<=r)
    {
        int m=l+(r-l)/2;
        if(a[m]==b)
        {
            found=true;
            break;
        }
        else if(a[m]<b)
        {
            l=m+1;
        }
        else
        {
            r=m-1;
        }
    }
    vector<int> v;
    
    if(found==false)
    {
        v.push_back(-1);
        v.push_back(-1);
        return v;
    }
    else
    {
        int l=0,r=a.size()-1;
        while(l<r)
        {
            int m=l+(r-l)/2;
            if(a[m]>=b)
            {
                r=m;
            }
            else
            {
                l=m+1;
            }
        }
        v.push_back(l);
        
        l=0,r=a.size()-1;
        while(l<r)
        {
            int m=l+(r-l+1)/2;
            if(a[m]>b)
            {
                r=m-1;
            }
            else
            {
                l=m;
            }
        }
        
        v.push_back(l);
        return v;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
