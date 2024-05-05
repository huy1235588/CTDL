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
        next = NULL;
    }
};
typedef struct Phone Phone;
struct ListPhone
{
    Phone *head = new Phone;
    ListPhone()
    {
        head = NULL;
    }
    // Hàm thêm một mục vào danh bạ
    void addPhone(int count)
    {
        if (count >= 30)
        {
            cout << "Can't add more number phone" << endl;
            return;
        }

        Phone *newPhone = new Phone;
        cout << "Enter full name: ";
        // cin.ignore();
        // cin.getline(newPhone->hoTen, 100);
        getchar();
        scanf("%[^\n]s", newPhone->hoTen);
        cout << "Enter number phone: ";
        cin >> newPhone->soDienThoai;

        cout << "Enter address: ";
        // cin.ignore();
        // cin.getline(newPhone->diaChi, 100);
        getchar();
        scanf("%[^\n]s", newPhone->diaChi);

        if (head == NULL)
        {
            newPhone->next = NULL;
            head = newPhone;
        }
        else
        {
            newPhone->next = head;
            head = newPhone;
        }
        cout << "Added successfully.\n";
        count++;
    }

    // Hàm tìm và in thông tin theo số điện thoại
    void findAndPrint()
    {
        int numberPhone;
        cout << "Enter the phone number to search: ";
        cin >> numberPhone;

        Phone *currentPhone = head;
        while (currentPhone->soDienThoai != numberPhone)
        {
            currentPhone = currentPhone->next;
        }
        cout << "Full name: " << currentPhone->hoTen << endl;
        cout << "Number phone: " << currentPhone->soDienThoai << endl;
        cout << "Address: " << currentPhone->diaChi << endl;
        return;

        cout << "Can't find number phone " << numberPhone << endl;
    }

    // Giải phóng bộ nhớ
    void deleteListPhone()
    {
        while (head->next != NULL)
        {
            Phone *currentPhone = head;
            head = currentPhone->next;
            delete (currentPhone);
            // head->next = currentPhone->next->next;
        }
        delete (head);
        if (head == NULL)
        {
            cout << "Delete success";
        }
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
    ListPhone phone; // Danh sách danh bạ
    int choise, count = 0;
    do
    {
        choise = dislayMenu();

        switch (choise)
        {
        case 1:
            phone.addPhone(count);
            count++;
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
