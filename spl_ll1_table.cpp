#include <vector>
#include <functional>
#include "spl_symbols.h"

Rule none;
static Rule rules[] = {
    /*0*/ {Symbol::input, {Symbol::opt_func_list, }},
    /*1*/ {Symbol::opt_func_list, {Symbol::func_list, Symbol::PIPE, Symbol::Epsilon, }},
    /*2*/ {Symbol::func_list, {Symbol::func_decl, Symbol::func_list_p, }},
    /*3*/ {Symbol::func_list_p, {Symbol::func_list, Symbol::PIPE, Symbol::Epsilon, }},
    /*4*/ {Symbol::func_decl, {Symbol::IDENT, Symbol::OPEN_PARENTHESIS, Symbol::opt_arg_list, Symbol::CLOSE_PARENTHESIS, Symbol::block, }},
    /*5*/ {Symbol::opt_arg_list, {Symbol::arg_list, Symbol::PIPE, Symbol::Epsilon, }},
    /*6*/ {Symbol::arg_list, {Symbol::IDENT, Symbol::arg_list_p, }},
    /*7*/ {Symbol::arg_list_p, {Symbol::COMMA, Symbol::arg_list, Symbol::PIPE, Symbol::Epsilon, }},
    /*8*/ {Symbol::block, {Symbol::OPEN_BRACE, Symbol::stmt_list, Symbol::CLOSE_BRACE, }},
    /*9*/ {Symbol::stmt_list, {Symbol::stmt, Symbol::stmt_list_p, }},
    /*10*/ {Symbol::stmt_list_p, {Symbol::stmt, Symbol::stmt_list, Symbol::PIPE, Symbol::Epsilon, }},
    /*11*/ {Symbol::stmt, {Symbol::IDENT, Symbol::stmt_p, }},
    /*12*/ {Symbol::stmt_p, {Symbol::OPEN_PARENTHESIS, Symbol::expr_list, Symbol::CLOSE_PARENTHESIS, Symbol::PIPE, Symbol::EQUAL, Symbol::expr, Symbol::PIPE, Symbol::Epsilon, }},
    /*13*/ {Symbol::expr_list, {Symbol::expr, Symbol::expr_list_p, }},
    /*14*/ {Symbol::expr_list_p, {Symbol::COMMA, Symbol::expr, Symbol::expr_list, Symbol::PIPE, Symbol::Epsilon, }},
    /*15*/ {Symbol::expr, {Symbol::term, Symbol::expr_p, }},
    /*16*/ {Symbol::expr_p, {Symbol::PLUS, Symbol::term, Symbol::expr, Symbol::PIPE, Symbol::Epsilon, }},
    /*17*/ {Symbol::term, {Symbol::factor, Symbol::term_p, }},
    /*18*/ {Symbol::term_p, {Symbol::ASTERISK, Symbol::factor, Symbol::term, Symbol::PIPE, Symbol::Epsilon, }},
    /*19*/ {Symbol::factor, {Symbol::NUMBER, Symbol::PIPE, Symbol::IDENT, Symbol::factor_p, Symbol::PIPE, Symbol::OPEN_PARENTHESIS, Symbol::expr, Symbol::CLOSE_PARENTHESIS, }},
    /*20*/ {Symbol::factor_p, {Symbol::OPEN_PARENTHESIS, Symbol::expr_list, Symbol::CLOSE_PARENTHESIS, Symbol::PIPE, Symbol::OPEN_PARENTHESIS, Symbol::expr, Symbol::CLOSE_PARENTHESIS, Symbol::PIPE, Symbol::Epsilon, }},
};

const Rule& getEntry(Symbol non_term, Symbol term)
{
    switch (non_term) {
        case Symbol::input:
            switch (term) {
                case Symbol::IDENT:
                    return rules[0];
            }
            break;
        case Symbol::opt_func_list:
            switch (term) {
                case Symbol::IDENT:
                    return rules[1];
            }
            break;
        case Symbol::func_list:
            switch (term) {
                case Symbol::IDENT:
                    return rules[2];
            }
            break;
        case Symbol::func_decl:
            switch (term) {
                case Symbol::IDENT:
                    return rules[4];
            }
            break;
        case Symbol::func_list_p:
            switch (term) {
                case Symbol::IDENT:
                    return rules[3];
            }
            break;
        case Symbol::opt_arg_list:
            switch (term) {
                case Symbol::IDENT:
                    return rules[5];
            }
            break;
        case Symbol::block:
            switch (term) {
                case Symbol::OPEN_BRACE:
                    return rules[8];
            }
            break;
        case Symbol::arg_list:
            switch (term) {
                case Symbol::IDENT:
                    return rules[6];
            }
            break;
        case Symbol::arg_list_p:
            switch (term) {
                case Symbol::COMMA:
                    return rules[7];
            }
            break;
        case Symbol::stmt_list:
            switch (term) {
                case Symbol::IDENT:
                    return rules[9];
            }
            break;
        case Symbol::stmt:
            switch (term) {
                case Symbol::IDENT:
                    return rules[11];
            }
            break;
        case Symbol::stmt_list_p:
            switch (term) {
                case Symbol::IDENT:
                    return rules[10];
            }
            break;
        case Symbol::stmt_p:
            switch (term) {
                case Symbol::OPEN_PARENTHESIS:
                    return rules[12];
            }
            break;
        case Symbol::expr_list:
            switch (term) {
                case Symbol::NUMBER:
                    return rules[13];
            }
            break;
        case Symbol::expr:
            switch (term) {
                case Symbol::NUMBER:
                    return rules[15];
            }
            break;
        case Symbol::expr_list_p:
            switch (term) {
                case Symbol::COMMA:
                    return rules[14];
            }
            break;
        case Symbol::term:
            switch (term) {
                case Symbol::NUMBER:
                    return rules[17];
            }
            break;
        case Symbol::expr_p:
            switch (term) {
                case Symbol::PLUS:
                    return rules[16];
            }
            break;
        case Symbol::factor:
            switch (term) {
                case Symbol::NUMBER:
                    return rules[19];
            }
            break;
        case Symbol::term_p:
            switch (term) {
                case Symbol::ASTERISK:
                    return rules[18];
            }
            break;
        case Symbol::factor_p:
            switch (term) {
                case Symbol::OPEN_PARENTHESIS:
                    return rules[20];
            }
            break;
    }

    return none;
}
