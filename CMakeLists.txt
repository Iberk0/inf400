
cmake_minimum_required(VERSION 3.10)
project(kiraz)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(IS_CC_GCC TRUE)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang" AND "${CMAKE_CXX_SIMULATE_ID}" STREQUAL "MSVC")
    set(IS_CC_CLANG TRUE)
    set(IS_CC_CLANG_CL TRUE)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "AppleClang")
    set(IS_CC_CLANG TRUE)
    set(IS_CC_CLANG_APPLE TRUE)

elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(IS_CC_CLANG TRUE)

elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set(IS_CC_MSVC TRUE)

else()
    message(FATAL_ERROR "Unrecognized compiler ${CMAKE_CXX_COMPILER_ID}")

endif()

if (NOT IS_CC_MSVC)
    add_compile_options(
        -Werror=return-type
        -Werror=dangling-else
        -Werror=non-virtual-dtor
        -Werror=suggest-override
    )

    if (IS_CC_GCC)
        add_compile_options(
            -Werror=return-local-addr
            -Wno-free-nonheap-object
        )

    elseif(IS_CC_CLANG)
        add_compile_options(
            -Werror=return-stack-address
        )

    endif()
endif()

## Flex/Bison configuration
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

if (WIN32)
    set(ADDITIONAL_FLEX_FLAGS "--wincompat")
else()
    set(ADDITIONAL_FLEX_FLAGS "")
endif()

file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/gen/include/kiraz)
include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}/gen/include
    ${CMAKE_CURRENT_BINARY_DIR}/gen/include/kiraz
)

flex_target(LEXER
    ${CMAKE_CURRENT_SOURCE_DIR}/lexer.l
    ${CMAKE_CURRENT_BINARY_DIR}/_lexer_gen.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/_lexer_gen.hpp
    COMPILE_FLAGS ${ADDITIONAL_FLEX_FLAGS}
)

bison_target(PARSER
    ${CMAKE_CURRENT_SOURCE_DIR}/parser.yy
    ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp
    COMPILE_FLAGS "-d -v -Wcounterexamples"
)

add_flex_bison_dependency(LEXER PARSER)

include(EncodeString)
amp_encode_string(
    INPUT         "${CMAKE_CURRENT_LIST_DIR}/io.ki"
    NAME          FILE_io_ki
    HEADER_OUTPUT HEADER_IO_KI
    SOURCE_OUTPUT SOURCE_IO_KI
)

include_directories(
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(kiraz STATIC
    fmt/chrono.h
    fmt/core.h
    fmt/format.cc
    fmt/std.h
    fmt/printf.h
    fmt/format-inl.h
    fmt/ostream.h
    fmt/ranges.h
    fmt/xchar.h
    fmt/color.h
    fmt/format.h
    fmt/compile.h
    fmt/args.h
    fmt/os.cc
    fmt/os.h

    kiraz/Token.h
    kiraz/Token.cpp
    kiraz/token/Literal.h
    kiraz/token/Literal.cpp
    kiraz/token/Operator.h
    kiraz/token/Operator.cpp

    kiraz/Node.h
    kiraz/Node.cpp

    kiraz/Compiler.h
    kiraz/Compiler.cpp

    kiraz/ast/Operator.h
    kiraz/ast/Operator.cpp

    kiraz/ast/Literal.h
    kiraz/ast/Literal.cpp

    ${BISON_PARSER_OUTPUTS}
    ${FLEX_LEXER_OUTPUTS}

    ${HEADER_IO_KI}
    ${SOURCE_IO_KI}

    lexer.hpp
    main.h
)

add_executable(kirazc main.cpp)
target_link_libraries(kirazc PRIVATE kiraz)

add_definitions(-DYYDEBUG=1)
target_link_libraries(${PROJECT_NAME} PRIVATE ${FLEX_LIBRARIES})

include(test.cmake)
