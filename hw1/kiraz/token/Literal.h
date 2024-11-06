#ifndef KIRAZ_TOKEN_LITERAL_H
#define KIRAZ_TOKEN_LITERAL_H

#include <kiraz/Token.h>

namespace token {

class Integer : public Token {
public:
    Integer(int64_t base, std::string_view value) 
        : Token(L_INTEGER), m_base(base), m_value(value) {}
    virtual ~Integer();

    std::string as_string() const override {return fmt::format("Int{}", m_value);}

    void print() {fmt::print("{}\n", as_string());}
    static int colno;

    auto get_base() const {return m_base;}
    auto get_value() const {return m_value;}
private:
    int m_id;
    int64_t m_base;
    std::string m_value;
};

class StringLiteral : public Token {
public:
    
    StringLiteral(std::string_view value) 
        : Token(L_STRING), m_value(value) {}

    std::string as_string() const override { return fmt::format("Str({})", m_value); }

    
    auto get_value() const {return m_value;}

private:
    std::string m_value;
};


class Identifier : public Token {
public:
    Identifier(std::string name)
        : Token(IDENTIFIER), m_name(name) {}
        virtual ~Identifier();
    std::string as_string() const override { return fmt::format("Id({})", m_name); }

    auto get_name() const { return m_name; }

private:
    std::string m_name;
};

class Import : public Token {
public:
    Import() : Token(KW_IMPORT) {}
    std::string as_string() const override { return "KW_IMPORT"; }
};

class Func : public Token {
public:
    Func() : Token(KW_FUNC) {}
    std::string as_string() const override { return "KW_FUNC"; }
};

class If : public Token {
public:
    If() : Token(KW_IF) {}
    std::string as_string() const override { return "KW_IF"; }
};

class While : public Token {
public:
    While() : Token(KW_WHILE) {}
    std::string as_string() const override { return "KW_WHILE"; }
};

class Class : public Token {
public:
    Class() : Token(KW_CLASS) {}
    std::string as_string() const override { return "KW_CLASS"; }
};

class Let : public Token {
public:
    Let() : Token(KW_LET) {}
    std::string as_string() const override { return "KW_LET"; }
};

class Else : public Token {
public:
    Else() : Token(KW_ELSE) {}
    std::string as_string() const override { return "KW_ELSE"; }
};

class Return : public Token {
public: 
    Return() : Token(KW_RETURN) {}
    std::string as_string() const override { return "KW_RETURN";}
};
}

#endif // KIRAZ_TOKEN_LITERAL_H
