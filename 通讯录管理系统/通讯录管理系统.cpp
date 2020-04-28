#include<iostream> //标准输入输出流
#include<iomanip> //对齐 域宽
#define MAX_SIZE 1000
using namespace std; //使用c++封装的标准函数库 cout、endl...

struct Person {
	string p_name; //名字
	int p_gender = 0; //性别
	int p_age = 0; //年龄
	string p_phone; //电话
	string p_address; //地址
	string p_note; //备注
};

struct Book {
	Person* person = new Person[MAX_SIZE];
	int book_size = 0;
};

void showMenu();
void addPerson(Book* book);
void showPerson(Book* book, int id = 0);
void deletePerson(Book* book);
int isExist(Book* book, string name);
void findPerson(Book* book);
void modifyPerson(Book* book);
void cleanPerson(Book* book);

int main(int argc, char** argv, char** env) {

	//存储用户输入
	int select = 0;
	//初始化通讯录
	Book book;

	while (true)
	{
		//显示菜单
		showMenu();
		//接收输入
		cin >> select;
		switch (select) {
		case 0: //退出系统
			cout << "欢迎下次使用本系统！再见" << endl;
			return 0;
			break;
		case 1:
			addPerson(&book); //使用地址传递
			break;
		case 2:
			showPerson(&book, 0);
			break;
		case 3:
			deletePerson(&book);
			break;
		case 4:
			findPerson(&book);
			break;
		case 5:
			modifyPerson(&book);
			break;
		case 6:
			cleanPerson(&book);
			break;
		default:
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}

//菜单展示
void showMenu() {
	cout << "*******通讯录管理系统******" << endl;
	cout << "****** 1，添加联系人 ******" << endl;
	cout << "****** 2，显示联系人 ******" << endl;
	cout << "****** 3，删除联系人 ******" << endl;
	cout << "****** 4，查找联系人 ******" << endl;
	cout << "****** 5，修改联系人 ******" << endl;
	cout << "****** 6，清空联系人 ******" << endl;
	cout << "****** 0，退出系统 ********" << endl;
	cout << "***************************" << endl;
}
//添加联系人
void addPerson(Book* book) {
	//判断通讯录人数
	if (book->book_size >= MAX_SIZE) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		//添加联系人
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		int res = isExist(book, name);
		if (res != -1) {
			cout << "存在联系人" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			book->person[book->book_size].p_name = name;
		}



		cout << "请输入性别: " << endl;
		cout << " 1 -- 男  2 -- 女 " << endl;
		int gender = 0;
		while (true) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				book->person[book->book_size].p_gender = gender;
				break;
			}
			cout << "输入错误，重新输入！" << endl;
		}

		cout << "请输入年龄" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age >= 10 && age <= 100) {
				book->person[book->book_size].p_age = age;
				break;
			}
			cout << "输入错误，重新输入！" << endl;
		}

		cout << "请输入联系电话" << endl;
		string phone = "";
		cin >> phone;
		book->person[book->book_size].p_phone = phone;

		cout << "请输入地址" << endl;
		string address = "";
		cin >> address;
		book->person[book->book_size].p_address = address;

		cout << "请输入备注" << endl;
		string note = "";
		cin >> note;
		book->person[book->book_size].p_note = note;

		book->book_size++;

		cout << "添加成功！" << endl;

		system("pause");
		system("cls");
	}
}
//显示联系人
void showPerson(Book* book, int id) {
	if (book->book_size != 0) {
		//设置左对齐 设置小数点后精度为8位 设置精度固定
		cout << setiosflags(ios::left) << setprecision(8) << setiosflags(ios::fixed);
		cout << "姓名" << "\t";
		cout << "性别" << "\t";
		cout << "年龄" << "\t";
		cout << setw(10) << "电话" << "\t";
		//设置数据精度宽度为15
		cout << setw(20) << "地址" << "\t";
		cout << "备注" << endl;
		if (id == 0) {
			for (int i = 0; i < book->book_size; i++) {
				cout << book->person[i].p_name << "\t";
				cout << (book->person[i].p_gender == 1 ? "男" : "女") << "\t";
				cout << book->person[i].p_age << "\t";
				cout << setw(10) << book->person[i].p_phone << "\t";
				cout << setw(20) << book->person[i].p_address << "\t";
				cout << book->person[i].p_note << endl;
			}
		}
		else {
			cout << book->person[id].p_name << "\t";
			cout << (book->person[id].p_gender == 1 ? "女" : "男") << "\t";
			cout << book->person[id].p_age << "\t";
			cout << setw(10) << book->person[id].p_phone << "\t";
			cout << setw(20) << book->person[id].p_address << "\t";
			cout << book->person[id].p_note << endl;
		}

	}
	else {
		cout << "当前记录为空！" << endl;
	}

	system("pause");
	system("cls");
}
//删除联系人
void deletePerson(Book* book) {

	cout << "请输入要删除的联系人名字: " << endl;
	string name;
	cin >> name;

	if (book->book_size == 0) {
		cout << "通讯录为空" << endl;
	}
	else {

		int res = isExist(book, name);
		if (res != -1) {
			for (int i = res; i < book->book_size; i++) {
				book->person[i] = book->person[i + 1];
				book->book_size--;

				cout << "删除成功" << endl;
			}
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}
//查找联系人存在
int isExist(Book* book, string name) {
	for (int i = 0; i <= book->book_size; i++) {
		if (book->person[i].p_name == name) {
			return i;
		}
	}
	return -1;
}
//查找联系人
void findPerson(Book* book) {
	cout << "请输入要查找的姓名：" << endl;
	string name;
	cin >> name;

	int res = isExist(book, name);

	if (res != -1) {
		showPerson(book, res);
	}
	else {
		cout << "查无此人" << endl;
		system("pause");
		system("cls");
	}
}
//修改联系人
void modifyPerson(Book* book) {
	cout << "请输入要修改的姓名：" << endl;
	string name;
	cin >> name;
	int res = isExist(book, name);

	if (res != -1) {
		//添加联系人
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		book->person[res].p_name = name;

		cout << "请输入性别: " << endl;
		cout << " 1 -- 男  2 -- 女 " << endl;
		int gender;
		while (true) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				book->person[res].p_gender = gender;
				break;
			}
			cout << "输入错误，重新输入！" << endl;
		}

		cout << "请输入年龄" << endl;
		int age;
		while (true) {
			cin >> age;
			if (age >= 10 && age <= 100) {
				book->person[res].p_age = age;
				break;
			}
			cout << "输入错误，重新输入！" << endl;
		}

		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		book->person[res].p_phone = phone;

		cout << "请输入地址" << endl;
		string address;
		cin >> address;
		book->person[res].p_address = address;

		cout << "请输入备注" << endl;
		string note;
		cin >> note;
		book->person[res].p_note = note;
		cout << "添加成功！" << endl;
	}
	else {
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void cleanPerson(Book* book) {
	book->book_size = 0;
	cout << "记录已经清空" << endl;
	system("pause");
	system("cls");

}