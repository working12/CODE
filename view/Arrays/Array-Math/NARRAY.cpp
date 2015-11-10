vector<int> Solution::repeatedNumber(const vector<int> &a) {
    
    int n=a.size();
    
    int xor_of_2_num=0;
    for(int i=0;i<n;i++)
    {
        xor_of_2_num^=a[i];
        xor_of_2_num^=(i+1);
    }
    int set_bit_pos=0;
    while( (xor_of_2_num & (1<<set_bit_pos))== 0)
    {
        set_bit_pos++;
    }
    
    int xor_with_setbit=0,xor_with_unsetbit=0;
    for(int i=1;i<=n;i++)
    {
        if( (i & (1<<set_bit_pos))>0 )
        {
            xor_with_setbit^=i;
        }
        else
        {
            xor_with_unsetbit^=i;
        }
    }
    
    int xor_with_setbit_arr=0,xor_with_unsetbit_arr=0;
    for(int i=1;i<=n;i++)
    {
        if( (a[i-1] & (1<<set_bit_pos))>0 )
        {
            xor_with_setbit_arr^=a[i-1];
        }
        else
        {
            xor_with_unsetbit_arr^=a[i-1];
        }
    }
    
    vector <int> answer;
    int num1,num2;
    
    num1=xor_with_setbit^xor_with_setbit_arr;
    num2=xor_with_unsetbit^xor_with_unsetbit_arr;
    
    if(num1==0)
    {
        num1=num2;
    }
    num2=num1^xor_of_2_num;
    int ct=0;
    for(int i=0;i<n;i++)
      if(a[i]==num1)
      {
          ct++;
      }
      if(ct==2)
      {
          answer.push_back(num1);
      }
      else
      {
          answer.push_back(num2);
      }
      answer.push_back(answer[0]^xor_of_2_num);
    return answer;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
