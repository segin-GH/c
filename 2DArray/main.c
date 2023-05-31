#include <stdio.h>

int main()
{      
    int i = 0,j = 0;    
    int arr[4][2]={{1000,100},{1001,101},{1002,102},{1003,103}};     
    
    
    for(i = 0; i < 4; i++)
    {    
        {    
            printf("device %d = Device ID [%d] SRC ID [%d] \n",i ,arr[i][0] ,arr[i][1]);    
        }   
    }    
    return 0;  
}   
