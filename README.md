# bitset_ex
a C++ bitset class which allows set bit-number during run time. As know, the standard C++ doesn't support init a bitset class during runtime using a runtime result.

# interface
1. set(const int bitpos) - set the given bitpos to 1, if the parameter is -1, set all bit to 1

2. reset(const int bitpos, const bool value) - set the given bitpos to the given value (0 or 1)

3. test(const int bitpos) - try to get the bit value, true for 1, and false for 0

4. operator(const int bitpos) - the same as the function test(..)

5. print() - output the bitset, the output format is controlled by function set_output_format(...)

6. set_output_format(const int cluster_bit_size) - set output format

7. operator[] - set to true or set to false 

please contact zxg519@sina.com or xgzhang at seu.edu.cn if you have any question to use the class.

# A simple example
int main()  
{  
   &nbsp;&nbsp;&nbsp;bitset_ex bs(7);   
   &nbsp;&nbsp;&nbsp;&nbsp;bs.set();   
   &nbsp;&nbsp;&nbsp;&nbsp;bs.set_output_format(4);   
   &nbsp;&nbsp;&nbsp;&nbsp;bs.print();     
   
   &nbsp;&nbsp;&nbsp;&nbsp;bs.set(3);     
   &nbsp;&nbsp;&nbsp;&nbsp;bs.reset(2);     
   &nbsp;&nbsp;&nbsp;&nbsp;bs.reset(4);     
   &nbsp;&nbsp;&nbsp;&nbsp;bs.print();     
   
   &nbsp;&nbsp;&nbsp;&nbsp;bs[2] = true;     
   &nbsp;&nbsp;&nbsp;&nbsp;bs[3] = false;     
   &nbsp;&nbsp;&nbsp;&nbsp;bs.print();      
   
   &nbsp;&nbsp;&nbsp;&nbsp;if(bs.test(2))    
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<"good"<<endl;    
   &nbsp;&nbsp;&nbsp;&nbsp;else  
   &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;cout<<"bad"<<endl;  
}
 

