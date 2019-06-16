#include <iostream>
#include <cstring>
#include <limits>

using std::cout;
using std::cin;

void toUpper(){
    const int SIZE = 100;
    char str[SIZE] {};
 
    (cout << "Insert string:\n").flush();
    cin.clear();
    cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

    cin.get(str, SIZE);

    size_t i = 0;
    while (str[i]) {
        if(str[i] < 'a' || str[i] > 'z'){
            printf("%c ", str[i++]);
        } else {
            printf("%c ", (char)(str[i++]-32));
        }  
    }

}

void toLower(){
    const int SIZE = 100;
    char str[SIZE] {};
 
    (cout << "Insert string:\n").flush();
    cin.clear();
    cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );

    cin.get(str, SIZE);

    size_t i = 0;
    while (str[i]) {
        if(str[i] < 'A' || str[i] > 'Z'){
            printf("%c ", str[i++]);
        } else {
            printf("%c ", (char)(str[i++]+32));
        }  
    }
}

void revers(){
    const int SIZE = 100;
    char str[SIZE] {};

    (cout << "Enter a string bro: \n").flush();
    cin.clear();
    cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    
    cin.get(str, SIZE);

    for (int i = strlen(str) - 1; i > -1; i--)
    {
        cout << str[i];
    }
        
}

void toDiget(){
    char str_input[10];
    int size; 

    do {
        cout << "Insert string:";
        cin >> str_input;
        size = strlen(str_input);

    } while (size > 10);
    cout << "Number is: ";
    for (size_t i = 0; i < size; ++i){
        if(47 < (int)str_input[i] && (int)str_input[i] < 58){
            cout <<" "<< str_input[i] <<" ";
        }  
    }  
}

int main(){

    int choise = 0;
    cout << "Calculation program: \n"
         <<"1. Find number in string \n" 
         <<"2. To Upper string \n"
         <<"3. To Lower string \n"
         <<"4. Revers string \n"
         <<"\n";
    cin >> choise;

    switch (choise){
    case 1:
        toDiget();
        break;
    case 2:
        toUpper();
        break;
    case 3:
        toLower();
        break;
    case 4:
        revers();
        break;
    default:
        cout<<"Error choise!" <<"\n";
        break;
    }

    system("pause");
    return 0;
}