#include <iostream>

using namespace std;

#define ARR1_MAX 3
#define ARR2_MAX 2

string firstName; // for name input
string secondName;

double arr1[ARR1_MAX];
double arr2[ARR2_MAX]; //array[stuff]

double num; //allows for decimals

void getInput(double array[], int arraySize) { //takes into account array size and array itself
    for (int i = 0; i < arraySize; ++i) { //adds until array is full
        cout << "Enter a number: ";
        cin >> num;
        array[i] = num; //populate array
    }
}

void validateInput(double array[], int arraySize) {  // looks through array
    for (int i = 0; i < arraySize; ++i) { //keep looping as long as its less than the max size of array
        if (array[i] < 0) { //cant be negative
            cout << "No negatives! Enter a positive number.";
            getInput(arr1, ARR1_MAX); //keeps asking until all numbers are positive
            getInput(arr2, ARR2_MAX);
        }
    }
}

void sort(double array[], int arraySize) { //bubble sort
    for (int i = 0; i < arraySize; ++i) {
        for (int j = 0; j < arraySize - 1; ++j) {
            if (array[j] > array[j+1]) { //if one is bigger swap
                double store; 
                store = array[j]; //store values first to allow them to be moved
                array[j] = array[j+1]; //similar concept to swap function
                array[j+1] = store; 
            }
        }
    }
}

void swap(double *num1, double *num2) { // * lets you replace one thing with another
    double store;
    store = *num1; //store the value of number 1
    *num1 = *num2; //number 2 replaces number 1
    *num2 = store; //number one put where two was
}

void print(double array[], int arraySize){
    for (int i = 0; i < arraySize; ++i) { //loops through and prints out the array
        cout << array[i] << " "; //space in between
    }
}

int main() {

    //take name inputs
    cout << "Enter a first name: ";
    cin >> firstName;
    cout << "Enter a second name: ";
    cin >> secondName;

    getInput(arr1, ARR1_MAX); //get input and then validate
    getInput(arr2, ARR2_MAX);
    validateInput(arr1, ARR1_MAX);
    validateInput(arr2, ARR2_MAX);

    sort(arr1, ARR1_MAX); //sort :P
    sort(arr2, ARR2_MAX); 
    
    //print names and then their respective arrays
    cout << firstName << endl;
    print(arr1, ARR1_MAX);
    
    cout << secondName <<endl;
    print(arr2, ARR2_MAX);
    
    
    return 0;
}
