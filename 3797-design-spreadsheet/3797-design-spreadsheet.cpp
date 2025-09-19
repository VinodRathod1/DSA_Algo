#include <bits/stdc++.h>
using namespace std;

class Spreadsheet {
private:
    vector<vector<int>> grid; // rows x 26
    
    // Convert "A1" -> (row, col)
    pair<int,int> parseCell(const string& cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1; // 1-indexed to 0-indexed
        return {row, col};
    }
    
    // Evaluate an operand (either integer or cell reference)
    int getOperand(const string& op) {
        if (isdigit(op[0])) {
            return stoi(op);
        } else {
            auto [r, c] = parseCell(op);
            return grid[r][c];
        }
    }

public:
    Spreadsheet(int rows) {
        grid.assign(rows, vector<int>(26, 0));
    }

    void setCell(string cell, int value) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = value;
    }

    void resetCell(string cell) {
        auto [r, c] = parseCell(cell);
        grid[r][c] = 0;
    }

    int getValue(string formula) {
        // Formula looks like "=X+Y"
        string expr = formula.substr(1); // remove '='
        int plusPos = expr.find('+');
        string left = expr.substr(0, plusPos);
        string right = expr.substr(plusPos + 1);

        int val1 = getOperand(left);
        int val2 = getOperand(right);
        return val1 + val2;
    }
};
