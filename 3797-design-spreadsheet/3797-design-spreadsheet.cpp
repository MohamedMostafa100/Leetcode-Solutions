class Spreadsheet {
public:
    Spreadsheet(int rows) {
        values.assign(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        char col = cell[0] - 'A';
        int row = stoi(cell.substr(1, (int)cell.size() - 1)) - 1;
        values[row][col] = value;
    }
    
    void resetCell(string cell) {
        char col = cell[0] - 'A';
        int row = stoi(cell.substr(1, (int)cell.size() - 1)) - 1;
        values[row][col] = 0;
    }
    
    int getValue(string formula) {
        int op1 = 0;
        int op2 = 0;
        string ops[2] = {"", ""};
        int j = 0;
        for(int i = 1; i < formula.length(); i++)
        {
            if(formula[i] == '+')
            {
                j++;
                continue;
            }
            ops[j] += formula[i];
        }
        if(ops[0][0] >= 'A' && ops[0][0] <= 'Z')
        {
            char col = ops[0][0] - 'A';
            int row = stoi(ops[0].substr(1, (int)ops[0].size() - 1)) - 1;
            op1 = values[row][col];
        }
        else
        {
            op1 = stoi(ops[0]);
        }

        if(ops[1][0] >= 'A' && ops[1][0] <= 'Z')
        {
            char col = ops[1][0] - 'A';
            int row = stoi(ops[1].substr(1, (int)ops[1].size() - 1)) - 1;
            op2 = values[row][col];
        }
        else
        {
            op2 = stoi(ops[1]);
        }
        return op1 + op2;
    }
private:
    vector<vector<int>> values;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */