//
// Created by 郑绮欣 on 2020/11/6.
//
#include "menu.h"
#include "iostream"
#include "string"
using namespace std;
#define max 1000

struct person{
    string name;
    int sex;
    int age;
    string phone;
    string addr;
};

struct address_book{
    struct person person_arr[max];
    int curr_size;
};

//菜单界面
void show_menu(){
    cout << "**********************" << endl;
    cout << "***** 1.添加联系人 *****" << endl;
    cout << "***** 2.显示联系人 *****" << endl;
    cout << "***** 3.删除联系人 *****" << endl;
    cout << "***** 4.查找联系人 *****" << endl;
    cout << "***** 5.修改联系人 *****" << endl;
    cout << "***** 6.清空联系人 *****" << endl;
    cout << "***** 0.退出通讯录 *****" << endl;
    cout << "**********************" << endl;
}

//添加联系人
void add_person(struct address_book * book){
    if (book->curr_size == max){
        cout << "添加路已满人" << endl;
        return;
    }
    else{
        cout << "输入姓名：" << endl;
        string name;
        cin >> name;
        book->person_arr[book->curr_size].name = name;

        cout << "输入性别：(男1女2)" << endl;
        int sex = 0;
        while (true){
            cin >> sex;
            if (sex == 1 || sex == 2){
                book->person_arr[book->curr_size].sex = sex;
                break;
            }
            cout << "输入有误，重新输入" << endl;
        }

        cout << "输入年龄：" << endl;
        int age;
        cin >> age;
        book->person_arr[book->curr_size].age = age;

        cout << "输入电话：" << endl;
        string phone;
        cin >> phone;
        book->person_arr[book->curr_size].phone = phone;

        cout << "输入住址：" << endl;
        string addr;
        cin >> addr;
        book->person_arr[book->curr_size].addr = addr;

        book->curr_size ++;
        cout << "添加成功" << endl;


    }

}

//显示联系人
void show_person(struct address_book * book){
    if(book->curr_size == 0){
        cout << "当前通讯录为空" << endl;
    }
    else{
        for (int i = 0 ; i < book->curr_size; i++){
            cout << "姓名：" << book->person_arr[i].name <<"\t";
            cout << "年龄：" << book->person_arr[i].age  << "\t";
            cout << "性别：" << (book->person_arr[i].sex == 1 ? "男":"女" )<< "\t";
            cout << "电话：" << book->person_arr[i].phone <<"\t";
            cout << "地址：" << book->person_arr[i].addr <<endl;
        }
    }
}

//检测联系人是否存在
int is_exist(struct address_book * book, string name){
    for (int i = 0; i < book->curr_size; i++){
        if (name == book->person_arr[i].name){
            return i;
        }
    }
    return -1;
}

//删除联系人
void delete_peron(struct address_book * book){
    cout << "输入删除联系人姓名" << endl;
    string name;
    cin >> name;
    int ref = is_exist(book, name);
    if (ref == -1){
        cout << "无此联系人" << endl;
    }
    else {

        for(int i = ref; i < book->curr_size; i++){
            book->person_arr[i] = book->person_arr[i+1];
        }
        book->curr_size --;
        cout << "已删除此联系人" << endl;
    }

}

//查找联系人
void check_person(struct address_book * book){
    cout << "输入你要查找的联系人" << endl;
    string name;
    cin >> name;
    int ref = is_exist(book, name);
    if(ref != -1){//找到了
        cout << "姓名：" << book->person_arr[ref].name <<"\t";
        cout << "年龄：" << book->person_arr[ref].age  << "\t";
        cout << "性别：" << (book->person_arr[ref].sex == 1 ? "男":"女" )<< "\t";
        cout << "电话：" << book->person_arr[ref].phone <<"\t";
        cout << "地址：" << book->person_arr[ref].addr <<endl;
    }
    else{//没找到
        cout << "未找到你要查找的联系人" << endl;
    }
}

//修改
void modify_person(struct address_book * book){
    cout << "输入你要修改的联系人" << endl;
    string name;
    cin >> name;
    int ref = is_exist(book, name);

    if(ref != -1){//找到了
        cout << "输入你要修改的联系人年龄" << endl;
        int age;
        cin >> age;
        book->person_arr[ref].age = age;

        cout << "输入你要修改的联系人性别(男1女2)" << endl;
        int sex;
        cin >> sex;
        book->person_arr[ref].sex = sex;

        cout << "输入你要修改的联系人电话" << endl;
        string phone;
        cin >> phone;
        book->person_arr[ref].phone = phone;

        cout << "输入你要修改的联系人地址" << endl;
        string addr;
        cin >> addr;
        book->person_arr[ref].addr = addr;

        cout << "姓名：" << book->person_arr[ref].name  << "\t";
        cout << "年龄：" << book->person_arr[ref].age  << "\t";
        cout << "性别：" << (book->person_arr[ref].sex == 1 ? "男":"女" )<< "\t";
        cout << "电话：" << book->person_arr[ref].phone <<"\t";
        cout << "地址：" << book->person_arr[ref].addr <<endl;
    }
    else{//没找到
        cout << "未找到你要查找的联系人" << endl;
    }
}

//清空通讯录
void clean_person(struct address_book * book){
    book->curr_size = 0;
    cout << "通讯录已清空" << endl;
}
