//EDIT DISTANCE PROBLEM
//SOURCE: GFG. Exact copy from gfg.
//m and n are lengths of str1 & str2 respectively.
//Naive recursive solution
int editDist(string str1, string str2, int m, int n) 
{ 
    if (m == 0) return n; 
    if (n == 0) return m; 
  
    if (str1[m - 1] == str2[n - 1]) 
        return editDist(str1, str2, m - 1, n - 1); 

    return 1 + min(editDist(str1, str2, m, n - 1), // Insert 
                   editDist(str1, str2, m - 1, n), // Remove 
                   editDist(str1, str2, m - 1, n - 1) // Replace 
                   ); 
} 
//DP table solution based on above naive recursive approach.
int editDistDP(string str1, string str2, int m, int n) 
{ 
    int dp[m + 1][n + 1]; 

    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0) dp[i][j] = j; // Min. operations = j 
            else if (j == 0) dp[i][j] = i; // Min. operations = i 
			
            else if (str1[i - 1] == str2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1]; 
  
            else
                dp[i][j] = 1 + min(dp[i][j - 1], // Insert 
                                   dp[i - 1][j], // Remove 
                                   dp[i - 1][j - 1]); // Replace 
        } 
    } 
    return dp[m][n]; 
} 
//TC O(m x n) Space Complexity: O(m x n)
//IMPROVEMENT:: SC can be improved to O(m or n) since only previous row is required to construct current row. 
//Hence Dp[2][n+1] (or Dp[m+1][2]) will serve the purpose too. 
