#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// �ṹ������

//������ʽ1
//struct Stu
//{
//	char name[20];
//	unsigned int age;
//
//};

//������ʽ2
//struct Stu
//{
//	char name[20];
//	unsigned int age;
//
//}s1,s2;//s1��s2�� struct Stu���͵ı�����������ʵ��
////s1,s2��ȫ�ֵı���
//
//int main()
//{
//	struct Stu s3;//s3�Ǿֲ��ı���
//
//
//	return 0;
//}
//
////������ʽ3
//// �����ṹ�����ͣ�ֻ����һ�Σ�
//struct
//{
//	char name[20];
//	unsigned int age;
//}s1;//ֻ����������һ��

//struct
//{
//	int a;
//	char b;
//	float c;
//}a[20],*p;//������һ�����飬���������ȫ����������ṹ�������
//// ������һ�������ṹ��ָ�� p

// �ṹ���������
// �ڽṹ���а���һ�� ͬ���͵Ľṹ��ָ��

//struct Node
//{
//	int data;
//	struct Node* next;//�ṹ��ָ��
//};

//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;//�ѽṹ��stuct Node ������Ϊ Node
// stuct Node n1;  ��
// Node n1;        һ����

//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}* linklist;
////���������һ����˼��
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//};
//typedef struct Node* linklist;


// �ṹ������Ķ���ͳ�ʼ��
/*struct Point
{
	int x;
	int y;
}p1;*///�����ṹ�����͵�ͬʱ���������p1
//struct Point p2;//����֮�󣬶������p2
//struct Point
//{
//	int x;
//	int y;
//}p1={2,3};//�����ṹ���ͬʱ����������p1��ͬʱ��ʼ������p1
//struct Point p2 = { 2,5 };//�����ṹ��֮�󣬴�������ʱ����ʼ������p2
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
//struct Stu s1 = { "����",20,{30,'a'} };//��ʼ��
//
//int main()
//{
//	printf("%s %d %d %c", s1.name, s1.age, s1.s.n, s1.s.ch);
//	return 0;
//}

//�ṹ���ڴ����

// �ṹ��Ķ������
// 1.��һ����Ա����ṹ�����ƫ����Ϊ0�ĵ�ַ������ʼλ�ã�
// 2.������Ա����Ҫ���뵽ĳ�����֣������������������ĵ�ַ��
//   ������=������Ĭ�ϵ�һ�������� �� �ó�Ա��ռ�ֽڴ�С��  ��Сֵ
//   vs ��Ĭ�ϵĶ������� 8
// 3.�ṹ����ܴ�СΪ��������(ÿ����Ա��������һ��������������������
// 4.���Ƕ���˽ṹ�������£�Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ��������С����
//   ������������������Ƕ�׽ṹ��Ķ�����������������

// �ṹ���ڴ�Ķ�������ÿռ任ʱ���������
//  size_t offsetof(structName,memberName)// ����һ����Ա�������ڽṹ�������е�ƫ����
#include <stddef.h>
// gcc������û��Ĭ�϶����������������ǳ�Ա�������С

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
// �ṹ������Ƶ�ʱ��Ҫ������Ҫ�������룬��Ҫ������ʡ�ռ�
// ��ռ�ÿռ�С�ĳ�Ա����������һ�𣬿��Խ�ʡ�ռ�
//����ṹ��S1��S2���������һģһ����������ʹ�õĿռ��в���

// �޸�Ĭ�϶�����
//#pragma pack(4) // ����һ��Ԥ����ָ���ʾ��Ĭ�϶������ĳ�4
//#pragma pack()  // ��ʾ��Ĭ�϶������ָ��� 8
//#pragma pack(1) //�൱�ڲ�����
// Ĭ�϶�����һ���� 2 �� n �η�
// ������Ĭ�϶������� 8 ������£�
//struct S5
//{
//	int i;// 0-3
//	// 4-7
//	double d;// 8-15
//};

// ��Ĭ�϶������ĳ�4֮��
//struct S6
//{
//	int i;// 0-3
//	double d;// 4-11
//};

// �ṹ�崫�Σ�

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
//		printf("%d\n", (*ps).data[i]);// д��һ
//		printf("%d\n", ps->data[i]);// д����
//	}
//	printf("%d\n", (*ps).num);// д��һ
//	printf("%d\n", ps->num);// д����
//
//}
//
//int main()
//{
//	struct S s = { {1,2,3},100 };
//	print1(s);// ��ֵ���� //���ṹ���������ѹջ��ʹ�ù�����ڴ��ʱ�䣬������ʹ��
//	print2(&s);// ��ַ���� // Ч������һЩ��ռ���ڴ�С
//	return 0;
//}