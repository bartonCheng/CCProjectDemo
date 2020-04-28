#include<iostream> //��׼���������
#include<iomanip> //���� ���
#define MAX_SIZE 1000
using namespace std; //ʹ��c++��װ�ı�׼������ cout��endl...

struct Person {
	string p_name; //����
	int p_gender = 0; //�Ա�
	int p_age = 0; //����
	string p_phone; //�绰
	string p_address; //��ַ
	string p_note; //��ע
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

	//�洢�û�����
	int select = 0;
	//��ʼ��ͨѶ¼
	Book book;

	while (true)
	{
		//��ʾ�˵�
		showMenu();
		//��������
		cin >> select;
		switch (select) {
		case 0: //�˳�ϵͳ
			cout << "��ӭ�´�ʹ�ñ�ϵͳ���ټ�" << endl;
			return 0;
			break;
		case 1:
			addPerson(&book); //ʹ�õ�ַ����
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

//�˵�չʾ
void showMenu() {
	cout << "*******ͨѶ¼����ϵͳ******" << endl;
	cout << "****** 1�������ϵ�� ******" << endl;
	cout << "****** 2����ʾ��ϵ�� ******" << endl;
	cout << "****** 3��ɾ����ϵ�� ******" << endl;
	cout << "****** 4��������ϵ�� ******" << endl;
	cout << "****** 5���޸���ϵ�� ******" << endl;
	cout << "****** 6�������ϵ�� ******" << endl;
	cout << "****** 0���˳�ϵͳ ********" << endl;
	cout << "***************************" << endl;
}
//�����ϵ��
void addPerson(Book* book) {
	//�ж�ͨѶ¼����
	if (book->book_size >= MAX_SIZE) {
		cout << "ͨѶ¼����" << endl;
		return;
	}
	else {
		//�����ϵ��
		string name;
		cout << "����������: " << endl;
		cin >> name;
		int res = isExist(book, name);
		if (res != -1) {
			cout << "������ϵ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		else {
			book->person[book->book_size].p_name = name;
		}



		cout << "�������Ա�: " << endl;
		cout << " 1 -- ��  2 -- Ů " << endl;
		int gender = 0;
		while (true) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				book->person[book->book_size].p_gender = gender;
				break;
			}
			cout << "��������������룡" << endl;
		}

		cout << "����������" << endl;
		int age = 0;
		while (true) {
			cin >> age;
			if (age >= 10 && age <= 100) {
				book->person[book->book_size].p_age = age;
				break;
			}
			cout << "��������������룡" << endl;
		}

		cout << "��������ϵ�绰" << endl;
		string phone = "";
		cin >> phone;
		book->person[book->book_size].p_phone = phone;

		cout << "�������ַ" << endl;
		string address = "";
		cin >> address;
		book->person[book->book_size].p_address = address;

		cout << "�����뱸ע" << endl;
		string note = "";
		cin >> note;
		book->person[book->book_size].p_note = note;

		book->book_size++;

		cout << "��ӳɹ���" << endl;

		system("pause");
		system("cls");
	}
}
//��ʾ��ϵ��
void showPerson(Book* book, int id) {
	if (book->book_size != 0) {
		//��������� ����С����󾫶�Ϊ8λ ���þ��ȹ̶�
		cout << setiosflags(ios::left) << setprecision(8) << setiosflags(ios::fixed);
		cout << "����" << "\t";
		cout << "�Ա�" << "\t";
		cout << "����" << "\t";
		cout << setw(10) << "�绰" << "\t";
		//�������ݾ��ȿ��Ϊ15
		cout << setw(20) << "��ַ" << "\t";
		cout << "��ע" << endl;
		if (id == 0) {
			for (int i = 0; i < book->book_size; i++) {
				cout << book->person[i].p_name << "\t";
				cout << (book->person[i].p_gender == 1 ? "��" : "Ů") << "\t";
				cout << book->person[i].p_age << "\t";
				cout << setw(10) << book->person[i].p_phone << "\t";
				cout << setw(20) << book->person[i].p_address << "\t";
				cout << book->person[i].p_note << endl;
			}
		}
		else {
			cout << book->person[id].p_name << "\t";
			cout << (book->person[id].p_gender == 1 ? "Ů" : "��") << "\t";
			cout << book->person[id].p_age << "\t";
			cout << setw(10) << book->person[id].p_phone << "\t";
			cout << setw(20) << book->person[id].p_address << "\t";
			cout << book->person[id].p_note << endl;
		}

	}
	else {
		cout << "��ǰ��¼Ϊ�գ�" << endl;
	}

	system("pause");
	system("cls");
}
//ɾ����ϵ��
void deletePerson(Book* book) {

	cout << "������Ҫɾ������ϵ������: " << endl;
	string name;
	cin >> name;

	if (book->book_size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
	}
	else {

		int res = isExist(book, name);
		if (res != -1) {
			for (int i = res; i < book->book_size; i++) {
				book->person[i] = book->person[i + 1];
				book->book_size--;

				cout << "ɾ���ɹ�" << endl;
			}
		}
		else {
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
//������ϵ�˴���
int isExist(Book* book, string name) {
	for (int i = 0; i <= book->book_size; i++) {
		if (book->person[i].p_name == name) {
			return i;
		}
	}
	return -1;
}
//������ϵ��
void findPerson(Book* book) {
	cout << "������Ҫ���ҵ�������" << endl;
	string name;
	cin >> name;

	int res = isExist(book, name);

	if (res != -1) {
		showPerson(book, res);
	}
	else {
		cout << "���޴���" << endl;
		system("pause");
		system("cls");
	}
}
//�޸���ϵ��
void modifyPerson(Book* book) {
	cout << "������Ҫ�޸ĵ�������" << endl;
	string name;
	cin >> name;
	int res = isExist(book, name);

	if (res != -1) {
		//�����ϵ��
		string name;
		cout << "����������: " << endl;
		cin >> name;
		book->person[res].p_name = name;

		cout << "�������Ա�: " << endl;
		cout << " 1 -- ��  2 -- Ů " << endl;
		int gender;
		while (true) {
			cin >> gender;
			if (gender == 1 || gender == 2) {
				book->person[res].p_gender = gender;
				break;
			}
			cout << "��������������룡" << endl;
		}

		cout << "����������" << endl;
		int age;
		while (true) {
			cin >> age;
			if (age >= 10 && age <= 100) {
				book->person[res].p_age = age;
				break;
			}
			cout << "��������������룡" << endl;
		}

		cout << "��������ϵ�绰" << endl;
		string phone;
		cin >> phone;
		book->person[res].p_phone = phone;

		cout << "�������ַ" << endl;
		string address;
		cin >> address;
		book->person[res].p_address = address;

		cout << "�����뱸ע" << endl;
		string note;
		cin >> note;
		book->person[res].p_note = note;
		cout << "��ӳɹ���" << endl;
	}
	else {
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanPerson(Book* book) {
	book->book_size = 0;
	cout << "��¼�Ѿ����" << endl;
	system("pause");
	system("cls");

}