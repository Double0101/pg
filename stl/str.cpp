#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;
    cout << str << endl;
    printf("%s\n", str.c_str());
    string::iterator si = str.begin();

    *(si+2) = '\0';
    cout << str.length() << endl;
    cout << str << endl;

    string ss = "Thanks for your smile.";

    cout << ss.substr(0, 5) << endl;
    string su = "your";

    if (ss.find(su) != string::npos)
        cout << ss.find(su) << endl;

    string r = " you";

    ss.replace(5, 1, r);

    cout << ss << endl;

    return 0;
}