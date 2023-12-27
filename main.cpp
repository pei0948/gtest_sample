#include "calculator.h"
#include "add.h"
#include <iostream>

int main(int argc, char** argv) {
	std::shared_ptr<Adder> addSptr = std::make_shared<Adder>();
        std::shared_ptr<Calculator> calculatorSptr = std::make_shared<Calculator>();
        calculatorSptr->SetAddSptr(addSptr);
	std::cout << calculatorSptr->Add(1, 2) << std::endl;
	return 0;
}
