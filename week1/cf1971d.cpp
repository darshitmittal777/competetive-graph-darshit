#include<iostream>
#include<cmath>
#include<string>
#define ll long long
#define ull unsigned long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        string s="";
        cin>>s;
        bool check = false;int count =0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(s[i]!=s[i+1])
            {
                count++;
                if(s[i]=='0')
                check = true;
            }   
        }
        cout<<count-check+1<<endl;
        t--;
    }
    return 0;
}