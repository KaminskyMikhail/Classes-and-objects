#pragma once
class Counter {

private:
	int __a = 1;

public:
	Counter();
	Counter(int a);
	void inc();
	void dec();
	int get_val() const;

};
