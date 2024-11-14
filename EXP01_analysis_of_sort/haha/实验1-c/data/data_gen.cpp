#include<bits/stdc++.h>
using namespace std;

#define UP_BOUND 123456

/**
 * @brief 产生随机样本
 * 
 */
int main()
{
    
    //long long size_list[15] = {1000,2000,3000,4000,5000,6000,7000,8000,9000,10000};
    long long size_list[15] = {100000000};
    long long vector_size;
    int num_repeat = 20;
    for(int i=0;i<10;i++)
    {
        vector_size=size_list[i];
        string filename="data_"+to_string(vector_size)+".txt";
        const char*p=filename.data();
        FILE* fd=fopen(p,"w");
        for(int j=0;j<num_repeat;j++)
        {
            for(int k=0;k<vector_size;k++)
                fprintf(fd,"%d \t",rand()%UP_BOUND);
            fprintf(fd,"\n");
        }
        fclose(fd);
    }
	return 0;
	
}
