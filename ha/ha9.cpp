#include <iostream>
#include <cstring> // Để sử dụng hàm strncpy_s

using namespace std;

// Khai báo cấu trúc phoneDirectory
struct Phone
{
    char hoTen[50];
    char diaChi[50];
    int soDienThoai;
    Phone *next;
    Phone()
    {
        soDienThoai = 0;
        next = NULL;
    }
};
typedef struct Phone Phone;
struct ListPhone
{
    Phone *head = new Phone;
    Phone *tail = new Phone;
    /*     ListPhone()
        {
            head = NULL;
            tail = NULL;
        } */
    // Hàm thêm một mục vào danh bạ
    void addPhone()
    {
        Phone *newPhone = new Phone;
        cout << "Enter full name: ";
        cin.ignore();
        cin.getline(newPhone->hoTen, 100);

        cout << "Enter number phone: ";
        cin >> newPhone->soDienThoai;

        cout << "Enter address: ";
        cin.ignore();
        cin.getline(newPhone->diaChi, 100);
        if (head == NULL)
        {
            head->next = NULL;
            head = newPhone;
        }
        else
        {
            tail->next = newPhone;
        }
        tail = newPhone;
        cout << "Added successfully.\n";
    }

    // Hàm tìm và in thông tin theo số điện thoại
    void findAndPrint()
    {
        int numberPhone;
        cout << "Enter the phone number to search: ";
        cin >> numberPhone;

        Phone *currentPhone = head;
        while (currentPhone->soDienThoai == numberPhone)
        {
            currentPhone = currentPhone->next;
        }
        cout << "Full name: " << currentPhone->hoTen;
        cout << "Number phone: " << currentPhone->soDienThoai;
        cout << "Address: " << currentPhone->diaChi;
        return;

        cout << "Can't find number phone " << numberPhone << endl;
    }

    // Giải phóng bộ nhớ
    void deleteListPhone()
    {
        while (head->next != NULL)
        {
            Phone *currentPhone = head->next;
            head = currentPhone->next;
            head->next = currentPhone;
            delete (currentPhone);
        }
        delete (head);
    }
};
typedef struct ListPhone ListPhone;

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
    ListPhone phone;     // Danh sách danh bạ
    int countNumber = 0; // Số lượng mục trong danh bạ

    int choise;
    do
    {
        choise = dislayMenu();

        switch (choise)
        {
        case 1:
            phone.addPhone();
            break;
        case 2:
            phone.findAndPrint();
            break;
        case 3:
            cout << "The program ends.\n";
            break;
        default:
            cout << "Invalid selection. Please try again.\n";
        }
    } while (choise != 3);
    phone.deleteListPhone();
    return 0;
}
