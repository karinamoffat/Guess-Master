//Q1.c – Assignment 3 – Karina Moffat

#include <stdio.h>

//Initialize the date structure
struct Date {
    int day;
    int month;
    int year;
};

typedef struct Date date;

//A function to compare passed through data
//First determine which year is smaller
//If years and days are equal determine the smaller month
//If years are equal determine smaller month
int ifSmaller(date arr, date pivot) {
        if (arr.year > pivot.year){
            return 1;
        } else if (arr.year == pivot.year && arr.month == pivot.month && arr.day > pivot.day) {
            return 1;
        }else if (arr.year == pivot.year && arr.month > pivot.month){
            return 1;
        }
    //If none of the cases fit return false
    return 0;
}

//A function to compare passed through data
//First determine which year is smaller
//If years and days are equal determine the smaller month
//If years are equal determine smaller month
int ifLarger(date arr, date pivot) {
    if (arr.year < pivot.year) {
        return 1;
    } else if (arr.year == pivot.year && arr.month == pivot.month && arr.day == pivot.day) {
        return 1;
    } else if (arr.year == pivot.year && arr.month < pivot.month) {
        return 1;
    }
        //If none of the cases fit, return false
        return 0;
}

//A function to sort the given date
//Use a temporary date to implement a sorting algorithm to sort the dates from lowest to highest
void sortDate(date arr[],int first,int last){
    int i, j, pivot;
    date temp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        //If the first index is less than the last index, set the pivot and 'i' equal to the first value, and 'j' equal to the last

        while(i<j){
            while(ifLarger(arr[i], arr[pivot])&&i<last)
                i++;
            while(ifSmaller(arr[j], arr[pivot]))
                j--;
            if(i<j){
                temp= arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            } }
        //sort the dates from lowest to highest value until 'i' is no longer less than 'j'

        temp= arr[pivot];
        arr[pivot]= arr[j];
        arr[j]=temp;

        sortDate(arr,first,j-1);
        sortDate(arr,j+1,last);
        //recursively call the sortDate function, reduce the value of last by one each iteration
        //then, recursively call the sortDate function increasing the value of first by one each iteration
    }
}


int main() {
    date dateArray[] = {{20, 1, 2014}, {25, 3, 2010}, {3, 12, 1676},
                   {18, 11, 1982}, {19, 4,2015},{ 9, 7, 2015},
                   {12, 8, 2010},{30, 8, 2010}, {21, 1, 2014},
                   {20, 7, 2014},{18, 11, 2020}};

    sortDate(dateArray, 0, (sizeof(dateArray)/sizeof(dateArray[0]))-1);
    //use the sortDate function to sort each date value in the given array

    //Print the array after the swap
    for (int i=0; i<sizeof(dateArray)/sizeof(dateArray[0]); i++){
        printf("{%d, %d, %d}\n", dateArray[i].day, dateArray[i].month, dateArray[i].year);
    }
}

