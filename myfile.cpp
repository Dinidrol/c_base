#include <iostream>
#include <cmath>

using namespace std;
 
enum constants  {
    constants_two = 2, 
    constans_four = 4, 
};
 
int  coeff_a = 0;
int  coeff_b = 0;
int  coeff_c = 0;

int main()
{   
    cout << "Input coefficient <A>: ";
    cin >> coeff_a;

    cout << "Input coefficient <B>: ";
    cin >> coeff_b;

    cout << "Input coefficient <C>: ";
    cin >> coeff_c;

    auto discriminant = (coeff_b * coeff_b) - (constans_four * coeff_a * coeff_c);
    cout << "Discrimiant: " << discriminant <<"\n";

    if(discriminant > 0){
        auto x1 = (-coeff_b) + sqrt(discriminant);
        x1 = x1 / (constants_two * coeff_a);
        cout << "x1: " << x1 <<"\n"; 

        auto x2 = (-coeff_b) - sqrt(discriminant);
        x2 = x2 / (constants_two * coeff_a);
        cout << "x2: " << x2 <<"\n"; 

    } else if (discriminant == 0){

        auto x = (-coeff_b);
        x = x / (constants_two * coeff_a);
        cout << "x: " << x <<"\n"; 

    } else {

        cout << "Discrimiant < 0\n";

    }

    system ("pause");
    return 0;

}