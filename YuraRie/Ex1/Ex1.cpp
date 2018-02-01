
#include <iostream>

//Function prototype
void toFizzBuzz(unsigned int value);


int main(){

    std::cout << "\n===Unit1===\n";
    for(int i = 1;i <= 100 ; ++i)
        toFizzBuzz(i);
    std::cout << "\n";

    std::cout << "\n===Unit2===\n";


    std::cout << "\n===Unit3===\n";
    
    
    std::cout << "\n===Unit4===\n";
    
    
    std::cout << "\n===Unit5===\n\n\n";

    
    return 0;
}

//ループと割り算系のものを使わない縛りのFizzBuzz
inline void toFizzBuzz(unsigned int value) {
    unsigned int value3(value), value5(value), value5_m(value);
    bool b3(0), b5(0);
    int shift;
    //3 check
    value3 = ((value3 >> 4) & 0x0f0f0f0f) + (value3 & 0x0f0f0f0f);
    value3 = (value3 >> 8) + value3;
    value3 = (value3 >> 16) + value3;
    value3 = ((value3 >> 4) & 7) + (value3 & 0xf);
    b3 = ((0x49249248 >> value3) & 1);
    //5 check
    value5 = (value5 & 0x33333333) ;
    value5_m = ((value5_m >> 2) & 0x33333333);
    value5 = ((value5 >> 4)& 0x0F0F0F0F) + (value5 & 0x0F0F0F0F);
    value5 = ((value5 >> 8)& 0x00FF00FF) + (value5 & 0x00FF00FF);
    value5 = ((value5 >> 16)& 0xFFFF) + (value5 & 0xFFFF);
    value5_m = ((value5_m >> 4)& 0x0F0F0F0F) + (value5_m& 0x0F0F0F0F);
    value5_m = ((value5_m >> 8)& 0x00FF00FF) + (value5_m& 0x00FF00FF);
    value5_m = ((value5_m >> 16)& 0xFFFF) + (value5_m& 0xFFFF);
    shift = (value5) - (value5_m);
    b5 = ((0x842108421 >> shift) & 1 );
    //out
    if(b3|b5)
        std::cout << (b3?"Fizz":"") << (b5?"Buzz":"") << ' ';
    else
        std::cout << value << ' ';
}
