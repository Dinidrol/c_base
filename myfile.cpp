#include <iostream>
#include <cstdlib>
#include <bitset>
 
using std::cout;
using std::cin;

enum {
    TREE = 1,
    AVERAGE,
    BIT_SUMM,
    WIN_TICKET,
    REVERS_NUMBER,
    ODD_SUMM,
    BIT_SET,
    BEST_DIV,
    BEST_DIV_3

};

void tree(){
    int width = 0;
    cout << "Input size tree:\n";
    cin >> width;
    if(width %2 == 0){
        ++width;
    }
    for(int i = width/2; i>=0; --i){
        for (int j = 0; j < i; ++j) {
			cout<<' ';
		}
		for (int k = 1; k <= width - i * 2; ++k) {
			cout<<'*';
		}
	    cout<<"\n";
    }
}


void average (){
    int summ = 0;
    int counter = 0;
    int input_number = 0;
    

    cout << "Input number: ";
    cin >> input_number;

    while(input_number > 0){
        summ += input_number % 10;
        input_number /= 10;
        ++ counter;
    }

    auto average = summ / counter;
    cout << "Average: " << average << "\n";
}

void bits_summ(){

    unsigned number = 0;
    unsigned res = 0;

    cout <<"Input number to count set bit: ";
    cin >> number;

    for(int i=0; i<=31; i++) {
        res += ((number & (1 << i)) != 0);
    }
    cout << res << "\n";    
    
    printf("\n");
    //Для проверки выражения
    std::bitset<8> b(number);
    printf("Check using bitset class %s\n", b.to_string().c_str());
}

void happy_ticket(){
    int a, tmp1=0, tmp2=0;

    cout <<"Input ticket number:\n";
    cin>>a;

    for(int i=0; i<3; i++){
        tmp1+=a%10; a/=10;
    }

    for(int i=0; i<3; i++){
        tmp2+=a%10; a/=10;
    }

    if(tmp1==tmp2){
        cout<<"Yes\n";
    } else {
        cout<<"No\n";
    }
}

void coup_number(){

    unsigned int n = 0,m = 0;

    cout <<"Insert number:\n";
    cin >> n;
    
    while (n > 0) {
        m = m*10 + n%10;
        n = n/10;
    }
    cout << m;
    
}

void odd_summ(){
    constexpr int N = 4;
    int mas[N]; 
    int sum=0;

    cout <<"Insert number: \n";

    for (int i = 0; i < N; i++){
        cin >> mas[i];  
    }
    
    for (int i = 0; i < N; i++){
        if (mas[i]%2 != 0){
            sum=sum+mas[i];
        }
    }
    cout <<"Summ of elements: "<< sum << "\n";
}

void bit_set(){
    unsigned number;
    unsigned bitNum;

    cout << "Input number: \n";
    cin >> number;

    cout <<"Input bit set number: \n";
    cin >> bitNum;

    number >>= bitNum-1;

    if(number & 1){
        cout << "Bit set";
    } else {
        cout <<"Bit dont set";
    }

}

void best_div(){
    int number;
    int div;

    cout << "Input number: \n";
    cin >> number;

    int half = number/2;

    for(int i = 1; i <= half; ++i ){
        if(number % i == 0){
            div = i;
        }
    }

    cout << "Best div:" << div;
}

void div_by3(){
    constexpr int N = 5;
    int mas[N]; 
    int sum=0;

    cout <<"Insert number: \n";

    for (int i = 0; i < N; i++){
        cin >> mas[i];  
    }

    for (int i = 0; i < N; i++){
        sum +=mas[i];
    }

    if((sum%3) == 0){
        cout << "Insert number div by 3";
    } else {
        cout << "Insert number nodt div by 3";
    }

}



int main(){

    int choise = 0;
    cout << "Calculation program: \n"
         <<"1. Build tree \n" 
         <<"2. Average \n" 
         <<"3. Summ bit in number \n"
         <<"4. Happy ticket \n"
         <<"5. Inverse numbers \n"
         <<"6. The sum of odd elements\n"
         <<"7. Set bit in number\n"
         <<"8. Best div\n"
         <<"9. Best div by 3\n"
         <<"Choise number: ";
    cin >> choise;
    
    switch (choise){
        case TREE:
            tree();
            break;
        case AVERAGE:
            average();
            break;
        case BIT_SUMM:
            bits_summ();
            break;
        case WIN_TICKET:
            happy_ticket();
            break;
        case REVERS_NUMBER:
            coup_number();
            break;
        case ODD_SUMM:
            odd_summ();
            break;
        case BIT_SET:
            bit_set();
            break;
        case BEST_DIV:
            best_div();
            break;
        case BEST_DIV_3:
            div_by3();
            break;
        default:
            break;
    }
    
    return 0;
}