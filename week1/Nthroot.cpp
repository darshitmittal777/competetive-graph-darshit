#include <cmath>
int NthRoot(int n, int m) {
  // Write your code here.
  int s=0,e=m;
  int mid = s + (e-s)/2;
  while(s<e)
  {
    if(pow(mid,n)==m)
    return mid;
    else if (pow(mid,n)<m)
    s = mid+1;
    else
    e = mid;
    mid = s + (e-s)/2;
  }
  return -1;
}