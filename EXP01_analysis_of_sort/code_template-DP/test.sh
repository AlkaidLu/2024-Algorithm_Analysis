#!/bin/bash

# 测试脚本，下述内容仅为示例
# 使用前先增加执行权限: sudo chmod +x test.sh

echo "test srart"

./data_gen 1000 100 100
./main test_1000_100_100.data
./analyser test_1000_100_100.data
echo "--------------------------------------------"

./data_gen 1000 500 500
./main test_1000_500_500.data
./analyser test_1000_500_500.data
echo "--------------------------------------------"

echo "test end"




