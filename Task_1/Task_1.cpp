#include <iostream>
using namespace std;

class MyString
{
private:
    char* str;
    int length;

    static unsigned int createdObjects;
public:
    MyString();
    MyString(unsigned int len);
    MyString(const char* s);
    MyString(const initializer_list<char>& list);
    MyString(const MyString& obj);
    MyString(MyString&& obj);
    ~MyString();

    void Init(const char* s);
    void Init(const MyString& obj);
    void Print();

    void MyStrCopy(MyString& target);
    bool MyStrStr(const char* s);
    int MyChr(char c);
    int MyStrLen();
    void MyStrCat(const char* s);
    void MyStrCat(MyString& s);
    void DelChr(char c);
    int MyStrCmp(MyString& s);

    char* GetStr();
    int Getlength();

    MyString& operator=(const MyString& obj);
    MyString& operator=(MyString&& obj);

    static void InfoAboutObjects();
};

MyString::MyString()
{
    length = 80;
    str = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        str[i] = ' ';
    }
    str[length] = '\0';

    ++createdObjects;
}

MyString::MyString(unsigned int len)
{
    length = len;
    str = new char[length];

    for (int i = 0; i < length; i++)
    {
        str[i] = ' ';
    }

    ++createdObjects;
}

MyString::MyString(const char* s)
{
    length = 0;

    while (s[length] != '\0')
    {
        ++length;
    }
    str = new char[length + 1];
    for (int i = 0; i <= length; ++i)
    {
        str[i] = s[i];
    }
    str[length] = '\0';

    ++createdObjects;
}

MyString::MyString(const initializer_list<char>& list) 
{
    length = list.size();
    str = new char[length + 1];

    int i = 0;
    for (auto element: list)
    {
        str[i] = element;
        i++;
    }
    str[length] = '\0';

    ++createdObjects;
}

MyString::MyString(const MyString& obj)
{
    if (str != nullptr)
        delete[] str;

    length = obj.length;
    str = new char[length + 1];

    for (int i = 0; i <= length; i++)
    {
        str[i] = obj.str[i];
    }
}

MyString::MyString(MyString&& obj)
{
    length = obj.length;
    str = obj.str;

    obj.length = 0;
    obj.str = nullptr;
}

MyString::~MyString()
{
    delete[] str;
    --createdObjects;
}

void MyString::Init(const char* s)
{
    delete[] str;

    length = strlen(s);

    this->str = new char[length + 1];
    strcpy_s(this->str, length + 1, s);
}

void MyString::Init(const MyString& obj)
{
    delete[] str;

    length = obj.length;
    str = new char[length + 1];

    for (int i = 0; i <= length; i++)
    {
        str[i] = obj.str[i];
    }
}

void MyString::Print()
{
    cout << str << "\n";
}

void MyString::MyStrCopy(MyString& target)
{
    delete[] target.str;

    target.length = length;
    target.str = new char[length + 1];

    for (int i = 0; i <= length; i++)
    {
        target.str[i] = str[i];
    }
}

bool MyString::MyStrStr(const char* s)
{
    int sLength = strlen(s);
    if (sLength > length)
    {
        return false;
    }
    for (int i = 0; i <= length - sLength; ++i)
    {
        bool found = true;
        for (int j = 0; j < sLength; ++j)
        {
            if (str[i + j] != s[j])
            {
                found = false;
                break;
            }
        }
        if (found) {
            return true;
        }
    }
    return false;
}

int MyString::MyChr(char c)
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] == c)
        {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen()
{
    return length;
}

void MyString::MyStrCat(const char* s)
{
    int newLength = length + strlen(s);
    char* newStr = new char[newLength + 1];
    for (int i = 0; i < length; i++)
    {
        newStr[i] = str[i];
    }
    for (int i = 0; i <= strlen(s); i++)
    {
        newStr[length + i] = s[i];
    }
    delete[] str;
    str = newStr;
    length = newLength;
}

void MyString::MyStrCat(MyString& s)
{
    int newLength = length + s.Getlength();
    char* newStr = new char[newLength + 1];
    for (int i = 0; i < length; i++)
    {
        newStr[i] = str[i];
    }
    for (int i = 0; i <= s.Getlength(); i++)
    {
        newStr[length + i] = s.GetStr()[i];
    }
    delete[] str;
    str = newStr;
    length = newLength;
}

void MyString::DelChr(char c)
{
    int newLength = 0;
    for (int i = 0; i < length; ++i)
    {
        if (str[i] != c)
        {
            ++newLength;
        }
    }
    char* newStr = new char[newLength + 1];
    int j = 0;
    for (int i = 0; i < length; ++i)
    {
        if (str[i] != c)
        {
            newStr[j++] = str[i];
        }
    }
    newStr[newLength] = '\0';
    delete[] str;
    str = newStr;
    length = newLength;
}

int MyString::MyStrCmp(MyString& s)
{
    if (length < s.length)
        return -1;
    else if (length > s.length)
        return 1;
    else
        return 0;
}

char* MyString::GetStr()
{
    return str;
}

int MyString::Getlength()
{
    return length;
}

MyString& MyString::operator=(const MyString& obj)
{
    if (this != &obj)
    {
        if (str != nullptr)
            delete[] str;

        length = obj.length;
        str = new char[length + 1];

        for (int i = 0; i <= length; i++)
        {
            str[i] = obj.str[i];
        }
    }
    return *this;
}

MyString& MyString::operator=(MyString&& obj)
{
    if (this != &obj)
    {
        if (str != nullptr)
            delete[] str;

        length = obj.length;
        str = obj.str;

        obj.length = 0;
        obj.str = nullptr;
    }
    return *this;
}

void MyString::InfoAboutObjects()
{
    cout << "Created objects: " << MyString::createdObjects << "\n";
}

unsigned int MyString::createdObjects = 0U;

int main()
{
    MyString obj1("Vasya");
    MyString obj2("Petya");

    cout << "Print:\n";

    obj1.Print();
    obj2.Print();

    cout << "\n";

    obj1.MyStrCopy(obj2);

    cout << "Copy:\n";

    obj1.Print();
    obj2.Print();

    cout << "\n";

    obj1.Init("Vasya is going home. ");

    cout << "Search substring in string:\n";

    obj1.Print();
    obj2.Print();

    cout << "\n";

    cout << boolalpha << obj1.MyStrStr(obj2.GetStr()) << "\n\n";

    cout << "Search a char in a string ('.'):\n";

    obj1.Print();

    cout << obj1.MyChr('.') << "\n\n";

    cout << "String length:\n";

    obj1.Print();

    cout << obj1.MyStrLen() << "\n\n";

    obj2.Init("Petya is doing the same.");

    cout << "String concatenation:\n";

    obj1.Print();
    obj2.Print();

    obj1.MyStrCat(obj2);

    cout << "\n";

    obj1.Print();

    cout << "\nDelete a char in a string ('.'):\n";

    obj1.Print();

    obj1.DelChr('.');

    obj1.Print();

    cout << "\nString compare:\n";

    obj1.Print();
    obj2.Print();
    
    cout << "\n" << obj1.MyStrCmp(obj2) << "\n\n";

    cout << "String1 and String2:" << "\n";

    obj1.Print();
    obj2.Print();

    obj1 = obj2;

    cout << "\nString1 = String2:" << "\n";

    obj1.Print();
    obj2.Print();

    cout << "\nMyString obj{'A', 'L', 'E', 'X'};\n";

    MyString obj{ 'A', 'L', 'E', 'X' };

    obj.Print();

    cout << "\n";

    MyString::InfoAboutObjects();
}