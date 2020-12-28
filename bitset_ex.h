// Example program
/**
   a simple version of dynamic bitset class with the name: bitset_ex
   all rights are NOT reserved by DR. zxg519@sina.com
   2020-12-28
   
Interface：
   set()
   reset()
   test()
   operator []
   print()
*/
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
using namespace std;

class bitset_ex
{
public:
    
	bitset_ex(const int bit_size1) :bit_size(bit_size1)
	{
		long_size = (bit_size + (long_bit_size - 1)) / long_bit_size;
		data = new long[long_size]();
		memset(data, 0, sizeof(long)*long_size);
	}
	~bitset_ex()
	{
		delete []data;
	}
public:
	bool test(const int bit_pos) const
	{
		return data[bit_pos / long_bit_size] & (1 << (bit_pos % long_bit_size));
	}
	const bool operator[](const int bit_pos) const
	{
		return data[bit_pos / long_bit_size] & (1 << (bit_pos % long_bit_size));
	}
	void set(const int bit_pos=-1, const bool set_value = true)
	{
		if (bit_pos == -1)
		{
			memset(data, 0XFF, sizeof(long)*long_size);
			return;
		}
		//---------------------------------------------------------------------
		if (set_value)
			data[bit_pos / long_bit_size] |= (1 << (bit_pos % long_bit_size));
		else
			data[bit_pos / long_bit_size] &= (~(1 << (bit_pos % long_bit_size)));
	}
	void reset(const int bit_pos = -1)
	{
		if (bit_pos == -1)  //  if bit_pos == -1, reset all bit to zero
		{
			memset(data, 0, sizeof(long)*long_size);
		}
		else // otherwise, only set the given bit_pos to zero
		{
			data[bit_pos / long_bit_size] &= (~(1 << (bit_pos % long_bit_size)));
		}
	}

	void print()
	{
		bool if_start = false;
		for (int i = bit_size - 1; i >= 0; --i)
		{
			if ((*this)[i] == true)
				cout << 1;
			else
				cout << 0;
		}		
		cout << endl;
	}
protected:
	long*  data;
	int    long_size;
	int    bit_size;
	const static int long_bit_size = sizeof(long)*8;
};
