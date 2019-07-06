#include <iostream>
#include <cstring>
#include <functional>
using std::cout;
using std::cin;

enum{
    UNSIGNED = 1,
    DOUBLE = 2,
    CHAR = 3
};

template <class Type, size_t N>
void show_arr(Type (&arr)[N]){
    for (size_t it{}; it < N; ++it){
        cout << arr[it]<<" | ";
    }
    cout << "\n";
}

template <typename Type, size_t N>
void random_arr_number(Type (&arr)[N]){
    if(std::is_same<Type, unsigned int>::value){
        for(size_t it{}; it < N; ++it){
            arr[it] = 1 + rand() % 7;
        }
    } else if(std::is_same<Type, double>::value){
        for(size_t it{}; it < N; ++it){
            arr[it] = 0.01 * (rand() % 101);
        }
    } else if (std::is_same<Type, char>::value){
        for (size_t it{}; it < N; ++it){
            arr[it] = 'a' + rand() % ('z' - 'a' + 1);
        }
    }

}

template <class Type>
void swap(Type &a, Type &b){
    Type temp = a;
    a = b;
    b = temp;
}

template <class Type>
void compare_swap (Type &a, Type &b){
    if(b<a){
        swap(a,b);
    }
}



template <class Type, size_t N>
void sort_buble(Type (&arr)[N]){
    for(size_t i = 0; i < N-1; ++i){
        for(size_t j = 0; j < N-1; ++j){
            compare_swap(arr[j], arr[j+1]);
        }
    }
}

int main (){
    int choise = 0;
    constexpr uint16_t SIZE = 20;
    unsigned int arr_int[SIZE];
    double arr_double[SIZE];
    char arr_char[SIZE];
    void *end_arr;
    
    cout << "Programm sort arr size 20 and auto fill arr\n"
        <<"1. Sort unsigned\n"
        <<"2. Sort double\n"
        <<"3. Sort char\n";
    cin >> choise;


    switch (choise){
        case UNSIGNED:
            random_arr_number(arr_int);
            cout << "Dont sort arr: \n";
            show_arr(arr_int);
            sort_buble(arr_int);
            cout << "Sort arr: \n";
            show_arr(arr_int);
            break;
        case DOUBLE:
            random_arr_number(arr_double);
            cout << "Dont sort arr: \n";
            show_arr(arr_double);
            sort_buble(arr_double);
            cout << "Sort arr: \n";
            show_arr(arr_double);
            break;
        case CHAR:
            random_arr_number(arr_char);
            cout << "Dont sort arr: \n";
            show_arr(arr_char);
            sort_buble(arr_char);
            cout << "Sort arr: \n";
            show_arr(arr_char);
            break;
        default:
            cout << "Error choise!\n";
            break;
    }

    return 0;
}