#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "algorithm.h"
#include <fstream>

using namespace std;

#define UP_BOUND 123456

double SumTimeInsert,SumTimeBubble,SumTimeMerge,SumTimeQuick,SumTimeShell;
long long CntCmpInsert,CntCmpBubble,CntCmpMerge,CntCmpQuick,CntCmpShell;
long long CntSwpInsert,CntSwpBubble,CntSwpMerge,CntSwpQuick,CntSwpShell;

double SumTimeMerge2,SumTimeQuick2,SumTimeShell2;
long long CntCmpMerge2,CntCmpQuick2,CntCmpShell2;
long long CntSwpMerge2,CntSwpQuick2,CntSwpShell2;
//Get the data of QuickSort,MergeSort and ShellSort curves
int main2(int MaxVectorSize, int NumRepeat)
{
    srand(time(NULL));
    ofstream outputFile("output2.txt");
    outputFile.close();

    for(int Scale = 10; Scale <= MaxVectorSize; Scale += 20)
    {
        for (int i = 0; i < NumRepeat; i++)
        {
            vector<int> vec(Scale);
            //InsertSort 
            for (int j = 0; j < Scale; j++)
                vec[j] = rand() % UP_BOUND;
            clock_t start_time, end_time;

            //QuickSort
            vector<int> vec3 = vec;
            start_time = clock();
            QuickSort(vec3, 0, vec3.size() - 1, CntCmpQuick2, CntSwpQuick2);
            end_time = clock();
            SumTimeQuick2 += (double)(end_time - start_time) / CLOCKS_PER_SEC;

            //MergeSort
            vector<int> vec4 = vec;
            start_time = clock();
            MergeSort(vec4, 0, vec4.size() - 1, CntCmpMerge2, CntSwpMerge2);
            end_time = clock();
            SumTimeMerge2 += (double)(end_time - start_time) / CLOCKS_PER_SEC;

            //ShellSort
            vector<int> vec5 = vec;
            start_time = clock();
            ShellSort(vec5, CntCmpShell2, CntSwpShell2);
            end_time = clock();
            SumTimeShell2 += (double)(end_time - start_time) / CLOCKS_PER_SEC;
        }

        printf("The performance of %d QuickSort is:\n",Scale);
        cout << "The average time is " << SumTimeQuick2 / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpQuick2 / NumRepeat << "." << endl;
        cout << "The number of swaps is " << CntSwpQuick2 / NumRepeat << "." << endl << endl;

        printf("The performance of %d MergeSort is:\n",Scale);
        cout << "The average time is " << SumTimeMerge2 / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpMerge2 / NumRepeat << "." << endl;
        cout << "The number of swaps is " << CntSwpMerge2 / NumRepeat << "." << endl << endl;

        printf("The performance of %d ShellSort is:\n",Scale);
        cout << "The average time is " << SumTimeShell2 / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpShell2 / NumRepeat << "." << endl; 
        cout << "The number of swaps is " << CntSwpShell2 / NumRepeat << "." << endl << endl;

        ofstream outputFile("output2.txt", ios::app);

        if (outputFile.is_open()) {
            outputFile << Scale << endl;
            outputFile << SumTimeQuick2 / NumRepeat << endl;
            outputFile << CntCmpQuick2 / NumRepeat << endl;
            outputFile << CntSwpQuick2 / NumRepeat << endl;
            outputFile << SumTimeMerge2 / NumRepeat << endl;
            outputFile << CntCmpMerge2 / NumRepeat << endl;
            outputFile << CntSwpMerge2 / NumRepeat << endl;
            outputFile << SumTimeShell2 / NumRepeat << endl;
            outputFile << CntCmpShell2 / NumRepeat << endl;
            outputFile << CntSwpShell2 / NumRepeat << endl;
            outputFile.close();
        } else {
            cout << "无法打开文件" << std::endl;
        }
    }
    return 0;
}

int main()
{
    int MaxVectorSize;
    int NumRepeat;
    cout << "Please enter the max size of the vector:";
    cin >> MaxVectorSize;
    cout << "Please enter the number of repeats:";
    cin >> NumRepeat;
    srand(time(NULL));
    ofstream outputFile("output.txt");
    outputFile.close();

    for(int Scale = 10; Scale <= MaxVectorSize; Scale += 20)
    {
        for (int i = 0; i < NumRepeat; i++)
        {
            vector<int> vec(Scale);
            //InsertSort 
            for (int j = 0; j < Scale; j++)
                vec[j] = rand() % UP_BOUND;
            clock_t start_time, end_time;
            vector<int> vec1 = vec;
            start_time = clock();
            InsertSort(vec1, CntCmpInsert, CntSwpInsert);
            end_time = clock();
            SumTimeInsert += (double)(end_time - start_time) / CLOCKS_PER_SEC;
            
            //BubbleSort
            vector<int> vec2 = vec;
            start_time = clock();
            BubbleSort(vec2, CntCmpBubble, CntSwpBubble);
            end_time = clock();
            SumTimeBubble += (double)(end_time - start_time) / CLOCKS_PER_SEC;

            //QuickSort
            vector<int> vec3 = vec;
            start_time = clock();
            QuickSort(vec3, 0, vec3.size() - 1, CntCmpQuick, CntSwpQuick);
            end_time = clock();
            SumTimeQuick += (double)(end_time - start_time) / CLOCKS_PER_SEC;

            //MergeSort
            vector<int> vec4 = vec;
            start_time = clock();
            MergeSort(vec4, 0, vec4.size() - 1, CntCmpMerge, CntSwpMerge);
            end_time = clock();
            SumTimeMerge += (double)(end_time - start_time) / CLOCKS_PER_SEC;

            //ShellSort
            vector<int> vec5 = vec;
            start_time = clock();
            ShellSort(vec5, CntCmpShell, CntSwpShell);
            end_time = clock();
            SumTimeShell += (double)(end_time - start_time) / CLOCKS_PER_SEC;
        }

        printf("The performance of %d InsertSort is:\n",Scale);
        cout << "The average time is " << SumTimeInsert / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpInsert / NumRepeat << "." << endl;
        cout << "The number of swaps is " << CntSwpInsert / NumRepeat << "." << endl << endl;

        printf("The performance of %d BubbleSort is:\n",Scale);
        cout << "The average time is " << SumTimeBubble / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpBubble / NumRepeat << "." << endl;
        cout << "The number of swaps is " << CntSwpBubble / NumRepeat << "." << endl << endl;

        printf("The performance of %d QuickSort is:\n",Scale);
        cout << "The average time is " << SumTimeQuick / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpQuick / NumRepeat << "." << endl;
        cout << "The number of swaps is " << CntSwpQuick / NumRepeat << "." << endl << endl;

        printf("The performance of %d MergeSort is:\n",Scale);
        cout << "The average time is " << SumTimeMerge / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpMerge / NumRepeat << "." << endl;
        cout << "The number of swaps is " << CntSwpMerge / NumRepeat << "." << endl << endl;

        printf("The performance of %d ShellSort is:\n",Scale);
        cout << "The average time is " << SumTimeShell / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpShell / NumRepeat << "." << endl; 
        cout << "The number of swaps is " << CntSwpShell / NumRepeat << "." << endl << endl;

        ofstream outputFile("output.txt", ios::app);

        if (outputFile.is_open()) {
            outputFile << Scale << endl;
            outputFile << SumTimeInsert / NumRepeat << endl;
            outputFile << CntCmpInsert / NumRepeat << endl;
            outputFile << CntSwpInsert / NumRepeat << endl;
            outputFile << SumTimeBubble / NumRepeat << endl;
            outputFile << CntCmpBubble / NumRepeat << endl;
            outputFile << CntSwpBubble / NumRepeat << endl;
            outputFile << SumTimeQuick / NumRepeat << endl;
            outputFile << CntCmpQuick / NumRepeat << endl;
            outputFile << CntSwpQuick / NumRepeat << endl;
            outputFile << SumTimeMerge / NumRepeat << endl;
            outputFile << CntCmpMerge / NumRepeat << endl;
            outputFile << CntSwpMerge / NumRepeat << endl;
            outputFile << SumTimeShell / NumRepeat << endl;
            outputFile << CntCmpShell / NumRepeat << endl;
            outputFile << CntSwpShell / NumRepeat << endl;
            outputFile.close();
        } else {
            cout << "无法打开文件" << std::endl;
        }
    }
    main2(MaxVectorSize, NumRepeat);
    return 0;
}
