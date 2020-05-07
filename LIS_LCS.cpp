/* Dynamic Programming C++ implementation of LIS problem */
#include<bits/stdc++.h> 
using namespace std; 
/* lis() returns the length of the longest increasing 
subsequence in arr[] of size n */

int lis( int arr[], int n )  {  
	int lis[n];  
	int maxValue, maxlis = 1;
	
	lis[0] = 1;  
	for (int i = 1; i < n; i++ )  { 
        maxValue = 0; 
        for (int j = 0; j < i; j++ )   
            if ( arr[j] < arr[i] )  
                maxValue = max( maxValue, lis[j]); 
		
		lis[i] = maxValue + 1;
		maxlis = max(maxlis, lis[i]);
    }
  
    return maxlis;
	//return *max_element(lis, lis+n); 
} 

//TC O(n2) SC O(n).
