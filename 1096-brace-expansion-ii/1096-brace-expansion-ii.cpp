class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        vector<string> res;
        stack<unordered_set<string>> exprs;
        stack<char> ops;
        string cur = "";
        expression = "{" + expression + "}";
        for(int i = 0; i < expression.length(); i++)
        {
            if(expression[i] >= 'a' && expression[i] <= 'z')
            {
                cur += expression[i];
                if(i != 0 && expression[i - 1] == '}')
                {
                    ops.push('*');
                }
            }
            else if(expression[i] == '{')
            {
                if(i != 0 && (expression[i - 1] == '}' || (expression[i - 1] >= 'a' && expression[i - 1] <= 'z')))
                {
                    ops.push('*');
                }
                if(!cur.empty())
                {
                    unordered_set<string> newSet;
                    newSet.insert(cur);
                    exprs.push(newSet);
                }
                ops.push('{');
                cur = "";
            }
            else if(expression[i] == ',')
            {
                if(!cur.empty())
                {
                    unordered_set<string> newSet;
                    newSet.insert(cur);
                    exprs.push(newSet);
                }
                cur = "";
                while(ops.top() != '{' && ops.top() != '+')
                {
                    unordered_set<string> operand1 = exprs.top();
                    exprs.pop();
                    unordered_set<string> operand2 = exprs.top();
                    exprs.pop();
                    ops.pop();
                    exprs.push(multiply(operand1, operand2));
                }
                ops.push('+');
            }
            else
            {
                if(!cur.empty())
                {
                    unordered_set<string> newSet;
                    newSet.insert(cur);
                    exprs.push(newSet);
                }
                cur = "";
                while(ops.top() != '{')
                {
                    unordered_set<string> operand1 = exprs.top();
                    exprs.pop();
                    unordered_set<string> operand2 = exprs.top();
                    exprs.pop();
                    char operation = ops.top();
                    ops.pop();
                    if(operation == '*')
                    {
                        exprs.push(multiply(operand1, operand2));
                    }
                    else
                    {
                        exprs.push(add(operand1, operand2));
                    }
                }
                ops.pop();
            }
        }
        res.assign(exprs.top().begin(), exprs.top().end());
        sort(res.begin(), res.end());
        return res;
    }
private:
    unordered_set<string> multiply(unordered_set<string>& expr1, unordered_set<string>& expr2)
    {
        unordered_set<string> exprs;
        for(auto& e1 : expr1)
        {
            for(auto& e2 : expr2)
            {
                exprs.insert(e2 + e1);
            }
        }
        return exprs;
    }
    unordered_set<string> add(unordered_set<string>& expr1, unordered_set<string>& expr2)
    {
        unordered_set<string> exprs;
        for(auto& e1 : expr1)
        {
            exprs.insert(e1);
        }
        for(auto& e2 : expr2)
        {
            exprs.insert(e2);
        }
        return exprs;
    }
};