#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
 
enum {
    Constants_two = 2, 
    Constans_four = 4, 
};
 

int main()
{   
    int  coeff_a = 0;
    int  coeff_b = 0;
    int  coeff_c = 0;
    

    cout << "Input coefficient <A>: ";
    cin >> coeff_a;
    
    cout << "Input coefficient <B>: ";
    cin >> coeff_b;

    cout << "Input coefficient <C>: ";
    cin >> coeff_c;

    auto discriminant = (coeff_b * coeff_b) - (Constans_four * coeff_a * coeff_c);
    cout << "Discrimiant: " << discriminant <<"\n";

    if(discriminant > 0){
        if(coeff_a > 0){
            auto x1 = (-coeff_b) + sqrt(discriminant);
            x1 /= (Constants_two * coeff_a);
            cout << "x1: " << x1 <<"\n"; 

            auto x2 = (-coeff_b) - sqrt(discriminant);
            x2 /=  (Constants_two * coeff_a);
            cout << "x2: " << x2 <<"\n"; 
        } else {
            cout << "x: 0 \n"; 
        }

    } else if (discriminant == 0){
        if(coeff_a > 0){
            auto x = (-coeff_b)/(Constants_two * coeff_a);
            cout << "x: " << x <<"\n"; 
        } else {
            cout << "x: 0 \n";
        }
    } else {
        cout << "Discrimiant < 0\n";
    }

    
    return 0;
}