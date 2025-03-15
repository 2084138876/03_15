#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 结构体类型

//创建方式1
//struct Stu
//{
//	char name[20];
//	unsigned int age;
//
//};

//创建方式2
//struct Stu
//{
//	char name[20];
//	unsigned int age;
//
//}s1,s2;//s1和s2是 struct Stu类型的变量，即对象、实体
////s1,s2是全局的变量
//
//int main()
//{
//	struct Stu s3;//s3是局部的变量
//
//
//	return 0;
//}
//
////创建方式3
//// 匿名结构体类型（只能用一次）
//struct
//{
//	char name[20];
//	unsigned int age;
//}s1;//只能在这里用一次

//struct
//{
//	int a;
//	char b;
//	float c;
//}a[20],*p;//创建了一个数组，里面的数据全是这个匿名结构体的类型
//// 创建了一个匿名结构体指针 p

// 结构体的自引用
// 在结构体中包含一个 同类型的结构体指针

//struct Node
//{
//	int data;
//	struct Node* next;//结构体指针
//};

//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;//把结构体stuct Node 重命名为 Node
// stuct Node n1;  和
// Node n1;        一样了

//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}* linklist;
////和下面这个一个意思：
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//};
//typedef struct Node* linklist;


// 结构体变量的定义和初始化
/*struct Point
{
	int x;
	int y;
}p1;*///声明结构体类型的同时，定义变量p1
//struct Point p2;//声明之后，定义变量p2
//struct Point
//{
//	int x;
//	int y;
//}p1={2,3};//创建结构体的同时，创建变量p1，同时初始化变量p1
//struct Point p2 = { 2,5 };//创建结构体之后，创建变量时，初始化变量p2
//
//struct Score
//{
//	int n;
//	char ch;
//};
//struct Stu
//{
//	char name[20];
//	unsigned int age;
//	struct Score s;
//};
//struct Stu s1 = { "张三",20,{30,'a'} };//初始化
//
//int main()
//{
//	printf("%s %d %d %c", s1.name, s1.age, s1.s.n, s1.s.ch);
//	return 0;
//}

//结构体内存对齐

// 结构体的对齐规则：
// 1.第一个成员在与结构体变量偏移量为0的地址处（起始位置）
// 2.其他成员变量要对齐到某个数字（对齐数）的整数倍的地址处
//   对齐数=编译器默认的一个对齐数 与 该成员所占字节大小的  较小值
//   vs 中默认的对齐数是 8
// 3.结构体的总大小为最大对齐数(每个成员变量都有一个对齐数）的整数被。
// 4.如果嵌套了结构体的情况下，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是
//   所有最大对齐数（包含嵌套结构体的对齐数）的整数倍。

// 结构体内存的对齐就是拿空间换时间的做法！
//  size_t offsetof(structName,memberName)// 计算一个成员在其所在结构体类型中的偏移量
#include <stddef.h>
// gcc编译器没有默认对齐数，对齐数就是成员的自身大小

//struct S1
//{
//	char c1;
//	int i;
//	char c2;
//};
//
//struct S2
//{
//	char c1;
//	char c2;
//	int i;
//};
//
//struct S3
//{
//	double d;
//	char c;
//	int i;
//};
//
//struct S4
//{
//	char c1;
//	struct S3 s3;
//	double d;
//};
//
//int main()
//{
//	printf("%d\n", sizeof(struct S1));//12
//	printf("%d\n", sizeof(struct S2));//8
//	printf("%d\n", sizeof(struct S3));//16
//	printf("%d\n", sizeof(struct S4));//32
//	printf("%d\n", offsetof( struct S1,c1));
//	printf("%d\n", offsetof( struct S1,i));
//	printf("%d\n", offsetof( struct S1,c2));
//	return 0;
//}
// 结构体在设计的时候要做到既要做到对齐，又要做到节省空间
// 让占用空间小的成员尽量集中在一起，可以节省空间
//例如结构体S1和S2里面的数据一模一样，但是所使用的空间有差异

// 修改默认对齐数
//#pragma pack(4) // 这是一条预处理指令，表示把默认对齐数改成4
//#pragma pack()  // 表示把默认对齐数恢复到 8
//#pragma pack(1) //相当于不对齐
// 默认对齐数一般是 2 的 n 次方
// 下面是默认对齐数是 8 的情况下：
//struct S5
//{
//	int i;// 0-3
//	// 4-7
//	double d;// 8-15
//};

// 把默认对齐数改成4之后：
//struct S6
//{
//	int i;// 0-3
//	double d;// 4-11
//};

// 结构体传参：

//struct S
//{
//	int data[100];
//	int num;
//};
//
//void print1(struct S ss)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", ss.data[i]);
//	}
//	printf("%d\n", ss.num);
//}
//
//void print2(const struct S* ps)
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		printf("%d\n", (*ps).data[i]);// 写法一
//		printf("%d\n", ps->data[i]);// 写法二
//	}
//	printf("%d\n", (*ps).num);// 写法一
//	printf("%d\n", ps->num);// 写法二
//
//}
//
//int main()
//{
//	struct S s = { {1,2,3},100 };
//	print1(s);// 传值调用 //传结构体对象会产生压栈，使用过多的内存和时间，不建议使用
//	print2(&s);// 传址调用 // 效果更好一些，占用内存小
//	return 0;
//}