#include<bits/stdc++.h>
using namespace std;

vector<int> funGame (vector<int> arr) {
   // Write your code here
   vector <int>ans;
   int s=0,e=arr.size()-1,n =e;
   while(true)
   {
        if(s>n||e<0)
        break;
        if(arr[s]>arr[e])
        {
            ans.push_back(1);
            e--;
        }
        else if(arr[e]>arr[s])
        {
            ans.push_back(2);
            s++;
        }
        else if(arr[s]==arr[e])
        {
            ans.push_back(0);
            e--;
            s++;
        }
   }
   return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i_arr=0; i_arr<n; i_arr++)
    {
    	cin >> arr[i_arr];
    }

    vector<int> out_;
    out_ = funGame(arr);
    cout << out_[0];
    for(int i_out_=1; i_out_<out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}