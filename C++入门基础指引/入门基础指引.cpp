/*
* ����ע��
* ע��
*/

// ����ע��
//������ȡ д�� ����
#include<iostream>
//���� ����� ���� ���� ����ת�� �ڴ���� ��ѧ��ʽ�ĺ���
#include<cstdlib>
//����ʹ��STL���ַ�����
#include<string>
//�ṩѰ���ֵ ��Сֵ�ĺ���
#include<limits>
//C++�ķ��� ��������Ҳ��Ϊ����
#include <vector>
//C++���㷨��
#include<algorithm>
#include <sstream>
#include <numeric>
//c++��ʱ����
#include <ctime>
//c++����ѧ������
#include <cmath>
// ʹ���ļ�ϵͳ file IO
#include <fstream> 

//ʹ�ñ�׼�������ռ�
using namespace std;

//����ȫ�ֱ���
int iGlobal = 0;

//��������
const double PI = 3.141;


/*
* ��������
*/
double AddNumbers(double num1, double num2);
void AssignAge(int age);
int AssignAge2(int age);
void AssignAge3(int* pAge);
void DoubleArray(int* arr, int size);

//������
int main(int argc, char** argv) {

	{
		//����ַ���������̨
		cout << "Hello World!" << endl;

		// ---------- �������� ----------
		//����ֵ������������true��false
		bool married = true;
		//�ַ��͵ı�����ע��ʹ�õ�����
		char myGrade = 'A';
		//ָ�����͵��ַ�����ע��ָ��ָ������ڴ�ռ䣬һ�����岻���Ը��ģ�����������������õ�ʱ����Ҫ�ƶ�ָ�롣�������׶ξͻ���ؽ��ڴ档
		const char* p1 = "abcd";
		//�����ַ����飬����ʹ����Ϊ�ַ���ʹ�á������޸ģ��ڳ������е�ʱ��Ż���ؽ��ڴ�
		char p2[] = "1234";

		//���������в�ͬ�����ֵ��Сֵ
		cout << "Min unsigned short int: " << numeric_limits<unsigned short int>::min() << endl;
		cout << "Max unsigned short int: " << numeric_limits<unsigned short int>::max() << endl;

		cout << "Min short int: " << numeric_limits<short int>::min() << endl;
		cout << "Max short int: " << numeric_limits<short int>::max() << endl;

		cout << "Min int: " << numeric_limits<int>::min() << endl;
		cout << "Max int: " << numeric_limits<int>::max() << endl;

		//long int �� int һ�����ȣ����ڵĳ�������long long
		cout << "Min long long: " << numeric_limits<long long>::min() << endl;
		cout << "Max long long: " << numeric_limits<long long>::max() << endl;

		//��������������
		cout << "Min float: " << numeric_limits<float>::min() << endl;
		cout << "Max float: " << numeric_limits<float>::max() << endl;

		cout << "Min double: " << numeric_limits<double>::min() << endl;
		cout << "Max double: " << numeric_limits<double>::max() << endl;

		//long double �� double ��ʾ��λ��һ��
		cout << "Min long double: " << numeric_limits<long double>::min() << endl;
		cout << "Max long double: " << numeric_limits<long double>::max() << endl;

		//floatС�����ȷ7λ�������ͻ����
		//float f1 = 1.12345678;
		//float f2 = 1.12345678;
		//С�������λ
		//printf("Sum = %.8f\n", (f1 + f2));
		//double��ȷС�����15λ������Ҳ�����
		//double d1 = 1.1234567890123456;
		//double d2 = 1.1234567890123456;
		//printf("Sum 2 = %.16f\n", (d1 + d2));

		//�鿴��������ռ�ó���
		cout << "int bytes: " << sizeof(int) << endl;

		//���ڴ�ӡ����
		printf("%c %d %5d %.3f %s\n", 'A', 10, 5, 3.1234, "Hi");

		//�����ַ���
		string str1 = "this is a string ?";

		//��ӡ�ַ���
		cout << str1 << endl;
		//��������洢�ַ���
		string str2 = "23", str3 = "12";
		cout << "����һ����" << endl;
		//cin >> str2;
		cout << "����ڶ�����" << endl;
		//cin >> str3;

		//ת���ַ���������
		int num2 = stoi(str2);
		int num3 = stoi(str3);

		//������
		// Math Operators
		printf("%d + %d = %d\n", num2, num3, (num2 + num3));
		printf("%d - %d = %d\n", num2, num3, (num2 - num3));
		printf("%d * %d = %d\n", num2, num3, (num2 * num3));
		printf("%d / %d = %d\n", num2, num3, (num2 / num3));
		printf("%d %% %d = %d\n", num2, num3, (num2 % num3));

		//�����
		//��������� > < >= <= == !=
		//�߼������ && || ��

		string sAge = "23";
		cout << "����������䣺 " << endl;
		//cin >> sAge;
		int iAge = stoi(sAge);

		if ((iAge >= 1) && (iAge <= 18)) {
			cout << "�ഺ����" << endl;
		}
		else if (iAge == 35) {
			cout << "�ƽ�����" << endl;
		}
		else if ((iAge > 18) || (iAge < 60)) {
			cout << "Ŭ����С��" << endl;
		}
		else {
			cout << "�����������������" << endl;
		}

		//��Ŀ�����

		int iVote = 34;
		bool(iVote >= 30) ? "��ѡ�ɹ�" : "����Ŭ��";

		//���� : ��ͬ�������ݵļ���
		int arrNums1[10] = { 1 };
		int arrNums2[] = { 1,2,3 };
		int arrNums3[5] = { 8,9 };
		//�������Ԫ��
		cout << arrNums2[1] << endl;
		//�ı�����Ԫ��
		arrNums3[0] = 12;
		cout << arrNums3[0] << endl;
		//��ά����
		//1st num : �м���
		//2st num : �м���
		//3st num : �м���
		int arrNums4[2][2][2] = { {{1,2},{3,4}},{{5,6},{7,8}} };
		cout << arrNums4[0][0][0] << endl;
		cout << arrNums4[0][0][1] << endl;
		cout << arrNums4[0][1][0] << endl;
		cout << arrNums4[0][1][1] << endl;
		cout << arrNums4[1][0][0] << endl;
		cout << arrNums4[1][0][1] << endl;

		//vectors ���飬����֪�������С��ʱ��ʹ��
		vector<int> vNum1(2);

		vNum1[0] = 12;
		vNum1[1] = 13;
		cout << "Vector Size is : " << vNum1.size() << endl;


		// ѭ��
		//whileѭ��
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


		//����һ������������һ��ѭ����������
		vector<string> words;
		//����һ���ַ�����
		stringstream ss("some words here!"
			"hi good you "
			"good water!");
		//������ʱ���ݵı���
		string word;
		//ѭ��ȡ��ÿһ�����ݣ����տո� �ָ�
		while (getline(ss, word, ' ')) {
			words.push_back(word);
		}
		//ѭ����������
		for (unsigned int i = 0; i < words.size(); i++) {
			cout << words[i] << endl;
		}

		//ѭ����������
		int arrNums5[] = { 12,3,43 };
		for (auto x : arrNums5) {
			cout << x << endl;
		}


		//��������Ϸ
		//��Ҫ����ctime��
		//�������������
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

		//�ַ���
		//c++���ַ�����һϵ�пɸı���ַ�
		string myStr1 = "I am chinese";

		//��ӡ��һ���ַ�
		cout << "1st : " << myStr1[0] << endl;
		//��ȡ���һ���ַ�
		cout << "last : " << myStr1.back() << endl;
		//��ȡ�ַ����ĳ���
		cout << "Length : " << myStr1.size() << endl;
		cout << "Length : " << myStr1.length() << endl;
		//�����ַ���
		string myStr2 = myStr1;
		//����ͷ��4���ַ�
		string myStr3(myStr2, 4);
		//����ַ���
		string myStr4 = myStr1 + "Hello bartonBoy";
		//׷�ӵ�β��
		myStr4.append("!!!");
		//���ָ�������ַ�
		myStr4.erase(8, myStr4.size() - 4);
		cout << myStr4 << endl;
		//���ҹ��� �����ز����ַ���index�����߷���npos
		if (myStr2.find("I") != string::npos) {
			cout << "String Index: " << myStr2.find("I") << endl;
		}
		//��ȡ�ַ���
		cout << "substring is : " << myStr2.substr(3, 8) << endl;
		//ת��int��string
		string numString = to_string(1 + 23);
		cout << "I am string from num : " << numString << endl;

		//һЩ�ж�
		char letterZ = 'Z';
		char num5 = '5';
		char aSpace = ' ';
		cout << "����һ����ĸ/���� : " << isalnum(letterZ) << endl;
		cout << "������ĸ : " << isalpha(letterZ) << endl;
		cout << "�������� : " << isdigit(num5) << endl;
		cout << "���ǿո� : " << isspace(aSpace) << endl;

		//��ѧ����
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


		  // ���ú���
		printf("%.1f + %.1f = %.1f\n", 5.0,
			4.0, AddNumbers(5, 4));
		int age2 = 43;
		AssignAge(age2);
		cout << "New Age : " << age2 << endl;
		age2 = AssignAge2(age2);
		cout << "New Age " << age2 << "\n";


		//ָ��
		//ָ��洢�ڴ�ĵ�ַ
		//ָ��ĵ�ַ��int����
		int* pAge2 = NULL;

		//������ֵ��ָ��
		pAge2 = &age2;
		//���ָ��
		cout << "Address : " << pAge2 << "\n";
		//��ȡָ���ֵ
		cout << "Value at Address : " << *pAge2 << "\n";

		//ͨ��++ -- ���������ָ��
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


		//�������ݵĲ���ָ��
		age2 = 43;
		//�ı�ָ���ڴ�
		AssignAge3(&age2);
		//��ӡֵ
		cout << "Pointer Age " << age2 << "\n";

		// �������飬ʹ�ú����ӱ���ֵ
		int arr[] = { 1,2,3,4 };
		DoubleArray(arr, 4);
		for (int i = 0; i < 4; ++i) {
			cout << "Array " << arr[i] << "\n";
		}


		//�쳣����
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
* ��������
*/

double AddNumbers(double num1 = 0, double num2 = 0) {
	return num1 + num2;
}

// �����ڲ�����ı����������Ա���߷���
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

// ʹ��ָ�봫�ݲ���
void AssignAge3(int* pAge) {

	// ʹ��ָ������ڴ棬�ı����ֵ
	*pAge = 22;

}

// ʹ������ָ����� ����������
void DoubleArray(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		arr[i] = arr[i] * 2;
	}
}

