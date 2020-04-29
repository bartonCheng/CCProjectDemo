#include<iostream> //标准输入输出流
#include<sqlite3.h> //sqlite头文件
#include <vector>  //转换编码
#include<Windows.h> //转换编码

using namespace std; //使用标准的std函数

//添加sqlite数据库
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

	//数据库操作
	//const char* dir = "C:\\project\\data.db";
	//同级目录创建data.db
	const char* dir = "data.db";
	createDB(dir);
	createTable(dir);
	deleteData(dir);
	insertData(dir);
	selectData(dir);
	updateData(dir);
	return 0;
}





//创建数据库
static int createDB(const char* s) {
	sqlite3* DB;
	//定义返回码exit
	int exit = 0;
	//执行语句 接收返回结果
	exit = sqlite3_open(s, &DB);
	//关闭连接
	sqlite3_close(DB);

	return 0;
}
//插入数据表
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
//插入数据
static int insertData(const char* s) {
	sqlite3* DB;

	char* messageError;
	int exit = sqlite3_open(s, &DB);

	string sql = "INSERT INTO USER(NAME,PHONE,AGE,ADDRESS,NOTE) VALUES('张三','18953856789',23,'北京市海淀区','同学');"
		"INSERT INTO USER(NAME,PHONE,AGE,ADDRESS,NOTE) VALUES('李四','18953234789',13,'北京市大兴区','同事');"
		"INSERT INTO USER(NAME,PHONE,AGE,ADDRESS,NOTE) VALUES('小花','18953856888',53,'北京市朝阳区','舍友');"
		"INSERT INTO USER(NAME,PHONE,AGE,ADDRESS,NOTE) VALUES('白马王子','13153856789',20,'北京市海淀区','同学');";
	sql = ASCII2UTF8(sql);

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "插入数据错误！" << endl;
		sqlite3_free(messageError);
	}
	else {
		cout << "数据插入成功！" << endl;
	}

	return 0;
}
//查询数据
static int selectData(const char* s) {
	sqlite3* DB;

	int exit = sqlite3_open(s, &DB);

	string sql = "SELECT * FROM USER";

	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}
//查询回调函数
static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
	//system("chcp 65001");
	SetConsoleOutputCP(65001);
	for (int i = 0; i < argc; i++) {
		cout << azColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;

	return 0;
}
//更新数据
static int updateData(const char* s) {
	sqlite3* DB;

	char* messageError;

	int exit = sqlite3_open(s, &DB);

	string sql = "UPDATE USER SET PHONE = '18956668888' WHERE NAME = '张三';";
	sql = ASCII2UTF8(sql);
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK) {
		cerr << "更新数据错误！" << endl;
		sqlite3_free(messageError);
	}
	else {
		cout << "数据更新成功！" << endl;
	}

	return 0;
}
//删除数据
static int deleteData(const char* s) {
	sqlite3* DB;

	int exit = sqlite3_open(s, &DB);

	string sql = "DELETE FROM USER;";

	exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);
	return 0;
}



//UTF-8转Unicode 
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
//unicode 转为 ascii 
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
//utf-8 转 ascii 
string UTF_82ASCII(string& strUtf8Code) {
	string strRet("");
	//先把 utf8 转为 unicode 
	wstring wstr = Utf82Unicode(strUtf8Code);
	//最后把 unicode 转为 ascii 
	strRet = WideByte2Acsi(wstr);
	return strRet;
}
//ascii 转 Unicode 
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
//Unicode 转 Utf8 
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
//ascii 转 Utf8 
string ASCII2UTF8(string& strAsciiCode) {
	string strRet("");
	//先把 ascii 转为 unicode 
	wstring wstr = Acsi2WideByte(strAsciiCode);
	//最后把 unicode 转为 utf8 
	strRet = Unicode2Utf8(wstr);
	return strRet;
}