from parser import Parser
from lark import Lark, Transformer, UnexpectedCharacters, UnexpectedToken

text = open("input.rs").read()


lexer = Lark.open(
    'grammar.lark',
    start='start',
    parser='lalr',
    lexer='standard',
).parse(text)

# print(Parser().transform(lexer).pretty())
print(
    ' '.join(
        Parser().transform(lexer).split()
    ).replace(';;', ';').replace(';;', ';') #.replace(';', ';\n')
)
