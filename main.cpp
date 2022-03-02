/* 
modeCalculator.cpp - calculates the mode of a dataset
Author: Jensen McKenzie
Module: 3
Project: Homework 3
Problem Statement: Write a program which determines how many pieces of pie most people eat in a year. 

Algorithm/Plan:
   1. Create a function that sorts and array of integers in ascending order.
    1a. For each element in the array, check if there is another element that is greater than it. If so, switch the two positions, so the smaller element comes first.
  2. Create a function to calculate the mode of a sorted array of integers.
   2a. Set up variables to store the current mode, current count, previous number, and greatest count.
   2b. Loop through the array, setting number to the current integer, and checking to see how long the current repeating count is. If the current repeated number's count is greater than the gretest count, set the mode to the current number, and update the greatest count.
   2c. Return the mode, or the number with the greatest count.
  3. Set up a dynamic array of integers, and prompt the user to enter the slices of pie consumed by each person for the year.
  4. Sort the array in ascending order, and print the result. Then print the mode of the array.
*/

#include <iostream>
using namespace std;

//Sort ascending function, sorts the given array in ascending order by grade
void sortAscending(int* arr, int length){
    //Temp student variable for swapping positions later on
    int temp;
    //For each item in the array, check every other item to see if their grade is greater than the current one
    for (int i = 0; i < length; i++){
        for (int j = i+1; j < length; j++){
            if (arr[i] > arr[j]){
                //If the grade is greater, swap the two positions, placing the smaller grade closer to the front of the array
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

//Mode calculation function, calculates the number that appears the most in a given array of integers
int calcMode(int* arr, int length){
    //The previous number
    int number = arr[0];
    //The curerent mode
    int mode = number;
    //The current count
    int count = 1;
    //The greatest count
    int greatestCount = 1;

    //Loop through the entire array
    for (int i=1; i<length; i++)
    {
        //If the current number is equal to the previous one, increment the count
        if (arr[i] == number) {
            ++count;
            //If the current number is not equal to the previous number...
        }else{
            //Check to see if the current count is greater than the greatest count
            if (count >= greatestCount){
                //Update the greatest count, and the current mode
                greatestCount = count;
                mode = arr[i];
            }
            //Set the current count to 1, and set the previous number to the current one
            count = 1;
            number = arr[i];
        }
    }
    //Return the current mode
    return mode;
}

int main() {
    //Initialize a dynamically allocated array of integers, of size 15
    int* list = new int[15];
    //For each element in the array, prompt the user to enter the number of pie slices consumed for that person, and store this number in the array
    for (int i = 0; i < 15; i++){
        if (i != 0){
            cout << endl;
        }
        cout << "Enter the number of pie pieces for person " << i + 1 << ":";
        cin >> list[i];
    }
    //Sort the array in ascending order, and print the result
    sortAscending(list, 15);
    cout << "\nSorted list:" << endl;
    for (int i = 0; i < 15; i++){
        cout << list[i] << endl;
    }
    //Calculate the mode of the array, and print the result
    cout << "\nMode: " << calcMode(list, 15);
}