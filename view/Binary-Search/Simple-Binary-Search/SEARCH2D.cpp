// First finding the value >B so the previous index will be <=B
// search over here. if this prev index = -1 return 0.
int Solution::searchMatrix(vector<vector<int> > &a, int B) {
    int m=a.size();
    int n=a[0].size();

    if(m==1 && n==1)
      return a[0][0]==B?1:0;
    int l=0,r=m-1;
    
    while(l<r)
    {
        int mid=l+(r-l)/2;
       
        if(a[mid][0]>B)
        {
            r=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    l--;
   

    if(l<0)
       return 0;
    else
    {
        int in=l;
        int lo=0,hi=n-1;
        while(lo<=hi)
        {
            int mid=lo+(hi-lo)/2;
            if(a[in][mid]<B)
            {
                lo=mid+1;
            }
            else if(a[in][mid]==B)
            {
                return 1;
            }
            else
            {
                hi=mid-1;
            }
        }
        
        return 0;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
