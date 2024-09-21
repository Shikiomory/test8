#include <iostream>

using namespace std;
class mstring{

char *str;
int length;
public:
    mstring() {
        str = nullptr;
        length = 0;
    }
    mstring(const char *str) {
        length = strlen(str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++) {
            this->str[i] = str[i];
        }

        this->str[length] = '\0';
    }

    mstring(const mstring &other) {
        length = strlen(other.str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++) {
            this->str[i] = other.str[i];
        }

        this->str[length] = '\0';
        
    }

    mstring(mstring &&other) {
        this->length = other.length;
        this->str = other.str;

        other.str = nullptr;
    }
    ~mstring() {
        delete [] this->str;
    }

    mstring& operator = (const mstring &other) {
        if (this->str != nullptr) {
            delete [] str;
        }

        length = strlen(other.str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++) {
            this->str[i] = other.str[i];
        }

        this->str[length] = '\0';
        
        return *this;
    }

    mstring operator + (const mstring &other) {
        mstring newStr;
        int len1 = strlen(this->str);
        int len2 = strlen(other.str);
        newStr.length = len1 + len2;
        newStr.str = new char[len1 + len2 + 1];
        int i = 0;
        for(;i < len1; i++) {
            newStr.str[i] = this->str[i];
        }
        for(int j = 0; j < len2; j++, i++) {
            newStr.str[i] = other.str[j];
        }

        newStr.str[len1 + len2] = '\0';

        return newStr;
    }
    
    bool operator == (const mstring &other){
        if (this->length != other.length) {
            return false;
        }
        int i = 0;

        while (this->str[i] == other.str[i] && i < this->length) {
            i++;
        }
        return i == this->length ? true : false;
    }
    
    bool operator != (const mstring &other) {
        return !(this->operator==(other));
    }

    char operator [] (int index) {
        return this->str[index];
    }


    int Length(){
        return length;  
    }
    void print() {
        cout << str;
    }

private:
    int strlen(const char ch[]) {
        int i = 0;
        while (ch[i] != '\0') {
            ++i;
        }
        return i;
    }
};

int main() {
    mstring str("hello");
    mstring str2 = str;
    mstring res;
    res = str + str2;
    cout << endl << str.Length() << endl;
    cout << str2.Length() << endl;
    cout << res.Length() << endl;
    res.print();
    cout << '\n' << (str == res) << endl;
    cout << str[1] << endl;
    cout << "hello";
    return 0;
}
