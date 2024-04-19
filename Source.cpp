#include <iostream> 
#include <vector> 
using namespace std;
class Strang {
private:
    vector<char> str;
public:
    Strang() {
        vector<char> str = { 0 };
    }
    Strang(vector<char> s) {
        for (auto i : s) {
            str.push_back(i);
        }
    }
    int Size() {
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
    friend Strang operator+(Strang& str1, Strang& str2) {
        vector<char> res;
        for (auto i : str1.str) {
            res.push_back(i);
        }
        for (auto i : str2.str) {
            res.push_back(i);
        }
        return res;
    }
};
int main()
{
    vector<char> v = { 'h','e','l','l' ,'o' ,' ' };
    Strang str(v);
    vector<char> g = { 'f' ,'r' ,'i' ,'e' ,'n' ,'d' };
    Strang str1(g);
    int a = str1.Size();
    Strang str3;
    cin >> str3;
    cout << str3 << "\n";
    cout << str + str1;
}
