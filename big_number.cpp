#include <bits/stdc++.h>
#include <cmath>
#include <stdlib.h>   

using std::cout;
using std::cin;
using std::string;

bool check_number(string str1, string str2) { 

    unsigned lenght_1 = str1.length();
    unsigned lenght_2 = str2.length(); 

    
    if (lenght_1 < lenght_2){
        return true;
    } 
    if (lenght_2 < lenght_1){
        return false;
    }

    for (uint32_t i = 0; i < lenght_1; i++){
        if (str1[i] < str2[i]){
            return true;
        } else if (str1[i] > str2[i]){
            return false; 
        } 
    } 
    return false; 
} 
   
string findDiff(string str1, string str2) { 
    
    if (check_number(str1, str2)){ 
        swap(str1, str2); 
    }
    
    string str = "";   
    uint32_t lenght_1 = str1.length();
    uint32_t lenght_2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    uint32_t carry = 0; 
  
    for (size_t i = 0; i < lenght_2; i++) { 
  
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
         
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } else {
            carry = 0;
        } 
        str.push_back(sub + '0'); 
    } 
  
    
    for (size_t i = lenght_2; i < lenght_1; i++) { 
        int sub = ((str1[i]-'0') - carry); 
           
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } else{
            carry = 0;
        } 
              
        str.push_back(sub + '0'); 
    } 
  
    reverse(str.begin(), str.end()); 
  
    return str; 
} 


int main() { 
    string str1 = "978"; 
    string str2 = "12977"; 
    cout << findDiff(str1, str2) << "\n"; 
      
    string s1 = "100"; 
    string s2 = "1000000"; 
    cout << findDiff(s1,s2); 
      
    return 0; 
} 
