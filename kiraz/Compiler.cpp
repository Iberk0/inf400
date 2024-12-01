
#include "Compiler.h"
#include <cassert>

#include <fmt/format.h>
#include <kiraz/ast/Literal.h>
#include <resource/FILE_io_ki.h>

#define IDENTIFIER(name) {std::string(name), Node::Ptr()}

#define FUNCTION2(name, returnType, argType1, argType2) { \
    name, std::make_shared<ast::Func>( \
        std::make_shared<ast::Identifier>(name), \
        std::make_shared<ast::FuncArgs>(std::vector<Node::Ptr>{ \
            std::make_shared<ast::FuncArg>(std::make_shared<ast::Identifier>("arg1"), std::make_shared<ast::Identifier>(argType1)), \
            std::make_shared<ast::FuncArg>(std::make_shared<ast::Identifier>("arg2"), std::make_shared<ast::Identifier>(argType2)) \
        }), \
        std::make_shared<ast::Identifier>(returnType), \
        nullptr  \
    ) \
} 


Node::Ptr SymbolTable::s_module_ki;
Node::Ptr SymbolTable::s_module_io;

SymbolTable::~SymbolTable() {}

Compiler *Compiler::s_current;

extern Token::Ptr curtoken;

Compiler::Compiler() {
    assert(! s_current);
    s_current = this;
    Node::reset_root();
}

Compiler::~Compiler() {
    if (buffer) {
        yy_delete_buffer(buffer);
        buffer = nullptr;
    }
    reset_parser();
    s_current = nullptr;
}

int Compiler::compile_file(const std::string &file_name, std::ostream &ostr) {
    yyin = fopen(file_name.data(), "rb");
    if (! yyin) {
        perror(file_name.data());
        return 2;
    }

    yyparse();
    auto root = Node::get_root();
    reset();

    return compile(root, ostr);
}

int Compiler::compile_string(const std::string &code, std::ostream &ostr) {
    buffer = yy_scan_string(code.data());
    yyparse();
    auto root = Node::get_root();
    reset();

    return compile(root, ostr);
}

Node::Ptr Compiler::compile_module(const std::string &str) {
    buffer = yy_scan_string(str.data());
    yyparse();
    auto retval = Node::pop_root();
    reset();

    return retval;
}

void Compiler::reset_parser() {
    curtoken.reset();
    Node::reset_root();
    Token::colno = 0;
    yylex_destroy();
}

void Compiler::reset() {
    if (buffer) {
        yy_delete_buffer(buffer);
        buffer = nullptr;
    }
    reset_parser();
}

int Compiler::compile(Node::Ptr root, std::ostream &ostr) {
    if (! root) {
        return 1;
    }

    SymbolTable st(ScopeType::Module);

    if (auto ret = root->compute_stmt_type(st)) {
        set_error(fmt::format(
                "Error at {}:{}: {}\n", ret->get_line(), ret->get_col(), ret->get_error()));
        Node::reset_root();
        return 1;
    }

    /*
    MemoryManager mm;
    if (auto ret = root->gen_wat(mm, ostr)) {
        return 2;
    }
    */

    return 0;
}

SymbolTable::SymbolTable()
        : m_symbols({
                  std::make_shared<Scope>(Scope::SymTab{
                    IDENTIFIER("Boolean"),
                    IDENTIFIER("Function"),
                    IDENTIFIER("Class"),
                    IDENTIFIER("Integer64"),
                    IDENTIFIER("Module"),
                    IDENTIFIER("String"),
                    IDENTIFIER("Void"),
                    IDENTIFIER("true"),
                    IDENTIFIER("false"),
                    FUNCTION2("and", "Boolean", "Boolean", "Boolean"),
                    FUNCTION2("or", "Boolean", "Boolean", "Boolean"),
                    FUNCTION2("not", "Boolean", "Boolean", "")
                  }, ScopeType::Module, nullptr),
          }) {
    if (! s_module_io) {
        s_module_io = Compiler::current()->compile_module(FILE_io_ki);
    }
}

SymbolTable::SymbolTable(ScopeType scope_type) : SymbolTable() {
    m_symbols.back()->scope_type = scope_type;
}
