class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char ch : expression) {
            if(ch == ',' )
                continue;

            if(ch != ')') {
                st.push(ch);
            }
            else {
                bool hastrue = false;
                bool hasfalse = false;

                while(!st.empty() && st.top() != '(') {
                    char c = st.top();
                    st.pop();

                    if(c == 't') hastrue = true;
                    if(c == 'f') hasfalse = true;
                }

                st.pop();

                char op = st.top();
                st.pop();

                bool result;

                if(op == '&')
                    result = !hasfalse;
                else if(op == '|')
                    result = hastrue;
                else
                    result = !hastrue;

                st.push(result ? 't' : 'f');
            }
        }

        return st.top() == 't';
    }
};