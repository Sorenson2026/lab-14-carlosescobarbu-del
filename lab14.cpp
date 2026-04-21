/*
Carlos Escobar Bu
This program dynamically allocates an array large enough to hold a user-defined number of test scores.
4/21/2026
Lab 4
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
double* getScores(int&);
void selectionSort(double*, int);
double calcAverage(const double*, int);
void displayScores(const double*, int, double);
void freeMemory(double*);

//It dynamically allocates an array large enough to hold a user-defined number of test scores. Once all the scores are entered, the array should be passed to a function that sorts them in ascending order.
int main()
{
    cout << "This program will ask you to enter the quantity of tests that you took, then it will sort them, and after that it will  calculates the average score, and it will drop the lowest score." << endl << endl;
    int numScores = 0;
    double* scores = getScores(numScores);

    selectionSort(scores, numScores);

    double average = calcAverage(scores, numScores);

    displayScores(scores, numScores, average);

    freeMemory(scores);
    return 0;
}

// Dynamically allocate array and get scores
double* getScores(int& size)
{
    cout << "How many test scores do you want to enter? ";
    cin >> size;

    while (size <= 0)
    {
        cout << "Enter a number greater than 0: ";
        cin >> size;
    }

    double* arr = new double[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter score #" << i + 1 << ": ";
        cin >> *(arr + i);

        while (*(arr + i) < 0)
        {
            cout << "Negative scores are not allowed. Re-enter score #" << i + 1 << ": ";
            cin >> *(arr + i);
        }
    }

    return arr;
}

// Selection Sort in ascending order
void selectionSort(double* arr, int size)
{
    for (int start = 0; start < (size - 1); start++)
    {
        int minIndex = start;
        double minValue = *(arr + start);

        for (int index = start + 1; index < size; index++)
        {
            if (*(arr + index) < minValue)
            {
                minValue = *(arr + index);
                minIndex = index;
            }
        }

        *(arr + minIndex) = *(arr + start);
        *(arr + start) = minValue;
    }
}

// Calculate average with lowest score dropped
double calcAverage(const double* arr, int size)
{
    if (size <= 1)
        return 0.0;

    double total = 0.0;

    // start at 1 so the lowest score (after sorting) is skipped
    for (int i = 1; i < size; i++)
    {
        total += *(arr + i);
    }

    return total / (size - 1);
}

// Display sorted scores and average
void displayScores(const double* arr, int size, double average)
{
    cout << fixed << setprecision(2);

    cout << "\nSorted Test Scores\n";
    cout << "------------------\n";

    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << endl;
    }

    cout << "\nLowest score dropped: " << *arr << endl;
    cout << "Average of remaining scores: " << average << endl;
}

// Free dynamic memory
void freeMemory(double* arr)
{
    delete[] arr;
}