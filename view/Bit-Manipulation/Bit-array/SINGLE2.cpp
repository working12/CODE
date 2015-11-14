int Solution::singleNumber(const vector<int> &a1) {
    
    int n=a1.size();
    
    int result=0;
    for(int i=0;i<32;i++)
    {
        long bm=1LL<<i;
        int sum=0;
        for(int j=0;j<n;j++)
        {
            if((a1[j]&(bm))>0)
            sum++;
            sum%=3;
        }
        if((sum%3)==1)
            result=result|bm;        
    }
    return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
