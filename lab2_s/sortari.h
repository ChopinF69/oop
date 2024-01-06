//
// Created by lazar on 05.01.2024.
//

#ifndef LAB2_S_SORTARI_H
#define LAB2_S_SORTARI_H
#include <iostream>
void bubble(int a[] , int n)
{
    int i;
    bool schimbat = 0;//presupunem ca din prima e sortat
    do {
        schimbat = 0;
        for(i = 0 ; i < n - 1 ; ++i)
            if(a[i] > a[i + 1])
            {
                std::swap(a[i] , a[i + 1]);
                schimbat = 1;
            }
    }while(schimbat == 1);
}
void insertion_sort(int *a , int n)
{
    //pana la i avem vectorul sortat , dupa i e nesortat
    //si vrem sa aducem elemetul de pe pozitia i
    //unde trebuie in partea stanga , adica inainte de i
    /*
     * a = { 2 , 5 , 4 , 3}
     * i = 2 -> a[i] = 4
     * mergem cat timp a[i] < a[j] && j >= 0
     */
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && a[j - 1] > a[j]) {
            std::swap(a[j - 1], a[j]);
            --j;
        }
    }
}
void selection_sort(int *a , int n)
{
    /*
     * in stanga la i vom avea vectorul sortat
     * in dreapta vom avea vectorul nesortat
     * la fiecare iteratie gasim pozitia minima din dreapta
     * suntem 100% siguri ca vor veni in ordine
     */
    for(int i = 0 ; i < n  ; ++i)
    {
        int pozMin = i;
        for(int j = i ; j < n; ++j)
        {
            if(a[pozMin] > a[j])pozMin = j;
        }
        //std::cout << a[pozMin] << " "<< a[i] << "\n";
        std::swap(a[pozMin] , a[i]);
    }
}

void merge_2_lists(int *array, const int left, const int mid, const int right) {
    size_t size_left = mid - left + 1;
    size_t size_right = right - mid;

    auto *left_array = new int[size_left];
    auto *right_array = new int[size_right];

    // Copy data to temporary arrays left_array[] and right_array[]
    for (int i = 0; i < size_left; ++i)
        left_array[i] = array[left + i];
    for (int j = 0; j < size_right; ++j)
        right_array[j] = array[mid + 1 + j];

    int index_left = 0, index_right = 0;
    int index_merged = left;

    while (index_left < size_left && index_right < size_right) {
        if (left_array[index_left] <= right_array[index_right]) {
            array[index_merged] = left_array[index_left];
            index_left++;
        } else {
            array[index_merged] = right_array[index_right];
            index_right++;
        }
        index_merged++;
    }

    // Copy the remaining elements of left_array[], if there are any
    while (index_left < size_left) {
        array[index_merged] = left_array[index_left];
        index_left++;
        index_merged++;
    }

    // Copy the remaining elements of right_array[], if there are any
    while (index_right < size_right) {
        array[index_merged] = right_array[index_right];
        index_right++;
        index_merged++;
    }

    delete[] left_array;
    delete[] right_array;
}
void merge_sort(int *a , const int begin , const int end)
{
    if(begin >= end)
        return;
    int mid = begin + (end - begin) / 2;
    merge_sort(a , begin , mid);
    merge_sort(a , mid + 1 , end);
    merge_2_lists(a , begin , mid , end);
}
int partition(int arr[],int low,int high)
{
    //choose the pivot

    int pivot=arr[high];
    //Index of smaller element and Indicate
    //the right position of pivot found so far
    int i=(low-1);

    for(int j=low;j<=high;j++)
    {
        //If current element is smaller than the pivot
        if(arr[j]<pivot)
        {
            //Increment index of smaller element
            i++;
            std::swap(arr[i],arr[j]);
        }
    }
    std::swap(arr[i+1],arr[high]);
    return (i+1);
}

// The Quicksort function Implement

void quick_sort(int arr[],int low,int high)
{
    // when low is less than high
    if(low<high)
    {
        // pi is the partition return index of pivot

        int pi=partition(arr,low,high);

        //Recursion Call
        //smaller element than pivot goes left and
        //higher element goes right
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}
#endif //LAB2_S_SORTARI_H
