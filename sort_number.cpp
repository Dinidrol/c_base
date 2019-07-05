#include <iostream>
#include <cstring>
using std::cout;
using std::cin;

enum{
    UNSIGNED = 1,
    DOUBLE,
    CHAR
};

template <class Type>
void show_arr(Type *start_arr, void *end_arr){
    for ( ;start_arr != end_arr; ++start_arr){
        cout << *start_arr<<" | ";
    }
    cout << "\n";
}

template <typename Type, size_t N>
void random_arr_number(Type (&arr)[N]){
    if(sizeof(Type) == sizeof(unsigned int)){
        for(size_t it{}; it < N; ++it){
            arr[it] = 1 + rand() % 7;
        }
    } else if(sizeof(Type) == sizeof(double)){
        for(size_t it{}; it < N; ++it){
            arr[it] = 0.01 * (rand() % 10);
        }
    } else if (sizeof(T) == sizeof(char)){
        for (size_t i = 0; i < count; i++){
            arr[i] = 'A' + rand() % ('z' - 'A' + 1);
        }
    }

}

template <class Type>
void swap(Type *a, Type *b){
    Type temp = *a;
    *a = *b;
    *b = temp;
}

void sort_unsigned(unsigned int *start_arr, void *end_arr){
    size_t size_arr = 0;
    size_t end_sort = size_arr - 1;

    for(uint32_t *ptr = start_arr; ptr != end_arr; ++ptr){
        ++size_arr;
    }
    unsigned int temp;
    for(size_t i = 0; i < end_sort; ++i){
        for(size_t j = i +1; j < size_arr; ++j){
            if(start_arr[i] > start_arr[j]){
                swap(&start_arr[i], &start_arr[j]);
            }
        }
    }
}

void sort_double(double *start_arr, void *end_arr){
    size_t size_arr = 0;
    size_t end_sort = size_arr - 1;
    
    for(double *ptr = start_arr; ptr != end_arr; ++ptr){
        ++size_arr;
    }
    double temp;
    for(size_t i = 0; i < end_sort; ++i){
        for(size_t j = i + 1; j < size_arr; ++j){
            if(start_arr[i] > start_arr[j]){
                swap(&start_arr[i], &start_arr[j]);
            }
        }
    }
}

void sort_char(char *start_arr, void *end_arr){
    size_t size_arr = strlen(start_arr);
    size_t end_sort = size_arr - 1;
    char temp;

    for(size_t i = 0; i < end_sort; ++i){
        for(size_t j = i + 1; j < size_arr; ++j){
            if(start_arr[i] > start_arr[j]){
               swap(&start_arr[i], &start_arr[j]);
            }
        }
    }
}

int main (){
    size_t choise = 0;
    constexpr uint16_t SIZE = 20;
    unsigned int arr_int[SIZE];
    double arr_double[SIZE];
    char arr_char[SIZE];
    void *end_arr;
    
    cout << "Programm sort arr size 20 and auto fill arr\n"
        <<"1. Sort unsigned\n"
        <<"2. Sort double\n"
        <<"3. Sort char";
    cin >> choise;


    switch (choise){
        case UNSIGNED:
            end_arr = &arr_int[SIZE];
            random_arr_number(arr_int);
            cout << "Dont sort arr: \n";
            show_arr(arr_int, end_arr);
            sort_unsigned(arr_int, end_arr);
            cout << "Sort arr: \n";
            show_arr(arr_int, end_arr);
            break;
        case DOUBLE:
            end_arr = arr_double;
            random_arr_number(arr_double);
            cout << "Dont sort arr: \n";
            show_arr(arr_double, end_arr);
            sort_double(arr_double, end_arr);
            cout << "Sort arr: \n";
            show_arr(arr_double, end_arr);
            break;
        case CHAR:
            end_arr = arr_char;
            random_arr_number(arr_char);
            cout << "Dont sort arr: \n";
            show_arr(arr_char, end_arr);
            sort_char(arr_char, end_arr);
            cout << "Sort arr: \n";
            show_arr(arr_char, end_arr);
        default:
            cout << "Error choise!\n";
            break;
    }

    return 0;
}