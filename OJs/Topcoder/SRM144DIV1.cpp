#include <iostream>                  //引用库
#include <string.h>
#include <vector>
using namespace std;                 //命名空间
 
class BinaryCode{                                 //函数
    public:
		char d[50];
		int i, assume=0, counter=0;
    vector <string> decode(char* code)
    {
    	vector <string> vct1 = 
        for(i=1; i<=50; i++){
        	d[0] = assume;
        	if (i == 1) 
				d[1] = code[0] - d[0];
			if (i == str(code)+1){
				d[i] = code[i] - d[i-1];
				counter += 1;
				if (counter == 1){
					assume = 1;
					i = 0;
				}
				if (counter == 2){
					return vct1;
				}
			}
				
        	else
        		d[i] = code[i-1] - d[i-1] - d[i-2];
        	
		}
        
    }
