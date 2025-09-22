class Spreadsheet {
public:
    vector<vector<int>> table;
    Spreadsheet(int rows) {
        table.resize(rows);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < 26; j++){
                table[i].push_back(0);
            }        
        }
    }
    void setCell(string cell, int value){
        char col_char = cell[0];
        string row_char = cell.substr(1, cell.size() -1);
        int col = col_char - 'A';
        int row = stoi(row_char);
        table[row][col] = value;
    }
    void resetCell(string cell) {
        char col_char = cell[0];
        string row_char = cell.substr(1, cell.size() -1);
        int col = col_char - 'A';
        int row = stoi(row_char);
        table[row][col] = 0;
    }
    
    int getValue(string formula) {
        int split_p = 0;
        for (int i = 1; i < formula.size(); i++){
            if(formula[i] == '+'){
                split_p = i;
                break;
            }
        }
        string first_part = formula.substr(1, split_p -1);
        string second_part = formula.substr(split_p + 1, formula.size() - split_p - 1);
        int first_val=0, second_val = 0;
        if(  first_part[0] >= 'A' && first_part[0] <= 'Z'){
            char col_char = first_part[0];
            string row_char = first_part.substr(1, first_part.size() -1);
            int col = col_char - 'A';
            int row = stoi(row_char);
            first_val = table[row][col];
        }else{
            first_val = stoi(first_part);
        }
        if(  second_part[0] >= 'A' && second_part[0] <= 'Z'){
            char col_char = second_part[0];
            string row_char = second_part.substr(1, second_part.size() -1);
            int col = col_char - 'A';
            int row = stoi(row_char);
            second_val = table[row][col];
        }else{
            second_val = stoi(first_part);
        }
        return first_val + second_val;
    }
};
