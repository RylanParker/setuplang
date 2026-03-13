#include <iostream>
#include <windows.h>
#include <Lmcons.h>
#include <string>
#include <shlobj.h>
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
    char buf[512];

    string user_name = get_user();
    cout << "username: " << user_name << "\n";

    char desktopPath[MAX_PATH];
    SHGetFolderPathA(NULL, CSIDL_DESKTOPDIRECTORY, NULL, 0, desktopPath);

    string path = string(desktopPath) + "\\testfolder";
    cout << "path: " << path << "\n";
    snprintf(buf, sizeof(buf), "mkdir \"%s\" && type nul > \"%s\\test.cpp\"", path.c_str(), path.c_str());
    popen(buf, "r");
}

int main()
{
    create_cpp();

    return 0;
}