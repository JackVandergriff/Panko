grammar Panko;

// PARSER RULES

file : MODULE IDENTIFIER SEMICLN (statement)+ EOF;

block : OBRACE (statement)* CBRACE;

func_decl: ret_type=typed_identifier OPAREN (params+=typed_identifier (COMMA params+=typed_identifier)*)? CPAREN block;

statement : func_decl #block_statement
 | var_decl SEMICLN #semi_statement
 | type_decl #block_statement
 | if_statement #block_statement
 | while_loop #block_statement
 | block #block_statement
 | return_statement SEMICLN #semi_statement
 | expression SEMICLN #semi_statement;

expression : OPAREN expression CPAREN #paren_expr
 | expression (PERIOD accessors+=IDENTIFIER)+ #access_expr
 | expression OBRACKET INTLIT CBRACKET #array_access_expr
 | lhs=expression binary_operator rhs=expression #binary_expr
 | unary_operator expression #unary_expr
 | IDENTIFIER OPAREN argument_list? CPAREN #func_expr
 | lhs=expression assignment_operator rhs=expression #simple_assignment
 | expression op=(INC | DEC) #complex_assignment
 | OBRACE (object_var COMMA)* object_var CBRACE #obj_expr
 | OBRACKET (expression COMMA)* expression CBRACKET #array_expr
 | IDENTIFIER #id_expr
 | INTLIT #int_lit
 | FLOATLIT #float_lit
 | (TRUE | FALSE) #bool_lit
 | KW_NULL #null_lit;

type : OPAREN type CPAREN #paren_type
 | type type_unary_operator #unary_type
 | lhs=type type_binary_operator rhs=type #binary_type
 | OBRACKET type (COMMA type)* CBRACKET #tuple_type
 | type ELIPSIS #array_type
 | (INT | FLOAT | KW_NULL) #builtin_type
 | IDENTIFIER #id_type;

typed_identifier : type id=IDENTIFIER;

argument_list : expression (COMMA expression)*;

var_decl : typed_identifier (ASSIGN expression)?;

if_statement : IF if_block (ELSE IF if_block)* (ELSE final=block)?;

if_block : OPAREN expression CPAREN block;

while_loop : WHILE OPAREN expression CPAREN block;

return_statement : RETURN expression;

type_decl : TYPE IDENTIFIER OBRACE ((vars+=var_decl SEMICLN) | funcs+=func_decl)+ CBRACE;

object_var : IDENTIFIER COLON expression;


// KEYWORDS

TYPE : 'type';
TRUE : 'true';
FALSE : 'false';
IF : 'if';
ELSE : 'else';
WHILE : 'while';
FOR : 'for';
KW_NULL : 'null';
INT : 'int';
FLOAT : 'float';
RETURN : 'return';
MODULE : 'module';
IMPORT : 'import';

// OPERATORS

OR : '||';
AND : '&&';
EQ : '==';
NEQ : '!=';
GT : '>';
LT : '<';
GTEQ : '>=';
LTEQ : '<=';
ADD : '+';
SUB : '-';
MUL : '*';
DIV : '/';
MOD : '%';
XOR : '^';
BITOR : '|';
BITAND : '&';
BITNOT : '~';
NOT : '!';
ELIPSIS : '...';

binary_operator : OR | AND | EQ | NEQ | GT | LT | GTEQ | LTEQ | ADD | SUB | MUL | DIV | MOD | XOR | BITAND | BITOR ;
unary_operator : BITNOT | NOT;
type_unary_operator : GT | LT | MUL;
type_binary_operator : BITAND | BITOR;

// ASSIGNMENT OPERATORS

ASSIGN : '=';
ADDEQ : '+=';
SUBEQ : '-=';
MULEQ : '*=';
DIVEQ : '/=';
MODEQ : '%=';
XOREQ : '^=';
BITOREQ : '|=';
BITANDEQ : '&=';
INC : '++';
DEC : '--';

assignment_operator : ASSIGN | ADDEQ | SUBEQ | MULEQ | DIVEQ | MODEQ | XOREQ | BITANDEQ | BITOREQ;


// OTHER DELIMITERS

SEMICLN : ';';
COLON : ':';
COMMA : ',';
PERIOD : '.';
OPAREN : '(';
CPAREN : ')';
OBRACE : '{';
CBRACE : '}';
OBRACKET : '[';
CBRACKET : ']';

// LITERALS 

IDENTIFIER
 : [a-zA-Z_] [a-zA-Z_0-9]*;

INTLIT
 : [0-9]+;

FLOATLIT
 : [0-9]+ '.' [0-9]* | '.' [0-9]+;

COMMENT 
 : '//' ~[\r\n]* -> skip;

MULTILINE_COMMENT
 : '/*' .*? '*/' -> skip;

SPACE
 : [ \t\r\n] -> skip;