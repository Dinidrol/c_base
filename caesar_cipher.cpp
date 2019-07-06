#include <iostream>
#include <cstring>

using std::cout;
using std::cin; 

int main() {
    constexpr size_t SIZE = 100;
	char input_buff[SIZE]{};
 
    cout<<"Input message to coding: \n";
    cin>>input_buff;

    size_t lenght = strlen(input_buff);
 
    for(size_t i = 0; i < lenght; ++i){
        input_buff[i] += 3;
    }

    cout << "Coding message: \n";   
    cout << input_buff<<"\n";
    
    cout<<"Decode: \n";

    for(size_t i = 0; i < lenght; ++i){
        input_buff[i] -= 3;
    }
        
    cout << input_buff << "\n";

	return 0;
}