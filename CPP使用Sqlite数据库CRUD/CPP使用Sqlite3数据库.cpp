#include<iostream> //��׼���������
#include<sqlite3.h> //sqliteͷ�ļ�
#include <vector>  //ת������
#include<Windows.h> //ת������

using namespace std; //ʹ�ñ�׼��std����

//���sqlite���ݿ�
static int createDB(const char* s);
static int createTable(const char* s);
static int insertData(const char* s);
static int selectData(const char* s);
static int callback(void* NotUsed, int argc, char** argv, char** azColName);
static int updateData(const char* s);
static int deleteData(const char* s);

string ASCII2UTF8(string& strAsciiCode);

int main(int argc, char** argv, char** env)
{

	//���ݿ����
	//const char* dir = "C:\\project\\data.db";
	//ͬ��Ŀ¼����data.db
	const char* dir = "data.db";
	createDB(dir);
	createTable(dir);
	deleteData(dir);
	insertData(dir);
	selectData(dir);
	updateData(dir);
	return 0;
}





//�������ݿ�
static int createDB(const char* s) {
	sqlite3* DB;
	//���巵����exit
	int exit = 0;
	//ִ����� ���շ��ؽ��
	exit = sqlite3_open(s, &DB);
	//�ر�����
	sqlite3_close(DB);

	return 0;
}
//�������ݱ�
static int createTable(const char* s) {
	sqlite3* DB;

	string sql = "CREATE TABLE IF NOT EXISTS USER ("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT,"
		"NAME VARCHAR NOT NULL,"
		"PHONE VARCHAR NOT NULL,"
		"AGE INT NOT NULL,"
		"ADDRESS CHAR(50) NOT NULL,"
		"NOTE CHAR(20) NOT NULL); ";
	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		char* messageError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK) {
			cerr << "Error Create DB" << endl;
			sqlite3_free(messageError);
		}
		else {
			cout << "Table Create Success!" << endl;
		}

		sqlite3_close(DB);
	}
	catch (const exception& e)
	{
		cerr << e.what();
	}
	return 0;
}
//��������
static int insertData(const char* s) {
	sqlite3* DB;

	char* messageError;
	int exit = sqlite3_open(s, &DB);

	string sql = "INSERT INTO USER(NAME,PHONE,AGE,ADDRESS,NOTE) VALUES('����','18953856789',23,'�����к�����','ͬѧ');"
		"INSERT INTO USER(NAME,PHONE,AGE,ADDRESS,NOTE) VALUES('����','18953234789',13,'�����д�����','ͬ��');"
		"INSERT INTO USER(NAME,PHONE,AGE,ADDRESS,NOTE) VALUES('С��','18953856888',53,'�����г�����','����');"
		"INSERT INTO USER(NAME,PHONE,AGE,ADDRESS,NOTE) VALUES('��������','13153856789',20,'�����к�����','ͬѧ');";
	sql = ASCII2UTF8(sql);

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "�������ݴ���" << endl;
		sqlite3_free(messageError);
	}
	else {
		cout << "���ݲ���ɹ���" << endl;
	}

	return 0;
}
//��ѯ����
static int selectData(const char* s) {
	sqlite3* DB;

	int exit = sqlite3_open(s, &DB);

	string sql = "SELECT * FROM USER";

	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}
//��ѯ�ص�����
static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	//system("chcp 65001");
	SetConsoleOutputCP(65001);
	for (int i = 0; i < argc; i++) {
		cout << azColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;

	return 0;
}
//��������
static int updateData(const char* s) {
	sqlite3* DB;

	char* messageError;

	int exit = sqlite3_open(s, &DB);

	string sql = "UPDATE USER SET PHONE = '18956668888' WHERE NAME = '����';";
	sql = ASCII2UTF8(sql);
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "�������ݴ���" << endl;
		sqlite3_free(messageError);
	}
	else {
		cout << "���ݸ��³ɹ���" << endl;
	}

	return 0;
}
//ɾ������
static int deleteData(const char* s) {
	sqlite3* DB;

	int exit = sqlite3_open(s, &DB);

	string sql = "DELETE FROM USER;";

	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
	return 0;
}



//UTF-8תUnicode 
std::wstring Utf82Unicode(const std::string& utf8string) {
	int widesize = ::MultiByteToWideChar(CP_UTF8, 0, utf8string.c_str(), -1, NULL, 0);
	if (widesize == ERROR_NO_UNICODE_TRANSLATION) {
		throw std::exception("Invalid UTF-8 sequence.");
	}
	if (widesize == 0) {
		throw std::exception("Error in conversion.");
	}
	std::vector<wchar_t> resultstring(widesize);
	int convresult = ::MultiByteToWideChar(CP_UTF8, 0, utf8string.c_str(), -1, &resultstring[0], widesize);
	if (convresult != widesize) {
		throw std::exception("La falla!");
	}
	return std::wstring(&resultstring[0]);
}
//unicode תΪ ascii 
string WideByte2Acsi(wstring& wstrcode) {
	int asciisize = ::WideCharToMultiByte(CP_OEMCP, 0, wstrcode.c_str(), -1, NULL, 0, NULL, NULL);
	if (asciisize == ERROR_NO_UNICODE_TRANSLATION) {
		throw std::exception("Invalid UTF-8 sequence.");
	}
	if (asciisize == 0) {
		throw std::exception("Error in conversion.");
	}
	std::vector<char> resultstring(asciisize);
	int convresult = ::WideCharToMultiByte(CP_OEMCP, 0, wstrcode.c_str(), -1, &resultstring[0], asciisize, NULL, NULL);
	if (convresult != asciisize) {
		throw std::exception("La falla!");
	}
	return std::string(&resultstring[0]);
}
//utf-8 ת ascii 
string UTF_82ASCII(string& strUtf8Code) {
	string strRet("");
	//�Ȱ� utf8 תΪ unicode 
	wstring wstr = Utf82Unicode(strUtf8Code);
	//���� unicode תΪ ascii 
	strRet = WideByte2Acsi(wstr);
	return strRet;
}
//ascii ת Unicode 
wstring Acsi2WideByte(string& strascii) {
	int widesize = MultiByteToWideChar(CP_ACP, 0, (char*)strascii.c_str(), -1, NULL, 0);
	if (widesize == ERROR_NO_UNICODE_TRANSLATION) {
		throw std::exception("Invalid UTF-8 sequence.");
	}
	if (widesize == 0) {
		throw std::exception("Error in conversion.");
	}
	std::vector<wchar_t> resultstring(widesize);
	int convresult = MultiByteToWideChar(CP_ACP, 0, (char*)strascii.c_str(), -1, &resultstring[0], widesize);
	if (convresult != widesize) {
		throw std::exception("La falla!");
	}
	return std::wstring(&resultstring[0]);
}
//Unicode ת Utf8 
std::string Unicode2Utf8(const std::wstring& widestring) {
	int utf8size = ::WideCharToMultiByte(CP_UTF8, 0, widestring.c_str(), -1, NULL, 0, NULL, NULL);
	if (utf8size == 0) {
		throw std::exception("Error in conversion.");
	}
	std::vector<char> resultstring(utf8size);
	int convresult = ::WideCharToMultiByte(CP_UTF8, 0, widestring.c_str(), -1, &resultstring[0], utf8size, NULL, NULL);
	if (convresult != utf8size) {
		throw std::exception("La falla!");
	}
	return std::string(&resultstring[0]);
}
//ascii ת Utf8 
string ASCII2UTF8(string& strAsciiCode) {
	string strRet("");
	//�Ȱ� ascii תΪ unicode 
	wstring wstr = Acsi2WideByte(strAsciiCode);
	//���� unicode תΪ utf8 
	strRet = Unicode2Utf8(wstr);
	return strRet;
}