int Solution::sqrt(int x) {
    /*
    1 2 3 4 5 6 7 8 9 10 11 12
    1 4 9 16 25 49 64 81 100 ...
    sqrt(2)=sqrt(3)=sqrt(1)=1;
    sqrt(5)=sqrt(6)=sqrt(7)=sqrt(8)=sqrt(4)=2
    we have to find the greatest integer m such that m*m<=x is true or m*m>x is false
    m= 1 2 3 4 5 6 7 8 9 10 11
       f f f t t t t t t t t   for x=11
    That is the sqrt for sure.
    
    */
    if(x<=1)
        return max(x,0);
    int l=1,r=x;
    while(l<r)
    {
        long long m=l+(r-l+1)/2;
        if(m*m >x )
            r=m-1;
        else
        {
            l=m;
        }
    }
    return l;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
