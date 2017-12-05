/*
 CSS 342 Assignment 4
 Purpose:           Improving the merge sort algorithm
 Implementation:    The mergesortImproved class implement STL vector of
                    Comparable in order to hold the input and keep
                    sorted data
 Compilation:       To compile the project, make sure to include
                    all of these library before run:
                    #include <stdio.h>
                    #include <iostream>
                    #include <string>
                    #include <vector>
                    #include <math.h>
                    compile using this command:
                    g++ -std=c++11 main.cpp cannibals.cpp cannibals.hpp
 
 @file mergesortImproved.cpp
 @author Leo Le
 @version 1.0   11/25/2017
 */
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

/**
 The merge implements the STL vector to keep and hold all
 the data to be merge. This function is used to merge two sub-arrays
 into one. It is utilized for sorting the data into its correct order
 
 @param arr     The array that holds all the data to be sorted
 @param temp    The temporary array that holds all the sorted/merged
 data
 @param first   The first index of the original array
 @param mid     The middle index of the original array
 @param last    The last index of the original array
 */
template<class Comparable>
void merge(vector<Comparable> &arr, vector<Comparable> &temp, int first, int mid, int last)
{
    // Initialize the local indices to indicate the subarrays
    int first1 = first;            // Beginning of first subarray
    int last1 = mid;               // End of first subarray
    int first2 = mid + 1;          // Beginning of second subarray
    int last2 = last;              // End of second subarray
    int index = first1;            // Next available location in tempArray
    
    //2 filled sub-arrays, compare the smaller element in both sub-arrays
    while ((first1 <= last1) && (first2 <= last2))
    {
        //compare 2 sorted sub-arrays
        if (arr[first1] <= arr[first2])
        {
            temp[index] = arr[first1];
            first1++;
        }
        else
        {
            temp[index] = arr[first2];
            first2++;
        }
        index++;
    }
    
    //merge the first sub-array to the temp-array
    while (first1 <= last1)
    {
        temp[index] = arr[first1];
        first1++;
        index++;
    }
    
    //merge the second sub-array to the temp-array
    while (first2 <= last2)
    {
        temp[index] = arr[first2];
        first2++;
        index++;
    }
}

/**
 The merge sort implements the STL vector to keep and hold all
 the data that has been sorted. The merge sort has 2 loops. The first 
 loop will separate the original array into small sub-arrays with specific
 size starting from 1 to the size of the array. The second loop will merge
 all the data within the original array into the temp-array. After it is 
 done merging, the temp-array will be used for the next iteration by
 copying it back to the original array.
 
 @param arr     The array that holds all the data to be sorted
 */
template <class Comparable>
void mergesortImproved(vector<Comparable> &arr)
{
    //initialize variables
    int size = arr.size( );
    int subSize, first, mid, last, check1, check2;
    //temporary array with the same size
    vector<Comparable> temp(size);
    temp = arr;
    //loop for each sub-array with specific size (Breaking down the array)
    for (subSize = 1; subSize < size; subSize *= 2)
    {
        //loop for iterating through each sub-array
        for (first = 0; first < size - 1; first += subSize * 2)
        {
            //calculate the middle index
            mid = first + subSize - 1;
            //calculate the last index of the sub-array and compare it to the last index of the array
            check1 = first + (subSize * 2) - 1;
            check2 = size - 1;
            //check the smallest number of the last element
            if (check1 < check2)
                last = check1;
            else
                last = check2;
            //merge/sort the data from the sub-arrays into the temp-array
            merge(arr, temp, first, mid, last);
        }
        //When the temp-array is filled with sorted data, put all data from
        //the sorted temp-array to the original array and use it for the next iteration.
        arr = temp;
    }
}
