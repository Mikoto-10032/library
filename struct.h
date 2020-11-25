#ifndef STRUCT_H
#define STRUCT_H

//读者
typedef struct Reader
{
	char name[20];			//姓名
	int id;					//帐号
	char pwd[20];			//密码
	int money;				//押金
	int book_num;			//借书数量
	char id_card[20];		//身份证号
	int tel[13];				//联系电话
	Book* lend_book;		//已借的图书
}Reader;

//图书
typedef struct Book
{
	char name[20];			//书名
	char number[20];		//编号
	char type[20];			//种类
	char author[20];		//作者
	int flag;					//借阅情况
	int lend_time;			//借阅总时长
	int renew_cnt;			//续借次数
	char press[20];			//出版社
	int year;					//年份
	int price;				//价格
}Book;

//图书管理员
typedef struct Manager		
{
	int id;
	char pwd[20];
}Manager;

//采编员
typedef struct Editor
{
	int id;
	char pwd[20];
}Editor;

//系统管理员
typedef struct Admin
{
	int id;
	char pwd[20];
}Admin;

#endif//STRUCT_H
