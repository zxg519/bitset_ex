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
   
   
改造成C语言，也很简单：
   init(),       返回指针
   release(long*,...)     干掉
   set(long*,....)
   reset(long*,...)
   output(long*,...)
   test(long*,const int bitpos)
   
或者，直接用struct,
    bitset_init(struct bitset_ex*, ...)
    bitset_relase(struct bitset_ex*,...)
    bitset_set(struct bitset_ex*,...)
    bitset_rest(struct bitset_ex*,...)
    ....
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
        delete[]data;
    }
public:
    size_t size()    {
        return bit_size;
    }
    bool any()
    {
        long ret = 0;
        for (int i = 0; i < long_size; ++i)
            ret |= data[i];
        return (ret != 0);
    }
    bool none()
    {
        long ret = 0;
        for (int i = 0; i < long_size; ++i)
            ret = data[i];
        return (ret == 0);
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
    void set(const int bit_pos = -1, const bool set_value = true)
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
            if (i % cluster_output == 0)
                cout << " ";
        }
        cout << endl;
    }
public:
    class delegator
    {
        public:
            delegator(bitset_ex& bs, const int bitpos) :p(&bs), bit_pos(bitpos){}
        public:
            delegator& operator = (const bool value) // a special design
            {
                if (p)
                    p->set(bit_pos, value);
                return (*this);
            }
            delegator& operator=(const delegator& db)  //bitset_ex b1(..),b2(..);   b1[i] = b2[j];
            {    // assign delegator to element
                p->set(bit_pos, bool(db));
                return (*this);
            }
            bool operator ~() const
            {    // return complemented element
                return (!p->test(bit_pos));
            }
            operator bool() const                     // if(bi[i]) 
            {    // return element
                return (p->test(bit_pos));
            }
        protected:
            bitset_ex * p;
            int         bit_pos;
    };

    bitset_ex::delegator operator[](const int bit_pos)
    {
        return bitset_ex::delegator(*this,bit_pos);
    }

public:
    void set_output_format(const int output_cluster_digits = 8) // 如： 111101 00110011 11110000， 即多少个bit后输出空格分开！
    {
        if (output_cluster_digits <= 0)
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
    const static int long_bit_size = sizeof(long) * 8;
};

/*************************************************************************************************
  a simple example.
  
#include <bitset>

int main()
{

    bitset_ex b1(5);
    b1.reset();
    b1.print();
    b1.set();
    b1.print();
    b1.set(0, 1);
    b1.set(1, 0);
    b1.set(2, 1);
    b1.set(3, 1);
    b1.print();
    b1[3] = 0;       // using inner class object to assign bit!!!!!!!!!!!!!!
    cout << b1[3] << endl;
    b1.print();
    
    //----------------------------------------------------------------------------
    cout << "hi" << endl;
    bitset_ex b(57);
    b.set();
    b.print();
    b.reset(10);
    b.print();
    b.reset();
    b.print();
    b.set();
    b.print();
    for (int i = 10; i < 50; ++i)
    {
        b.reset(i);
        assert(b[i] == false);
        assert(b.test(i) == false);
    }
    b.print();

    for (int i = 10; i < 50; ++i)
    {
        b.set(i);
        assert(b[i] == true);
        assert(b.test(i) == true);
    }

    b.reset(20);
    assert(b[20] == false);
    assert(b.test(20) == false);

    b.reset(30);
    assert(b[30] == false);
    assert(b.test(30) == false);

    b.reset(40);
    assert(b[40] == false);
    assert(b.test(40) == false);
    b.print();
    b.print();
    cout << endl;

}
*******************************************************************************************************/
