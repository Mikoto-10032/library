#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
	void* ptr;
	struct Node* prev;
	struct Node* next;
}Node;
//创建节点
Node* create_node(void *ptr)
{
	Node* node = malloc(sizeof(Node));
	node->prev = node;
	node->next = node;
	node->ptr = ptr;
	return node;
}

typedef struct List
{
	Node* head;
	size_t size;
}List;
//创建带空节点的链表
List* create_list(void)
{
	List* list = malloc(sizeof(List));
	list->head = create_node(NULL);
	list->size = 0;
	return list;
}
//在next节点和prev节点之间，添加数据为ptr节点
void _add_list(Node* prev,Node* next,void* ptr)
{
	Node* node = create_node(ptr);
	prev->next = node;
	node->prev = prev;
	next->prev = node;
	node->next = next;
}
//删除node节点
void _del_list(Node* node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
}
//寻找下标为index（从0开始）的节点
Node* _index_list(List* list,int index)
{
	if(0 > index || index >= list->size)
		return NULL;
	Node* node = list->head->next;
	if(index < list->size/2)
		while(index--) node = node->next;
	else
		while(index++ <= list->size) node = node->prev;
	return node;
}
//寻找数据为value的节点，cmp为函数指针，存放比较的内容
Node* _value_list(List* list,void* value,int (*cmp)(void*,void*))
{
	for(Node* n=list->head->next; n!=list->head; n=n->next)
	{
		if(0 == cmp(n->ptr,value))
			return n;
	}
	return NULL;
}
//头添加
void add_head_list(List* list,void* ptr)
{
	_add_list(list->head,list->head->next,ptr);
	list->size++;
}
//尾添加
void add_tail_list(List* list,void *ptr)
{
	_add_list(list->head->prev,list->head,ptr);
	list->size--;
}
//指定位置添加节点
bool add_index_list(List* list,int index,void* ptr)
{
	Node* node = _index_list(list,index);
	if(NULL == node)
		return false;
	_add_list(node->prev,node,ptr);
	list->size++;
	return true;
}
//指定value值前添加节点
bool add_value_list(List* list,void* value,void* ptr,int (*cmp)(void*,void*))
{
	Node* node = _value_list(list,value,cmp);
	if(NULL == node)
		return false;
	_add_list(node->prev,node,ptr);
	list->size++;
	return true;
}
//头删除
bool del_head_list(List* list)
{
	if(0 >= list->size)
		return false;
	_del_list(list->head->next);
	list->size--;
	return true;
}
//尾删除
bool del_tail_list(List* list)
{
	if(0 >= list->size)
		return false;
	_del_list(list->head->prev);
	list->size--;
	return true;
}
//指定位置删除
bool del_index_list(List* list,int index)
{
	Node* node = _index_list(list,index);
	if(NULL == node)
		return false;
	_del_list(node);
	list->size--;
	return true;
}
//指定数据删除
bool del_value_list(List* list,void* value,int (*cmp)(void*, void*))
{
	Node* node = _value_list(list,value,cmp);
	if(NULL == node)
		return false;
	_del_list(node);
	list->size--;
	return true;
}
//遍历
void show_list(List* list,void(*show)(void*))
{
	printf("List:%p Node:%d\n",list,list->size);
	for(Node* n=list->head->next; n!=list->head; n=n->next)
	{
		show(n->ptr);
	}
	puts("*********显示完毕*********");
}
/*
int main(int argc,const char* argv[])
{
	typedef struct Student
	{
		char name[20];
		char sex;
		int number;
	}Student;
//遍历数据
	void show_stu(void* ptr)
	{
		Student* stu = ptr;
		printf("name:%s sex:%s number:%d\n",stu->name,stu->sex?"男":"女",stu->number);
	}
//比较姓名相等
	int cmp(void* p1,void* p2)
	{
		Student *stu1 = p1, *stu2=p2;
		return strcmp(stu1->name,stu2->name);
	}

	List* list = create_list();
	for(int i=0;i<10;i++)
	{
		Student* stu = malloc(sizeof(Student));
		sprintf(stu->name,"hehe%d",i);
		stu->sex = i%2;
		stu->number = 10010+i;
		add_head_list(list,stu);
	}
	Student stu = {"xixi***",1,12345};
	Student stu2 = {"hehe9",1,12345};
	add_value_list(list,&stu2,&stu,cmp);
	//add_index_list(list,0,&stu);
	show_list(list,show_stu);
	//del_head_list(list);
	//del_tail_list(list);
	//del_index_list(list,10);
	del_value_list(list,&stu,cmp);
	show_list(list,show_stu);
}*/
