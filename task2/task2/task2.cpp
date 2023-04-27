/*Create a patient management system in the polyclinic. Each patient has
the program is assigned a random number. The system should contain the following
functions. After calling each function, the time it takes should be displayed
was performed The system should contain the following functions:
1. Creation, reduction and expansion of the list of patients.
2. Adding and removing a patient.
3. QuickSort and BogoSort sorting to choose from.
4. Patient search through binary and linear search.
5. Insertion of the patient on a certain index. Implement it iteratively and
recursively
6. Finding the largest and smallest index. Implement iteratively
and recursively.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(int arr[], int SIZE);
void resizeArray(int*& oldArr, int oldSize, int newSize);
void addPatient(int& SIZE, int*& arr);
void deletePatient(int& SIZE, int arr[]);
void quicksort(int arr[], int left, int right);
bool is_sorted(int arr[], int size);
void shuffle(int arr[], int size);
void bogosort(int arr[], int size);
int binarySearch(int arr[], int SIZE, int target);
int linearSearch(int arr[], int SIZE, int target);
void placePatient(int arr[], int SIZE, int index, int newPatient);
void placePatientRecursive(int arr[], int SIZE, int index, int newPatient);
int findMaxRecursive(int arr[], int SIZE);
int findMaxIterative(int arr[], int SIZE);
int findMinRecursive(int arr[], int SIZE);
int findMinIterative(int arr[], int SIZE);

int main() {

    srand(time(NULL));

    // Initialize the array
    int SIZE, choice;    
    cout << "Enter size of array: ";
    cin >> SIZE;

    int* arr = new int[SIZE];

    // Initialize the array with random values
    for (int i = 0; i < SIZE; i++) {

        int num = rand() % 100;
        arr[i] = num;
    }

    // Print the original array
    cout << "Original array: ";
    printArray(arr, SIZE);
    cout << endl;

    // Main menu
    while (true) {

        // Display menu options and get user choice
        cout << "\nMake your choice: " << endl;
        cout << "1. Resize array\n2. Add and delete patient\n3. QuickSort or BogoSort\n";
        cout << "4. Binary or Linear search\n5. Place patient in specific index\n6. Find the largest and smallest values\n7. Exit\n";
        cin >> choice;

        // Resize array
        if (choice == 1) {

            int new_size;
            cout << "Enter the new size of the array: ";
            cin >> new_size;

            // Call the resizeArray function to resize the array
            resizeArray(arr, SIZE, new_size);

            // Update the size variable to reflect the new size of the array
            SIZE = new_size;
        }

        // Add and delete patient
        if (choice == 2) {

            // Declares an integer variable for new choice
            int optionDeleteAdd;

            cout << "To add patient press 1\nTo delete patient press 2:\n"; cin >> optionDeleteAdd;

            if (optionDeleteAdd == 1) {

                // Calls the addPatient function and passes the SIZE and arr variables as arguments
                addPatient(SIZE, arr);
            }
            else if (optionDeleteAdd == 2 && SIZE > 0) {

                deletePatient(SIZE, arr);
            }
        }

        //QuickSort or BogoSort
        if (choice == 3) {

            int optionQuickBogo;
            cout << "Quick sort press 1\nBogoSort press2\n"; cin >> optionQuickBogo;

            // Checks if the user chose to perform quicksort
            if (optionQuickBogo == 1) {

                // Measures the starting time of the quicksort algorithm using the clock() function
                clock_t start_time = clock();

                // Calls function for sorting
                quicksort(arr, 0, SIZE - 1);

                // Measures the ending time of the bogosort algorithm using the clock() function
                clock_t end_time = clock();

                // Function to display array to the user
                printArray(arr, SIZE); 

                double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
                cout << "Function execution time: " << time_taken << " seconds" << endl; // display execution time

            }
            // Checks if the user chose to perform bogosort
            if (optionQuickBogo == 2) {

                clock_t start_time = clock();

                bogosort(arr, SIZE);

                clock_t end_time = clock();

                printArray(arr, SIZE);

                double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
                cout << "Function execution time: " << time_taken << " seconds" << endl;
            }
        }
        // Binary or Linear search
        if (choice == 4) {

            int binaryLinear; 
            cout << "Binary search press 1\nLinear press2\n"; cin >> binaryLinear;

            //Binary search
            if (binaryLinear == 1) {

                // Input value for searching
                int target;
                cout << "Enter a value to search for: ";
                cin >> target;

                quicksort(arr, 0, SIZE - 1); // binarySearch requires array to be sorted. use quicksort  

                clock_t start_time = clock();

                int index = binarySearch(arr, SIZE, target);

                if (index == -1) { // index can`t be lower than 0

                    cout << "Target not found" << endl;
                }
                else {

                    cout << "Target found at index " << index << endl;
                }

                clock_t end_time = clock();
                double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
                cout << "Function execution time: " << time_taken << " seconds" << endl;

            }
            // Linear search
            else if (binaryLinear == 2) {


                int target;
                cout << "Enter a value to search for: ";
                cin >> target;

                clock_t start_time = clock();

                int index = linearSearch(arr, SIZE, target);                

                if (index == -1) {// index can`t be lower than 0

                    cout << "Target not found" << endl;
                }
                else {

                    cout << "Target found at index " << index << endl;
                }

                clock_t end_time = clock();
                double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
                cout << "Function execution time: " << time_taken << " seconds" << endl;
            }
        }
        // Place patient in specific index
        if (choice == 5) {

            int index;
            int newPatient;
            int option5;

            // Get index and new value from user
            cout << "Enter index where to place patient (0-" << SIZE - 1 << "): ";
            cin >> index;
            cout << "Enter patient number: ";
            cin >> newPatient;
            cout << "Recursive(1) or iteratively(2): "; cin >> option5; //choose Recursive or iteratively

            //Recursive
            if (option5 == 1) {

                clock_t start_time = clock();

                placePatientRecursive(arr, SIZE, index, newPatient);

                clock_t end_time = clock();

                printArray(arr, SIZE);

                double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
                cout << "Function execution time: " << time_taken << " seconds" << endl;
            }
            //iteratively
            if (option5 == 2) {

                clock_t start_time = clock();

                placePatient(arr, SIZE, index, newPatient);

                clock_t end_time = clock();

                printArray(arr, SIZE);

                double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
                cout << "Function execution time: " << time_taken << " seconds" << endl;
            }
        }
        //Find the largest and smallest values
        if (choice == 6) {

            int choice6;
            cout << "Enter 1 to find maximum value, or 2 to find minimum value: ";
            cin >> choice6;

            // Declaration of variables to store the result and the method used to find the result
            int result;
            int method;

            cout << "Enter 1 to use recursive method, or 2 to use iterative method: ";
            cin >> method;

            //maximum value
            if (choice6 == 1) {

                clock_t start_time = clock();
                //Recursive
                if (method == 1) {

                    result = findMaxRecursive(arr, SIZE);
                }
                //Iterative
                else {
                    result = findMaxIterative(arr, SIZE);
                }
                cout << "The maximum value in the array is: " << result << endl;
                clock_t end_time = clock();
                double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
                cout << "Function execution time: " << time_taken << " seconds" << endl;

            }
            //minimum value
            else {
                clock_t start_time = clock();

                //Recursive
                if (method == 1) {

                    result = findMinRecursive(arr, SIZE);
                }
                //Iterative
                else {

                    result = findMinIterative(arr, SIZE);
                }

                cout << "The minimum value in the array is: " << result << endl;
                clock_t end_time = clock();
                double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
                cout << "Function execution time: " << time_taken << " seconds" << endl;

            }
        }
        if (choice == 7) { // Exit program
            return 0;
        }
    }
}

// Function to resize the array
void resizeArray(int*& oldArr, int oldSize, int newSize) {
    clock_t start_time = clock();

    // Allocate a new array of the requested size
    int* newArr = new int[newSize];

    srand(time(NULL)); // Seed the random number generator with the current time

    // Copy the old values into the new array
    for (int i = 0; i < min(oldSize, newSize); i++) {
        newArr[i] = oldArr[i];
    }

    // Initialize the remaining elements of the new array with random values
    for (int i = oldSize; i < newSize; i++) {
        newArr[i] = rand() % 100; // Generate a random integer between 0 and 99
    }

    // Print the new array
    cout << "New array: ";
    for (int i = 0; i < newSize; i++) {
        cout << newArr[i] << " ";
    }
    cout << endl;

    // Free the memory occupied by the old array
    delete[] oldArr;

    // Update the old array pointer to point to the new array
    oldArr = newArr;

    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Function execution time: " << time_taken << " seconds" << endl;
}
// Function to add patient
void addPatient(int& SIZE, int*& arr) {

    int id;

    cout << "Enter patient ID: ";
    cin >> id;

    clock_t start_time = clock();

    // Allocate a new array with SIZE + 1 elements
    int* newArr = new int[SIZE + 1];

    // Copy elements from the original array into the new array
    for (int i = 0; i < SIZE; i++) {
        newArr[i] = arr[i];
    }

    // Add the new patient at the end of the new array
    newArr[SIZE] = id;

    // Delete the old array and point arr to the new array
    delete[] arr;
    arr = newArr;
    SIZE++;

    cout << "Patient " << id << " added successfully!" << endl;

    clock_t end_time = clock();

    printArray(arr, SIZE);

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Function execution time: " << time_taken << " seconds" << endl;

}
// Function to delete patient
void deletePatient(int& SIZE, int arr[]) {

    clock_t start_time = clock();

    SIZE--;

    clock_t end_time = clock();

    printArray(arr, SIZE);

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Function execution time: " << time_taken << " seconds" << endl;

}
// Function to Quick sort
void quicksort(int arr[], int left, int right) {
            
    // Partition the array by rearranging its elements 
    // so that elements smaller than pivot are moved to the left of the pivot, 
    // and elements greater than pivot are moved to the right of the pivot.
    int i = left, j = right;

    int tmp;
    int pivot = arr[(left + right) / 2];

    // This part of the quicksort function implements the partition step of the quicksort     
    while (i <= j) {

        // Move the left pointer to the right until it reaches an element that is greater than or equal to the pivot
        while (arr[i] < pivot) {

            i++;
        }
        while (arr[j] > pivot) {

            j--;
        }

        // Swap the elements at the left and right pointers if they are in the wrong subarray
        if (i <= j) {

            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

    // Recursively sort the subarrays to the left and right of the pivot until the entire array is sorted in ascending order.
    if (left < j) {
        quicksort(arr, left, j);
    }
    if (i < right) {
        quicksort(arr, i, right);
    }

}
// Function to check if the array is sorted
bool is_sorted(int arr[], int size) {

    for (int i = 0; i < size - 1; i++) {

        if (arr[i] > arr[i + 1]) {

            return false;
        }
    }
    return true;
}
// Function to shuffle elemnts for Bogo sort
void shuffle(int arr[], int size) {

    // Iterate through the array from the last element to the first element
    for (int i = size - 1; i > 0; i--) {

        // Generate a random index between 0 and i (inclusive)
        int j = rand() % (i + 1);

        // Swap the elements at indices i and j
        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}
// Function for Bogo sort
void bogosort(int arr[], int size) {

    // Repeat until the array is sorted
    while (!is_sorted(arr, size)) {

        // Randomly shuffle the elements of the array
        shuffle(arr, size);
    }

}
// Function for binary search
int binarySearch(int arr[], int SIZE, int target) {

    // Set the left and right pointers to the beginning and end of the array, respectively
    int left = 0, right = SIZE - 1;
    int midpoint;

    // Continue searching while the left pointer is less than or equal to the right pointer
    while (left <= right) {

        // Calculate the midpoint index of the current search interval
        midpoint = (left + right) / 2;

        // If the midpoint element matches the target element, return the midpoint index
        if (arr[midpoint] == target) {
            return midpoint;
        }
        // If the midpoint element is greater than the target element, move the right pointer
        // to the index immediately before the midpoint, narrowing the search interval to 
        // the left half of the current interval
        else if (arr[midpoint] > target) {
            right = midpoint - 1;
        }
        // If the midpoint element is less than the target element, move the left pointer 
        // to the index immediately after the midpoint, narrowing the search interval to 
        // the right half of the current interval
        else {
            left = midpoint + 1;
        }
    }

    // If the target element is not found in the array, return -1
    return -1;
}
// Function for linear search
int linearSearch(int arr[], int SIZE, int target) {

    for (int i = 0; i < SIZE; i++) {

        if (arr[i] == target) {

            return i; // return index where element is found
        }
    }
    return -1; // return -1 if element is not found
}
// Function to place the patient into index
void placePatient(int arr[], int SIZE, int index, int newPatient) {

    // Check if index is valid
    if (index < 0 || index >= SIZE) {
        cout << "Invalid index. Please try again." << endl;
        return;
    }

    // Insert new value at index
    arr[index] = newPatient;
}
// Function place patient recursively
void placePatientRecursive(int arr[], int SIZE, int index, int newPatient) {

    // Base case: index is valid, insert new value at index
    if (index >= 0 && index < SIZE) {
        arr[index] = newPatient;
        return;
    }

    // Recursive case: index is invalid, call function with adjusted index
    int newIndex;
    if (index < 0) {

        newIndex = SIZE - 1;
    }
    else {
        newIndex = 0;
    }
    placePatientRecursive(arr, SIZE, newIndex, newPatient);
}
// Function to find max recursively
int findMaxRecursive(int arr[], int SIZE) {

    if (SIZE == 1) { // If the array has only one element, return that element.
        return arr[0];
    }
    // Recursively find the maximum value of the remaining elements in the array.
    int maxOfRest = findMaxRecursive(arr + 1, SIZE - 1);

    // Compare the maximum value of the remaining elements with the first element of the array.
    // Return the maximum of the two.
    if (arr[0] > maxOfRest) {

        return arr[0];
    }
    else {
        return maxOfRest;
    }
}
// Function to find max iteratively
int findMaxIterative(int arr[], int SIZE) {

    // Initialize the maximum value to be the first element of the array.
    int maxVal = arr[0];

    // Iterate through the array, comparing each element with the maximum value.
    // If an element is greater than the current maximum value, update the maximum value.
    for (int i = 1; i < SIZE; i++) {

        if (arr[i] > maxVal) {

            maxVal = arr[i];
        }
    }
    // Return the maximum value.
    return maxVal;
}

// Function to find min recursively
int findMinRecursive(int arr[], int SIZE) {

    if (SIZE == 1) { // If the array has only one element, return that element.
        return arr[0];
    }
    // Recursively find the minimum value of the remaining elements in the array.
    int minOfRest = findMinRecursive(arr + 1, SIZE - 1);

    // Compare the minimum value of the remaining elements with the first element of the array.
    // Return the minimum of the two.
    if (arr[0] < minOfRest) {

        return arr[0];
    }
    else {
        return minOfRest;
    }
}

// Function to find min iteratively
int findMinIterative(int arr[], int SIZE) {

    // Initialize the minimum value to be the first element of the array.
    int minVal = arr[0];

    // Iterate through the array, comparing each element with the minimum value.
    // If an element is less than the current minimum value, update the minimum value.
    for (int i = 1; i < SIZE; i++) {

        if (arr[i] < minVal) {

            minVal = arr[i];
        }
    }
    // Return the minimum value.
    return minVal;
}

// Function to print array
void printArray(int arr[], int SIZE) {

    // Iterate through the array and print each element followed by a space.
    for (int i = 0; i < SIZE; ++i) {

        cout << arr[i] << " ";
    }
    // Print a new line at the end.
    cout << endl;
}