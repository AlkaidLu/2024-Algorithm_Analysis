#include"closest_points.h"
#define NUM 6
// 计算两个点之间的欧几里得距离
double Dis(vector<Point>points){
    if(points.size()!=2){
        printf("There should be 2 points to be in the vector.");
    }
    return sqrt(pow(points[0].x-points[1].x,2)+pow(points[0].y-points[1].y,2));;
}



int Cycle(int num){
    int number[NUM]={10,100,1000,10000,50000,100000}; // 定义一个数组，存储不同规模的点的数量
    clock_t time[NUM][3];// 定义一个二维数组，存储不同算法在不同规模下的运行时间
    
     // 打开一个文件用于写入结果，如果文件打开失败，输出错误信息并退出程序
    FILE* file = fopen("results.txt", "a");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<NUM;i++){
        // 生成指定数量的随机点
        vector<Point>points=getRandomPoints(-1*number[i],number[i],-1*number[i],number[i],number[i]);
        
        // 暴力法
        /*
        clock_t start1 = std::clock();
        vector<Point>result1=MinDistance(points);
        clock_t end1 = std::clock();
        */

        //朴素分治法
        clock_t start2 = std::clock();
        vector<Point>result2=naiveDivideConquer(points,number[i]);
        clock_t end2 = std::clock();

        //预处理分治法
        clock_t start3 = std::clock();
        vector<Point>result3=preprocessedDivideConquer(points,number[i]);
        clock_t end3 = std::clock();

        // 计算每种算法的运行时间并存储在time数组中
        //time[i][0]=end1-start1;
        time[i][1]=end2-start2;
        time[i][2]=end3-start3;
      
        //// 计算三个结果的欧几里得距离
        //double dis1 = Dis(result1);
        double dis2 = Dis(result2);
        double dis3 = Dis(result3);

        //// 如果三个结果的距离相等，则输出成功信息
        /*
         if(dis1==dis2&&dis1==dis3){
            printf("Successul run!!!\n");
        }
        */
        // 将结果写入文件
        /*
        fprintf(file, "In cycle %d:\nThere are %d points, the closest point-pair is (%f,%f) and (%f,%f) with the distance of %f.\n "
            "Time of Brute Force is: %ld\n (%f,%f),(%f,%f) with the distance of %f.\n "
            "Time of naive Divide and Conquer is: %ld\n (%f,%f),(%f,%f) with the distance of %f.\n "
            "Time of preprocessed Divide and Conquer is: %ld\n (%f,%f),(%f,%f) with the distance of %f.\n",
            i, number[i],
            result1[0].x, result1[0].y, result1[1].x, result1[1].y, dis1,
            static_cast<long>(time[i][0]), result1[0].x, result1[0].y, result1[1].x, result1[1].y, dis1,
            static_cast<long>(time[i][1]), result2[0].x, result2[0].y, result2[1].x, result2[1].y, dis2,
            static_cast<long>(time[i][2]), result3[0].x, result3[0].y, result3[1].x, result3[1].y, dis3);
*/

        fprintf(file, "In cycle %d.%d:\nThere are %d points, the closest point-pair is (%f,%f) and (%f,%f) with the distance of %f.\n "
            "Time of naive Divide and Conquer is: %ld\n (%f,%f),(%f,%f) with the distance of %f.\n "
            "Time of preprocessed Divide and Conquer is: %ld\n (%f,%f),(%f,%f) with the distance of %f.\n",
            num+1, i+1, number[i],
            result2[0].x, result2[0].y, result2[1].x, result2[1].y, dis2,
            static_cast<long>(time[i][1]), result2[0].x, result2[0].y, result2[1].x, result2[1].y, dis2,
            static_cast<long>(time[i][2]), result3[0].x, result3[0].y, result3[1].x, result3[1].y, dis3);

            if (ferror(file)) {
                perror("Error writing to file");
                fclose(file);
                exit(EXIT_FAILURE);
            }
        
    }
    // 关闭文件
    fclose(file);
    return 0;
}

int main(){
    //运行15次
    for(int i=0;i<15;i++){
        Cycle(i);
        printf("%d:Successul run!!!\n",i);
    }
    return 0;
}