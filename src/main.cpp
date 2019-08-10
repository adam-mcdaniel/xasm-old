

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




int main() {
	auto xasm = Machine();
	xasm.push(Object::Fn(Fn(table, xasm)));
	xasm.push(Object::String("table"));
	xasm.store();
	xasm.push(Object::Fn(Fn(table, xasm)));
	xasm.push(Object::String("new"));
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
	
    xasm.push(Object::Fn(Fn([] (Machine & xasm) { xasm.push(Object::String("new")); xasm.load(); xasm.call(); xasm.clone(); xasm.push(Object::String("self")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("self")); xasm.store();xasm.push(Object::String("value")); xasm.store();xasm.push(Object::String("sign")); xasm.store(); xasm.push(Object::String("value")); xasm.load(); xasm.clone(); xasm.push(Object::String("self")); xasm.load();xasm.push(Object::String("value")); xasm.index(); xasm.assign(); xasm.push(Object::String("sign")); xasm.load(); xasm.clone(); xasm.push(Object::String("self")); xasm.load();xasm.push(Object::String("sign")); xasm.index(); xasm.assign(); xasm.push(Object::String("self")); xasm.load();}, xasm))); xasm.clone(); xasm.push(Object::String("self")); xasm.load();xasm.push(Object::String("constructor")); xasm.index(); xasm.assign(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("self")); xasm.store();xasm.push(Object::String("value")); xasm.store(); xasm.push(Object::String("value")); xasm.load(); xasm.clone(); xasm.push(Object::String("self")); xasm.load();xasm.push(Object::String("value")); xasm.index(); xasm.assign();}, xasm))); xasm.clone(); xasm.push(Object::String("self")); xasm.load();xasm.push(Object::String("set_value")); xasm.index(); xasm.assign(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("self")); xasm.store();xasm.push(Object::String("value")); xasm.store(); xasm.push(Object::Number(1)); xasm.push(Object::String("self")); xasm.load();xasm.push(Object::String("value")); xasm.index(); xasm.add(); xasm.clone(); xasm.push(Object::String("self")); xasm.load();xasm.push(Object::String("value")); xasm.index(); xasm.assign();}, xasm))); xasm.clone(); xasm.push(Object::String("self")); xasm.load();xasm.push(Object::String("increment")); xasm.index(); xasm.assign(); xasm.push(Object::String("self")); xasm.load();}, xasm))); xasm.clone(); xasm.push(Object::String("Number")); xasm.store(); xasm.push(Object::Number(0)); xasm.push(Object::Number(5)); xasm.push(Object::String("Number")); xasm.load(); xasm.call(); xasm.push(Object::String("constructor")); xasm.method_call(); xasm.clone(); xasm.push(Object::String("num")); xasm.store(); xasm.push(Object::String("num")); xasm.load();xasm.push(Object::String("value")); xasm.index(); xasm.push(Object::String("println")); xasm.load(); xasm.call(); xasm.push(Object::String("num")); xasm.load(); xasm.push(Object::String("increment")); xasm.method_call(); xasm.push(Object::String("num")); xasm.load(); xasm.push(Object::String("increment")); xasm.method_call(); xasm.push(Object::String("num")); xasm.load();xasm.push(Object::String("value")); xasm.index(); xasm.push(Object::String("println")); xasm.load(); xasm.call();
}
