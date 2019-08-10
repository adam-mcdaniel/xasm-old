prelude = """
#include "dragon.hpp"
#include <iostream>
using namespace dragon;

using Fn = Function<dragon::Machine&, void, dragon::Machine>;

void table(Machine& xasm) {
	xasm.push(Object::Map());
}



void list(Machine& xasm) {
	xasm.push(Object::List({}));
}

void push(Machine& xasm) {
    auto l = xasm.pop();
    l->push(xasm.pop());
}

void pop(Machine& xasm) {
    auto l = xasm.pop();
    xasm.push(l->pop());
}



void print(Machine& xasm) {
    std::cout << xasm.pop()->format();
}

void println(Machine& xasm) {
    print(xasm);
    std::cout << std::endl;
}



"""