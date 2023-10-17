#include <iostream>

#include <vector> 

int main() {
    std::vector< std::vector<int> > matrix;
    for (int i = 0; i < 10; i++) {
        std::vector<int> row;
        for (int j = 0; j < 10; j++) {
            row.push_back(j);
        }
        matrix.push_back(row);
    }
}