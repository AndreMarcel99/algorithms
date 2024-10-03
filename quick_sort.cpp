#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
using namespace std;
using namespace std::chrono;

int random_number(int max, int min){
    srand(time(NULL));
    int random =  min + rand() % (max - min);
    return random;
}

int partition(int arr[], int lo, int hi){
    int pivot = arr[hi];
    int i = lo - 1;
    for(int j = lo; j <= hi - 1; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[hi]);
    return i + 1;
}

int partition_r(int arr[], int lo, int hi){
    int r = random_number(hi, lo);
    swap(arr[r], arr[hi]);   
    return partition(arr, lo, hi);
}

void quicksort(int arr[], int lo, int hi){
    if(lo < hi){
        int p = partition_r(arr, lo, hi);
        quicksort(arr, lo , p-1);
        quicksort(arr, p+1, hi);
    }
}

void fill_array(int arr[], int size){
    for(int i=0;i < size;i++){
        arr[i] = i;
    }
}

void mix_Array(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        int random =  rand() % size;
        swap(arr[i], arr[random]);
    }
}

float get_Average(int array[], int size){
    long times_array[50];
    for(int i=0; i < 50; i++){
        mix_Array(array, size);
        auto start = high_resolution_clock::now();
        quicksort(array, 0, size-1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        times_array[i] = duration.count();
    }
    long sum = 0;
    for(int i=0; i < 50; i++){
        sum += times_array[i];
    }
    float average = sum/50;
    return average;
}

int main()
{
    int arr_1[100];
    int arr_25[250];
    int arr_5[500];
    int arr_75[750];
    int arr_10[1000];
    int arr_12[1250];
    int arr_15[1500];
    int arr_17[1750];
    int arr_2[2000];

    int arr_sizes[9] = {100, 250, 500, 750, 1000, 1250, 1500, 1750, 2000};
    int arr_average[9];
    int aux = 0;

    int n = sizeof(arr_1) / sizeof(arr_1[0]);
    fill_array(arr_1, n);
    arr_average[aux] = get_Average(arr_1, n);
    aux++;

    n = sizeof(arr_25) / sizeof(arr_25[0]);
    fill_array(arr_25, n);
    cout << get_Average(arr_25, n) << "\n";

    n = sizeof(arr_5) / sizeof(arr_5[0]);
    fill_array(arr_5, n);
    cout << get_Average(arr_5, n) << "\n";

    n = sizeof(arr_75) / sizeof(arr_75[0]);
    fill_array(arr_75, n);
    cout << get_Average(arr_75, n) << "\n";

    n = sizeof(arr_10) / sizeof(arr_10[0]);
    fill_array(arr_10, n);
    cout << get_Average(arr_10, n) << "\n";    

    n = sizeof(arr_12) / sizeof(arr_12[0]);
    fill_array(arr_12, n);
    cout << get_Average(arr_12, n) << "\n";

    n = sizeof(arr_15) / sizeof(arr_15[0]);
    fill_array(arr_15, n);
    cout << get_Average(arr_15, n) << "\n";

    n = sizeof(arr_17) / sizeof(arr_17[0]);
    fill_array(arr_17, n);
    cout << get_Average(arr_17, n) << "\n";

    n = sizeof(arr_2) / sizeof(arr_2[0]);
    fill_array(arr_2, n);
    cout << get_Average(arr_2, n) << "\n";

    return 0;
}
