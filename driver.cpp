/*
 CSS 342 Assignment 4
 Purpose:           Improving the merge sort algorithm
 Implementation:    Used to test the improved merge sort 
                    and calculate the differences in 
                    the run-time of the original merge sort,
                    quick sort and improved merge sort
 
 @file driver.cpp
 @modified by Leo Le
 @author Ahmed Awad
 @version 1.0   11/25/2017
 */
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <sys/time.h>
#include "mergesort.cpp"
#include "quicksort.cpp"
#include "mergesortImproved.cpp"   // implement your mergesort
using namespace std;

// array initialization with random numbers
void initArray( vector<int> &array, int randMax ) {
    int size = array.size( );
    
    for ( int i = 0; i < size; ) {
        int tmp = ( randMax == -1 ) ? rand( ) : rand( ) % randMax;
        bool hit = false;
        for ( int j = 0; j < i; j++ ) {
            if ( array[j] == tmp ) {
                hit = true;
                break;
            }
        }
        if ( hit )
            continue;
        array[i] = tmp;
        i++;
    }
}

// array printing
void printArray( vector<int> &array, char arrayName[] ) {
    int size = array.size( );
    
    for ( int i = 0; i < size; i++ )
        cout << arrayName << "[" << i << "] = " << array[i] << endl;
}

// performance evaluation
int elapsed( timeval &startTime, timeval &endTime ) {
    return ( endTime.tv_sec - startTime.tv_sec ) * 1000000
    + ( endTime.tv_usec - startTime.tv_usec );
}

int main( int argc, char* argv[] ) {

      //verify arguments
      if ( argc != 2 ) {
        cerr << "usage: a.out size" << endl;
        return -1;
      }
    
      //verify an array size
      int size = atoi( argv[1] );
      if ( size <= 0 ) {
        cerr << "array size must be positive" << endl;
        return -1;
      }
    
    //initalize the size of the array/vector
    cout << "Size of the array to be sorted is " << size << endl;
    
    // array generation
    srand( 1 );
    vector<int> items(size);
    //generate the array
    initArray( items, size );
    //copy the data set for each sort
    vector<int> items1 = items;
    vector<int> items2 = items;
    
    
    // Improved Mersge Sort
    cout << "initial vector for improved mergeSort:" << endl;   // comment out when evaluating performance only
    printArray( items, "items" );                               // comment out when evaluating performance only
 
    struct timeval startTime, endTime;
    gettimeofday( &startTime, 0 );
    mergesortImproved( items );
    gettimeofday( &endTime, 0 );
    cout << "elapsed time: " << elapsed( startTime, endTime ) << endl;
    
    cout << "sorted:" << endl;                                  // comment out when evaluating performance only
    printArray( items, "items" );                               // comment out when evaluating performance only
    cout << endl << endl;
    
    
    // Original Merge Sort
    cout << "initial vector for original mergeSort:" << endl;   // comment out when evaluating performance only
    printArray( items1, "items" );                              // comment out when evaluating performance only
    
    struct timeval startTime1, endTime1;
    gettimeofday( &startTime1, 0 );
    mergeSort(items1, 0, size - 1);
    gettimeofday( &endTime1, 0 );
    cout << "elapsed time: " << elapsed( startTime1, endTime1 ) << endl;
    
    cout << "sorted:" << endl;                                  // comment out when evaluating performance only
    printArray( items1, "items" );                              // comment out when evaluating performance only
    cout << endl << endl;
    
    
    // Quick Sort
    cout << "initial vector for quickSort:" << endl;            // comment out when evaluating performance only
    printArray( items2, "items" );                              // comment out when evaluating performance only
    
    struct timeval startTime2, endTime2;
    gettimeofday( &startTime2, 0 );
    quickSort(items2, 0, size - 1);
    gettimeofday( &endTime2, 0 );
    cout << "elapsed time: " << elapsed( startTime2, endTime2 ) << endl;
    
    cout << "sorted:" << endl;                                  // comment out when evaluating performance only
    printArray( items2, "items" );                              // comment out when evaluating performance only
    cout << endl << endl;
    
    return 0;
} 
