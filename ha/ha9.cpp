#include <iostream>
#include <cstring> // Để sử dụng hàm strncpy_s

using namespace std;

// Khai báo cấu trúc phoneDirectory
struct Contact
{
    char *hoTen;
    char *diaChi;
    int soDienThoai;
    Contact *next;
};
typedef struct Contact Phone;
// Hàm thêm một mục vào danh bạ
void inputPhone(Phone *phone)
{
    char name[100];
    printf("Enter full name: ");
    cin.getline(phone->hoTen, 100);

    cout << "Enter number phone: ";
    cin >> phone->soDienThoai;

    cout << "Enter address: ";
    cin.ignore();
    cin.getline(phone->diaChi, 100);
    // cout << "Added successfully.\n";
}
void addPhone()
{
    Phone *phone = new Phone;
    inputPhone(phone);
    cout << sizeof(phone->hoTen);
}
// Hàm tìm và in thông tin theo số điện thoại
void findAndPrint(Phone *phone[30], int count)
{
    int numberPhone;
    cout << "Enter the phone number to search: ";
    cin >> numberPhone;

    bool foundPhone = false;
    while (/* condition */)
    {
        /* code */
    }

    if (!foundPhone)
    {
        cout << "Can't find number phone " << numberPhone << endl;
    }
}

// Hàm hiển thị menu và lựa chọn của người dùng
int dislayMenu()
{
    cout << "\n-------- MENU --------\n";
    cout << "1. Add phone to directory.\n";
    cout << "2. Find and print information of number phone.\n";
    cout << "3. Escape program.\n";
    cout << "--------------------===\n";
    cout << "Enter number: ";

    int choise;
    cin >> choise;
    return choise;
}

int main()
{
    Phone *phone;        // Danh sách danh bạ
    int countNumber = 0; // Số lượng mục trong danh bạ

    int choise;
    do
    {
        choise = dislayMenu();

        switch (choise)
        {
        case 1:
            addPhone();
            break;
        case 2:
            //findAndPrint(phone, countNumber);
            break;
        case 3:
            cout << "The program ends.\n";
            break;
        default:
            cout << "Invalid selection. Please try again.\n";
        }
    } while (choise != 3);

    for (int i = 0; i < countNumber; i++)
    {
        delete phone[i];
    }
    return 0;
}
