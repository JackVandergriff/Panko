//
// Created by jack on 2/19/21.
//

#include "panko_ast_builder.h"

using namespace panko;
using namespace panko::scope;

antlrcpp::Any ASTBuilder::visitFile(PankoParser::FileContext *context) {
    auto file = new ast::File();

    file->module = context->IDENTIFIER()->getText();
    auto pop = ast_context.push_local(file->module, ScopeType::MODULE);

    for (auto& statement : context->statement()) {
        file->statements.push_back(make_unique_any<ast::Statement>(statement->accept(this)));
    }

    return file;
}

antlrcpp::Any ASTBuilder::visitBlock(PankoParser::BlockContext *context) {
    auto block = new ast::Block();
    auto pop = ast_context.push_unique_local("", ScopeType::BLOCK);
    for (auto statement : context->statement()) {
        block->statements.push_back(make_unique_any<ast::Statement>(visit(statement)));
    }

    return static_cast<ast::Node*>(block);
}

antlrcpp::Any ASTBuilder::visitBlock_statement(PankoParser::Block_statementContext *context) {
    return visitChildren(context);
}

antlrcpp::Any ASTBuilder::visitSemi_statement(PankoParser::Semi_statementContext *context) {
    return context->children[0]->accept(this);
}

antlrcpp::Any ASTBuilder::visitFunc_decl(PankoParser::Func_declContext *context) {
    auto decl = new ast::FunctionDeclaration();
    ast::Function func{ast_context.mangle(context->ret_type->IDENTIFIER()->getText())};
    auto pop = ast_context.push_local(static_cast<std::string>(context->ret_type->IDENTIFIER()->getText()), ScopeType::FUNCTION);
    func.return_type = make_unique_any<ast::TypeIdentifier>(context->ret_type->type()->accept(this));

    if (!context->params.empty()) {
        for (auto param : context->params) {
            func.parameters.emplace_back(
                util::string_hash{param->IDENTIFIER()->getText()},
                make_unique_any<ast::TypeIdentifier>(param->type()->accept(this))
            );
        }
    }

    func.body = make_unique_any<ast::Block>(context->block()->accept(this));

    decl->function = built_ast.functions.make(std::move(func));

    return static_cast<ast::Node*>(decl);
}

antlrcpp::Any ASTBuilder::visitUnary_expr(PankoParser::Unary_exprContext *context) {
    auto expr = new ast::UnaryOperatorExpression();
    auto op = context->unary_operator()->getText();

    if (op == "!") {
        expr->op = ast::UnaryOperator::NOT;
    } else if (op == "~") {
        expr->op = ast::UnaryOperator::BITNOT;
    }

    expr->lhs = make_unique_any<ast::Expression>(context->expression()->accept(this));

    return static_cast<ast::Node*>(expr);
}

antlrcpp::Any ASTBuilder::visitComplex_assignment(PankoParser::Complex_assignmentContext *context) {
    auto expr = new ast::ComplexAssignment();
    expr->reference = make_unique_any<ast::Expression>(context->expression()->accept(this));
    expr->increment = context->op->getText() == "++";
    return static_cast<ast::Node*>(expr);
}

antlrcpp::Any ASTBuilder::visitBinary_expr(PankoParser::Binary_exprContext *context) {
    auto expr = new ast::BinaryOperatorExpression();
    auto op = context->binary_operator()->getText();

    if (op == "||") {
        expr->op = ast::BinaryOperator::OR;
    } else if (op == "&&") {
        expr->op = ast::BinaryOperator::AND;
    } else if (op == "==") {
        expr->op = ast::BinaryOperator::EQ;
    } else if (op == "!=") {
        expr->op = ast::BinaryOperator::NEQ;
    } else if (op == ">") {
        expr->op = ast::BinaryOperator::GT;
    } else if (op == "<") {
        expr->op = ast::BinaryOperator::LT;
    } else if (op == ">=") {
        expr->op = ast::BinaryOperator::GTEQ;
    } else if (op == "<=") {
        expr->op = ast::BinaryOperator::LTEQ;
    } else if (op == "+") {
        expr->op = ast::BinaryOperator::ADD;
    } else if (op == "-") {
        expr->op = ast::BinaryOperator::SUB;
    } else if (op == "*") {
        expr->op = ast::BinaryOperator::MUL;
    } else if (op == "/") {
        expr->op = ast::BinaryOperator::DIV;
    } else if (op == "%") {
        expr->op = ast::BinaryOperator::MOD;
    } else if (op == "^") {
        expr->op = ast::BinaryOperator::XOR;
    } else if (op == "&") {
        expr->op = ast::BinaryOperator::BITAND;
    } else if (op == "|") {
        expr->op = ast::BinaryOperator::BITOR;
    }

    expr->lhs = make_unique_any<ast::Expression>(context->lhs->accept(this));
    expr->rhs = make_unique_any<ast::Expression>(context->rhs->accept(this));

    return static_cast<ast::Node*>(expr);
}

antlrcpp::Any ASTBuilder::visitSimple_assignment(PankoParser::Simple_assignmentContext *context) {
    auto expr = new ast::SimpleAssignment();
    expr->reference = make_unique_any<ast::Expression>(context->lhs->accept(this));
    expr->expression = make_unique_any<ast::Expression>(context->rhs->accept(this));
    return static_cast<ast::Node*>(expr);
}

antlrcpp::Any ASTBuilder::visitId_expr(PankoParser::Id_exprContext *context) {
    auto expr = new ast::VariableExpression();
    expr->variable = {context->IDENTIFIER()->getText(), std::ref(ast_context)};
    return static_cast<ast::Node*>(expr);
}

antlrcpp::Any ASTBuilder::visitFunc_expr(PankoParser::Func_exprContext *context) {
    auto expr = new ast::FunctionCall();
    expr->function = {context->IDENTIFIER()->getText(), std::ref(ast_context)};

    if (context->argument_list()) {
        for (auto param : context->argument_list()->expression()) {
            expr->arguments.emplace_back(make_unique_any<ast::Expression>(param->accept(this)));
        }
    }

    return static_cast<ast::Node*>(expr);
}

antlrcpp::Any ASTBuilder::visitInt_lit(PankoParser::Int_litContext *context) {
    auto int_lit = new ast::IntegerLiteral();
    int_lit->value = std::stoi(context->INTLIT()->getText());
    return static_cast<ast::Node*>(int_lit);
}

antlrcpp::Any ASTBuilder::visitFloat_lit(PankoParser::Float_litContext *context) {
    auto float_lit = new ast::FloatLiteral();
    float_lit->value = std::stod(context->FLOATLIT()->getText());
    return static_cast<ast::Node*>(float_lit);
}

antlrcpp::Any ASTBuilder::visitVar_decl(PankoParser::Var_declContext *context) {
    auto expr = new ast::VariableDeclaration();
    expr->variable = built_ast.variables.make(
        ast_context.mangle(context->typed_identifier()->IDENTIFIER()->getText()),
        make_unique_any<ast::TypeIdentifier>(context->typed_identifier()->type()->accept(this))
    );

    if (auto assn = context->expression()) {
        expr->assignment = make_unique_any<ast::Expression>(assn->accept(this));
    }

    return static_cast<ast::Node*>(expr);
}

antlrcpp::Any ASTBuilder::visitIf_statement(PankoParser::If_statementContext *context) {
    auto statement = new ast::IfStatement();
    for(auto block : context->if_block()) {
        auto& back = statement->if_blocks.emplace_back();
        back.condition = make_unique_any<ast::Expression>(block->expression()->accept(this));
        back.block = make_unique_any<ast::Block>(block->block()->accept(this));
    }

    if (context->final) {
        statement->else_block = make_unique_any<ast::Block>(context->final->accept(this));
    }

    return static_cast<ast::Node*>(statement);
}

antlrcpp::Any ASTBuilder::visitWhile_loop(PankoParser::While_loopContext *context) {
    auto statement = new ast::WhileLoop();
    statement->condition = make_unique_any<ast::Expression>(context->expression()->accept(this));
    statement->body = make_unique_any<ast::Block>(context->block()->accept(this));
    return static_cast<ast::Node*>(statement);
}

antlrcpp::Any ASTBuilder::visitBool_lit(PankoParser::Bool_litContext *context) {
    auto literal = new ast::BoolLiteral();
    literal->value = context->TRUE();
    return static_cast<ast::Node*>(literal);
}

antlrcpp::Any ASTBuilder::visitReturn_statement(PankoParser::Return_statementContext *context) {
    auto statement = new ast::ReturnStatement();
    statement->expression = make_unique_any<ast::Expression>(context->expression()->accept(this));
    return static_cast<ast::Node*>(statement);
}

antlrcpp::Any ASTBuilder::visitParen_expr(PankoParser::Paren_exprContext *context) {
    return context->expression()->accept(this);
}

antlrcpp::Any ASTBuilder::visitType_decl(PankoParser::Type_declContext *context) { // big TODO also mangle???
    auto type_node = new ast::TypeDeclaration();
    ast::Type type{context->IDENTIFIER()->getText()};

    for (auto var : context->vars) {
        type.attributes.emplace_back(
            util::string_hash{var->typed_identifier()->IDENTIFIER()->getText()},
            make_unique_any<ast::TypeIdentifier>(var->typed_identifier()->type()->accept(this))
        );
    }

    type_node->type = built_ast.types.make(std::move(type));

    return static_cast<ast::Node*>(type_node);
}

antlrcpp::Any ASTBuilder::visitAccess_expr(PankoParser::Access_exprContext *context) {
    auto access = new ast::AccessExpression();

    access->reference = make_unique_any<ast::Expression>(context->expression()->accept(this));
    for (const auto& accessor : context->accessors) {
        access->accessors.emplace_back(accessor->getText());
    }

    return static_cast<ast::Node*>(access);
}

antlrcpp::Any ASTBuilder::visitObj_expr(PankoParser::Obj_exprContext *context) {
    auto expr = new ast::ObjectExpression();

    for (auto var : context->object_var()) {
        expr->members.emplace_back(
            util::string_hash{var->IDENTIFIER()->getText()},
            make_unique_any<ast::Expression>(visit(var->expression()))
        );
    }

    return static_cast<ast::Node*>(expr);
}

ASTBuilder::ASTBuilder() {
    built_ast.types.make("int");
    built_ast.types.make("float");
    built_ast.types.make("bool");
}

ASTBuilder& ASTBuilder::appendFile(PankoParser& parser) {
    built_ast.files.emplace_back((ast::File*)visitFile(parser.file()));
    return *this;
}

[[nodiscard]] const ast::AST& ASTBuilder::getTree() const {
    return built_ast;
}

antlrcpp::Any ASTBuilder::visitBuiltin_type(PankoParser::Builtin_typeContext *context) {
    auto type = new ast::TypeIdentifier();
    type->id.identifier = context->getText();
    return static_cast<ast::Node*>(type);
}

antlrcpp::Any ASTBuilder::visitId_type(PankoParser::Id_typeContext *context) {
    auto type = new ast::TypeIdentifier();
    type->id.identifier = context->IDENTIFIER()->getText();
    return static_cast<ast::Node*>(type);
}

antlrcpp::Any ASTBuilder::visitParen_type(PankoParser::Paren_typeContext *context) {
    return context->type()->accept(this);
}

antlrcpp::Any ASTBuilder::visitTuple_type(PankoParser::Tuple_typeContext *context) {
    auto type = new ast::TypeIdentifier();
    type->op = ast::TypeOperator::TUPLE;

    std::string name = "tp";
    for (auto tuple_type : context->type()) {
        type->other_types.push_back(make_unique_any<ast::TypeIdentifier>(tuple_type->accept(this)));
    }

    return static_cast<ast::Node*>(type);
}

antlrcpp::Any ASTBuilder::visitBinary_type(PankoParser::Binary_typeContext *context) {
    auto type = new ast::TypeIdentifier();

    auto op = context->type_binary_operator()->getText();
    if (op == "&") {
        type->op = ast::TypeOperator::CONJUNCTION;
    } else if (op == "|") {
        type->op = ast::TypeOperator::DISJUNCTION;
    }

    type->other_types.push_back(make_unique_any<ast::TypeIdentifier>(context->lhs->accept(this)));
    type->other_types.push_back(make_unique_any<ast::TypeIdentifier>(context->rhs->accept(this)));

    return static_cast<ast::Node*>(type);
}

antlrcpp::Any ASTBuilder::visitUnary_type(PankoParser::Unary_typeContext *context) {
    auto type = new ast::TypeIdentifier();

    auto op = context->type_unary_operator()->getText();
    if (op == "*") {
        type->op = ast::TypeOperator::REFERENCE;
    } else if (op == "<") {
        type->op = ast::TypeOperator::SUBSET;
    } else if (op == ">") {
        type->op = ast::TypeOperator::SUPERSET;
    }

    type->other_types.push_back(make_unique_any<ast::TypeIdentifier>(context->type()->accept(this)));

    return static_cast<ast::Node*>(type);
}

antlrcpp::Any ASTBuilder::visitArray_type(PankoParser::Array_typeContext *context) {
    auto type = new ast::TypeIdentifier();
    type->op = ast::TypeOperator::ARRAY;
    type->other_types.push_back(make_unique_any<ast::TypeIdentifier>(context->type()->accept(this)));

    return static_cast<ast::Node*>(type);
}

antlrcpp::Any ASTBuilder::visitArray_expr(PankoParser::Array_exprContext *context) {
    auto expr = new ast::ArrayExpression();

    for (auto member : context->expression()) {
        expr->members.push_back(make_unique_any<ast::Expression>(member->accept(this)));
    }

    return static_cast<ast::Node*>(expr);
}

antlrcpp::Any ASTBuilder::visitNull_lit(PankoParser::Null_litContext *) {
    return static_cast<ast::Node*>(new ast::NullLiteral());
}

antlrcpp::Any ASTBuilder::visitArray_access_expr(PankoParser::Array_access_exprContext *context) {
    auto expr = new ast::ArrayAccessExpression();
    expr->reference = make_unique_any<ast::Expression>(context->expression()->accept(this));
    expr->index = std::stoi(context->INTLIT()->getText());
    return static_cast<ast::Node*>(expr);
}
