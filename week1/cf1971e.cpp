#include<iostream>
#include<cmath>
#include<string>
#define ll long long
#define ull unsigned long long
using namespace std;

int search(ll array[],ll x,int n)
{
    int s=0,e=n,mid = s + (e-s)/2,possible=0;
    while(s<e)
    {
        if(array[mid]>x)
        {
            e = mid;
        }
        else if(array[mid]<x)
        {
            possible = mid;
            s = mid+1;
        }
        else
        {
            possible = mid;
            break;
        }
        mid = s + (e-s)/2;
    }
    return possible;
}

int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
        ll n,k,q;
        cin>>n>>k>>q;
        ll *time = new ll[k+1];
        ll *distance = new ll[k+1];
        ll *total_time = new ll[q];
        distance[0] = 0; time[0] = 0;
        for(int i=0;i<k;i++)
        cin>>distance[i+1];
        for(int i=0;i<k;i++)
        cin>>time[i+1];
        for(int i = 0;i<q;i++)
        {
            int pos;
            ll q_dist;
            cin>>q_dist;
            pos = search(distance,q_dist,k+1);
            if(pos<k)
            {
                total_time[i] = ((double)time[pos] + (double)((double)q_dist-distance[pos])*((double)time[pos+1]-time[pos])/((double)distance[pos+1]-distance[pos]));
            }
            else
            total_time[i] = time[k];
        }
        for(int i = 0;i<q;i++)
        cout<<total_time[i]<<' ';
        cout<<endl;
        delete(time);
        delete(total_time);
        delete(distance);
        t--;
    }
    return 0;
}