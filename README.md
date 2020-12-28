# bitset_ex
a C++ bitset class which allows set bit-number during run time. As know, the standard C++ doesn't support init a bitset class during runtime using a runtime result.

# interface
1. set(const int bitpos) - set the given bitpos to 1, if the parameter is -1, set all bit to 1

2. reset(const int bitpos, const bool value) - set the given bitpos to the given value (0 or 1)

3. test(const int bitpos) - try to get the bit value, true for 1, and false for 0

4. operator(const int bitpos) - the same as the function test(..)

5. print() - output the bitset, the output format is controlled by function set_output_format(...)

6. set_output_format(const int cluster_bit_size) - set output format

please contact zxg519@sina.com or xgzhang at seu.edu.cn if you have any question to use the class.

# A simple example
int main()  
{  
   bitset_ex bs(7);   
   bs.set();   
   bs.set_output_format(4);   
   bs.print();     
   
   bs.set(1);     
   bs.set(2);     
   bs.reset(3);     
   bs.print();     
   
   if(bs.test(2))    
       cout<<"good"<<endl;    
   else  
       cout<<"bad"<<endl;  
}
 

