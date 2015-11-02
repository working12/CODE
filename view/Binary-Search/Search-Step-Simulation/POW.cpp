int Solution::pow(int x1, int n1, int d) {

    /*
       2^7
       
       7-->1    6-->  3--> 2--> 1-->
           1*2  4     8   16   16*8=128
    */
    long long r=1;
    long long x=x1,n=n1;//to avoid overflow. Otherwise int creates problem.
    if(x==0)
      return 0;
    
    if(n==0)
      return 1%d;
    x=x%d; //redundant
    while(n)
    {
        if((n&1)==0)
        {
            x=(x*x)%d;   
            n/=2;
        }
        else
        {
            r=(r*x)%d;
            n--;
        }
       //n/=2; This must not be here..it should be in even part. Trick..logic..
    }
    
    return r<0?r+d:r%d;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
