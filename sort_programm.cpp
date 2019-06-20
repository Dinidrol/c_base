#include <iostream>
#include <ctime>
#include <functional>

using std::cout;
using std::cin;

enum {
    BUBLE_SORT_INCREASE =1,
    BUBLE_SORT_DECREASE,
    QUICK_SORT
};

void swap_element_arr(int &first, int &second){
    int temp = first;
    first = second;
    second = temp;
}

void buble_sort(int *ptr_arr, uint16_t size, std::function<bool (int, int)>func){
    if(!ptr_arr) return;
    for(uint16_t i = 0; i < size - 1; ++i){
        for(uint16_t j = 0; j < size - 1; ++j){
            if(func(ptr_arr[j], ptr_arr[j+1])){
                swap_element_arr(ptr_arr[j], ptr_arr[j + 1]);
            }
        }
    }
}

void quicksort(int *ptr_arr, int first, int last){

    if(!ptr_arr) return;

    int mid;
    int f=first, l=last;
    mid = ptr_arr[(f+l) / 2]; 

    do {
        while (ptr_arr[f]<mid) f++;
        while (ptr_arr[l]>mid) l--;
        if (f<=l) {
            swap_element_arr(ptr_arr[f], ptr_arr[l]);
            f++;
            l--;
        }
    } while (f<l);
    
    if (first<l) {
        quicksort(ptr_arr, first, l);
    }
    
    if (f<last) {
        quicksort(ptr_arr, f, last);
    }
}

int main(){
    int *ptr_arr;
    int arr_number[] {5,2,1,6,3,8,1,23,34,14,56,13,54,13,54,53,21,23,45,67,86,26,12,23,2,1,3,4,5,34,5,7,8,4,24,12,34,5,3,53,6,5,7,89,86,23,25};
    int temp;
    
    ptr_arr = arr_number;

    size_t lenght =  sizeof(arr_number)/sizeof(arr_number[0]);

    int choise = 0;

    time_t start, end;

    cout <<"Welcom in program\n"
         <<"1. Bubble sort up\n"
         <<"2. Bublle sort down\n"
         <<"3. Quick sort\n";
    cin >> choise;

    switch (choise){
        case BUBLE_SORT_INCREASE:
            start = clock();
            buble_sort(ptr_arr, lenght, [](int first, int second) {return first > second;});
            end = clock();
            break;
        case BUBLE_SORT_DECREASE:
            start = clock();
            buble_sort(ptr_arr, lenght, [](int first, int second) {return first < second;});
            end = clock();
            break;
        case QUICK_SORT:
            start = clock();
            quicksort(ptr_arr, 0, lenght - 1);
            end = clock();
        default:
            break;
    }

    //buble_sort(ptr_arr, lenght, [](int first, int second) {return first > second;});
    cout << "Sorting arr: ";
    for(size_t i = 0; i< lenght; ++i){
        cout << arr_number[i] << " ";
    }
    cout <<"\n";

    cout <<"Working time bubble sort: " << end<< " " << start << " " << "\n";

    return 0;
}
