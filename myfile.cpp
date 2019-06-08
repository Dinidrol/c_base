#include <iostream>
#include <cmath>
#include <limits>

using std::cout;
using std::cin;
 
enum {
    CONSTANTS_TWO = 2, 
    CONSTANTS_FOUR = 4, 
};
 

int main()
{   
    int  coeff_a = 0;
    int  coeff_b = 0;
    int  coeff_c = 0;
    
    std::cout << "Enter the coefficients from the range.\t"
        << std::numeric_limits<int>::min() << '\t'
        << std::numeric_limits<int>::max() << '\n';


    cout << "Input coefficient <A>: ";
    while ( !(cin >> coeff_a) ){
        (cout << "Error! Re-Input coefficient <A>: ").flush();
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }

    cout << "Input coefficient <B>: ";
    while ( !(cin >> coeff_b) ){
        (cout << "Error! Re-Input coefficient <A>: ").flush();
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }


    cout << "Input coefficient <C>: ";
    while ( !(cin >> coeff_c) ){
        (cout << "Error! Re-Input coefficient <A>: ").flush();
        cin.clear();
        cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
    }

    auto discriminant = (coeff_b * coeff_b) - (CONSTANTS_FOUR * coeff_a * coeff_c);
    cout << "Discrimiant: " << discriminant <<"\n";

    if(coeff_a == 0){

        cout << "x: 0 \n";

    } else if(discriminant > 0){

        auto x1 = (-coeff_b) + sqrt(discriminant);
        x1 /= (CONSTANTS_TWO * coeff_a);
        cout << "x1: " << x1 <<"\n"; 

        auto x2 = (-coeff_b) - sqrt(discriminant);
        x2 /=  (CONSTANTS_TWO * coeff_a);
        cout << "x2: " << x2 <<"\n"; 

    } else if (discriminant == 0){

        auto x = (-coeff_b)/(CONSTANTS_TWO * coeff_a);
        cout << "x: " << x <<"\n"; 

    } else {

        cout << "Discrimiant < 0\n";

    }

    
    return 0;
}