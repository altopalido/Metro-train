#include "classes.h"
//#include <stdlib.h>
//#include <time.h>
//#include <iostream>
//#include <string>

int main(int argc, char *argv[]){
	srand(time(NULL));
	int k;
	if(argc!=2){
		cout<<"Lathos plhthos parametrwn"<<endl;
		exit(2);
	}
	k= atoi(argv[1]);
	treno b(k,7);
	b.operate();
	b.printStatistics();
}