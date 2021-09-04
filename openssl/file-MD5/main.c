#include <stdio.h>
#include <stdlib.h>
#include "md5.h"

int main(int argc, char * argv[]){
    unsigned char *md5;

    if(argc != 2){
    	fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    	return -1;
    }

    md5 = get_file_MD5(argv[1]);
    if(md5 != NULL){
        print_MD5(md5);
    } else {
        
    }
    free(md5);
    
    return 0;
}
