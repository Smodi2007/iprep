
To return max of an array.
//lis[n];
return *max_element(lis, lis+n); 


==============================================
#include <bits/stdc++.h> 
using namespace std;
int main() {
  
    vector<vector<int>> nums =  {
                                    {3,4,5, 0, 0},
                                    {3,2,6, 0, 0},
                                    {2,2,1, 0, 0}
                                }; 
    printf("%d \n", nums.size());
    printf("%d \n", nums[0].size());
    return 0;
}
OutPut:
3 
5 
========================================================
