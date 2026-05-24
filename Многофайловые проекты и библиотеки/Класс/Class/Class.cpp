#include "Class.h"
#include <iostream>


Counter::Counter() {}

Counter::Counter(int a) {
	this->__a = a;
}

	void Counter::inc() {
		++__a;
	}
	void Counter::dec() {
		--__a;
	}
	int Counter::get_val() const {
		return __a;
	}



