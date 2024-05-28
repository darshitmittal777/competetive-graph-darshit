#include<bits/stdc++.h>
using namespace std;
vector<int> solution (int N, vector<int> C) {
    vector<int> ans;
    vector<int> q;
    for(vector<int>::iterator i=C.begin();i!=C.end();i++)
    {
        if(*i==0)
        {
            ans.push_back(q.back());
            q.pop_back();
        }
        else
        {
            q.push_back(*i);
        }
    }
    return ans;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> C(N);
    for(int i_C = 0; i_C < N; i_C++)
    {
    	cin >> C[i_C];
    }

    vector<int> out_;
    out_ = solution(N, C);
    cout << out_[0];
    for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
    {
    	cout << " " << out_[i_out_];
    }
}