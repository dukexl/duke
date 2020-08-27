#include <stdio.h>
#include <signal.h>
#include <execinfo.h>
#include <stdlib.h>

/*
1）官方说法是：
SIGSEGV --- Segment Fault. The possible cases of your encountering this error are:
1.buffer overflow --- usually caused by a pointer reference out of range.
2.stack overflow --- please keep in mind that the default stack size is 8192K.
3.illegal file access --- file operations are forbidden on our judge system.

2）SIGBUS与SIGSEGV信号的一般区别如下:
1) SIGBUS(Bus error)意味着指针所对应的地址是有效地址，但总线不能正常使用该指针。通常是未对齐的数据访问所致。
2) SIGSEGV(Segment fault)意味着指针所对应的地址是无效地址，没有物理内存对应该地址。

SIGFPE是当一个进程执行了一个错误的算术操作时发送给它的信号
*/
int test_flag = 1;  // 1 means SIGSEGV, 2 means SIGFPE

namespace detail
{
	void c_do_nothing(float f, int c)
	{
		printf("This is c_do_nothing : %f, %d\n", f, c);
		if (test_flag == 1)
		{
			char *p = reinterpret_cast<char*>(c);
			*p = 'C';     // 段错误
		}
		else if (test_flag == 2)
		{
			c = int(f) / c; // 浮点数例外
		}
		printf("result = %d\n", c);
	}
}


void bTwo(int b, const char *str)
{
	printf("This is bTwo : %d  %s\n", b, str);
	detail::c_do_nothing(b * 1.2, 0);
}

void aTest(int a)
{
	printf("This is aTest : %d\n", a);
	bTwo(a + 1, "hello world");
}

void debugBacktrace(int sig)
{
	const static int array_size = 100;
	void *array[array_size];
	char **strings;

	if (sig == SIGSEGV)
		fprintf(stderr, "\n###### 段错误 ######\n");
	else if (sig == SIGFPE)
		fprintf(stderr, "\n###### 浮点数例外 ######\n");
	else
		fprintf(stderr, "\n###### 其他错误 ######\n");

	int size = backtrace(array, array_size);
	fprintf(stderr, "Backtrace (deep : %d):\n", size);
	strings = backtrace_symbols(array, size);
	for (int i = 0; i < size; ++i)
	{
		fprintf(stderr, "%d: %s\n", i, strings[i]);
	}
	free(strings);
	exit(-1);
}

int main()
{
	// catch 段错误
	signal(SIGSEGV, debugBacktrace);
	// catch 浮点数例外 
	signal(SIGFPE, debugBacktrace);

	aTest(1);

	return 0;
}

/*********************************************************
This is aTest : 1
This is bTwo : 2  hello world
This is c_do_nothing : 2.400000, 0

###### 段错误 ######
Backtrace (deep : 6):
0: ./MyBacktrace(_Z14debugBacktracei+0x47) [0x400af7]
1: /lib64/libc.so.6(+0x363b0) [0x7ff79e79a3b0]
2: ./MyBacktrace(_ZN6detail12c_do_nothingEfi+0x6b) [0x400bfb]
3: ./MyBacktrace(main+0x2c) [0x4009bc]
4: /lib64/libc.so.6(__libc_start_main+0xf5) [0x7ff79e786505]
5: ./MyBacktrace() [0x4009ec]

说明：
1.当出发sigsegv时，程序正常流程被打断，信号处理函数debugBacktrace被调用，对应到结果输出中的标号0，1两行；
2.每行调用栈输出中的最后[]表示被调用函数的返回地址
3.从输出中可以看出最后一次的正常函数调用是[0x400c39], 可以进行反汇编：
	objdump -D backtrace_test > backtrace_test.dis
	然后就可以从汇编文件中找到相应函数地址了；
4.另外，也可以通过c++filt命令即可解析出原函数名，比如c++filt  _Z14debugBacktracei或者 c++filt _ZN6detail12c_do_nothingEfi；
********************************************************/