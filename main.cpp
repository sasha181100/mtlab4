
#include <bits/stdc++.h>
#include <regex>
using namespace std;

void skip(string &s, int &i) {
    while (i < s.size() && s[i] == ' ') {
        i++;
    }
}

set<string> nterms;
struct term;
set<string> terms;
map<string, string> reg;
bool trm(string &s) {
    if (isupper(s[0])) {
        return 0;
    }
    return 1;
}




struct item {
    string name;
    string code;
};

struct rule {
    string name;
    string args;
    string return_type;
    string code_after;
    vector<item> items;
    /*rule(string &name1, string &args1, string &return_type1, string &code_after1, vector<item> &items1) {
        name = name1;
        args = args1;
        return_type = return_type1;
        code_after = code_after1;
        items = items1;
    }*/
    //rule() = default;
};

vector<rule> rules;


string name_to_token(string term) {
    string tmp = "";
    for (int j = 0; j < term.size(); j++) {
        tmp += toupper(term[j]);
    }
    return tmp;
}

void gen_header(ofstream &fout) {

    fout << "#include <bits/stdc++.h>\n";
    fout << "#include <regex>\n";
    fout << "\n";
    fout << "using namespace std;\n";
    fout << "\n";
    fout << "enum class Token {\n";
    string tmp = "";
    for (auto term : terms) {
        tmp += name_to_token(term);
        tmp += ", ";
    }
    tmp += "EPS, END";
    fout << "    " << tmp << "\n";
    fout << "};\n";
    fout << "pair<Token, string> p[" << terms.size() << "] = {\n";
    for (auto term : terms) {
        fout << "    {Token::" << name_to_token(term) << ", " << reg[term] << "},\n";
    }
    fout << "};\n";

}


void gen_lexer(ofstream &fout) {
    fout << "struct lexer {\n";
    fout << "\n";
    fout << "    string str = \"\";\n";
    fout << "    size_t ind = 0;\n";
    fout << "    Token curToken;\n";
    fout << "    string cur_string;\n";
    fout << "\n";
    fout << "    explicit lexer(const string &s) {\n";
    fout << "        str = s;\n";
    fout << "    }\n";
    fout << "\n";
    fout << "    lexer() {\n";
    fout << "        str = \"\";\n";
    fout << "    }\n";
    fout << "\n";
    fout << "    void skip_spaces() {\n";
    fout << "        while (isspace(str[ind])) {\n";
    fout << "            ind++;\n";
    fout << "        }\n";
    fout << "    }\n";
    fout << "\n";
    fout << "    void next_token() {\n";
    fout << "        skip_spaces();\n";
    fout << "        if (ind >= str.size()) {\n";
    fout << "            curToken = Token::END;\n";
    fout << "            return;\n";
    fout << "        }\n";
    fout << "        smatch part;\n";
    fout << "        int maxi = 0;\n";
    fout << "        int num = 0;\n";
    fout << "        string tmp;\n";
    fout << "        for (int i = 0; i < " << terms.size() << "; i++) {\n";
    fout << "\n";
    fout << "            if (regex_search(str.cbegin() + ind, str.cend(), part, regex(\"^\" + p[i].second))) {\n";
    fout << "                if (part.str().size() > maxi) {\n";
    fout << "                    tmp = part.str();\n";
    fout << "                    maxi = part.str().size();\n";
    fout << "                    num = i;\n";
    fout << "                }\n";
    fout << "            }\n";
    fout << "        }\n";
    fout << "        if (maxi == 0) {\n";
    fout << "            throw \"err\";\n";
    fout << "        } else {\n";
    fout << "            ind += maxi;\n";
    fout << "            cur_string = tmp;\n";
    fout << "            curToken = p[num].first;\n";
    fout << "            skip_spaces();\n";
    fout << "        }\n";
    fout << "    }\n";
    fout << "    Token get_token() const {\n";
    fout << "        return curToken;\n";
    fout << "    }\n";
    fout << "    string get_string() {\n";
    fout << "        return cur_string;\n";
    fout << "    }\n";
    fout << "};\n\n";


};


map<string, set<string>> first;
map<string, set<string>> follow;
int find_rule(string nterm, string term) {
    int num = -1;
    for (int i = 0; i < rules.size(); i++) {
        if (rules[i].name != nterm) {
            continue;
        }
        if (!trm(rules[i].items[0].name)) {
            auto f = first[rules[i].items[0].name];
            if (f.find(term) != f.end()) {
                if (num == 1) {
                    throw "err";
                }
                num = i;
            }
        } else {
            if (term == rules[i].items[0].name) {
                if (num == 1) {
                    throw "err";
                }
                num = i;
            }
        }
    }
    return num;
}

void write_rule(rule rule, ofstream& fout, string return_type) {
    for (int i = 0; i < rule.items.size(); i++) {
        auto item = rule.items[i];
        if (isupper(item.name[0])) {
            fout << "            auto $" << item.name << " = " << item.name << "(" << item.code << ");\n";
            fout << "            " << return_type << " " << item.name << i + 1 << "ans = $" << item.name << ".first;\n";
            fout << "            res.second->ch.push_back($" << item.name << ".second);\n";
        } else if (item.name == "eps") {
            fout << "            res.second->ch.push_back(new Node(\"eps\"));\n";
        } else if (islower(item.name[0])) {
            fout << "            if (lex.get_token() != Token::" << name_to_token(item.name) << ") \n";
            fout << "                throw \"err\";\n";
            fout << "            pair< string, Node *> $" << item.name << ";\n";
            fout << "            $" << item.name << ".second = new Node(lex.get_string());\n";
            fout << "            string " << item.name << i + 1 << "ans = lex.get_string();\n";
            fout << "            res.second->ch.push_back($" << item.name << ".second);\n";
            fout << "            lex.next_token();\n";

        }
    }
    fout << "            " << rule.code_after << "\n";
}
void gen_parser(ofstream &fout) {
    fout << "struct parser {\n";
    fout << "    lexer lex;\n";
    fout << "    struct Node {\n";
    fout << "        vector<Node *> ch;\n";
    fout << "        string name;\n";
    fout << "        explicit Node(string s) {\n";
    fout << "            name = move(s);\n";
    fout << "        }\n";
    fout << "    };\n";
    fout << "\n";
    fout << "    explicit parser(string &s) {\n";
    fout << "        lex = lexer(s);\n";
    fout << "        lex.next_token();\n";
    fout << "    }\n";
    for (auto nterm : nterms) {
        rule rule;
        for (auto one : rules) {
            if (one.name == nterm) {
                rule = one;
                break;
            }
        }
        string ret_type = rule.return_type;
        if (ret_type == "") {
            ret_type = "Node *";
            fout << "    pair<" << ret_type << ", Node *>" << nterm << "(" << rule.args << ") {\n";
        } else {
            fout << "    pair<" << rule.return_type << ", Node *>" << nterm << "(" << rule.args << ") {\n";
        }
        fout << "        Token curToken = lex.get_token();\n";
        fout << "        pair<" << ret_type << ", Node *> res;\n";
        fout << "        " << ret_type << " $ans;\n";
        fout << "        res.second = new Node(\"" << rule.name << "\");\n";
        fout << "        switch (curToken) {\n";
        bool fol = 0;
        for (auto term : first[rule.name]) {
            if (term == "eps") {
                fol = 1;
                continue;
            }
            fout << "        case Token::" << name_to_token(term) << ": {\n";
            int num = find_rule(nterm, term);
            write_rule(rules[num], fout, ret_type);
            fout << "            break;\n";
            fout << "        }\n";
        }
        if (fol) {
            for (auto term: follow[rule.name]) {
                if (term == "end") {
                    fout << "        case Token::END: {\n";
                } else {
                    fout << "        case Token::" << name_to_token(term) << ": {\n";
                }
                int num = find_rule(nterm, "eps");
                write_rule(rules[num], fout, ret_type);
                fout << "            break;\n";
                fout << "        }\n";
            }
        }
        fout << "        default: \n";
        fout << "            throw \"err\";\n";

        fout << "        }\n";
        fout << "    res.first = $ans;\n";
        fout << "    return res;\n";
        fout << "    }\n";

    }
    fout << "};";

}


set<string> process_first_alpha(vector<item> &items, int pos, bool is_first) {
    if (pos >= items.size()) {
        if (is_first) {
            return {"eps"};
        } else {
            return {"end"};
        }
    }
    if (trm(items[pos].name)) {
        return {items[pos].name};
    } else if (items[pos].name == "eps") {
        return {"eps"};
    } else if (!trm(items[pos].name)) {
        auto nw = first[items[pos].name];
        if (nw.find("eps") != nw.end()) {
            nw.erase("eps");
            auto without = process_first_alpha(items, pos + 1, is_first);
            nw.insert(without.begin(), without.end());
        }
        return nw;
    }
    return {};
}
void process_first() {
    bool is_change = 1;
    while (is_change) {
        is_change = 0;
        for (auto rule : rules) {
            string not_term = rule.name;
            set<string> nw = process_first_alpha(rule.items, 0, 1);
            int prev = first[not_term].size();
            first[not_term].insert(nw.begin(), nw.end());
            if (prev != first[not_term].size()) {
                is_change = 1;
            }
        }
    }
}

void process_follow() {
    follow["E"].insert("end");
    bool is_change = 1;
    while (is_change) {
        is_change = 0;
        for (auto rule : rules) {
            string not_term = rule.name;
            for (int i = 0; i < rule.items.size(); i++) {
                if (trm(rule.items[i].name) || rule.items[i].name == "eps") {
                    continue;
                }
                auto nw = process_first_alpha(rule.items, i + 1, 0);
                int sz = follow[rule.items[i].name].size();
                if (nw.find("eps") != nw.end() || nw.find("end") != nw.end()) {
                    nw.erase("eps");
                    follow[rule.items[i].name].insert(follow[not_term].begin(), follow[not_term].end());
                }
                follow[rule.items[i].name].insert(nw.begin(), nw.end());
                if (sz != follow[rule.items[i].name].size()) {
                    is_change = 1;
                }
            }
        }
    }
}

string read_block(int &pos, string &s, char end) {
    string res;
    while (pos < s.size() && s[pos] != end) {
        res += s[pos];
        pos++;
    }
    pos++;
    while (pos < s.size() && s[pos] == ' ') {
        pos++;
    }
    return res;
}

void read_grammar(ifstream &fin) {
    string s;
    while (getline(fin, s)) {
        int pos = 0;
        string main = read_block(pos, s, ' ');
        if (main == "") continue;
        if (!trm(main)) {
            rule rule;
            rule.name = main;
            nterms.insert(main);
            string word = read_block(pos, s, ' ');
            if (word == "get") {
                string args = read_block(pos, s, ']');
                rule.args = args.substr(1, args.size() - 1);
                word = read_block(pos, s, ' ');
            }
            if (word == "ret") {
                string return_type = read_block(pos, s, ']');
                rule.return_type = return_type.substr(1, return_type.size() - 1);
                word = read_block(pos, s, ' ');
            }
            while (pos < s.size()) {
                if (s[pos] == '[') {
                    string acc = read_block(pos, s, ']');
                    acc = acc.substr(1, acc.size() - 1);
                    rule.items[rule.items.size() - 1].code = acc;
                } else if (s[pos] == '{') {
                    string acc = read_block(pos, s, '}');
                    acc = acc.substr(1, acc.size() - 1);
                    rule.code_after = acc;
                } else {
                    rule.items.push_back({read_block(pos, s, ' '), ""});
                }
            }
            rules.push_back(rule);
        } else {
            read_block(pos, s, ' ');
            string rega = s.substr(pos, s.size() - pos);
            reg[main] = rega;
            terms.insert(main);
        }
    }
}


int main() {
    //freopen("input.txt", "r", stdin);
    ifstream fin("input2.txt");
    read_grammar(fin);
    ofstream fout("../gen/output.cpp");
    gen_header(fout);
    gen_lexer(fout);
    process_first();
    process_follow();
    gen_parser(fout);
    /*string s = "2 + 2 * 2";
    parser parser(s);
    cout << parser.E().first << endl;*/
}
