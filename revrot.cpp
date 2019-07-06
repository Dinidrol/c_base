#include <iostream>
#include <string>


std::string revRot(const std::string &string, size_t sz){
    std::string answer;
    int chunk = 0;
    size_t lenght = string.size();
    size_t hulf_lenght = lenght/sz;

    if(sz <= 0 || lenght == 0 || lenght < sz){
        return "";
    }
    for(int i = 0; i < hulf_lenght; ++i){
        for(int j = 0; j < sz; ++j){
            chunk += string[(i*sz)+j];
        }
        if(chunk%2 == 0){
            for(int j = (sz-1); j >= 0; --j){
                answer.push_back(string[(i*sz)+j]);
            }
        }else{
            for(int j = 1; j < sz; ++j){
                answer.push_back(string[(i*sz)+j]);
            }
            answer.push_back(string[i*sz]);
        }
    }
    return answer;
}


int main (){
    std::cout << revRot("66443875", 4) <<"\n";
    std::cout << revRot("66443875", 8) <<"\n";
    std::cout << revRot("664438769", 8) <<"\n";
    std::cout << revRot("123456779", 8) <<"\n";
    std::cout << revRot("", 8);
    return 0;
}