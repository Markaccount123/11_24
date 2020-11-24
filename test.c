#define _CRE_SECURE_NO_WARNINGS 1 
#include<stdio.h>
//int main()
//{
//	//数组名是首元素的地址
//
//	//除了这两种情况以外其余的数组名都代表首元素地址
//	//1.sizeof(数组名) -- 数组名表示整个数组
//	//2.&数组名--数组名表示整个数组
//
//
//	//一维数组
//	int a[] = { 1, 2, 3, 4 };
//	printf("%d\n", sizeof(a));//计算的数组的总大小，单位是字节 16
//	printf("%d\n", sizeof(a + 0));//数组名表示首元素地址，a+0还是首元素地址，地址（指针）的大小在32位平台是4，在64位平台是8
//	printf("%d\n", sizeof(*a));//4 -- 数组名表示首元素地址，*a得到了首元素，类型为int，所以sizeof(*a)就是4
//	printf("%d\n", sizeof(a + 1));//4/8 数组名表示首元素的值，a+1第2个元素的地址，地址的大小就是4/8
//	printf("%d\n", sizeof(a[1]));//4 第二个元素的大小，每个元素是int类型的
//	printf("%d\n", sizeof(&a));//4  取出的是数组的地址，是数组的地址也是指针，所以占4/8个字节
//	printf("%d\n", sizeof(*&a));//16  可以理解为&和*相互抵消了，就剩下sizeof(a)了
//	printf("%d\n", sizeof(&a + 1));//4/8 &a拿到了整个数组，+1跳过了整个数组，但是他依旧是一个指针
//	printf("%d\n", sizeof(&a[0]));//  4/8 取出第一个元素的地址
//	printf("%d\n", sizeof(&a[0] + 1)); //  4/8 取出第二个元素的地址
//	return 0;
//}


//int main()
//{
//	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
//	printf("%d\n", sizeof(arr)); //6  sizeof计算的是数组的大小，每个元素的类型是char占一个字节
//	printf("%d\n", sizeof(arr + 0)); //  4/8 arr表示首元素的地址，+0还是首元素的地址，地址的大小是4个或者8个字节 
//	printf("%d\n", sizeof(*arr)); // 1  arr是首元素地址，然后*就得到了第一个首元素，其类型为char，所占的大小是1个字节
//	printf("%d\n", sizeof(arr[1])); // 1  第二个元素的大小
//	printf("%d\n", sizeof(&arr)); // 4/8 &arr拿到的是整个数组的地址
//	printf("%d\n", sizeof(&arr + 1)); // 4/8  &arr是整个数组的地址，+1跳过了整个数组，但他依旧是地址
//	printf("%d\n", sizeof(&arr[0] + 1));// 4/8 第二个元素的地址
//	//strlen就是要找'\0'他才会罢休
//	printf("%d\n", strlen(arr));// 是一个随机值  因为在里面找不到'\0' ，你也不知道哪个时候找到'\0'
//	printf("%d\n", strlen(arr + 0));//随机值
//	printf("%d\n", strlen(*arr));// 这里比较容易搞错   arr是首元素的地址，*得到了首元素'a'，然而'a'的ASCII值为97,strlen需要的是一个地址，
//	//你给我传了一个97,他是不明白什么意思的，所以程序会崩溃
//	printf("%d\n", strlen(arr[1])); //相当于传了一个'b'过去 --- ASCII值为98，所以这里也会报错
//	printf("%d\n", strlen(&arr));//  随机值
//	printf("%d\n", strlen(&arr + 1)); // 随机值 但是他和上面的那个随机值相差的大小应该至少是6个字符的长度
//	printf("%d\n", strlen(&arr[0] + 1));//随机值
//	return 0;
//}

//int main()
//{
//	char arr[] = "abcdef"; //  a b c d e f \0  
//	printf("%d\n", sizeof(arr)); //7  所占空间的大小
//	printf("%d\n", sizeof(arr + 0));// 4/8  arr是首元素的地址，+0还是首元素地址，地址即指针所占的空间大小根据平台来看
//	printf("%d\n", sizeof(*arr));//1  arr是首元素地址，*得到了首元素
//	printf("%d\n", sizeof(arr[1])); //1  计算的是第二个元素的大小
//	printf("%d\n", sizeof(&arr)); //   4/8   取到的是整个数组的地址
//	printf("%d\n", sizeof(&arr + 1)); // 4/8  &arr是数组的地址，+1跳过整个数组，但是他依旧是地址
//	printf("%d\n", sizeof(&arr[0] + 1));// 4/8 第二个元素的地址
//
//
//	printf("%d\n", strlen(arr));//6  对于strlen来说，就是要找到'\0'，并且'\0'并不算入他的大小内
//	printf("%d\n", strlen(arr + 0)); //6  首元素地址+0，依旧是首元素地址
//	printf("%d\n", strlen(*arr));//报错误  我需要接收的是一个地址，但是你给我传了一个'a'其对应的ASCII码值为97，就会访问97的地址，属于非法访问地址
//	printf("%d\n", strlen(arr[1])); // 报错误  和上面一样'b'
//	printf("%d\n", strlen(&arr));// 6 &arr得到了整个数组的地址，但是依旧从a的地址处开始，所以是6 
//	//但是这里会有警告  因为&arr得到的是数组的地址，应该存放在数组指针里面   strlen 的类型是const char*   char(*p)[7] = &arr;类型不同
//	printf("%d\n", strlen(&arr + 1));//随机值
//	printf("%d\n", strlen(&arr[0] + 1));//5
//	return 0;
//}

//int main()
//{
//	char *p = "abcdef";  //这是一个常量字符串，只是把首字符的地址放在了指针p内
//	printf("%d\n", sizeof(p));//  4/8   计算指针变量p的大小
//	printf("%d\n", sizeof(p + 1));//  指向了字符b的地址，但是依旧是一个指针
//	printf("%d\n", sizeof(*p));// 1  得到了第一个字符
//	printf("%d\n", sizeof(p[0]));// 1   这里不太好理解  p[0] == *(p+0)
//	printf("%d\n", sizeof(&p)); //  4/8  取到的是p的地址，相当于一个二级指针，依旧是指针
//	printf("%d\n", sizeof(&p + 1)); // 4/8
//	printf("%d\n", sizeof(&p[0] + 1));// 4/8  &p[0]得到了p的地址，+1得到了字符b的地址，是指针
//
//
//	printf("%d\n", strlen(p)); //6 p的地址相当于a的地址
//	printf("%d\n", strlen(p + 1));// 5 传过来的相当于字符b的地址
//	printf("%d\n", strlen(*p));// 报错 传过来了一个'b'
//	printf("%d\n", strlen(p[0]));// 报错
//	printf("%d\n", strlen(&p));// 随机值  什么时候遇见'\0'我是不知道的 
//	printf("%d\n", strlen(&p + 1));// 随机值
//	printf("%d\n", strlen(&p[0] + 1));//5 
//
//}

//
//int main()
//{
//	int a[3][4] = { 0 }; 
//	printf("%d\n", sizeof(a)); // 48
//	printf("%d\n", sizeof(a[0][0])); // 4
//	printf("%d\n", sizeof(a[0]));//16   a[0]是第一行的数组名，把它放在sizeof（）里面，表示求第一行数组的大小
//	printf("%d\n", sizeof(a[0] + 1));//答案应该是4  a[0]并没有单独放在sizeof内部，表示第一行第一个元素的地址，a[0]+1
//	//所以他表示第一行中第二个元素的地址
//	printf("%d\n", sizeof(*(a[0] + 1)));//4
//	printf("%d\n", sizeof(a + 1));// 4/8  指向的是第二行的指针
//	printf("%d\n", sizeof(*(a + 1)));//16
//	printf("%d\n", sizeof(&a[0] + 1)); //4 第二行的地址
//	printf("%d\n", sizeof(*(&a[0] + 1)));// 16
//	printf("%d\n", sizeof(*a));//16
//	printf("%d\n", sizeof(a[3]));//16 什么意思？不是最多是a[2]吗？ 你可能会认为你这报错了，但是对于sizeof来说并不在乎你里面的[]写多少
//	//所以对于他只是看一下，并不会验证他是否真的存在，相当于这里放了一个a[0]，只看类型，不进行访问
//}

//1
//int main() 
//{ 
//	int a[5] = { 1, 2, 3, 4, 5 }; 
//	int *ptr = (int *)(&a + 1);  
//	printf("%d,%d", *(a + 1), *(ptr - 1)); //  2   5
//	return 0; 
//	//程序的结果是什么
//} 


//2
//由于还没学习结构体，这里告知结构体的大小是20个字节 
//struct Test 
//{    
//	int Num;   
//	char *pcName;   
//	short sDate;    
//	char cha[2];    
//	short sBa[4];
//}*p; 
////假设p 的值为0x100000。 如下表表达式的值分别为多少？
//int main() 
//{   
//	p = (struct Test*)0x100000;
//	printf("%p\n", p + 0x1);  //p是一个结构体指针+1就会跳过整个结构体的大小，%p打印的是地址所以需要把每一位都打印上
//	//  0x100000 + 20  =   0x100014                   结果为0x00100014
//	printf("%p\n", (unsigned long)p + 0x1);  //把p强制类型转为无符号的整形相当于1048576+1=10485767 然后在给他转为16进制 
//	// 0x100001    所以结果为0x00100001
//	printf("%p\n", (unsigned int*)p + 0x1);  //跳过一个无符号的整形 也就是+4    结果为0x00100004
//	return 0;
//}

//3
//int main() 
//{ 
//	int a[4] = { 1, 2, 3, 4 }; // 01 00 00 00  02 00 00 00  03 00 00 00 04 00 00 00  在计算机内是小端字节序的存储形式，存储方式就是这样的
//	int *ptr1 = (int *)(&a + 1); 
//	int *ptr2 = (int *)((int)a + 1);  //a的地址强制转换为整形，然后+1，在转换为地址，相当于跟a相比增加了一个字节的大小
//	//a指向的是数组首元素的地址，也就是01的地方，现在指向的是第二个字节的地方00处，现在是int*的类型，一次访问4个字节
//	// 应该就是 00 00 00 02    然后我们把其地址的方式为  0x02000000   转换为16进制的数是2000000    
//	printf("%x,%x", ptr1[-1], *ptr2); 
//	return 0;
//}

//4
//
//#include <stdio.h> 
//int main()
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };  // 这是一个逗号表达式，最终的结果应该是每一个圆括号里面的后一个值   1 ， 3， 5，未初始化的默认为0
//	int *p; 
//	p = a[0]; 
//	printf("%d", p[0]);   
//	return 0;
//	//结果是1
//}


//5
//int main()
//{
//	int a[5][5];  // a的类型是 int (*)[5]
//	int(*p)[4];  // p的类型是 int(*)[4]
//	p = a;//这里你就会发现他们的类型是不相同的，所以编译器会报错，但是他依旧会把第一行的数组地址赋给p
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]); // 地址和地址相减得到的应该是他们之间元素个数，但是明显后面的地址是比前面的地址要大的
//	//以%d的形式打印是没有问题的得到的就会是-4   但是%p认为打印的是一个无符号的数，所以就应该直接打印的是-4的补码  0xfffffffc
//	return 0;
//}

//6
int main() 
{ 
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };   
	int *ptr1 = (int *)(&aa + 1);    
	int *ptr2 = (int *)(*(aa + 1));   
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));   
	return 0; 
}

7
#include <stdio.h>
int main() 
{ 
	char *a[] = { "work", "at", "alibaba" };   
	char**pa = a;    
	pa++;    
	printf("%s\n", *pa);  
	return 0; 
}


8
int main() 
{ 
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };  
	char**cp[] = { c + 3, c + 2, c + 1, c };  
	char***cpp = cp;   
	printf("%s\n", **++cpp);   
	printf("%s\n", *--*++cpp + 3);    
	printf("%s\n", *cpp[-2] + 3);  
	printf("%s\n", cpp[-1][-1] + 1);  
	return 0; 
}