using namespace std;
typedef pair<int,int> ii;
typedef pair<int ,ii> iii;
typedef long long ll;

vector<int> Solution::maxset(vector<int> &a) {
    int n=a.size();
    ll sum=0,start,end;
    ll maxSum=-1,maxStart,maxEnd;
    ll inRange=0;
    ll i;
    for( i=0;i<n;i++)
    {
        if(a[i]>=0) //consider 0 also
        {
            if(!inRange)
            {
                inRange=1;
                start=i;
            }
            
            sum+=a[i];
        }
        else
        {
            if(inRange)
            {
                end=i-1;
                inRange=0;
                if(maxSum<sum)
                {
                    maxSum=sum;
                    maxStart=start;
                    maxEnd=end;
                }
            }
            sum=0;
        }
    }
    if(inRange)
    {
        end=i-1;
        if(maxSum<sum)
        {
            maxSum=sum;
            maxStart=start;
            maxEnd=end;
        }
    }
    
    vector<int> answer;
    if(maxSum>=0) //here also consider 0.
    {
        for(int j=maxStart;j<=maxEnd;j++)
        {
            answer.push_back(a[j]);
        }
    }
    return answer;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
