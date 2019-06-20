#include <bits/stdc++.h>
#include <cmath>
#include <stdlib.h>   
 
using std::cout;
using std::cin;
 
 
int main()
{
    constexpr int SIZE = 225;
    int arr_number_1[SIZE];
    int arr_number_2[SIZE];
    int arr_sum_number[SIZE];

    char arr_char_1[SIZE];
    char arr_char_2[SIZE];

    int leng_1;
    int leng_2;
    
    cout << "Input number: \n";
    cin >> arr_char_1 >> arr_char_2;

    for(leng_1 = 0; arr_char_1[leng_1]; ++leng_1){
        arr_number_1[leng_1] = arr_char_1[leng_1] - '0'; 
    }

    for(leng_2 = 0; arr_char_2[leng_2]; ++leng_2){
        arr_number_2[leng_2] = arr_char_2[leng_2] - '0';
    }
    
    int i = leng_1 - 1;
    int j = leng_2 - 1;
    int k = 0;
    int carry_over = 0;

    for( ; i >= 0 && j >= 0; i--, j--, k++){
        arr_sum_number[k] = (arr_number_1[i] + arr_number_2[j] + carry_over) % 10;
        carry_over = (arr_number_1[i] + arr_number_2[j] + carry_over) / 10;
    }

    for(k--; k >= 0; k--){
        cout << arr_sum_number[k];
    }

    return 0;
}
 
