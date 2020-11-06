#include <iostream>
#include "string"
#include "menu.h"

#define max 1000

using namespace std;

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


int main() {
    int select = 0;
    struct address_book book;
    book.curr_size = 0;

    while(true){
        show_menu();
        cin >> select;
        switch (select) {
            case 1://1.添加联系人
                add_person(&book);
                break;
            case 2://2.显示联系人
                show_person(&book);
                break;
            case 3://3.删除联系人
                delete_peron(&book);
                break;
            case 4://4.查找联系人
                check_person(&book);
                break;
            case 5://5.修改联系人
                modify_person(&book);
                break;
            case 6://6.清空联系人
                clean_person(&book);
                break;
            case 0://0.退出通讯录
                cout << "欢迎下次使用" << endl;
                return 0;
                break;
            default:
                break;

        }

    }




    return 0;
}
