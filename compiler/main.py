from prelude import prelude
from parser import Parser
from lark import Lark, Transformer, UnexpectedCharacters, UnexpectedToken
from os.path import dirname, basename

import argparse

parser = argparse.ArgumentParser(description='Assemble a XASM program')
parser.add_argument(
    '--input', dest='input',
    help='Path to XASM source',
    required=True
)
parser.add_argument(
    '--output', dest='output',
    help='Path to output C++ source',
    required=True
)

args = parser.parse_args()


text = open(args.input).read()

# Create lexer
lexer = Lark.open(
    dirname(__file__) + '/grammar.lark',
    start='start',
    parser='lalr',
    lexer='standard',
).parse(text)


# C++ output
compiled = ' '.join(
        Parser().transform(lexer).split()
    ).replace(';;', ';').replace(';;', ';')


open(args.output, 'w').write(f'''
{prelude}
int main() {{
	auto xasm = Machine();
	xasm.push(Object::Fn(Fn(table, xasm)));
	xasm.push(Object::String("table"));
	xasm.store();
	xasm.push(Object::Fn(Fn(print, xasm)));
	xasm.push(Object::String("print"));
	xasm.store();
	xasm.push(Object::Fn(Fn(println, xasm)));
	xasm.push(Object::String("println"));
	xasm.store();
	xasm.push(Object::Fn(Fn(list, xasm)));
	xasm.push(Object::String("list"));
	xasm.store();
	xasm.push(Object::Fn(Fn(push, xasm)));
	xasm.push(Object::String("push"));
	xasm.store();
	xasm.push(Object::Fn(Fn(pop, xasm)));
	xasm.push(Object::String("pop"));
	xasm.store();
	
    {compiled}
}}
''')