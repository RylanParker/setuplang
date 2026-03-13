#include <iostream>
#include <windows.h>
#include <Lmcons.h>
#include <string>

using namespace std;

string get_user()
{
    wchar_t name[260];
    DWORD size = 260;

    if (GetUserNameW(name, &size)) {
        char ch[260];
        char DefChar = ' ';
        WideCharToMultiByte(CP_UTF8, 0, name, -1, ch, 260, NULL, NULL);
        return string(ch);
    } else {
        std::cout << "Failed to get username.\n";
    }

    return "";
}

void create_cpp()
{
    string user_name = get_user();
    cout << "username: " << user_name << "\n";
    string path = "C:\\Users\\" + user_name + "\\OneDrive\\Desktop\\testfolder";

    char buf[512];
    snprintf(buf, sizeof(buf), "mkdir \"%s\"; cd %s; echo. > \"%s\\test.cpp\"", path.c_str(), path.c_str());
    popen(buf, "r");
}

int main()
{
    create_cpp();

    return 0;
}