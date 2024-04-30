#include <iostream>
#include <cstring> // Để sử dụng hàm strncpy_s

using namespace std;

// Khai báo cấu trúc phoneDirectory
typedef struct phoneDirectory {
    char hoTen[100];
    char soDienThoai[15];
    char diaChi[100];
}Phone;

// Hàm thêm một mục vào danh bạ
void addPhone(Phone* phone, int &count) {
    if (count >= 30) {
        cout << "Directory is full, can't add more.\n";
        return;
    }

    cout << "Enter full name: ";
    cin.ignore();
    cin.getline(phone[count].hoTen, 100);

    cout << "Enter number phone: ";
    cin.getline(phone[count].soDienThoai, 15);

    cout << "Enter address: ";
    cin.getline(phone[count].diaChi, 100);
    count++;
    cout << "Added successfully.\n";
}

// Hàm tìm và in thông tin theo số điện thoại
void findAndPrint(Phone* phone, int count) {
    char numberPhone[15];
    cout << "Enter the phone number to search: ";
    cin >> numberPhone;

    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (strcmp(phone[i].soDienThoai, numberPhone) == 0) {
            cout << "Informstion of number phone: " << numberPhone << ":\n";
            cout << "Full name: " << phone[i].hoTen << endl;
            cout << "Address: " << phone[i].diaChi << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Can't find number phone " << numberPhone << endl;
    }
}

// Hàm hiển thị menu và lựa chọn của người dùng
int dislayMenu() {
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

int main() {
    Phone phone[30]; // Danh sách danh bạ
    int countNumber = 0;   // Số lượng mục trong danh bạ

    int choise;
    do {
        choise = dislayMenu();

        switch (choise) {
            case 1:
                addPhone(phone, countNumber);
                break;
            case 2:
                findAndPrint(phone, countNumber);
                break;
            case 3:
                cout << "The program ends.\n";
                break;
            default:
                cout << "Invalid selection. Please try again.\n";
        }
    } while (choise != 3);

    return 0;
}
