#include <iostream>
#include <cstdlib>
#include <limits>
 
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

int incriment_number (int best_div) {
	int summ = 0;
	while (best_div > 0) {
		summ += best_div % 10;
		best_div /= 10;
	}
	return summ;
}

void tree(){
    unsigned width_tree = 0;

    cout << "Input size tree:\n";
    
    
    while(!(cin >> width_tree)){
        (cout << "Error! Re-Input size tree (NUMBER UNSIGNEd): ").flush();
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }

    if(width_tree %2 == 0){
        ++width_tree;
    }
    for(int iteration = width_tree/2; iteration>=0; --iteration){
        for (int space = 0; space < iteration; ++space) {
			cout<<' ';
		}
		for (int star = 1; star <= width_tree - iteration * 2; ++star) {
			cout<<'*';
		}
	    cout<<"\n";
    }
}


void average (){
    unsigned summ = 0;
    unsigned counter = 0;
    unsigned input_number = 0;
    

    cout << "Program for calculating the average. Input only number: ";
   

    while(!(cin >> input_number)){
        (cout << "Error! Re-Input number (NUMBER UNSIGNED): ").flush();
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }


    if (input_number !=0){
        while(input_number > 0){
            summ += input_number % 10;
            input_number /= 10;
            ++ counter;
        }

        auto average = summ / counter;
        cout << "Average: " << average << "\n";
    } else {
        cout << "Нou have not entered a single number \n";
    }

}

void bits_summ(){

    unsigned dec_number = 0;
    unsigned res = 0;

    cout <<"Input number to count set bit: ";
    
    
    while(!(cin >> dec_number)){
        (cout << "Error! Re-Input number (NUMBER UNSIGNED): ").flush();
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }
     

    while (dec_number !=0){
        res += dec_number & 1;
        dec_number >>= 1;
    }

    cout <<"The amount of bits set in the number:"<< res << "\n";    
    
}

void happy_ticket(){
tryAgain:
    unsigned ticket_number = 0;
    unsigned check_ticket_number = 0;
    unsigned high_bit = 0;
    unsigned low_bit = 0;

    size_t count_sign = 1;


    cout <<"Input ticket number:\n";
    
    while(!(cin >> ticket_number)){
        (cout << "Error! Re-Input number (NUMBER UNSIGNED): ").flush();
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }

    check_ticket_number = ticket_number;

    while((check_ticket_number/=10) > 0){
    	++count_sign;
    }

    if(count_sign > 6){
    	cout << "Sign number more 6 digit!";
    	goto tryAgain;
    }

    for(size_t i=0; i<3; i++){
        high_bit+=ticket_number%10; 
        ticket_number/=10;
    }

    for(size_t i=0; i<3; i++){
        low_bit+=ticket_number%10; 
        ticket_number/=10;
    }

    cout << (high_bit == low_bit) ? "You have are happy ticket!\n" : "You have are  not happy ticket bro!\n";

}

void revers_number(){

    unsigned input_number = 0;
    unsigned revers_number = 0;

    cout <<"Insert number:\n";
    
    while(!(cin >> input_number)){
        (cout << "Error! Re-Input number (NUMBER UNSIGNED): ").flush();
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }   
    

    while (input_number > 0) {
        revers_number = revers_number*10 + input_number%10;
        input_number = input_number/10;
    }
    cout <<"You revers string number: "<< revers_number;
    
}

void odd_summ(){
	size_t N = 5;
	int input_number = 0;
    int sum = 0;

    cout <<"Insert 100 any integers number: \n";

    for (size_t i = 0; i < N; i++){
        cin >> input_number;  
        if (input_number%2 != 0){
            sum+=input_number;
        }
    }
    
    cout <<"Summ even of elements: "<< sum << "\n";
}

void bit_set(){
    unsigned number;
    unsigned bitNum;

    cout << "Input number to check bit: \n";
    cin >> number;

    cout <<"Input bit set number: \n";
    cin >> bitNum;

    number >>= bitNum-1;

    if( (number > 0 ) && (number <=32)  && (number &(0x1 << (bitNum-1))) ){
        cout << "Bit set in number";
    } else {
        cout <<"Bit dont set in number";
    }

}

void best_div(){
    int number = 0;
    int div = 1;
    int previous_summ = 0;
    int best_div = 0;

    cout << "Input number: \n";
    cin >> number;

    while(div <= number){
        int current_summ = 0;
        if(!(number % div)){
            current_summ = incriment_number(div);
            if (current_summ >= previous_summ){
                best_div = div;
                previous_summ = current_summ;
            }
        }
        ++div;
    }
    cout << "Best div:" << best_div;
}

void div_by3(){
	size_t N = 5;
    int number = 0;
    int sum = 0;

    cout <<"Insert number: \n";
    for(size_t i = 0; i < N; ++i){
    	cin >> number;
    	sum += number;
    }

    cout << ((sum%3) == 0) ? "Insert number div by 3" : "Insert number nodt div by 3";
}



int main(){

    int choise = 0;
    cout << "Calculation program: \n"
         <<"1. Build tree \n" 
         <<"2. Average \n" 
         <<"3. Summ of bits in the number \n"
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
            revers_number();
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