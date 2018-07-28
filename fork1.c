2017年冬天（2017.11-2018.2），凌睿2周岁，然而春节在家的七八天里，老婆和孩子却接连生病，从腊月二十九开始，妈妈输液两天，孩子打针一次输液4次，直至初五我走。。。

vi 1.py +43
gg
5 G 
>> .




方法二：
SRC_FILE=$(wildcard *.c)   
func_point:$(SRC_FILE)   
	gcc $^ -o $@   
clean:   
	@echo "clean project"   
	-rm *.o   
	@echo "clean complete"   
.PHONY:clean  


方法一：
src=$(wildcard *.c) #wildcard *.c ./sub/*.c
srcNoDir=$(notdir $(src))
obj=$(patsubst %.c,%.o,$(srcNoDir) )

all:func_point

%.o:%.c
	gcc -c $^

func_point:$(obj)
	gcc $(obj) -o func_point

clean :
	-rm -rf $(obj)
	-rm -f *.[nes]
	-rm -f *.dx
.PHONY : default clean




//编写一个Linux C程序，在主进程中创建一个子进程，子进程中死循环输出“Hello world”字符串，
//主进程休眠10s后，向子进程发送信号结束子进程，随后主进程退出
#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
void main(){
    pid_t pid;
    printf("program is starting\n");
    pid=fork();

    switch(pid){
        case -1:
            exit(0);
            break;

        case 0:
            while(1){
                sleep(1);
                printf("hello world\n");
            }
            break;

        default:
            sleep(10);
            //发出终止信号
            kill(pid,SIGTERM);
            break;
    }
}


where
b b line; b func; b file:N
info b; info b n;
r
c
n
step finish
list ;list func; list file:N
p print; print /x var;print *a@10
ptype var



until 退出当前循环体
bt: 打印整个堆栈的回溯
bt 打印n个帧的回溯
frame : 切换到指定的帧，并打印该帧
up : 上移'n'个帧
down : 下移'n'个帧 ( n默认是1)
 jump 5 跳转到第五行， 配合tbreajk 5;
 watch i != 10 ；条件断电
(gdb) print *a@10  *如果a是一个数组，10个元素，如果要显示则： 

(gdb) start                         //开始调试
(gdb) n                             //一条一条执行
(gdb) step/s                        //执行下一条，如果函数进入函数
(gdb) backtrace/bt                  //查看函数调用栈帧
(gdb) info/i locals                 //查看当前栈帧局部变量
(gdb) frame/f                       //选择栈帧，再查看局部变量
(gdb) print/p                       //打印变量的值
(gdb) finish                        //运行到当前函数返回
(gdb) set var sum=0                 //修改变量值
(gdb) list/l 行号或函数名             //列出源码
(gdb) display/undisplay sum         //每次停下显示变量的值/取消跟踪
(gdb) break/b  行号或函数名           //设置断点
(gdb) continue/c                    //连续运行
(gdb) info/i breakpoints            //查看已经设置的断点
(gdb) delete breakpoints 2          //删除某个断点
(gdb) disable/enable breakpoints 3  //禁用/启用某个断点
(gdb) break 9 if sum != 0           //满足条件才激活断点
(gdb) run/r                         //重新从程序开头连续执行
(gdb) watch input[4]                //设置观察点
(gdb) info/i watchpoints            //查看设置的观察点
(gdb) x/7b input                    //打印存储器内容，b--每个字节一组，7--7组
(gdb) disassemble                   //反汇编当前函数或指定函数
(gdb) si                            // 一条指令一条指令调试 而 s 是一行一行代码
(gdb) info registers                // 显示所有寄存器的当前值
(gdb) x/20 $esp                    //查看内存中开始的20个数




//大根堆进行调整
void adjustHeap(int param1, int j, int inNums[])
{
    int temp=inNums[param1];
    for (int k=param1*2+1;k<j;k=k*2+1)
    {
        //如果右边值大于左边值，指向右边
        if (k+1<j && inNums[k]< inNums[k+1])
        {
            k++;
        }
        //如果子节点大于父节点，将子节点值赋给父节点,并以新的子节点作为父节点（不用进行交换）
        if (inNums[k]>temp)
        {
            inNums[param1]=inNums[k];
            param1=k;
        }
        else
            break;
    }
        //put the value in the final position
    inNums[param1]=temp;
}
//堆排序主要算法
void HeapSort(int nums,int inNums[])
{
    //1.构建大顶堆
    for (int i=nums/2-1;i>=0;i--)
    {
                //put the value in the final position
        adjustHeap(i,nums,inNums);
    }
    //2.调整堆结构+交换堆顶元素与末尾元素
    for (int j=nums-1;j>0;j--)
    {
                //堆顶元素和末尾元素进行交换
        int temp=inNums[0];
        inNums[0]=inNums[j];
        inNums[j]=temp;
 
        adjustHeap(0,j,inNums);//重新对堆进行调整
    }
}
int main() {
    int data[] = {6,5,8,4,7,9,1,3,2};
    int len = sizeof(data) / sizeof(int);
    HeapSort(len,data);
    return 0;
}