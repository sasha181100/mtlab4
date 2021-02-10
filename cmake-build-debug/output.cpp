#include <bits/stdc++.h>
#include <regex>

using namespace std;

enum class Token {
    
};
pair<Token, string> p[0] = {
struct lexer {

    string str = "";
    size_t ind = 0;
    Token curToken;
    string cur_string;

    explicit lexer(const string &s) {
        str = s;
    }

    lexer() {
        str = "";
    }

    void skip_spaces() {
        if (isspace(str[ind])) {
            ind++;
        }
    }

    void next_token() {
        skip_spaces();
        if (ind >= str.size()) {
            curToken = Token::END;
            return;
        }
        smatch part;
        int maxi = 0;
        int num = 0;
        string tmp;
        for (int i = 0; i < 0; i++) {

            if (regex_search(str.cbegin() + ind, str.cend(), part, regex("^" + p[i].second))) {
                if (part.str().size() > maxi) {
                    tmp = part.srt();
                    maxi = part.str().size();
                    num = i;
                }
            }
        }
        if (maxi == 0) {
            throw 
        } else {
            ind += maxi;
            cur_string = tmp;
            curToken = p[num].first;
            skip_spaces();
        }
    }
    Token get_token() const {
        return curToken;
    }
    string get_string() {
        return cur_string;
    }
};struct parser {
    lexer lex;
    struct Node {
        vector<Node *> ch;
        string name;
        explicit Node(string s) {
            name = move(s);
        }
    };

    explicit parser(string &s) {
        lex = lexer(s);
        lex.nextToken();
    }
    }
};