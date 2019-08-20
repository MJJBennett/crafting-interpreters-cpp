#!/usr/bin/env python3

# Script to generate expression classes

template__ = """#ifndef EXPRESSION_LOX_H
#define EXPRESSION_LOX_H

#include "tokens.h"

struct Expression
{
};
"""

after__ = """#endif  // EXPRESSION_LOX_H
"""

classes__ = {
    "Unary": [("Token", "op"), ("Expr", "right")],
    "Variable": [("Token", "name")],
    "Binary": [("Expr", "left"), ("Token", "op"), ("Expr", "right")],
    "Assign": [("Token", "name"), ("Expr", "value")],
    "This": [("Token", "keyword")],
    "Super": [("Token", "keyword"), ("Token", "method")],
    "Set": [("Expr", "object"), ("Token", "name"), ("Expr", "value")],
    "Logical": [("Expr", "left"), ("Token", "op"), ("Expr", "right")]
}

if __name__ == '__main__':
    with open("include/expression.h", "w") as file:
        file.write(template__)
        file.write("\n")

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
                needcomma = True
            needcomma = False
            file.write(")\n\t\t: ")
            for a in classes__[c]:
                if needcomma:
                    file.write(", ")
                file.write("m_" + a[1] + "(" + a[1] + ")")
                needcomma = True
            file.write("\n\t{\n\t}\n\nprivate:\n")
            for a in classes__[c]:
                k = a[0]
                file.write("\tconst ")
                if k == "Token":
                    file.write(k + " m_" + a[1])
                elif k == "Expr":
                    file.write("Expression* m_" + a[1])
                file.write(";\n")
            file.write("};\n\n")

        file.write(after__)
