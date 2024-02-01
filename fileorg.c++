#include <iostream>
#include <set>
using namespace std;
int main()
{
    string fname, command;
    set<string> files;
    while (true)
    {
        cout << ">> ";
        cin >> command;
        if (command == "create" or command == "insert" or command == "touch")
        {
            cin >> fname;
            auto it = files.find(fname);
            if (it != files.end())
            {
                cout << "File already exists." << endl;
            }
            else
            {
                files.insert(fname);
            }
        }
        else if (command == "display" or command == "show" or command == "ls")
        {
            for (auto file : files)
            {
                cout << file << endl;
            }
        }
        else if (command == "delete" or command == "remove" or command == "rm")
        {
            cin >> fname;
            auto it = files.find(fname);
            if (it != files.end())
            {
                files.erase(it);
            }
            else
            {
                cout << "File not found." << endl;
            }
        }
        else if (command == "exit" or command == "quit" or command == "q")
        {
            break;
        }
        else
        {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}
