#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
#include <cmath>
#include "matplotlibcpp.h"
#define _USE_MATH_DEFINES
using namespace std;
using namespace std::chrono;
namespace plt = matplotlibcpp;

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
    arr_average[aux] = get_Average(arr_25, n);
    aux++;

    n = sizeof(arr_5) / sizeof(arr_5[0]);
    fill_array(arr_5, n);
    arr_average[aux] = get_Average(arr_5, n);
    aux++;

    n = sizeof(arr_75) / sizeof(arr_75[0]);
    fill_array(arr_75, n);
    arr_average[aux] = get_Average(arr_75, n);
    aux++;

    n = sizeof(arr_10) / sizeof(arr_10[0]);
    fill_array(arr_10, n);
    arr_average[aux] = get_Average(arr_10, n);
    aux++;  

    n = sizeof(arr_12) / sizeof(arr_12[0]);
    fill_array(arr_12, n);
    arr_average[aux] = get_Average(arr_12, n);
    aux++;  

    n = sizeof(arr_15) / sizeof(arr_15[0]);
    fill_array(arr_15, n);
    arr_average[aux] = get_Average(arr_15, n);
    aux++; 

    n = sizeof(arr_17) / sizeof(arr_17[0]);
    fill_array(arr_17, n);
    arr_average[aux] = get_Average(arr_17, n);
    aux++; 

    n = sizeof(arr_2) / sizeof(arr_2[0]);
    fill_array(arr_2, n);
    arr_average[aux] = get_Average(arr_2, n);
    double k1,k2;
    k1 = arr_average[4] / pow(1000, 2);
    k2 = arr_average[4] / (1000 * (log(1000)));
    for(int i=0;i < 9;i++){
        cout <<arr_sizes[i] << ":" << arr_average[i] <<", ";
    }
    vector<double> y = {0,0,0,0,0,0,0,0,0};
    vector<double> x = {0,0,0,0,0,0,0,0,0};
    for (int i = 0; i < y.size(); i++){
        y[i] = arr_average[i];
        x[i] = arr_sizes[i];
    }
    vector<double> x_2(3000), x_log(3000), x_sub(3000);
    for(int i=0;i<3000; i++){
        x_2.at(i) = k1 * pow(i, 2);
        x_log.at(i) = k2 * (i * log(i));
        x_sub.at(i) = i;
    }
    plt::figure_size(1200, 780);
    plt::plot(x, y, "r--");
    plt::plot(x_sub, x_2);
    plt::plot(x_sub, x_log);
    plt::xlim(0, 3000);
    plt::ylim(0, 1000);
    plt::show();
    plt::save("./basic.png");
    return 0;
}
