vector<int> Solution::wave(vector<int> &a) {
    int n=a.size();
    sort(a.begin(),a.end());
    vector<int> answer;
   for(int i=0;i<n;i+=2)
   {
       if(i+1<n)
       swap(a[i],a[i+1]);
   }
   for(int i=0;i<n;i+=1)
   {
       answer.push_back(a[i]);
   }
   return answer;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
