#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;


void change_dns_ipv4(const string &interface, const vector<string> &new_dns)
{
    string primary_command = "netsh interface ipv4 set dns name=\"" + interface + "\" source=static addr=" + new_dns[0] + " primary";
    system(primary_command.c_str());
    for (size_t i = 1; i < new_dns.size(); ++i)
    {
        string secondary_command = "netsh interface ipv4 add dns name=\"" + interface + "\" addr=" + new_dns[i] + " index=2";
        system(secondary_command.c_str());
    }

    cout << "\nDNS ipv4 have been changed to: ";
    for (const auto &dns : new_dns)
    {
        cout << dns << " ";
    }
    cout << "for interface " << interface << endl;
}

void change_dns_ipv6(const string &interface, const vector<string> &new_dns)
{
    string primary_command = "netsh interface ipv6 set dns name=\"" + interface + "\" source=static addr=" + new_dns[0] + " primary";
    system(primary_command.c_str());
    for (size_t i = 1; i < new_dns.size(); ++i)
    {
        string secondary_command = "netsh interface ipv6 add dns name=\"" + interface + "\" addr=" + new_dns[i] + " index=2";
        system(secondary_command.c_str());
    }

    cout << "\nDNS ipv6 have been changed to: ";
    for (const auto &dns : new_dns)
    {
        cout << dns << " ";
    }
    cout << "for interface " << interface << endl;
}

void fun1() { cout << "XuLySubMenu1 processing...\n"; }
void fun2() { cout << "XuLySubMenu2 processing...\n"; }