#include <iostream>
#include <windows.h>
#include <Lmcons.h>
#include <string>

using namespace std;

string get_user()
{
    TCHAR name[UNLEN + 1];
    DWORD size = UNLEN + 1;

    // Get the username
    if (GetUserName((TCHAR*)name, &size)) {
        std::wcout << L"Hello, " << name << L"!\n"; 

        char ch[260];
        char DefChar = ' ';
        WideCharToMultiByte(CP_ACP,0, name,-1, ch,260,&DefChar, NULL);

        return string(ch);
    } else {
        std::cout << "Failed to get username.\n";
    }

    return "";
}

void create_cpp()
{
    string user_name = get_user();
    string path = "C:\\Users\\" + user_name + "\\Desktop";

    char buf[512];
    snprintf(buf, sizeof(buf), "cd %s; echo. > test.cpp", path.c_str());
    popen(buf, "r");
}

int main()
{
    create_cpp();

    return 0;
}