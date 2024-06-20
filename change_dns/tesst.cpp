#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

void Menu()
{
   system("cls");

   cout << "=================MENU================\n";
   cout << "1. Change ipv4 DNS\n";
   cout << "2. Change ipv6 DNS\n";
   cout << "3. Add ipv4\n";
   cout << "4. Dao nguoc so\n";
   cout << "0. Exit!!!\n";
   cout << "=====================================\n";
}

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

int main()
{
   std::string interface_name = "Ethernet";
   std::vector<std::string> google_ipv4 = {"8.8.8.8", "8.8.4.4"};
   std::vector<std::string> cloudflare_ipv4 = {"1.1.1.1", "1.0.0.1"};
   std::vector<std::string> google_ipv6 = {"2001:4860:4860::8888", "2001:4860:4860::8844"};
   std::vector<std::string> cloudflare_ipv6 = {"2606:4700:4700::1111", "2606:4700:4700::1001"};

   change_dns_ipv4(interface_name, google_ipv4);
   Menu();

   return 0;
}