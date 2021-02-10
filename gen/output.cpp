#include <bits/stdc++.h>
#include <regex>

using namespace std;

enum class Token {
    COLON, EQ, INT, KEYWORD, NAME, NUMBER, SEMICOLON, EPS, END
};
pair<Token, string> p[7] = {
    {Token::COLON, ":"},
    {Token::EQ, "="},
    {Token::INT, "Int"},
    {Token::KEYWORD, "^var|^val"},
    {Token::NAME, "[a-zA-Z]+"},
    {Token::NUMBER, "[0-9]+"},
    {Token::SEMICOLON, ";"},
};
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
        while (isspace(str[ind])) {
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
        for (int i = 0; i < 7; i++) {

            if (regex_search(str.cbegin() + ind, str.cend(), part, regex("^" + p[i].second))) {
                if (part.str().size() > maxi) {
                    tmp = part.str();
                    maxi = part.str().size();
                    num = i;
                }
            }
        }
        if (maxi == 0) {
            throw "err";
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
};

struct parser {
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
        lex.next_token();
    }
    pair<Node *, Node *>E() {
        Token curToken = lex.get_token();
        pair<Node *, Node *> res;
        Node * $ans;
        res.second = new Node("E");
        switch (curToken) {
        case Token::KEYWORD: {
            if (lex.get_token() != Token::KEYWORD) 
                throw "err";
            pair< string, Node *> $keyword;
            $keyword.second = new Node(lex.get_string());
            string keyword1ans = lex.get_string();
            res.second->ch.push_back($keyword.second);
            lex.next_token();
            if (lex.get_token() != Token::NAME) 
                throw "err";
            pair< string, Node *> $name;
            $name.second = new Node(lex.get_string());
            string name2ans = lex.get_string();
            res.second->ch.push_back($name.second);
            lex.next_token();
            if (lex.get_token() != Token::COLON) 
                throw "err";
            pair< string, Node *> $colon;
            $colon.second = new Node(lex.get_string());
            string colon3ans = lex.get_string();
            res.second->ch.push_back($colon.second);
            lex.next_token();
            auto $End = End();
            Node * End4ans = $End.first;
            res.second->ch.push_back($End.second);
            
            break;
        }
        default: 
            throw "err";
        }
    res.first = $ans;
    return res;
    }
    pair<Node *, Node *>End() {
        Token curToken = lex.get_token();
        pair<Node *, Node *> res;
        Node * $ans;
        res.second = new Node("End");
        switch (curToken) {
        case Token::INT: {
            if (lex.get_token() != Token::INT) 
                throw "err";
            pair< string, Node *> $int;
            $int.second = new Node(lex.get_string());
            string int1ans = lex.get_string();
            res.second->ch.push_back($int.second);
            lex.next_token();
            auto $Init = Init();
            Node * Init2ans = $Init.first;
            res.second->ch.push_back($Init.second);
            
            break;
        }
        case Token::NAME: {
            if (lex.get_token() != Token::NAME) 
                throw "err";
            pair< string, Node *> $name;
            $name.second = new Node(lex.get_string());
            string name1ans = lex.get_string();
            res.second->ch.push_back($name.second);
            lex.next_token();
            auto $Ends = Ends();
            Node * Ends2ans = $Ends.first;
            res.second->ch.push_back($Ends.second);
            
            break;
        }
        default: 
            throw "err";
        }
    res.first = $ans;
    return res;
    }
    pair<Node *, Node *>Ends() {
        Token curToken = lex.get_token();
        pair<Node *, Node *> res;
        Node * $ans;
        res.second = new Node("Ends");
        switch (curToken) {
        case Token::SEMICOLON: {
            if (lex.get_token() != Token::SEMICOLON) 
                throw "err";
            pair< string, Node *> $semicolon;
            $semicolon.second = new Node(lex.get_string());
            string semicolon1ans = lex.get_string();
            res.second->ch.push_back($semicolon.second);
            lex.next_token();
            
            break;
        }
        case Token::END: {
            res.second->ch.push_back(new Node("eps"));
            
            break;
        }
        default: 
            throw "err";
        }
    res.first = $ans;
    return res;
    }
    pair<Node *, Node *>Init() {
        Token curToken = lex.get_token();
        pair<Node *, Node *> res;
        Node * $ans;
        res.second = new Node("Init");
        switch (curToken) {
        case Token::EQ: {
            if (lex.get_token() != Token::EQ) 
                throw "err";
            pair< string, Node *> $eq;
            $eq.second = new Node(lex.get_string());
            string eq1ans = lex.get_string();
            res.second->ch.push_back($eq.second);
            lex.next_token();
            if (lex.get_token() != Token::NUMBER) 
                throw "err";
            pair< string, Node *> $number;
            $number.second = new Node(lex.get_string());
            string number2ans = lex.get_string();
            res.second->ch.push_back($number.second);
            lex.next_token();
            auto $Ends = Ends();
            Node * Ends3ans = $Ends.first;
            res.second->ch.push_back($Ends.second);
            
            break;
        }
        case Token::SEMICOLON: {
            auto $Ends = Ends();
            Node * Ends1ans = $Ends.first;
            res.second->ch.push_back($Ends.second);
            
            break;
        }
        case Token::END: {
            auto $Ends = Ends();
            Node * Ends1ans = $Ends.first;
            res.second->ch.push_back($Ends.second);
            
            break;
        }
        default: 
            throw "err";
        }
    res.first = $ans;
    return res;
    }
};