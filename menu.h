//
// Created by 郑绮欣 on 2020/11/6.
//

#ifndef MANAGEMENT_SYSTEM_MENU_H
#define MANAGEMENT_SYSTEM_MENU_H
#include "iostream"
#include "string"

using namespace std;


void add_person(struct address_book * book);
void show_menu();
int is_exist(struct address_book * book, string name);
void delete_peron(struct address_book * book);
void check_person(struct address_book * book);
void modify_person(struct address_book * book);
void clean_person(struct address_book * book);
void show_person(struct address_book * book);

#endif //MANAGEMENT_SYSTEM_MENU_H
