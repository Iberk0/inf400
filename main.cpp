
#include <cassert>
#include <cstdio>

#include "lexer.hpp"
#include "main.h"
#include "parser.hpp"

#include <kiraz/Node.h>

extern int yydebug;

enum Status {
    OK,
    ERR,
};

enum Mode {
    MODE_UNKNOWN,
    MODE_FILE,
    MODE_TEXT,
    MODE_HELP,
};

static int test(std::string_view str) {
    auto buffer = yy_scan_string(str.data());
    auto ret = yyparse();
    yy_delete_buffer(buffer);

    if (Node::current_root()) {
        fmt::print("{}\n", Node::current_root()->as_string());
    }

    return ret;
}

static int usage(int argc, char **argv) {
    fmt::print("Usage: {} -s [string to parse] ....\n", argv[0]);
    fmt::print("       {} -f [file to parse] ....\n", argv[0]);
    fmt::print("       {} -h Show this help\n", argv[0]);

    return ERR;
}

static int handle_mode_text(std::string_view arg) {
    if (auto ret = test(arg); ret != OK) {
        return ret;
    }

    return OK;
}

static int handle_mode_file(std::string_view arg) {
   FILE *file = fopen(arg.data(), "r");
    if (!file) {
        fmt::print("Error: Cannot open file {}\n", arg);
        return ERR;
    }

    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    
    std::vector<char> buffer(file_size + 1);  
    size_t read_size = fread(buffer.data(), 1, file_size, file);
    fclose(file);

    if (read_size != file_size) {
        fmt::print("Error: Could not read the complete file {}\n", arg);
        return ERR;
    }

    buffer[file_size] = '\0';

    
    if (auto ret = test(buffer.data()); ret != OK) {
        return ret;
    }

    return OK;
    return ERR;
}

int main(int argc, char **argv) {
    yydebug = 0;

    static Mode mode = MODE_UNKNOWN;

    if (argc < 2) {
        return usage(argc, argv);
    }

    for (auto i = 1; i < argc; ++i) {
        Node::reset_root();

        std::string_view arg(argv[i]);

        if (mode == MODE_UNKNOWN) {
            if (arg == "-f") {
                mode = MODE_FILE;
                continue;
            }

            if (arg == "-s") {
                mode = MODE_TEXT;
                continue;
            }

            if (arg == "-h") {
                mode = MODE_HELP;
                continue;
            }
        }

        switch (mode) {
        default:
        case MODE_HELP:
            return usage(argc, argv);

        case MODE_FILE:
            if (auto ret = handle_mode_file(argv[i]); ret != OK) {
                return ret;
            }
            return 1;

        case MODE_TEXT:
            if (auto ret = handle_mode_text(argv[i]); ret != OK) {
                return ret;
            }
            break;
        }

        mode = MODE_UNKNOWN;
    }

    if (mode != MODE_UNKNOWN) {
        return usage(argc, argv);
    }

    return 0;
}
