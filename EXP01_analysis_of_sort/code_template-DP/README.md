DEMO
===========================

##环境依赖
gcc 

##目录结构描述
├── README.md                   // help \
├── main.cpp                    // 主文件 \
├── algorithm.h                 // 算法声明头文件 \
├── algorithm.cpp               // 算法实现 \
├── data_gen.cpp                // 测试集数据生成 \
├── analyser.cpp                // 插桩代码测试 \
├── test.h                      // 测试函数声明头文件 \
├── test.cpp                    // 测试函数实现 \
├── test.sh                     // 辅助测试的bash脚本 \
├── Makefile                    // 编译规则

##测试步骤
1. 编译

2. 生成测试集

3. 测试、插桩测试

(可通过简单的bash脚本进行批量生成数据集和批量测试)

##V1.0 版本内容更新
1. 创建文件与基础实现