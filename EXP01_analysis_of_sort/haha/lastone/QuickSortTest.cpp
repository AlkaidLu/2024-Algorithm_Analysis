#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <string>
#include <cstring>
#include "QuickSortAlgorithm.cpp"
#include <fstream>

using namespace std;

#define UP_BOUND 123456

long long CntCmpQuick,CntCmpQuickRand,CntCmpQuickThree,CntCmpQuickKongXue,CntCmpQuickHoare,CntCmpQuickLomuto;
long long CntSwpQuick,CntSwpQuickRand,CntSwpQuickThree,CntSwpQuickKongXue,CntSwpQuickHoare,CntSwpQuickLomuto;
double SumTimeQuick,SumTimeQuickRand,SumTimeQuickThree,SumTimeQuickKongXue,SumTimeQuickHoare,SumTimeQuickLomuto;
int main()
{
    int MaxVectorSize;
    int NumRepeat;
    cout << "Please enter the max size of the vector:";
    cin >> MaxVectorSize;
    cout << "Please enter the number of repeats:";
    cin >> NumRepeat;
    srand(time(NULL));
    ofstream outputFile("outputQuick.txt");
    outputFile.close();

    for(int Scale = 10; Scale <= MaxVectorSize; Scale += 20)
    {
        for (int i = 0; i < NumRepeat; i++)
        {
            vector<int> vec(Scale); 
            for (int j = 0; j < Scale; j++)
                vec[j] = rand() % UP_BOUND;
            clock_t start_time, end_time;

            //QuickSort,the last element is the pivot
            vector<int> vec_quick = vec;
            start_time = clock();
            QuickSort(vec_quick, 0, vec_quick.size() - 1, CntCmpQuick, CntSwpQuick);
            end_time = clock();
            SumTimeQuick += (double)(end_time - start_time) / CLOCKS_PER_SEC;

            //QuickSortRand, rand element is the pivot
            vector<int> vec_quickRand = vec;
            start_time = clock();
            QuickSortRand(vec_quickRand, 0, vec_quickRand.size() - 1, CntCmpQuickRand, CntSwpQuickRand);
            end_time = clock();
            SumTimeQuickRand += (double)(end_time - start_time) / CLOCKS_PER_SEC;

            //QuickSortThree, the midnum of the last three element is the pivot
            vector<int> vec_quickThree = vec;
            start_time = clock();
            QuickSortThree(vec_quickThree, 0, vec_quickThree.size() - 1, CntCmpQuickThree, CntSwpQuickThree);
            end_time = clock();
            SumTimeQuickThree += (double)(end_time - start_time) / CLOCKS_PER_SEC;

            //QuickSortKongXue and the first element is the pivot
            vector<int> vec_quickKongXue = vec;
            start_time = clock();
            QuickSortKongXue(vec_quickKongXue, 0, vec_quickKongXue.size() - 1, CntCmpQuickKongXue, CntSwpQuickKongXue);
            end_time = clock();
            SumTimeQuickKongXue += (double)(end_time - start_time) / CLOCKS_PER_SEC;

            //QuickSortHoare and the first element is the pivot
            vector<int> vec_quickHoare = vec;
            start_time = clock();
            QuickSortHoare(vec_quickHoare, 0, vec_quickHoare.size() - 1, CntCmpQuickHoare, CntSwpQuickHoare);
            end_time = clock();
            SumTimeQuickHoare += (double)(end_time - start_time) / CLOCKS_PER_SEC;

            //QuickSortLomuto and the first element is the pivot
            vector<int> vec_quickLomuto = vec;
            start_time = clock();
            QuickSortLomuto(vec_quickLomuto, 0, vec_quickLomuto.size() - 1, CntCmpQuickLomuto, CntSwpQuickLomuto);
            end_time = clock();
            SumTimeQuickLomuto += (double)(end_time - start_time) / CLOCKS_PER_SEC;
        }

        printf("The performance of %d QuickSort is:\n",Scale);
        cout << "The average time is " << SumTimeQuick / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpQuick / NumRepeat << "." << endl;
        cout << "The number of swaps is " << CntSwpQuick / NumRepeat << "." << endl << endl;

        printf("The preformance of %d QuickSortRand is:\n",Scale);
        cout << "The average time is " << SumTimeQuickRand / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpQuickRand / NumRepeat << "." << endl;

        printf("The performance of %d QuickSortThree is:\n",Scale);
        cout << "The average time is " << SumTimeQuickThree / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpQuickThree / NumRepeat << "." << endl;
        cout << "The number of swaps is " << CntSwpQuickThree / NumRepeat << "." << endl << endl;

        printf("The performance of %d QuickSortKongXue is:\n",Scale);
        cout << "The average time is " << SumTimeQuickKongXue / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpQuickKongXue / NumRepeat << "." << endl;
        cout << "The number of swaps is " << CntSwpQuickKongXue / NumRepeat << "." << endl << endl;

        printf("The performance of %d QuickSortHoare is:\n",Scale);
        cout << "The average time is " << SumTimeQuickHoare / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpQuickHoare / NumRepeat << "." << endl;
        cout << "The number of swaps is " << CntSwpQuickHoare / NumRepeat << "." << endl << endl;

        printf("The performance of %d QuickSortLomuto is:\n",Scale);
        cout << "The average time is " << SumTimeQuickLomuto / NumRepeat << " s." << endl;
        cout << "The number of comparisons is " << CntCmpQuickLomuto / NumRepeat << "." << endl;

        ofstream outputFile("outputQuick.txt", ios::app);

        if (outputFile.is_open()) {
            outputFile << Scale << endl;
            outputFile << SumTimeQuick / NumRepeat << endl;
            outputFile << CntCmpQuick / NumRepeat << endl;
            outputFile << CntSwpQuick / NumRepeat << endl;

            outputFile << SumTimeQuickRand / NumRepeat << endl;
            outputFile << CntCmpQuickRand / NumRepeat << endl;
            outputFile << CntSwpQuickRand / NumRepeat << endl;

            outputFile << SumTimeQuickThree / NumRepeat << endl;
            outputFile << CntCmpQuickThree / NumRepeat << endl;
            outputFile << CntSwpQuickThree / NumRepeat << endl;

            outputFile << SumTimeQuickKongXue / NumRepeat << endl;
            outputFile << CntCmpQuickKongXue / NumRepeat << endl;
            outputFile << CntSwpQuickKongXue / NumRepeat << endl;

            outputFile << SumTimeQuickHoare / NumRepeat << endl;
            outputFile << CntCmpQuickHoare / NumRepeat << endl;
            outputFile << CntSwpQuickHoare / NumRepeat << endl;

            outputFile << SumTimeQuickLomuto / NumRepeat << endl;
            outputFile << CntCmpQuickLomuto / NumRepeat << endl;
            outputFile << CntSwpQuickLomuto / NumRepeat << endl;
            outputFile.close();
        } else {
            cout << "无法打开文件" << std::endl;
        }
    }
    return 0;
}
