2017�궬�죨2017.11-2018.2�������2���꣬Ȼ�������ڼҵ��߰�������źͺ���ȴ���������������¶�ʮ�ſ�ʼ��������Һ���죬���Ӵ���һ����Һ4�Σ�ֱ���������ߡ�����

vi 1.py +43
gg
5 G 
>> .




��������
SRC_FILE=$(wildcard *.c)   
func_point:$(SRC_FILE)   
	gcc $^ -o $@   
clean:   
	@echo "clean project"   
	-rm *.o   
	@echo "clean complete"   
.PHONY:clean  


����һ��
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




//��дһ��Linux C�������������д���һ���ӽ��̣��ӽ�������ѭ�������Hello world���ַ�����
//����������10s�����ӽ��̷����źŽ����ӽ��̣�����������˳�
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
            //������ֹ�ź�
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



until �˳���ǰѭ����
bt: ��ӡ������ջ�Ļ���
bt ��ӡn��֡�Ļ���
frame : �л���ָ����֡������ӡ��֡
up : ����'n'��֡
down : ����'n'��֡ ( nĬ����1)
 jump 5 ��ת�������У� ���tbreajk 5;
 watch i != 10 �������ϵ�
(gdb) print *a@10  *���a��һ�����飬10��Ԫ�أ����Ҫ��ʾ�� 

(gdb) start                         //��ʼ����
(gdb) n                             //һ��һ��ִ��
(gdb) step/s                        //ִ����һ��������������뺯��
(gdb) backtrace/bt                  //�鿴��������ջ֡
(gdb) info/i locals                 //�鿴��ǰջ֡�ֲ�����
(gdb) frame/f                       //ѡ��ջ֡���ٲ鿴�ֲ�����
(gdb) print/p                       //��ӡ������ֵ
(gdb) finish                        //���е���ǰ��������
(gdb) set var sum=0                 //�޸ı���ֵ
(gdb) list/l �кŻ�����             //�г�Դ��
(gdb) display/undisplay sum         //ÿ��ͣ����ʾ������ֵ/ȡ������
(gdb) break/b  �кŻ�����           //���öϵ�
(gdb) continue/c                    //��������
(gdb) info/i breakpoints            //�鿴�Ѿ����õĶϵ�
(gdb) delete breakpoints 2          //ɾ��ĳ���ϵ�
(gdb) disable/enable breakpoints 3  //����/����ĳ���ϵ�
(gdb) break 9 if sum != 0           //���������ż���ϵ�
(gdb) run/r                         //���´ӳ���ͷ����ִ��
(gdb) watch input[4]                //���ù۲��
(gdb) info/i watchpoints            //�鿴���õĹ۲��
(gdb) x/7b input                    //��ӡ�洢�����ݣ�b--ÿ���ֽ�һ�飬7--7��
(gdb) disassemble                   //����൱ǰ������ָ������
(gdb) si                            // һ��ָ��һ��ָ����� �� s ��һ��һ�д���
(gdb) info registers                // ��ʾ���мĴ����ĵ�ǰֵ
(gdb) x/20 $esp                    //�鿴�ڴ��п�ʼ��20����




//����ѽ��е���
void adjustHeap(int param1, int j, int inNums[])
{
    int temp=inNums[param1];
    for (int k=param1*2+1;k<j;k=k*2+1)
    {
        //����ұ�ֵ�������ֵ��ָ���ұ�
        if (k+1<j && inNums[k]< inNums[k+1])
        {
            k++;
        }
        //����ӽڵ���ڸ��ڵ㣬���ӽڵ�ֵ�������ڵ�,�����µ��ӽڵ���Ϊ���ڵ㣨���ý��н�����
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
//��������Ҫ�㷨
void HeapSort(int nums,int inNums[])
{
    //1.�����󶥶�
    for (int i=nums/2-1;i>=0;i--)
    {
                //put the value in the final position
        adjustHeap(i,nums,inNums);
    }
    //2.�����ѽṹ+�����Ѷ�Ԫ����ĩβԪ��
    for (int j=nums-1;j>0;j--)
    {
                //�Ѷ�Ԫ�غ�ĩβԪ�ؽ��н���
        int temp=inNums[0];
        inNums[0]=inNums[j];
        inNums[j]=temp;
 
        adjustHeap(0,j,inNums);//���¶Զѽ��е���
    }
}
int main() {
    int data[] = {6,5,8,4,7,9,1,3,2};
    int len = sizeof(data) / sizeof(int);
    HeapSort(len,data);
    return 0;
}