#include <iostream>
#include <algorithm>
#include <cstdlib>   

using std::cout;
using std::cin;
using std::string;

   
string findDiff(string &str1, string &str2) { 
    
    if (str1.compare(str2) != 0){ 
        swap(str1, str2); 
    }
 
    string str = "";   
    size_t lenght_1 = str1.length();
    size_t lenght_2 = str2.length(); 
  
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    uint8_t carry = 0; 
  
    for (size_t i = 0; i < lenght_2; i++) { 
  
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
         
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } else {
            carry = 0;
        } 
        str += (sub + '0'); 
    } 
  
    
    for (size_t i = lenght_2; i < lenght_1; i++) { 
        int sub = ((str1[i]-'0') - carry); 
           
        if (sub < 0) { 
            sub = sub + 10; 
            carry = 1; 
        } else{
            carry = 0;
        } 
              
        str += (sub + '0'); 
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
