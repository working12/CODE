/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool cmp(Interval a,Interval b)
 {
     return a.start<b.start;
 }
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    
    vector<Interval> answer;
    int newStart=newInterval.start;
    int newEnd=newInterval.end;
    Interval forming_interval(newStart,newEnd);//=new Interval(newStart,newEnd);
    for(int i=0;i<intervals.size();i++)
    {
        if(intervals[i].start>intervals[i].end)
        swap(intervals[i].start,intervals[i].end);
        if((intervals[i].start>newEnd)|| (intervals[i].end<newStart) )
        {
            answer.push_back(intervals[i]);
        }
        else 
        {
            forming_interval.start=min(forming_interval.start,intervals[i].start);
            forming_interval.end=max(forming_interval.end,intervals[i].end);
        }
    }
    answer.push_back(forming_interval);
    sort(answer.begin(),answer.end(),cmp);
    return answer;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
