//CROC 2016 elimination 
//Ternary Search
//645C codeforces
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef map<ll,ll>::iterator mapit;
typedef set<int>::iterator setit;

const int maxn = 1e5 + 2;
const int maxlog = 20;
const int mod = 1e9 + 7;
const int maxh = 2 * 350;
int n , k;
vector<int> v;
int ans(int x , int y , int l){
    return max(v[y] - v[l] , v[l] - v[x]);
}
int bs(int l , int r){
    int x = l , y = r;
    while(l <= r){
        int mid = (l + r + 1) / 2;
        if(l == r)
            return ans(x , y , l);
        else{
        // '=' can be placed anywhere...That's not important.
            if(ans(x , y , mid - 1) < ans(x , y , mid))
                r = mid - 1;
            else
                l = mid;
        }
    }
}
int main()
{
	ios_base::sync_with_stdio(false) , cin.tie(0) , cout.tie(0);
	cin >> n >> k;
	k ++ ;
	string s;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i ++ )
        if(s[i] == '0')
            v.pb(i);
    int first = 0 , lst = k - 1;
    int ans = maxn;
    while(lst != v.size()){
        ans = min(ans , bs(first , lst));
        lst ++ ;
        first ++ ;
    }
    cout << ans;
	return 0;
}
