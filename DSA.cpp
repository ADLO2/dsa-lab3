#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <chrono>
using namespace std;

#include "DataGenerator.h"
const int DATASIZE1 = 10000;
const int DATASIZE2 = 30000;
const int DATASIZE3 = 50000;
const int DATASIZE4 = 100000;
const int DATASIZE5 = 300000;
const int DATASIZE6 = 500000;

/////////////////////// IMPLEMENT SORTING ALGORITHM HERE ///////////////////////
void SelectionSort(int a[], int n, unsigned long long &cCount) {
    cCount = 0;
    int minIndex;
    for (int i = 0; (++cCount && i < n - 1); i++)
    {
        minIndex = i;
        for (int j = i + 1; (++cCount && j < n); j++)
        {
            if (++cCount && a[minIndex] > a[j]) {
                minIndex = j;
            }
        }
        swap(a[minIndex], a[i]);
    }
}

void InsertionSort(int a[], int n, unsigned long long &cCount) {

}
void RadixSort(int a[], int n, unsigned long long &cCount) {
    
}
void BubbleSort(int a[], int n, unsigned long long &cCount) {
    
}
void HeapSort(int a[], int n, unsigned long long &cCount) {
    
}
void MergeSort(int a[], int n, unsigned long long &cCount) {
    
}
void QuickSort(int a[], int n, unsigned long long &cCount) {
    
}
void ShakerSort(int a[], int n, unsigned long long &cCount) {
    
}
void ShellSort(int a[], int n, unsigned long long &cCount) {
    
}
void CountingSort(int a[], int n, unsigned long long &cCount) {
    
}
void FlashSort(int a[], int n, unsigned long long &cCount) {
    
}

//  NGHIA
//Cmd 1 [5] : [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
//Ex:         a.exe            -a radix-sort  input.txt     -both
void Command1(string algoName, string inputFilePath, string outputParameters) {
    // Open input file
    fstream input;
    input.open(inputFilePath, ios::in);
    if (!input.is_open()) {
        cout << "Cannot open file " << inputFilePath << " !" << endl;
        return;
    }

    // Declaration and Initialize values
    int n;
    input >> n;
    if (n <= 0) {
        cout << "Input file is invalid" << endl;
        return;
    }
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        input >> a[i];
    }
    unsigned long long compareCount = 0;
    double runTime = 0;

    // Print out information to console 
    cout << "ALGORITHM MODE" << endl;
    
    if (algoName == "selection-sort") 
    {
        cout << "Algorithm : Selection Sort" << endl;
    }
    else if (algoName == "binary-insertion-sort" || algoName == "insertion-sort") 
    {
        cout << "Algorithm : Insertion Sort" << endl;
    } 
    else if (algoName == "radix-sort") 
    {
        cout << "Algorithm : Radix Sort" << endl;
    }
    else if (algoName == "bubble-sort") 
    {
        cout << "Algorithm : Bubble Sort" << endl;
    }
    else if (algoName == "heap-sort") 
    {
        cout << "Algorithm : Heap Sort" << endl;
    }
    else if (algoName == "merge-sort") 
    {
        cout << "Algorithm : Merge Sort" << endl;
    }
    else if (algoName == "quick-sort") 
    {
        cout << "Algorithm : Quick Sort" << endl;
    }
    else if (algoName == "shaker-sort") 
    {
        cout << "Algorithm : Shaker Sort" << endl;
    }
    else if (algoName == "shell-sort") 
    {
        cout << "Algorithm : Shell Sort" << endl;
    }
    else if (algoName == "counting-sort") 
    {
        cout << "Algorithm : Counting Sort" << endl;
    }
    else if (algoName == "flash-sort") 
    {
        cout << "Algorithm : Flash Sort" << endl;
    }
    else
    {
        cout << "Your algorithm name " << algoName << " is invalid !" << endl;
        cout << "          selection-sort : Selection Sort" << endl;
        cout << "   binary-insertion-sort : Insertion Sort" << endl;
        cout << "          insertion-sort : Insertion Sort" << endl;
        cout << "              radix-sort : Radix Sort" << endl; 
        cout << "             bubble-sort : Bubble Sort" << endl; 
        cout << "               heap-sort : Heap Sort" << endl; 
        cout << "              merge-sort : Merge Sort" << endl; 
        cout << "              quick-sort : Quick Sort" << endl; 
        cout << "             shaker-sort : Shaker Sort" << endl; 
        cout << "              shell-sort : Shell Sort" << endl; 
        cout << "           counting-sort : Counting Sort" << endl; 
        cout << "              flash-sort : Flash Sort" << endl;
        return;
    }
    cout << "Input file : " << inputFilePath << endl;
    cout << "Input size : " << n << endl;
    cout << string(28,'-') << endl;

    // Check output parameters before sorting
    if (outputParameters != "-both" && outputParameters != "-time" && outputParameters != "-comp") {
        cout << "Your Output parameters " << outputParameters << " is invalid" << endl;
        cout << "   -time: running time" << endl;
        cout << "   -comp: number of comparisions" << endl;
        cout << "   -both: both above options." << endl;
        return;
    }

    // Execute algorithm
    if (algoName == "selection-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        SelectionSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "binary-insertion-sort" || algoName == "insertion-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        InsertionSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    } 
    else if (algoName == "radix-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        RadixSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "bubble-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        BubbleSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "heap-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        HeapSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "merge-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        MergeSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "quick-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        QuickSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "shaker-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        ShakerSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "shell-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        ShellSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "counting-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        CountingSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "flash-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        FlashSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    
    // Print out results as output Parameters
    if (outputParameters == "-both") {
        cout << "Running time : " << runTime << "ms" << endl;
        cout << "Comparisons : " << compareCount << endl << endl;
    } else if (outputParameters == "-time") {
        cout << "Running time : " << runTime << "ms" << endl;
    } else if (outputParameters == "-comp") {
        cout << "Comparisons : " << compareCount << endl;
    }

    // Write down the sorted array to the "output.txt" file
    fstream output;
    output.open("output.txt", ios::out);
    for (int i = 0; i < n; i++)
    {
        output << a[i] << " ";
    }

    // Close file after using
    input.close();
    output.close();
    delete [] a;
}

// NGHIA
//Cmd 2 [6] : [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
//             a.exe            -a selection-sort 50        -rand         -time
void Command2(string algoName, int inputSize, string inputOrder, string outputParameters) {
    // Declaration and Initialize values
    string inputOrderName;
    int n = inputSize;
    if (n <= 0) {
        cout << "Input file is invalid" << endl;
        return;
    }
    int* a = new int[n];
    if (inputOrder == "-rand") // randomized data
    {
        GenerateRandomData(a, n);
        inputOrderName = "Randomized data";
    }
    else if (inputOrder == "-nsorted") // nearly sorted data
    {
        GenerateNearlySortedData(a, n);
        inputOrderName = "Nearly sorted data";
    }
    else if (inputOrder == "-sorted") // sorted data
    {
        GenerateSortedData(a, n);
        inputOrderName = "Sorted data";
    }
    else if (inputOrder == "-rev") // reverse sorted data
    {
        GenerateReverseData(a, n);
        inputOrderName = "Reverse sorted data";
    } else {
        cout << "Your input Order " << inputOrder << " is invalid !" << endl;
        cout << "     -rand: Randomized data" << endl;
        cout << "  -nsorted: Nearly sorted data" << endl;
        cout << "   -sorted: Sorted data" << endl;
        cout << "      -rev: Reverse sorted data" << endl;
        return;
    }
    unsigned long long compareCount = 0;
    double runTime = 0;

    // Write down the generated input to the "input.txt" file.
    fstream writeToInput;
    writeToInput.open("input.txt", ios::out);
    writeToInput << n << endl;
    for (int i = 0; i < n; i++)
    {
        writeToInput << a[i] << " ";
    }
    

    // Print out information to console 
    cout << "ALGORITHM MODE" << endl;

    if (algoName == "selection-sort") 
    {
        cout << "Algorithm : Selection Sort" << endl;
    }
    else if (algoName == "binary-insertion-sort" || algoName == "insertion-sort") 
    {
        cout << "Algorithm : Insertion Sort" << endl;
    } 
    else if (algoName == "radix-sort") 
    {
        cout << "Algorithm : Radix Sort" << endl;
    }
    else if (algoName == "bubble-sort") 
    {
        cout << "Algorithm : Bubble Sort" << endl;
    }
    else if (algoName == "heap-sort") 
    {
        cout << "Algorithm : Heap Sort" << endl;
    }
    else if (algoName == "merge-sort") 
    {
        cout << "Algorithm : Merge Sort" << endl;
    }
    else if (algoName == "quick-sort") 
    {
        cout << "Algorithm : Quick Sort" << endl;
    }
    else if (algoName == "shaker-sort") 
    {
        cout << "Algorithm : Shaker Sort" << endl;
    }
    else if (algoName == "shell-sort") 
    {
        cout << "Algorithm : Shell Sort" << endl;
    }
    else if (algoName == "counting-sort") 
    {
        cout << "Algorithm : Counting Sort" << endl;
    }
    else if (algoName == "flash-sort") 
    {
        cout << "Algorithm : Flash Sort" << endl;
    }
    else
    {
        cout << "Your algorithm name " << algoName << " is invalid !" << endl;
        cout << "          selection-sort : Selection Sort" << endl;
        cout << "   binary-insertion-sort : Insertion Sort" << endl;
        cout << "          insertion-sort : Insertion Sort" << endl;
        cout << "              radix-sort : Radix Sort" << endl; 
        cout << "             bubble-sort : Bubble Sort" << endl; 
        cout << "               heap-sort : Heap Sort" << endl; 
        cout << "              merge-sort : Merge Sort" << endl; 
        cout << "              quick-sort : Quick Sort" << endl; 
        cout << "             shaker-sort : Shaker Sort" << endl; 
        cout << "              shell-sort : Shell Sort" << endl; 
        cout << "           counting-sort : Counting Sort" << endl; 
        cout << "              flash-sort : Flash Sort" << endl;
        return;
    }
    cout << "Input size : " << n << endl;
    cout << "Input order : " << inputOrderName << endl;
    cout << string(28,'-') << endl;

    // Execute algorithm
    if (algoName == "selection-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        SelectionSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "binary-insertion-sort" || algoName == "insertion-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        InsertionSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    } 
    else if (algoName == "radix-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        RadixSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "bubble-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        BubbleSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "heap-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        HeapSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "merge-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        MergeSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "quick-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        QuickSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "shaker-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        ShakerSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "shell-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        ShellSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "counting-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        CountingSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else if (algoName == "flash-sort") 
    {
        auto started = chrono::high_resolution_clock::now();
        FlashSort(a, n, compareCount);
        auto done = chrono::high_resolution_clock::now();
        runTime = chrono::duration_cast<chrono::milliseconds>(done - started).count();
    }
    else
    {
        cout << "Your algorithm name " << algoName << " is invalid !" << endl;
        cout << "          selection-sort : Selection Sort" << endl;
        cout << "   binary-insertion-sort : Insertion Sort" << endl;
        cout << "          insertion-sort : Insertion Sort" << endl;
        cout << "              radix-sort : Radix Sort" << endl; 
        cout << "             bubble-sort : Bubble Sort" << endl; 
        cout << "               heap-sort : Heap Sort" << endl; 
        cout << "              merge-sort : Merge Sort" << endl; 
        cout << "              quick-sort : Quick Sort" << endl; 
        cout << "             shaker-sort : Shaker Sort" << endl; 
        cout << "              shell-sort : Shell Sort" << endl; 
        cout << "           counting-sort : Counting Sort" << endl; 
        cout << "              flash-sort : Flash Sort" << endl;
        return;
    }
    
    // Print out results as output Parameters
    if (outputParameters == "-both") {
        cout << "Running time : " << runTime << "ms" << endl;
        cout << "Comparisons : " << compareCount << endl << endl;
    } else if (outputParameters == "-time") {
        cout << "Running time : " << runTime << "ms" << endl;
    } else if (outputParameters == "-comp") {
        cout << "Comparisons : " << compareCount << endl;
    }

    // Write down the sorted array to the "output.txt" file
    fstream output;
    output.open("output.txt", ios::out);
    for (int i = 0; i < n; i++)
    {
        output << a[i] << " ";
    }

    // Close file after using
    writeToInput.close();
    output.close();
    delete [] a;
}

void Command3() {

}

void Command4() {

}

void Command5() {

}

int main(int argc, char* argv[]) {
    if (argc < 5 || argc > 6) 
    {
        cout << "Invalid syntax!"                                                                                        << endl;
        cout << "Command 1 : Run a sorting algorithm on the given input data."                                           << endl;
        cout << "           [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]"                         << endl;
        cout << "Command 2 : Run a sorting algorithm on the data generated automatically with specified size and order." << endl;
        cout << "           [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]"            << endl;
        cout << "Command 3 : Run a sorting algorithm on ALL data arrangements of a specified size."                      << endl;
        cout << "           [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]"                          << endl;
        cout << "Command 4 : Run two sorting algorithms on the given input."                                             << endl;
        cout << "           [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]"                               << endl;
        cout << "Command 5 : Run two sorting algorithms on the data generated automatically."                            << endl;
        cout << "           [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]"                  << endl;
        return 0;
    }

    string mode = argv[1];
    string algorithmName = argv[2];
    string argv3 = argv[3];

    // Check the argv[3] is number or file input path,
    // use for distinguishing Command 1 from Command 3
    bool checkArgv3 = (argv3.find_first_not_of("0123456789") == string::npos);
    
    // COMMAND 1
    if ((mode == "-a") && (argc == 5) && (checkArgv3 == false)) 
    {
        string outputParameter = argv[4];
        Command1(algorithmName, argv3, outputParameter);
    }
    // COMMAND 2
    else if ((mode == "-a") && (argc == 6)) 
    {
        int inputSize = stoi(argv3);
        string inputOrder = argv[4];
        string outputParameter = argv[5];
        Command2(algorithmName, inputSize, inputOrder, outputParameter);
    }
    // COMMAND 3
    else if ((mode == "-a") && (argc == 5) && (checkArgv3 == true)) 
    {
        cout << "cmd 3";
    }
    // COMMAND 4
    else if ((mode == "-c") && (argc == 5)) 
    {
        cout << "cmd 4";
    }
    // COMMAND 5
    else if ((mode == "-c") && (argc == 6)) 
    {
        cout << "cmd 5";
    }
    else
    {
        cout << "Invalid syntax!"                                                                                        << endl;
        cout << "Command 1 : Run a sorting algorithm on the given input data."                                           << endl;
        cout << "           [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]"                         << endl;
        cout << "Command 2 : Run a sorting algorithm on the data generated automatically with specified size and order." << endl;
        cout << "           [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]"            << endl;
        cout << "Command 3 : Run a sorting algorithm on ALL data arrangements of a specified size."                      << endl;
        cout << "           [Execution file] -a [Algorithm] [Input size] [Output parameter(s)]"                          << endl;
        cout << "Command 4 : Run two sorting algorithms on the given input."                                             << endl;
        cout << "           [Execution file] -c [Algorithm 1] [Algorithm 2] [Given input]"                               << endl;
        cout << "Command 5 : Run two sorting algorithms on the data generated automatically."                            << endl;
        cout << "           [Execution file] -c [Algorithm 1] [Algorithm 2] [Input size] [Input order]"                  << endl;
    }

    return 0;
}

// int main() {
//     int* a = new int[DATASIZE4];
//     GenerateRandomData(a, DATASIZE4);
//     unsigned long long compareCount;
//     clock_t tStart = clock();
//     SelectionSort(a, DATASIZE4, compareCount);
//     clock_t tEnd = clock();
//     double runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
//     cout << "Running time : " << fixed << setprecision(5) << runTime*1000 << "ms" << endl;

//     int* b = new int[DATASIZE4];
//     GenerateRandomData(b, DATASIZE4);
//     unsigned long long compareCount2;
//     auto started = chrono::high_resolution_clock::now();
//     SelectionSort(b, DATASIZE4, compareCount2);
    // auto done = chrono::high_resolution_clock::now();
    // cout << "Runtime : " << chrono::duration_cast<chrono::milliseconds>(done-started).count() << "ms";
// }