#include <iostream> 
#include <vector> 
using namespace std;

class Strang {
private:
    vector<char> str;

public:
    Strang() : str({ 0 }) {} // конструктор по умолчанию

    Strang(const vector<char>& s) : str(s) {} // передаем вектор по ссылке

    int Size() const {
        return str.size();
    }

    friend ostream& operator<<(ostream& out, const Strang& str1) {
        for (auto i : str1.str) {
            out << i;
        }
        return out;
    }

    friend istream& operator>>(istream& in, Strang& str1) {
        char sim;
        while (in.get(sim) && sim != '\n') {
            str1.str.emplace_back(sim);
        }
        return in;
    }

    friend Strang operator+(const Strang& str1, const Strang& str2) {
        vector<char> res = str1.str;
        res.insert(res.end(), str2.str.begin(), str2.str.end());
        return Strang(res);
    }
};

int main() {
    vector<char> v = { 'h','e','l','l' ,'o' ,' ' };
    Strang str(v);
    vector<char> g = { 'f' ,'r' ,'i' ,'e' ,'n' ,'d' };
    Strang str1(g);
    Strang str3;
    int a = str1.Size();
    
    cin >> str3;
    cout << a << "\n";
    cout << str + str1;
}
