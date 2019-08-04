#include<stdio.h>

//折半查找法 
//无函数 版本 
/*
main (){
	int a[15] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int low = 0,high = 14,mid, value, i;  
	printf("Please enter a number: ");
	scanf("%d",&value);
	
	if(value > a[low] || value < a[high])
		printf("  无此数\n");
    else{
		while (low <= high) {  
	        mid = (low + high)/2;  
	        if (value < a[mid]) {  
	            low = mid+1;  
	        }else if (value > a[mid]){  
	            high = mid - 1;  
	        }else{  
	            i = mid;
	            break;
			}
		}
		printf("The index is %d\n",i);
	}
	
	return 0;
}
*/

//函数版本 
int searchItem(int arr[],int len, int value){  
    int low = 0,high = len-1,mid;  
    while (low <= high) {  
        mid = (low + high)/2;  
        if (value < arr[mid]) {  
            low = mid+1;  
        }else if (value > arr[mid]){  
            high = mid - 1;  
        }else{  
            return mid;  
        }  
    } 
    return -1;
}

int main()
{
	int a[15] = {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
	int num;
	printf("Please enter a number: ");
	scanf("%d",&num);
	int l = searchItem(a,15,num);
	if(l == -1)
		printf("无此数\n");
	else 
		printf("下标是： %d\n",l);
	
	return 0;
}
