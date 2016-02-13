int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost) {
    int n=gas.size();
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    v[i]=gas[i]-cost[i];
    for(int i=0;i<n;i++)
    {
        if(v[i]>=0)
        {
            int ff=v[i];
            int j=(i+1)%n;
            bool fool=false;
            while(j!=i)
            {
                if(ff+v[j]>=0)
                {
                    ff+=v[j];
                    j=(j+1)%n;
                }
                else
                {
                    fool=true;
                    break;
                }
                
            }
            if(fool)
             continue;
             else
             return i;
        }
    }
    return -1;
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
