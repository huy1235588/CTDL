#include "change_dns.hpp"

using namespace std;

std::string interface_name = "Ethernet";
std::vector<std::string> google_ipv4 = {"8.8.8.8", "8.8.4.4"};
std::vector<std::string> cloudflare_ipv4 = {"1.1.1.1", "1.0.0.1"};
std::vector<std::string> google_ipv6 = {"2001:4860:4860::8888", "2001:4860:4860::8844"};
std::vector<std::string> cloudflare_ipv6 = {"2606:4700:4700::1111", "2606:4700:4700::1001"};

void Submenu1();
void Submenu2();
void XuLySubMenu1();
void XuLySubMenu2();
int ChonMenu();

void Menu()
{
    cout << "=================MENU================\n";
    cout << "1. Change ipv4 DNS\n";
    cout << "2. Change ipv6 DNS\n";
    cout << "3. Add ipv4\n";
    cout << "4. Dao nguoc so\n";
    cout << "0. Exit!!!\n";
    cout << "=====================================\n";
}

int ChonMenu()
{
    int choice;
    cout << "Please enter your choice: ";
    cin >> choice;
    return choice;
}

void XuLyMenu(int chon)
{

    switch (chon)
    {
    case 1:
        Submenu1();
        XuLySubMenu1();
        break;
    case 2:
        Submenu2();
        XuLySubMenu2();
        break;
    case 0:
        cout << "Exit!!!\n";
        exit(1);
        break;
    default:
        cout << "Your choice is not valid!" << endl;
        break;
    }
}

void Submenu1()
{
    cout << "=================MENU================\n";
    cout << "1. Change to google server\n";
    cout << "2. Change to cloudflare server\n";
    cout << "0. Exit!!!\n";
    cout << "=====================================\n";
}
void Submenu2()
{
    cout << "=================MENU================\n";
    cout << "1. Change to google server\n";
    cout << "2. Change to cloudflare server\n";
    cout << "0. Exit!!!\n";
    cout << "=====================================\n";
}

void XuLySubMenu1()
{
    int chon = ChonMenu();

    switch (chon)
    {
    case 1:
        // change_dns_ipv4(interface_name, google_ipv4);
        fun1();
        break;
    case 2:
        // change_dns_ipv4(interface_name, cloudflare_ipv4);
        fun2();
        break;
    case 0:
        cout << "Exit!!!\n";
        exit(1);
        break;
    default:
        cout << "Your choice is not valid!" << endl;
        break;
    }
}

void XuLySubMenu2()
{
    int chon = ChonMenu();
    switch (chon)
    {
    case 1:
        // change_dns_ipv6(interface_name, google_ipv6);
        fun1();
        break;
    case 2:
        // change_dns_ipv6(interface_name, cloudflare_ipv6);
        fun2();
        break;
    case 0:
        cout << "Exit!!!\n";
        exit(1);
        break;
    default:
        cout << "Your choice is not valid!" << endl;
        break;
    }
}