
#include <string>
using std::string;

#include <iostream>

void Replace(string& s, const string& oldVal, const string& newVal)
{
    for (auto beg = s.begin(); std::distance(beg, s.end()) >=
                               std::distance(oldVal.begin(), oldVal.end());) {
        if (string{beg, beg + oldVal.size()} == oldVal) {
            beg = s.erase(beg, beg + oldVal.size());
            beg = s.insert(beg, newVal.cbegin(), newVal.cend());
            std::advance(beg, newVal.size());
        }
        else
            ++beg;
    }
}

int main()
{
    {
        string str{"To drive straight thru is a foolish, tho courageous act."};
        Replace(str, "thru", "through");
        Replace(str, "tho", "though");
        std::cout << str << std::endl;
    }
    {
        string str{
            "To drive straight thruthru is a foolish, thotho courageous act."};
        Replace(str, "thru", "through");
        Replace(str, "tho", "though");
        std::cout << str << std::endl;
    }
    {
        string str{"To drive straight thru is a foolish, tho courageous act."};
        Replace(str, "thru", "thruthru");
        Replace(str, "tho", "though");
        std::cout << str << std::endl;
    }
    {
        string str{"my world is a big world"};
        Replace(str, "world",
                "worldddddddddddddddddddddddddddddddddddddddddddddddd");
        std::cout << str << std::endl;
    }
    return 0;
}