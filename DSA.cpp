#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <time.h>
using namespace std;

#include "DataGenerator.h"
const int DATASIZE1 = 10000;
const int DATASIZE2 = 30000;
const int DATASIZE3 = 50000;
const int DATASIZE4 = 100000;
const int DATASIZE5 = 300000;
const int DATASIZE6 = 500000;

////////////////////////// IMPLEMENT SORTING ALGORITHM HERE ///////////////////////
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

//Cmd 1 [5] : [Execution file] -a [Algorithm] [Given input] [Output parameter(s)]
//Ex:         a.exe            -a radix-sort  input.txt     -both
void Command1(string algoName, string inputFilePath, string outputParameters) {
    // Open input file
    fstream input;
    input.open(inputFilePath, ios::in);

    // Declaration and Initialize values
    int n;
    input >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        input >> a[i];
    }
    unsigned long long compareCount = 0;
    double runTime = 0;

    // Print out information to console 
    cout << "ALGORITHM MODE" << endl;
    cout << "Algorithm : " << algoName << endl;
    cout << "Input file : " << inputFilePath << endl;
    cout << "Input size : " << n << endl;
    
    // Execute algorithm
    if (algoName == "selection-sort") 
    {
        clock_t tStart = clock();
        SelectionSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    }
    else if (algoName == "binary-insertion-sort" || algoName == "insertion-sort") 
    {
        clock_t tStart = clock();
        InsertionSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    } 
    else if (algoName == "radix-sort") 
    {
        clock_t tStart = clock();
        RadixSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    }
    else if (algoName == "bubble-sort") 
    {
        clock_t tStart = clock();
        BubbleSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    }
    else if (algoName == "heap-sort") 
    {
        clock_t tStart = clock();
        HeapSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    }
    else if (algoName == "merge-sort") 
    {
        clock_t tStart = clock();
        MergeSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    }
    else if (algoName == "quick-sort") 
    {
        clock_t tStart = clock();
        QuickSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    }
    else if (algoName == "shaker-sort") 
    {
        clock_t tStart = clock();
        ShakerSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    }
    else if (algoName == "shell-sort") 
    {
        clock_t tStart = clock();
        ShellSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    }
    else if (algoName == "counting-sort") 
    {
        clock_t tStart = clock();
        CountingSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    }
    else if (algoName == "flash-sort") 
    {
        clock_t tStart = clock();
        FlashSort(a, n, compareCount);
        clock_t tEnd = clock();
        runTime = double(tEnd - tStart)/double(CLOCKS_PER_SEC);
    }
    
    // Print out results as output Parameters
    cout << string(28,'-') << endl;
    if (outputParameters == "-both") {
        cout << "Running time : " << fixed << setprecision(5) << runTime << "s" << endl;
        cout << "Comparisons : " << compareCount << endl << endl;
    } else if (outputParameters == "-time") {
        cout << "Running time : " << fixed << setprecision(5) << runTime << "s" << endl;
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
}

//Cmd 2 [6] : [Execution file] -a [Algorithm] [Input size] [Input order] [Output parameter(s)]
//             a.exe            -a selection-sort 50        -rand         -time


int main(int argc, char* argv[]) {
    // Check argc and argv
    // cout << "argc : " << argc << endl;
    // for (int i = 0; i < argc; i++) {
    //     cout << argv[i] << "\n";
    // }

    string mode = argv[1];
    string algorithmName = argv[2];
    string argv3 = argv[3];

    // Check the argv[3] is number or file input path,
    // use for distinguishing Command 1 from Command 3
    bool checkArgv3 = (argv3.find_first_not_of("0123456789") == string::npos);
    
    // COMMAND 1
    if ((argc == 5) && (mode == "-a") && (checkArgv3 == false)) 
    {
        string outputParameter = argv[argc - 1];
        Command1(algorithmName, argv3, outputParameter);
    }
    // COMMAND 2
    else if ((argc == 6) && (mode == "-a")) 
    {
        cout << "cmd 2";
    }
    // COMMAND 3
    else if ((argc == 5) && (mode == "-a") && (checkArgv3 == true)) 
    {
        cout << "cmd 3";
    }
    // COMMAND 4
    else if ((argc == 5) && (mode == "-c")) 
    {
        cout << "cmd 4";
    }
    // COMMAND 5
    else if ((argc == 6) && (mode == "-c")) 
    {
        cout << "cmd 5";
    }

    return 0;
}
