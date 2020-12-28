// Example program
/**
   a simple version of dynamic bitset class with the name: bitset_ex
   all rights are NOT reserved by DR. zxg519@sina.com
   2020-12-28
*/
#include <iostream>
#include "bitset_ex.h"
using namespace std;

int main()
{

	bitset_ex b1(3);
	b1.reset();
	b1.print();
	b1.set();
	b1.print();
	b1.set(0, 1);
	b1.set(1, 0);
	b1.set(2, 1);
	b1.print();

	//----------------------------------------------------------------------------
	cout << "hi" << endl;
	bitset_ex b(1500);
	b.set();
	b.print();
	b.reset(10);
    b.set_output_format(8);
	b.print();
	b.reset();
    b.set_output_format(10);
	b.print();
	for (int i = 10; i < 50; ++i)
	{
		b.set(i);
		assert(b[i] == true);
		assert(b.test(i) == true);
	}	
	b.reset(20);
	assert(b[20] == false);
	assert(b.test(20)==false);

	b.reset(30);
	assert(b[30] == false);
	assert(b.test(30) == false);

	b.reset(40);
	assert(b[40] == false);
	assert(b.test(40) == false);
    b.set_output_format(8);
	b.print();
	cout << endl;
}
