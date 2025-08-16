class Solution {
public:
    int maximum69Number (int num) {
        string strNum = to_string(num);
        for(int i = 0; i < strNum.length(); i++)
        {
            if(strNum[i] == '6')
            {
                strNum[i] = '9';
                break;
            }
        }
        return stoi(strNum);
    }
};