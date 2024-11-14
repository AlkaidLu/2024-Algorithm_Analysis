# Usage

_需要在 Linux 环境下运行。_

```bash
cd /path/to/this/folder
make
python script.py
```

---

运行`make`后，输出应当为

```bash
>make
g++ -O3 -o main.o main.cpp Test.cpp algorithm.cpp
```

并且，工作目录下会多出一个`mian.o`文件。

---

运行`python script.py`后，输出将会类似于：

```
>python script.py
...
Running InsertSort with size 10...
InsertSort with size 10 completed.
Running BubbleSort with size 10...
BubbleSort with size 10 completed.
Running MergeSort with size 10...
MergeSort with size 10 completed.
Running QuickSort with size 10...
QuickSort with size 10 completed.
Running ShellSort with size 10...
ShellSort with size 10 completed.
Running BlockQuickSort with size 10...
BlockQuickSort with size 10 completed.
Running DualPivotQuickSort with size 10...
DualPivotQuickSort with size 10 completed.
...
```

---

根据电脑性能差距，Python 脚本的整个运行过程需要 1~2 小时。如果你觉得这太久了，请修改`script.py`中的第`74`行，将`"--repeat=10"`改为`"--repeat=1"`。这样，运行时间会控制在 6~12 分钟。

此外，你可以单独运行`main.o`来测试某种算法。下面是`main.o`的帮助信息：

```bash
>./main.o
usage: ./main <FUNCTION> [OPTION]
DESCRIPTION:
FUNCTION:
    --function=FUNC
        MUST be given. if not, turn to --help
        choose function FUNC to sort the vector
        FUNC list: InsertSort, BubbleSort, MergeSort, QuickSort, ShellSort, BlockQuickSort, DualPivotQuickSort,
        OptimizedQuickSort, LogQuickSort
        (LogQuickSort is the same with QuickSort but it will print branch predictions and recursion depth instead of
        comparsions and moves)
OPTION:
    -h, --help
        print this help info and quit
    -t, --test
        run the function Test() to check the FUNC
        this parameter will disable --size and --repeat
    --size=N
        to determine vector_size in main
        the default value is 10000 if not specially given
    --repeat=N
        to determine num_repeat in main
        the default value is 100 if not specially given
```

下面是运行示例：

```
>./main.o --function=QuickSort --size=100000 --repeat=10
The average time is 0.0052576 s.
Comparisons: 2029938, Moves: 3260251
>./main.o --function=QuickSort -t
The code is correct.
```

很遗憾的是，本程序不支持自动补全，所以需要准确输入算法的名称，推荐先打印帮助信息，然后复制粘贴（查看上面的帮助信息，在 FUNC list 中的就是所有可使用的排序算法的名称）。
