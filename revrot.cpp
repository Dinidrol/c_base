#include <iostream>
#include <string>

class revrot{
    public:
        static std::string revRot(const std::string &string, unsigned sz);

};

std::string revrot::revRot(const std::string &string, unsigned sz){
    std::string answer;
    int chunk = 0;
    unsigned lenght = string.size();
    unsigned hulf_lenght = lenght/sz;

    if(sz <= 0 || lenght == 0 || lenght < sz){
        return "";
    }
    for(int i = 0; i < hulf_lenght; i++){
        for(int j = 0; j < sz; j++){
            chunk += string[(i*sz)+j];
        }
        if(chunk%2 == 0){
            for(int j = (sz-1); j >= 0; j--){
                answer.push_back(string[(i*sz)+j]);
            }
        }else{
            for(int j = 1; j < sz; j++){
                answer.push_back(string[(i*sz)+j]);
            }
            answer.push_back(string[i*sz]);
        }
    }
    return answer;
}


int main (){
    revrot b;
    std::cout << b.revRot("66443875", 4) <<"\n";
    std::cout << b.revRot("66443875", 8) <<"\n";
    std::cout << b.revRot("664438769", 8) <<"\n";
    std::cout << b.revRot("123456779", 8) <<"\n";
    std::cout << b.revRot("", 8);
    return 0;
}