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
		for (int i = bit_size - 1; i >= 0; --i)
		{
			if ((*this)[i] == true)
				cout << 1;
			else
				cout << 0;
                        if(i % cluster_output == 0)
                                cout<<" ";
		}		
		cout << endl;
	}
public:
    void set_output_format(const int output_cluster_digits = 8) // 如： 111101 00110011 11110000， 即多少个bit后输出空格分开！
    {
        if(output_cluster_digits <= 0)
        {
            cluster_output = 8;   // 非法输入，强制设置为8-bit连续输出，从低位到高位！
        }
        cluster_output = output_cluster_digits;
    }
    
protected:
	long*  data;
	int    long_size;         // 多少位整数，内部使用！！！    
	int    bit_size;          // 位数
    int    cluster_output;    // 连续多少位输出后加分隔空格，如 1111 0000, 或者 11110000 00110011 ，或者 11 1111100000 0011001100
	const static int long_bit_size = sizeof(long)*8;
};
