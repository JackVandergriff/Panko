#include <iostream>
#include <filesystem>
#include "antlr4-runtime/PankoLexer.h"
#include "antlr4-runtime/PankoParser.h"

#include "panko_interpreter.h"
#include "panko_ast_builder.h"

using namespace std;
using namespace antlr4;
using namespace panko;

int main() {
    std::ifstream stream;
    //std::cout << "[---] Open file: ";
    std::filesystem::path path{"../sample.pk"};
    //std::cin >> path;

    if (!std::filesystem::exists(path)) {
        std::cout << "[!!!] File " << path.lexically_normal() << " doesn't exist\n";
    }

    stream.open(path);

    ANTLRInputStream input(stream);
    PankoLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();
    for (auto token : tokens.getTokens()) {
        std::cout << token->toString() << std::endl;
    }

    PankoParser parser(&tokens);

    ASTBuilder builder;
    auto& ast = builder.appendFile(parser).getTree();

    runtime::Interpreter interpreter{ast};

    interpreter.run();

    return 0;
}