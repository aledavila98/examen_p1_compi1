#ifndef __SPL_SYMBOLS_H__
#define __SPL_SYMBOLS_H__

#include <vector>

enum class Symbol: unsigned {
    input = 0,
    opt_func_list = 1,
    func_list = 2,
    func_decl = 3,
    func_list_p = 4,
    opt_arg_list = 5,
    block = 6,
    arg_list = 7,
    arg_list_p = 8,
    stmt_list = 9,
    stmt = 10,
    stmt_list_p = 11,
    stmt_p = 12,
    expr_list = 13,
    expr = 14,
    expr_list_p = 15,
    term = 16,
    expr_p = 17,
    factor = 18,
    term_p = 19,
    factor_p = 20,
    Eof = 21,
    PIPE = 22,
    IDENT = 23,
    OPEN_PARENTHESIS = 24,
    CLOSE_PARENTHESIS = 25,
    COMMA = 26,
    OPEN_BRACE = 27,
    CLOSE_BRACE = 28,
    EQUAL = 29,
    PLUS = 30,
    ASTERISK = 31,
    NUMBER = 32,
    Epsilon = 33
};

struct Rule {
    Rule() = default;
    Rule(const Rule&) = delete;

    Symbol lhs;
    std::vector<Symbol> rhs;
    bool isEmpty() const { return rhs.empty(); }
};

using RuleRef = std::reference_wrapper<Rule>;

static inline unsigned indexOf(Symbol s) {
    unsigned index = static_cast<unsigned>(s);
    if (index < 21) return index;
    else return (index - 21);
}

static inline bool isTerminal(Symbol s) {
    return static_cast<unsigned>(s) >= 21;
}

const Rule& getEntry(Symbol non_term, Symbol term);

#endif