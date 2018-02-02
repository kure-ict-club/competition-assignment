#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

//単純選択ソート
void selection(std::vector<int> &a, int n);
//バブルソート
void bubble(std::vector<int> &a, int n);

template<typename T>
bool swap_X(T* a,T* b);


int main(){

    std::fstream fs("data.txt");
    std::string line,buf,select,select_a;
    std::vector<int> data;
    getline(fs,line);
    std::istringstream iss(line);
    getline(iss, select, ':');
    getline(iss, select_a);
    getline(fs, line);
    getline(fs, line);
    std::istringstream iss2(line);
    while(getline(iss2, buf, ' ')){
        data.push_back(std::stoi(buf));
    }

    //
    if(select_a.c_str() == "1") 
        selection(data, data.size());
    else
        bubble(data, data.size());


    if(select.c_str() == "0"){
        std::cout << "0";
        for(auto it = data.begin();it != data.end();it++)
            std::cout << " " << *it;
    }
    else{
        std::cout << "1";
        for(auto it = data.rbegin();it != data.rend();it++)
            std::cout << " " << *it;
    }
    std::cout << "\n";
    return 0;
}


//単純選択ソート
void selection(std::vector<int> &a, int n)
{
	int i, j;
	
	for(i = 0; i < n -1; i++){
		int min = i;
		for(j = i +1; j < n; j++ )
			if(a[j] < a[min])
				min = j;
		swap_X(&a[i], &a[min]);
	}
}

//バブルソート
void bubble(std::vector<int> &a, int n)
{
	int k = 0;
	
	while(k < n - 1){
		int j;
		int last = n - 1;
		
		for(j = n - 1; j > k; j--){
			if(a[j - 1] > a[j]){
				swap_X(&a[j -1], &a[j]);
				last = j;
			}
		}
		k = last;
	}
}

//swap
template<typename T>
bool swap_X(T* a,T* b)
{
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return 0;
}
