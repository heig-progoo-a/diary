#include <iostream> 
using namespace std;

int main() {
    int x;
    cin >> x;
    cin.putback('a');
    cin.ignore(1, '#'); 
    cout << cin.peek();
}