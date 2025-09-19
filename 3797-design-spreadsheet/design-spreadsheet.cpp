
class Spreadsheet {
private:
    int rows;
    vector<vector<int>> grid; // rows x 26 spreadsheet
    
    // helper: parse "A1" → (row, col)
    pair<int,int> parseCell(const string &cell) {
        char colChar = cell[0];
        int col = colChar - 'A';
        int row = stoi(cell.substr(1)) - 1; // convert 1-indexed to 0-indexed
        return {row, col};
    }
    
    // helper: get value (either integer literal or cell reference)
    int getVal(const string &token) {
        if (isalpha(token[0])) {
            auto [r, c] = parseCell(token);
            return grid[r][c];
        } else {
            return stoi(token);
        }
    }
    
public:
    Spreadsheet(int r) {
        rows = r;
        grid.assign(rows, vector<int>(26, 0)); // initialize all to 0
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
        formula = formula.substr(1); // remove '='
        size_t plusPos = formula.find('+');
        string left = formula.substr(0, plusPos);
        string right = formula.substr(plusPos + 1);
        return getVal(left) + getVal(right);
    }
};


/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */