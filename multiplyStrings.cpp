/*///////////////////////////////////////
LC43, Multiply Strings
++++++++code copied verbatim from GFG++++++
GFG https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
/////////////////////////////////////////
*/
string multiply(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) return "0"; 
  
    vector<int> result(len1 + len2, 0); 
 
    int i_n1 = 0, i_n2 = 0;  
 
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
 
        i_n2 = 0;             
        for (int j=len2-1; j>=0; j--) 
        {  
            int n2 = num2[j] - '0';   
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
   
            carry = sum/10; 
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
 
        i_n1++; 
    } 
 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
		i--; 
 
    if (i == -1) return "0"; 
 
    string s = ""; 
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
} 
//TC O(len1 X len2)  SC O(len1 + len2)