#include <iostream>
#include <cstring>
using namespace std;
 

int main() {
    constexpr int SIZE = 100;
	char input_buff[SIZE]{};
 
    cout<<"Input message to coding: \n";
    cin>>input_buff;

    int lenght = strlen(input_buff);
 
    for(int i = 0; i < lenght; ++i){
        input_buff[i] += 3;
    }

    cout << "Coding message: \n";   
    cout << input_buff<<"\n";
    
    cout<<"Decode: "<<endl;

    for(int i = 0; i < lenght; ++i){
        input_buff[i] -= 3;
    }
        
    cout << input_buff << "\n";

	return 0;
}