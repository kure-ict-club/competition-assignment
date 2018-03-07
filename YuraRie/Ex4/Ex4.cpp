
#include <iostream>
#include <vector>
#include <cmath>

class PrimeFactorData;

//-------------------------------------------------------------------------------------------
//  prototype
//-------------------------------------------------------------------------------------------
//  素数生成
std::vector<int> PrimeGenerator(unsigned int len);
//  素因数分解
std::vector<PrimeFactorData> PrimeFactorization(unsigned int len, std::vector<int> prime);
//  rad(n)
unsigned int rad(unsigned int n, std::vector<int> prime);
//  q(a, b, c)
double q(unsigned int a, unsigned int b, unsigned int c, std::vector<int> prime);
//-------------------------------------------------------------------------------------------


int main(){
    std::cout << "    シングルスレッドでしかやってないので遅いです。\n\
    終わりないので気を付けて。\n\
    やるならマルチスレッドに改造してください。\n";
    auto prime = PrimeGenerator(100*100*100*100);
    std::cout << "k が1以上の時のみ\n";
    unsigned int s;
    for(int a = 1; a <= 100; a++){
        for(int b = 1; b <= 100; b++){
            if(1 <= (s = q(a, b, a+b, prime))){
                std::cout << s << "\n";
            }
        }
    }

    return 0;
}

class PrimeFactorData{
public:
    unsigned int number;
    unsigned int amount;
};

//素数生成
std::vector<int> PrimeGenerator(unsigned int len)
{
    std::vector<int> prime;
    prime.reserve(len-1);
    int i = 2;
    do{
        prime.push_back(i);
    } while(i++ < len);

    auto it = prime.begin();
    auto it_d = it;
    auto it_end = prime.end();
    while(it < it_end){
        i = *it;
        it_d = it+1;
        while(it_d < it_end){
            if(*it_d % i == 0){
                prime.erase(it_d);
                it_end = prime.end();
            } else it_d++;
        }
        it++;
    }
    prime.shrink_to_fit();
    return prime;
}

//素因数分解
std::vector<PrimeFactorData> PrimeFactorization(unsigned int len, std::vector<int> prime)
{
    if((len/2) > *(prime.end()-1) ){
        std::cout << "over\n";
    }
    std::vector<PrimeFactorData> data;
    PrimeFactorData pf;
    for(auto it : prime){
        unsigned int g = 0, temp = len;
        while((temp % it) == 0){
            temp /= it;
            g++;
        }
        if(g != 0){
            pf.number = it;
            pf.amount = g;
            data.push_back(pf);
        }
    }

    return data;
}

//rad(n)
unsigned int rad(unsigned int n, std::vector<int> prime){
    auto primeF = PrimeFactorization(n, prime);
    unsigned int data = 1;
    for(auto it: primeF)
        data *= it.number;
    return data;
}

//q(a, b, c)
double q(unsigned int a, unsigned int b, unsigned int c, std::vector<int> prime)
{
    return std::log(c) / std::log(rad(a*b*c, prime));
}

