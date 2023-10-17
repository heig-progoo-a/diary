#include <iostream>
#include <regex>

Circle Circle::fromstring(std::string str) {
    // https://regex101.com/r/DxSPVF/1
    std::regex re("\\(\\s*(\\d+(?:\\.\\d+)?)\\s*,\\s*"
                  "(\\d+(?:\\.\\d+)?)\\s*,\\s*"
                  "(\\d+(?:\\.\\d+)?)\\s*\\)");
    std::smatch matches;

    if(!std::regex_search(str, matches, re) || !(matches.size() == 4))
        abort();

    int k = 1;
    int x= stod(matches[k++].str());
    int  stod(matches[k++].str()) << "\n";
    std::cout << stod(matches[k++].str()) << "\n";
    return Circle(x,y, r);
}

int main() {
    parse("(2a,    3;4000]");
}