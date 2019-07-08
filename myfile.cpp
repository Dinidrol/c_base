#include <iostream>
#include <string>
#include <set>
#include <regex>
#include <curl/curl.h>

std::set<std::string> get_all_links( std::string text ){
    static const std::regex hl_regex( "href=(.*?)>", std::regex_constants::icase);
    return { std::sregex_token_iterator( text.begin(), text.end(), hl_regex, 1 ),
             std::sregex_token_iterator() } ;
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp){
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main(int argc, char  *argv[]){
    CURL *curl;
    CURLcode res;
    std::string readBuffer;
 
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
 
    }
    for( std::string hlink : get_all_links(readBuffer) ) std::cout << hlink << '\n' ;
    
    return 0;
}