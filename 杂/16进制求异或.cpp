/**
 * C/C++两个十六进制字符串异或
 * @Filename:  hexstrxor.c
 * @author  :  vfhky  2014.11.09  https://typecodes.com/cseries/hexstrxor.html
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

//ASCII码中将字符转换成对应的十进制数
int char2int( char input )
{
    return input>64?(input-55):(input-48);
}

//ASCII码中将十进制数转换成对应的字符
int int2char( char input )
{
    return input>9?(input+55):(input+48);
}

//将十六进制字符串HexStr1和HexStr2异或得到HexStr
void hexstrxor( char * HexStr1, char * HexStr2, char * HexStr )
{
    int i, iHexStr1Len, iHexStr2Len, iHexStrLenLow, iHexStrLenGap;

    //转换成大写并求长度
    strupr( HexStr1 );
    strupr( HexStr2 );
    iHexStr1Len = strlen( HexStr1 );
    iHexStr2Len = strlen( HexStr2 );

    //获取最小的长度
    iHexStrLenLow = iHexStr1Len<iHexStr2Len?iHexStr1Len:iHexStr2Len;

    //获取长度差值
    iHexStrLenGap = abs( iHexStr1Len-iHexStr2Len );

    //两个十六进制的字符串进行异或
    for( i=0; i<iHexStrLenLow; i++ )
    {
        *(HexStr+i) = char2int( HexStr1[i] ) ^ char2int( HexStr2[i] );
        *(HexStr+i) = int2char( *(HexStr+i) );
    }
    if( iHexStr1Len>iHexStr2Len )
        memcpy( HexStr+i, HexStr1+i, iHexStrLenGap );
    else if( iHexStr1Len<iHexStr2Len )
        memcpy( HexStr+i, HexStr2+i, iHexStrLenGap );
    *( HexStr+iHexStrLenLow+iHexStrLenGap ) = 0x00;
}


int main( int argc, char * argv[] )
{
    //两个十六进制的字符串以及异或的结果result
    
    
    
    while(1)
	{	
		char *HexStr1 = new char[50];
	    char *HexStr2 = new char[50];
		char result[17] = {0};
    	scanf("%s",HexStr1);
		scanf("%s",HexStr2);
	
	    //调用异或方法
	    hexstrxor( HexStr1, HexStr2, result );
	    //打印异或结果
	    printf( "\nresult=[%s]\n", result );
	}
	

    return 0;
}
