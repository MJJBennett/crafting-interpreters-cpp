#!/usr/bin/env python3

# Script to generate expression classes

template__ = """#ifndef EXPRESSION_LOX_H
#define EXPRESSION_LOX_H

#include <vector>
#include "tokens.h"

struct Expression
{
};

"""

after__ = """#endif  // EXPRESSION_LOX_H
"""

classes__ = {
    "Assign": [("Token", "name"), ("Expr", "value")],
    "Binary": [("Expr", "left"), ("Token", "op"), ("Expr", "right")],
    "Call": [("Expr", "callee"), ("Token", "paren"), ("le", "arguments")],
    "Get": [("Expr", "object"), ("Token", "name")],
    "Grouping": [("Expr", "expression")],
    "Literal": [("Literal", "value")],
    "Logical": [("Expr", "left"), ("Token", "op"), ("Expr", "right")],
    "Set": [("Expr", "object"), ("Token", "name"), ("Expr", "value")],
    "Super": [("Token", "keyword"), ("Token", "method")],
    "This": [("Token", "keyword")],
    "Unary": [("Token", "op"), ("Expr", "right")],
    "Variable": [("Token", "name")]
}

if __name__ == '__main__':
    with open("include/expression.h", "w") as file:
        file.write(template__)

        for c in classes__:
            cn = c + "Expr"
            file.write("struct " + cn + ";\n");

        file.write("""
template<typename T>
struct Visitor
{
""")

        for c in classes__:
            cn = c + "Expr"
            file.write("\tT visit" + cn + "(const " + cn + "& expr);\n")
        file.write("};\n\n")

        for c in classes__:
            cn = c + "Expr"
            file.write("struct " + cn + " : public Expression\n{\npublic:\n\t" + cn + "(")
            needcomma = False
            for a in classes__[c]:
                k = a[0]
                if needcomma:
                    file.write(", ")
                if k == "Token":
                    file.write(k + " " + a[1])
                elif k == "Expr":
                    file.write("const Expression* " + a[1])
                elif k == "le":
                    file.write("std::vector<const Expression*> " + a[1])
                elif k == "Literal":
                    file.write("Literal " + a[1])
                needcomma = True
            needcomma = False
            file.write(")\n\t\t: ")
            for a in classes__[c]:
                if needcomma:
                    file.write(", ")
                file.write("m_" + a[1] + "(" + (a[1] if a[0] not in ['le'] else ("std::move(" + a[1] + ")"))  + ")")
                needcomma = True
            file.write("\n\t{\n\t}\n\n")
            file.write("\ttemplate<typename T>\n")
            file.write("\tT accept(")
            # Visitor signature
            file.write("Visitor<T> visitor")
            file.write(")\n\t{\n\t\treturn visitor.visit" + cn + "(*this);\n\t}")
            file.write("\n\nprivate:\n")
            for a in classes__[c]:
                k = a[0]
                file.write("\tconst ")
                if k == "Token":
                    file.write(k + " m_" + a[1])
                elif k == "Expr":
                    file.write("Expression* m_" + a[1])
                elif k == "le":
                    file.write("std::vector<const Expression*> m_" + a[1])
                elif k == "Literal":
                    file.write("Literal m_" + a[1])
                file.write(";\n")
            file.write("};\n\n")

        file.write(after__)
