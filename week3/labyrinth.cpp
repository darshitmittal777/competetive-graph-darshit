#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<string>
#define ll long long
#define ull unsigned long long
using namespace std;

//DFS 
// int solve(vector<vector<int>> &map,int x,int y,vector<vector<int>> &check,int s =0)
// {
//     map[x][y] = 3;
//     check[x][y] = 1;
//     if (x - 1 >= 0 && check[x - 1][y] == 0 && map[x - 1][y] == 0) {
//         return solve(map, x - 1, y, check,s+1);
//     }
//     if (y - 1 >= 0 && check[x][y - 1] == 0 && map[x][y - 1] == 0) {
//         return solve(map, x, y - 1,  check,s+1);
//     }
//     if (x + 1 < map.size() && check[x + 1][y] == 0 && map[x + 1][y] == 0) {
//         return solve(map, x + 1, y,  check,s+1);
//     }
//     if (y + 1 < map[0].size() && check[x][y + 1] == 0 && map[x][y + 1] == 0) {
//         return solve(map, x, y + 1,  check,s+1);
//     }
//     if (x - 1 >= 0 && check[x - 1][y] == 0 && map[x - 1][y] == 2) {
//         return s+1;
//     }
//     if (y - 1 >= 0 && check[x][y - 1] == 0 && map[x][y - 1] == 2) {
//         return s+1;
//     }
//     if (x + 1 < map.size() && check[x + 1][y] == 0 && map[x + 1][y] == 2) {
//         return s+1;
//     }
//     if (y + 1 < map[0].size() && check[x][y + 1] == 0 && map[x][y + 1] == 2) {
//         return s+1;
//     }
// }

int solve(vector<vector<int>> &map,int a,int b,vector<vector<int>> &check,vector<vector<int>> &level,vector<vector<char>> &path)
{
    queue<pair<int,int>>q;
    q.push({a,b});
    check[a][b] = 1;
    while(!q.empty())
    {
        pair<int,int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        if (x + 1 < map.size() && check[x + 1][y] == 0 && map[x + 1][y] == 2) 
        {
            path[x+1][y] = 'D';
            return level[x][y]+1;
        }
        if (y + 1 < map[0].size() && check[x][y + 1] == 0 && map[x][y + 1] == 2) 
        {
            path[x][y+1] = 'R';
            return level[x][y]+1;
        }
        if (x - 1 >= 0 && check[x - 1][y] == 0 && map[x - 1][y] == 2) 
        {
            path[x-1][y] = 'U';
            return level[x][y]+1;
        }
        if (y - 1 >= 0 && check[x][y - 1] == 0 && map[x][y - 1] == 2) 
        {
            path[x][y-1] = 'L';
            return level[x][y]+1;
        }
        if (x - 1 >= 0 && check[x - 1][y] == 0 && map[x - 1][y] == 0) 
        {
            q.push({x-1,y});
            path[x-1][y] = 'U';
            check[x - 1][y] = 1;
            level[x-1][y] = level[x][y] + 1;
        }
        if (y - 1 >= 0 && check[x][y - 1] == 0 && map[x][y - 1] == 0) 
        {
            q.push({x,y-1});
            path[x][y-1] = 'L';
            check[x][y-1] = 1;
            level[x][y-1] = level[x][y] + 1;
        }
        if (x + 1 < map.size() && check[x + 1][y] == 0 && map[x + 1][y] == 0) 
        {
            q.push({x+1,y});
            path[x+1][y] = 'D';
            check[x +1][y] =1;
            level[x+1][y] = level[x][y] + 1;
        }
        if (y + 1 < map[0].size() && check[x][y + 1] == 0 && map[x][y + 1] == 0) 
        {
            q.push({x,y+1});
            path[x][y+1] = 'R';
            check[x][y+1] = 1;
            level[x][y+1] = level[x][y] + 1;
        }
    }
    return -1;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> map;
    int x, y,aa,bb; // Coordinates of the starting point 'A'
    for(int i=0;i<n;i++)
    {
        map.push_back({});
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
            char a=s[j];
            if(a=='#')
                map[i].push_back(-1);
            if(a=='A')
            {
                x = i;
                y = j;
                map[i].push_back(1);
            }
            if(a=='B')
            {
                map[i].push_back(2);
                aa = i;
                bb = j;
            }
            if(a=='.')
                map[i].push_back(0);
        }
    }
    vector<vector<int>> check(map.size(), vector<int>(map[0].size(), 0));
    vector<vector<int>> level(map.size(), vector<int>(map[0].size(), 0));
    vector<vector<char>> path(map.size(), vector<char>(map[0].size(), '*'));
    int ans = solve(map,x,y,check,level,path);
    if(ans==-1)
    cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        cout<<ans<<endl;
        string s = "";
        pair<int,int> end = {aa,bb};
        while(path[aa][bb]!='*')
        {
            
            s = path[aa][bb] + s;
            if(path[aa][bb]=='U')
            aa++;
            else if(path[aa][bb]=='D')
            aa--;
            else if(path[aa][bb]=='R')
            bb--;
            else if(path[aa][bb]=='L')
            bb++;
        }
        cout<<s;
    }
    return 0;
}
