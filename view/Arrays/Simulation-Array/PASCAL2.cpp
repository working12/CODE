typedef long long ll;
vector<int> Solution::getRow(int n) {
    vector<int> answer(n+1,0);
    answer[0]=1;
    if(n==0)
    {
        return answer;
    }
    /*
    1 0 0 0 0 -->0
    1 1 0 0 0 -->1
    1 2 1 0 0 -->2
    1 3 3 1 0 -->3
    1 4 6 4 1 -->4
    */
    else
    {
        int b;
        for(int i=1;i<=n;i++)
        {
            b=0;
            for(int j=0;j<=i;j++)
            {
                if(j==0)
                {
                    b=answer[0];
                    continue;
                }
                
                int t=b+answer[j];
                b=answer[j];
                answer[j]=t;
            }
        }
        vector<int> z;
        for(int i=0;i<=n;i++)
        {
            z.push_back(answer[i]);
        }
        return z;
    }
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
