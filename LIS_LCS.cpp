#include<bits/stdc++.h> 
using namespace std; 
/* Dynamic Programming C++ implementation of LIS problem */
/* lis() returns the length of the longest increasing 
subsequence in arr[] of size n */

int lis( int arr[], int n )  
{  
    int lis[n];  
	int maxValue, maxlis = 1;
	
	lis[0] = 1;  
    for (int i = 1; i < n; i++ )  
    { 
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


/*************************************************************
**************************************************************
**************************************************************
**************************************************************/
/* Dynamic Programming C++ implementation of LCS problem */
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
////WITH lcs[m+1][n+1] :Preferred.
int lcs( char *X, char *Y, int m, int n )  {
	int lcs[m+1][n+1];  
    int i, j; 
	//Building lcs[][].
	//0th row represent as if length of X is zero ie. empty X i.e there is no X[0] at all.
	//in this approach lcs[i][j] corresponds to X[i-1] & Y[j-1] ie lcs runs one index ahead of X/Y.
    for (i = 0; i <= m; i++) {  
        for (j = 0; j <= n; j++) {
          	if (i == 0 || j == 0)  
            	lcs[i][j] = 0;  
			else if (X[i-1] == Y[j-1])  
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);  
        } 
    }  
    return lcs[m][n];  
}
////WITH lcs[m][n]
int lcs( char *X, char *Y, int m, int n )  
{  
    int lcs[m][n];  
    int i, j;  
	//setting first row/col
	for (j = 0; j < n; j++) {
		if (X[0] == Y[j])  lcs[0][j] = 1; 
		else lcs[0][j] = 0;
	}
	for (i = 0; i < m; i++) { 
		if (X[i] == Y[0])  lcs[i][0] = 1; 
		else lcs[i][0] = 0;
	}
	//Building lcs[][].
    for (i = 1; i < m; i++) {  
        for (j = 1; j < n; j++) {
			if (X[i] == Y[j])  
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);  
        }  
    }  
    return lcs[m-1][n-1];  
}  


