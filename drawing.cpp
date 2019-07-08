#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using std::cout;

class Shape {
    public:
        virtual void draw(){
            cout <<"Function to draw shape in CLI\n";
        }

        virtual void calc_square(int a){
           cout <<"Function to calc shape in CLI\n";
        }
};

class Quadrate: public Shape {
    public: 
        void draw(){
            for (size_t i = 0; i < a; ++i){
                for (size_t j = 0; j < a; ++j)
                    (i == 0 || i == a - 1 || j == 0 || j == a - 1) ? cout << "*" : cout << " ";
                cout << "\n";
             }
        }

        void calc_square(unsigned side_a){
            a = side_a;
            square_quadrate = side_a * side_a;
            cout << "Square quadrate: " << square_quadrate <<"\n";
        }
    private:
        unsigned a;
        unsigned square_quadrate;
};

class Circle: public Shape {
    public:
        void draw(){
            size_t cout_shape = 2 * radius + 1;

            for (size_t y = 0; y < cout_shape; ++y){
                for (size_t x = 0; x < cout_shape; ++x){
                    if ((int)hypot(abs(radius - x), abs(radius - y)) == radius){ 
                        cout << "*";
                    } else {
                        cout << " ";
                    }
                }
                cout << "\n";
            }
            cout << "\n";
        }

        void calc_square(unsigned radius_shape){
            radius = radius_shape;
            square_shape = M_PI * pow(radius_shape, 2);
            cout <<"Squre shape: "<<square_shape <<"\n";
        }
    private:
        unsigned radius;
        double square_shape;
};

class Rectangle: public Shape {
    public: 
        void draw(){
            for (size_t i = 0; i < side_a; ++i){
                for (size_t j = 0; j < side_b; ++j)
                    (i == 0 || i == side_a - 1 || j == 0 || j == side_b - 1) ? cout << "*" : cout << " ";
                cout << "\n";
             }
        }

        void calc_square(unsigned a, unsigned b){
            side_a = a;
            side_b = b;
            square_rectangle = a * b;
            cout << "Square rectangle: " << square_rectangle <<"\n";
        }
    private:
        unsigned side_a;
        unsigned side_b;
        unsigned square_rectangle;
};


int main(){

    Circle c;
    c.calc_square(5);
    c.draw();
    cout<<"Override Shape:\n";
    Shape* shape = &c;
    shape->calc_square(6);
    shape->draw();


    /* 
    Quadrate q;
    q.calc_square(5);
    q.draw();

    Rectangle r;
    r.calc_square(4,8);
    r.draw();
*/



    return 0;
}