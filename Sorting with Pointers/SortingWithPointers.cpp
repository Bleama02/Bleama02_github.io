// Filename: Blea_HW28.cpp
// Description: Sorting With Pointers
// Author: Marcus Blea
// Date: 10/13/22

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

const int MAX_ELEMENTS = 500;

// Function Prototypes
void swap(int *index1, int *index2);

void displayArray(int values[], int size);
int bruteForceSort(int values[], int size);
int bubbleSort(int values[], int size);
int bubblePPSort(int values[], int size);
int selectionSort(int values[], int size);
int insertionSort(int values[], int size);

int main()
{
    srand(time(0));

    int numElements;
    int numComparisons;
    int valuesBubble[MAX_ELEMENTS];
    int valuesBruteForce[MAX_ELEMENTS];
    int valuesBubblePP[MAX_ELEMENTS];
    int valuesSelection[MAX_ELEMENTS];
    int valuesInsertion[MAX_ELEMENTS];

    cout << "How many elements in the array? ";
    cin >> numElements;

    if (numElements > MAX_ELEMENTS)
    {
        cout << "ERROR! To many Elements!" << endl;
        return -1;
    }

    // generate data
    for (int i = 0; i < numElements; i++)
    {
        valuesBruteForce[i] = 1 + rand() % numElements;
        valuesBubble[i] = valuesBruteForce[i];
        valuesBubblePP[i] = valuesBruteForce[i];
        valuesSelection[i] = valuesBruteForce[i];
        valuesInsertion[i] = valuesBruteForce[i];
    }

    // Run the algorithms...

    numComparisons = bruteForceSort(valuesBruteForce, numElements);
    cout << "number of comparisons; " << numComparisons << endl;
    cout << endl;

    numComparisons = bubbleSort(valuesBubble, numElements);
    cout << "number of comparisons; " << numComparisons << endl;
    cout << endl;

    numComparisons = bubblePPSort(valuesBubblePP, numElements);
    cout << "number of comparisons; " << numComparisons << endl;
    cout << endl;

    numComparisons = selectionSort(valuesSelection, numElements);
    cout << "number of comparisons; " << numComparisons << endl;
    cout << endl;

    numComparisons = insertionSort(valuesInsertion, numElements);
    cout << "number of comparisons; " << numComparisons << endl;
    cout << endl;
}

void displayArray(int values[], int size)
{
    for (int i = 0; i < size; i++)
        cout << values[i] << " ";
    cout << endl;
}

void swap(int *index1, int *index2)
{
    int temp = *index2;
    *index2 = *index1;
    *index1 = temp;
}

int bruteForceSort(int values[], int size)
{
    int numComparisons = 0;
    cout << "BRUTE SORT" << endl;
    cout << "Before Sorting: " << endl;
    displayArray(values, size);

    // sorting algorithm...
    int storeArray[MAX_ELEMENTS];
    int i, j, indexOfMin;
    for (i = 0; i < size; i++)
    {
        indexOfMin = 0;
        for (j = 0; j < size; j++)
        {
            numComparisons++;
            if (values[j] < values[indexOfMin])
                indexOfMin = j;
        }
        storeArray[i] = values[indexOfMin];
        values[indexOfMin] = 9999999;
    }

    cout << "After sorting: " << endl;
    displayArray(storeArray, size);

    return numComparisons;
}

int bubbleSort(int values[], int size)
{
    int numComparisons = 0;
    cout << "BUBBLE SORT" << endl;
    cout << "Before Sorting: " << endl;
    displayArray(values, size);

    // sorting algorithm...

    int maxElm;
    int index;
    for (maxElm = size - 1; maxElm > 0; maxElm--)
    {
        for (index = 0; index < maxElm; index++)
        {
            numComparisons++;
            if (values[index] > values[index + 1])
            {
                swap(&values[index], &values[index + 1]);
            }
        }
    }

    cout << "After sorting: " << endl;
    displayArray(values, size);
    return numComparisons;
}

int bubblePPSort(int values[], int size)
{
    int numComparisons = 0;
    cout << "BUBBLE SORT PLUS PLUS" << endl;
    cout << "Before Sorting: " << endl;
    displayArray(values, size);

    // sorting algorithm...

    int maxElement;
    int index;
    bool swapsMade = true;
    swapsMade = true;
    for (maxElement = size - 1; maxElement > 0 && swapsMade; maxElement--)
    {
        swapsMade = false;
        for (index = 0; index < maxElement; index++)
        {
            numComparisons++;
            if (values[index] > values[index + 1])
            {
                swap(&values[index], &values[index + 1]);
                swapsMade = true;
            }
        }
    }
    cout << "After sorting: " << endl;
    displayArray(values, size);
    return numComparisons;
}

int selectionSort(int values[], int size)
{
    int numComparisons = 0;
    cout << "SELECTION SORT" << endl;
    cout << "Before Sorting: " << endl;
    displayArray(values, size);

    // sorting algorithm...
    int i, j, iMin;
    for (j = 0; j < size - 1; j++)
    {
        iMin = j;
        for (i = j + 1; i < size; i++)
        {
            numComparisons++;
            if (values[i] < values[iMin])
            {
                iMin = i;
            }
        }
        if (iMin != j)
        {
            swap(&values[j], &values[iMin]);
        }
    }

    cout << "After sorting: " << endl;
    displayArray(values, size);
    return numComparisons;
}

int insertionSort(int values[], int size)
{
    int numComparisons = 0;
    cout << "INSERTION SORT" << endl;
    cout << "Before Sorting: " << endl;
    displayArray(values, size);

    // sorting algorithm...
    int pulledIndex, pulledValue, insertIndex;

    for (pulledIndex = 1; pulledIndex < size; pulledIndex++)
    {
        pulledValue = values[pulledIndex];
        insertIndex = pulledIndex;
        while (insertIndex > 0 && values[insertIndex - 1] > pulledValue)
        {
            numComparisons += 2;
            values[insertIndex] = values[insertIndex - 1];
            insertIndex = insertIndex - 1;
        }
        values[insertIndex] = pulledValue;
    }

    cout << "After sorting: " << endl;
    displayArray(values, size);

    return numComparisons;
}