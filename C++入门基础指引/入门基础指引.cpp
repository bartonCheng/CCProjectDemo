/*
* 多行注释
* 注释
*/

// 单行注释
//包含读取 写出 函数
#include<iostream>
//包含 随机数 排序 搜索 类型转换 内存管理 数学公式的函数
#include<cstdlib>
//允许使用STL的字符串类
#include<string>
//提供寻最大值 最小值的函数
#include<limits>
//C++的泛型 向量类型也成为容器
#include <vector>
//C++的算法库
#include<algorithm>
#include <sstream>
#include <numeric>
//c++的时间类
#include <ctime>
//c++的数学计算类
#include <cmath>
// 使用文件系统 file IO
#include <fstream> 

//使用标准的命名空间
using namespace std;

//声明全局变量
int iGlobal = 0;

//声明常量
const double PI = 3.141;


/*
* 函数声明
*/
double AddNumbers(double num1, double num2);
void AssignAge(int age);
int AssignAge2(int age);
void AssignAge3(int* pAge);
void DoubleArray(int* arr, int size);

//主函数
int main(int argc, char** argv) {

	{
		//输出字符串到控制台
		cout << "Hello World!" << endl;

		// ---------- 数据类型 ----------
		//布尔值变量，可以是true、false
		bool married = true;
		//字符型的变量，注意使用单引号
		char myGrade = 'A';
		//指针类型的字符串，注意指针指向的是内存空间，一旦定义不可以更改，否则会程序崩溃，引用的时候需要移动指针。程序编译阶段就会加载进内存。
		const char* p1 = "abcd";
		//定义字符数组，可以使用作为字符串使用。可以修改，在程序运行的时候才会加载进内存
		char p2[] = "1234";

		//整数类型有不同的最大值最小值
		cout << "Min unsigned short int: " << numeric_limits<unsigned short int>::min() << endl;
		cout << "Max unsigned short int: " << numeric_limits<unsigned short int>::max() << endl;

		cout << "Min short int: " << numeric_limits<short int>::min() << endl;
		cout << "Max short int: " << numeric_limits<short int>::max() << endl;

		cout << "Min int: " << numeric_limits<int>::min() << endl;
		cout << "Max int: " << numeric_limits<int>::max() << endl;

		//long int 和 int 一样长度，现在的长整型是long long
		cout << "Min long long: " << numeric_limits<long long>::min() << endl;
		cout << "Max long long: " << numeric_limits<long long>::max() << endl;

		//浮点型数据类型
		cout << "Min float: " << numeric_limits<float>::min() << endl;
		cout << "Max float: " << numeric_limits<float>::max() << endl;

		cout << "Min double: " << numeric_limits<double>::min() << endl;
		cout << "Max double: " << numeric_limits<double>::max() << endl;

		//long double 和 double 表示的位数一样
		cout << "Min long double: " << numeric_limits<long double>::min() << endl;
		cout << "Max long double: " << numeric_limits<long double>::max() << endl;

		//float小数点后精确7位，超过就会溢出
		//float f1 = 1.12345678;
		//float f2 = 1.12345678;
		//小数点后七位
		//printf("Sum = %.8f\n", (f1 + f2));
		//double精确小数点后15位，超过也会溢出
		//double d1 = 1.1234567890123456;
		//double d2 = 1.1234567890123456;
		//printf("Sum 2 = %.16f\n", (d1 + d2));

		//查看数据类型占用长度
		cout << "int bytes: " << sizeof(int) << endl;

		//关于打印函数
		printf("%c %d %5d %.3f %s\n", 'A', 10, 5, 3.1234, "Hi");

		//创建字符串
		string str1 = "this is a string ?";

		//打印字符串
		cout << str1 << endl;
		//定义变量存储字符串
		string str2 = "23", str3 = "12";
		cout << "输入一个数" << endl;
		//cin >> str2;
		cout << "输入第二个数" << endl;
		//cin >> str3;

		//转换字符串到整数
		int num2 = stoi(str2);
		int num3 = stoi(str3);

		//计算结果
		// Math Operators
		printf("%d + %d = %d\n", num2, num3, (num2 + num3));
		printf("%d - %d = %d\n", num2, num3, (num2 - num3));
		printf("%d * %d = %d\n", num2, num3, (num2 * num3));
		printf("%d / %d = %d\n", num2, num3, (num2 / num3));
		printf("%d %% %d = %d\n", num2, num3, (num2 % num3));

		//运算符
		//条件运算符 > < >= <= == !=
		//逻辑运算符 && || ！

		string sAge = "23";
		cout << "输入你的年龄： " << endl;
		//cin >> sAge;
		int iAge = stoi(sAge);

		if ((iAge >= 1) && (iAge <= 18)) {
			cout << "青春岁月" << endl;
		}
		else if (iAge == 35) {
			cout << "黄金岁月" << endl;
		}
		else if ((iAge > 18) || (iAge < 60)) {
			cout << "努力吧小伙" << endl;
		}
		else {
			cout << "输入错误，请重新输入" << endl;
		}

		//三目运算符

		int iVote = 34;
		bool(iVote >= 30) ? "竞选成功" : "继续努力";

		//数组 : 相同类型数据的集合
		int arrNums1[10] = { 1 };
		int arrNums2[] = { 1,2,3 };
		int arrNums3[5] = { 8,9 };
		//输出数组元素
		cout << arrNums2[1] << endl;
		//改变数组元素
		arrNums3[0] = 12;
		cout << arrNums3[0] << endl;
		//多维数组
		//1st num : 有几层
		//2st num : 有几列
		//3st num : 有几行
		int arrNums4[2][2][2] = { {{1,2},{3,4}},{{5,6},{7,8}} };
		cout << arrNums4[0][0][0] << endl;
		cout << arrNums4[0][0][1] << endl;
		cout << arrNums4[0][1][0] << endl;
		cout << arrNums4[0][1][1] << endl;
		cout << arrNums4[1][0][0] << endl;
		cout << arrNums4[1][0][1] << endl;

		//vectors 数组，当不知道数组大小的时候使用
		vector<int> vNum1(2);

		vNum1[0] = 12;
		vNum1[1] = 13;
		cout << "Vector Size is : " << vNum1.size() << endl;


		// 循环
		//while循环
		int i = 1;
		while (i <= 20)
		{
			if (i % 2 == 0) {
				i += 1;
				continue;
			}
			if (i == 15) {
				break;
			}
			cout << i << endl;
			i += 1;
		}


		//定义一个数组容器，一会循环容器数据
		vector<string> words;
		//定义一个字符串流
		stringstream ss("some words here!"
			"hi good you "
			"good water!");
		//接受临时数据的变量
		string word;
		//循环取出每一行数据，按照空格 分隔
		while (getline(ss, word, ' ')) {
			words.push_back(word);
		}
		//循环容器数据
		for (unsigned int i = 0; i < words.size(); i++) {
			cout << words[i] << endl;
		}

		//循环数组数据
		int arrNums5[] = { 12,3,43 };
		for (auto x : arrNums5) {
			cout << x << endl;
		}


		//猜数字游戏
		//需要引入ctime库
		//设置随机数种子
		srand((unsigned)time(NULL));

		int secretNum = rand() % 11;
		int guess = 0;

		/*do
		{
			cout << "Guess the num: " << endl;
			cin >> guess;
			if (guess > secretNum) {
				cout << "Too Big !" << endl;
			}
			if (guess < secretNum) {
				cout << "Too Small !" << endl;
			}
		} while (secretNum != guess);*/

		cout << "You Guess it!!!" << endl;

		//字符串
		//c++的字符串是一系列可改变的字符
		string myStr1 = "I am chinese";

		//打印第一个字符
		cout << "1st : " << myStr1[0] << endl;
		//获取最后一个字符
		cout << "last : " << myStr1.back() << endl;
		//获取字符串的长度
		cout << "Length : " << myStr1.size() << endl;
		cout << "Length : " << myStr1.length() << endl;
		//复制字符串
		string myStr2 = myStr1;
		//复制头部4个字符
		string myStr3(myStr2, 4);
		//组合字符串
		string myStr4 = myStr1 + "Hello bartonBoy";
		//追加到尾部
		myStr4.append("!!!");
		//清除指定区间字符
		myStr4.erase(8, myStr4.size() - 4);
		cout << myStr4 << endl;
		//查找功能 ，返回查找字符的index，或者返回npos
		if (myStr2.find("I") != string::npos) {
			cout << "String Index: " << myStr2.find("I") << endl;
		}
		//抽取字符串
		cout << "substring is : " << myStr2.substr(3, 8) << endl;
		//转换int到string
		string numString = to_string(1 + 23);
		cout << "I am string from num : " << numString << endl;

		//一些判断
		char letterZ = 'Z';
		char num5 = '5';
		char aSpace = ' ';
		cout << "这是一个字母/数字 : " << isalnum(letterZ) << endl;
		cout << "这是字母 : " << isalpha(letterZ) << endl;
		cout << "这是数字 : " << isdigit(num5) << endl;
		cout << "这是空格 : " << isspace(aSpace) << endl;

		//数学功能
		cout << "abs(-10) = " << abs(-10) << endl;
		cout << "max(5, 4) = " << (std::max)(5, 4) << endl;
		cout << "min(5, 4) = " << min(5, 4) << endl;
		cout << "fmax(5.3, 4.3) = " << fmax(5.3, 4.3) << endl;
		cout << "fmin(5.3, 4.3) = " << fmin(5.3, 4.3) << endl;
		cout << "ceil(10.45) = " << ceil(10.45) << endl;
		cout << "floor(10.45) = " << floor(10.45) << endl;
		cout << "round(10.45) = " << round(10.45) << endl;
		cout << "pow(2,3) = " << pow(2, 3) << endl;
		cout << "sqrt(100) = " << sqrt(100) << endl;
		cout << "cbrt(1000) = " << cbrt(1000) << endl;
		// e ^ x
		cout << "exp(1) = " << exp(1) << endl;
		// 2 ^ x
		cout << "exp2(1) = " << exp2(1) << endl;
		// e * e * e ~= 20 so log(20.079) ~= 3
		cout << "log(20.079) = " << log(20.079) << endl;
		// 2 * 2 * 2 = 8
		cout << "log2(8) = " << log2(8) << endl;
		// Hypotenuse : SQRT(A^2 + B^2)
		cout << "hypot(2,3) = " << hypot(2, 3) << endl;
		// Also sin, cos, tan, asin, acos, atan, atan2,
		// sinh, cosh, tanh, asinh, acosh, atanh


		  // 调用函数
		printf("%.1f + %.1f = %.1f\n", 5.0,
			4.0, AddNumbers(5, 4));
		int age2 = 43;
		AssignAge(age2);
		cout << "New Age : " << age2 << endl;
		age2 = AssignAge2(age2);
		cout << "New Age " << age2 << "\n";


		//指针
		//指针存储内存的地址
		//指针的地址是int类型
		int* pAge2 = NULL;

		//访问数值的指针
		pAge2 = &age2;
		//输出指针
		cout << "Address : " << pAge2 << "\n";
		//获取指针的值
		cout << "Value at Address : " << *pAge2 << "\n";

		//通过++ -- 访问数组的指针
		int intArray[] = { 1,2,3,4 };
		int* pIntArray = intArray;

		cout << "1st value " << *pIntArray <<
			" Address " << pIntArray << endl;
		pIntArray++;
		cout << "2nd value" << *pIntArray <<
			" Address " << pIntArray << endl;
		pIntArray--;
		cout << "1st value" << *pIntArray <<
			" Address " << pIntArray << endl;


		//函数传递的参数指针
		age2 = 43;
		//改变指针内存
		AssignAge3(&age2);
		//打印值
		cout << "Pointer Age " << age2 << "\n";

		// 创建数组，使用函数加倍数值
		int arr[] = { 1,2,3,4 };
		DoubleArray(arr, 4);
		for (int i = 0; i < 4; ++i) {
			cout << "Array " << arr[i] << "\n";
		}


		//异常操作
		double newNum3 = 10, newNum4 = 0;
		try {
			if (newNum4 == 0) {
				throw "Division by Zero Error";
			}
			else {
				printf("%.1f / %.1f = %.1f", newNum3, newNum4,
					(newNum3 / newNum4));
			}
		}

		catch (const char* exp) {
			cout << "Error : " << exp << endl;
		}
	}

	return 0;
}



/*
* 函数定义
*/

double AddNumbers(double num1 = 0, double num2 = 0) {
	return num1 + num2;
}

// 函数内部定义的变量，不可以被外边访问
void AssignName() {
	string name = "Derek";
}

void AssignAge(int age) {
	age = 24;
}

int AssignAge2(int age) {
	age = 24;
	return age;
}

// 使用指针传递参数
void AssignAge3(int* pAge) {

	// 使用指针操作内存，改变变量值
	*pAge = 22;

}

// 使用两个指针变量 ，操作数组
void DoubleArray(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = arr[i] * 2;
	}
}

