//
//  hw3.c
//  
//
//  Created by Sai Peri on 9/17/18.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    //First need to fetch file with wget function (download into working directory
    system("WGET http://undcemcs01.und.edu/~ronald.marsh/CLASS/CS451/hw3-data.txt");
    printf("Download successful!");
    
    return 0;
    
}
