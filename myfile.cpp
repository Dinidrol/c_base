#include <iostream>
#include <cstring>
#include <limits>

using std::cout;
using std::cin;

enum {
    TO_LOWER = 1,
    TO_UPPER,
    REVERS_STR,
    FIND_NUMBER,
    SHIFT_NUMBER = 32, // Разность между заглавной 'A' и 'a' в таблице кодировке 
    SIZE_ARR = 100
};

void toUpper(){
    char str_input[SIZE_ARR] {};
    size_t size;

    do{
        cout << "Insert string (MAX 99 symbol) to Upper:";
        cin >> str_input;
        size = strlen(str_input);
    } while (size > SIZE_ARR);

    for(size_t i = 0; str_input[i]; ++i) {
        if(str_input[i] < 'a' && str_input[i] > 'z'){
            cout << str_input[i];
        } else {
            cout << (char)(str_input[i] - SHIFT_NUMBER);
        }  
    }

}

void toLower(){
    char str_input[SIZE_ARR] {};
    size_t size;

    do{
        cout << "Insert string (MAX 99 symbol) to Lower:";
        cin >> str_input;
        size = strlen(str_input);
    } while (size > SIZE_ARR);

    for(size_t i = 0; str_input[i]; ++i) {
        if(str_input[i] < 'A' && str_input[i] > 'Z'){
            cout << str_input[i];
        } else {
            cout << (char)(str_input[i] + SHIFT_NUMBER);
        }  
    }
}

void revers(){
    char str_input[SIZE_ARR] {};
    size_t size = 0; 

    do{
        cout << "Insert string (MAX 99 symbol) to Find Number:";
        cin >> str_input;
        size = strlen(str_input);
    } while (size > SIZE_ARR);

    size_t half_size_input_arr = size/2;

    for (size_t i = 0; i < half_size_input_arr; ++i){
        char temp = str_input[i];
        str_input[i] = str_input[size - i - 1];
        str_input[size-i-1] = temp;
    }

    cout << str_input;
        
}

void findNumber(){
    char str_input[SIZE_ARR];
    size_t size; 

    do {
        cout << "Insert string (MAX 99 symbol) to find Number on string:";
        cin >> str_input;
        size = strlen(str_input);

    } while (size > SIZE_ARR);

    cout << "Number is: ";

    for (size_t i = 0; str_input[i]; ++i){
        if('0' <= str_input[i] && str_input[i] <= '9'){
            cout <<" "<< str_input[i] <<" ";
        }  
    }  
}

int main(){

    int choise = 0;
    cout << "Calculation program: \n"
         <<"1. To Lower string \n" 
         <<"2. To Upper string \n"
         <<"3. To Revers string \n"
         <<"4. Find number in string \n"
         <<"\n";
    cin >> choise;

    switch (choise){
    case TO_LOWER:
        toLower();
        break;
    case TO_UPPER:
        toUpper();
        break;
    case REVERS_STR:
        revers();
        break;
    case FIND_NUMBER:
        findNumber();
        break;
    default:
        cout<<"Error choise!" <<"\n";
        break;
    }

    return 0;
}