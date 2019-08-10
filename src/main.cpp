

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
	
    xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("a")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("b")); xasm.store(); xasm.push(Object::String("a")); xasm.load();}, xasm)));}, xasm))); xasm.clone(); xasm.push(Object::String("True")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("a")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("b")); xasm.store(); xasm.push(Object::String("b")); xasm.load();}, xasm)));}, xasm))); xasm.clone(); xasm.push(Object::String("False")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("a")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("b")); xasm.store(); xasm.push(Object::String("a")); xasm.load(); xasm.push(Object::String("b")); xasm.load(); xasm.push(Object::String("a")); xasm.load(); xasm.call(); xasm.call();}, xasm)));}, xasm))); xasm.clone(); xasm.push(Object::String("And")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("a")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("b")); xasm.store(); xasm.push(Object::String("b")); xasm.load(); xasm.push(Object::String("a")); xasm.load(); xasm.push(Object::String("a")); xasm.load(); xasm.call(); xasm.call();}, xasm)));}, xasm))); xasm.clone(); xasm.push(Object::String("Or")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("a")); xasm.store(); xasm.push(Object::String("True")); xasm.load(); xasm.push(Object::String("False")); xasm.load(); xasm.push(Object::String("a")); xasm.load(); xasm.call();}, xasm))); xasm.clone(); xasm.push(Object::String("Not")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("c")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("a")); xasm.store(); xasm.push(Object::Fn(Fn([] (Machine & xasm) {xasm.push(Object::String("b")); xasm.store(); xasm.push(Object::String("b")); xasm.load(); xasm.push(Object::String("a")); xasm.load(); xasm.push(Object::String("c")); xasm.load(); xasm.call(); xasm.call();}, xasm)));}, xasm)));}, xasm))); xasm.clone(); xasm.push(Object::String("If")); xasm.store(); xasm.push(Object::Number(10000)); xasm.clone(); xasm.push(Object::String("n")); xasm.store(); xasm.push(Object::String("n")); xasm.load();while (*xasm.pop()) {xasm.push(Object::String("b")); xasm.push(Object::String("a")); xasm.push(Object::String("False")); xasm.load(); xasm.push(Object::String("True")); xasm.load(); xasm.push(Object::String("And")); xasm.load(); xasm.call(); xasm.call(); xasm.push(Object::String("If")); xasm.load(); xasm.call(); xasm.call(); xasm.call(); xasm.push(Object::String("println")); xasm.load(); xasm.call(); xasm.push(Object::Number(1)); xasm.push(Object::String("n")); xasm.load(); xasm.sub(); xasm.clone(); xasm.push(Object::String("n")); xasm.store();xasm.push(Object::String("n")); xasm.load();}
}
