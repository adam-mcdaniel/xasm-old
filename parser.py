from lark import Lark, Transformer, UnexpectedCharacters, UnexpectedToken


MACHINE = "xasm"

push = lambda val: f'{MACHINE}.push({val});'
quote = lambda name: "\"" + str(name) + "\""
load = lambda name: f'{push(x_str(quote(name)))} {MACHINE}.load();'

x_num = lambda n: f'Object::Number({n})'
x_str = lambda s: f'Object::String({s})'
x_fn = lambda fn: f'Object::Fn(Fn([] (Machine & {MACHINE}) {{{fn}}}, {MACHINE}))'
x_while_loop = lambda condition, fn: f'{condition};while (*{MACHINE}.pop()) {{{fn};{condition}}}'

x_call = f'{MACHINE}.call();'
x_method_call = lambda index: f'{push(x_str(quote(index)))} {MACHINE}.method_call()'


literal = lambda l: lambda self, n: l

def dot_name(names):
    result = ""
    for name in names:
        result += push(x_str(quote(name))) + f' {MACHINE}.index();'
    return result

def index_name(names):
    result = ""
    for name in names:
        result += name + f' {MACHINE}.index();'
    return result

class Parser(Transformer):
    def start(self, values):
        str_vals = list(map(str, values))
        return '\n'.join(str_vals)
        
    def assign(self, names):
        name = names[0]
        return f'{MACHINE}.clone(); ' + push(x_str(quote(name))) + f' {MACHINE}.store();'
        
    def attribute_assign(self, names):
        return f'{MACHINE}.clone(); ' + names[0][0] + dot_name(names[0][1:]) + f' {MACHINE}.assign();'
        
    def index_assign(self, names):
        return f'{MACHINE}.clone(); ' + names[0][0] + index_name(names[0][1:]) + f' {MACHINE}.assign();'

    def method_call(self, values):
        return values[0][0] + dot_name(values[0][1:-1]) + ' ' + x_method_call(values[0][-1]) + ';'
        # if len(names[0]) > 2:
        #     return dot_name(names[0][:-1]) + ' ' + x_method_call(names[0][-1]) + ';'
        # else:
        #     return load(names[0][0]) + ' ' + x_method_call(names[0][1]) + ';'

    def call(self, values):
        function = values[0]
        return function + ' ' + x_call

    def load_dot(self, values):
        return values[0][0] + dot_name(values[0][1:])

    def load_index(self, values):
        return values[0][0] + index_name(values[0][1:])

    def index_name(self, names):
        return [names[0]] + list(names[1:])

    def dot_name(self, names):
        return [load(names[0])] + list(names[1:])

    def dot_value(self, names):
        return names
        # result = names[0]
        # for name in names[1:]:
        #     result += push(x_str(quote(name))) + f' {MACHINE}.index();'
        # return result

    def parameters(self, names):
        result = ""
        for name in names:
            result += push(x_str(quote(name))) + f' {MACHINE}.store();'
        return result

    def group(self, exprs):
        return self.start(exprs)

    def fn(self, exprs):
        return push(x_fn(self.start(exprs)))

    def while_loop(self, exprs):
        return x_while_loop(exprs[0], exprs[1])

    name = lambda self, names: str(names[0])
    def load(self, names):
        name = names[0]
        return load(name)

    mul = literal(f'{MACHINE}.mul();')
    div = literal(f'{MACHINE}.div();')
    add = literal(f'{MACHINE}.add();')
    sub = literal(f'{MACHINE}.sub();')
    
    string = lambda self, n: push(x_str(n[0]))
    number = lambda self, n: push(x_num(n[0]))
    true = lambda *_: push(x_num(1))
    false = lambda *_: push(x_num(0))