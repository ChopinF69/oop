#include <iostream>

void bubble(int a[] , int n);
void insertion_sort(int *a , int n);
void selection_sort(int *a , int n);
void merge_sort(int *a , const int begin , const int end);
void quick_sort(int arr[],int low,int high);

#include "sortari.h"

int main() {

    //bubble
    int a[] = {5 ,4 , 3};
    bubble(a , 3);
    for(int i = 0 ; i < 3 ; ++i)std::cout << a[i] << " ";
    std::cout << "\n";

    //insertion sort
    int b[] = {5 ,4 , 3 , 2};
    insertion_sort(b , 4);
    for(int i = 0 ; i < 4 ; ++i)std::cout << b[i] << " ";
    std::cout << "\n";

    //selection sort
    int c[] = {5 , 2 ,3 , 1};
    selection_sort(c , 4);
    for(int i = 0 ; i < 4; ++i)std::cout << c[i] << " ";
    std::cout << "\n";

    //merge sort
    int d[] = {4 , 5 , 3 , 1};
    size_t sizeD = sizeof(d) / sizeof(d[0]);
    merge_sort(d , 0 , sizeD - 1);
    for(int i = 0 ; i < sizeD ; ++i)std::cout << d[i] << " ";
    std::cout << "\n";

    //quick_sort

    int e[] = {3 , 4 , 1 , 2};
    size_t sizeE = sizeof(e) / sizeof(e[0]);
    quick_sort(e , 0 , sizeE);
    for(int i = 0 ; i < sizeE ; ++i)std::cout << e[i] << " ";
    std::cout << "\n";
    return 0;
}
