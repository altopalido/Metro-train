#include "classes.h"
#include <stdlib.h>
#include <time.h>

epivatis::epivatis(){
	eisithrio=rand()%2;
	cout<<"eisitirio="<<eisithrio<<endl;
	meiwmeno=rand()%2;
}

epivatis::~epivatis(){
	cout<<"A passenger has been destroyed"<<endl;
}

vagoni::vagoni(int maxCapacity): maxCapacity(maxCapacity), num_of_passengers(0) {
	//num_of_passengers=0;
	//epivates= new epivatis[3];
	//cout<<"num_of_passengers="<<num_of_passengers;
	cout<<"A waggon with capacity for "<<maxCapacity<<" passengers, was created"<<endl;
}

vagoni::~vagoni(){
	delete [] epivates;
	cout<<"A waggon was destroyed"<<endl;
}

int vagoni::inStation(){
	elegxos=0;
	int epivivazontai,apovivazontai;
	//srand(time(NULL));
	elegxos=rand()%2;
	if(elegxos==0){
		cout<<"to vagoni den elegxetai"<<endl;
	}
	else{
		cout<<"to vagoni elegxetai"<<endl;
	}
	epivivazontai=rand()% maxCapacity + 1;
	apovivazontai=rand()% maxCapacity + 1;
	cout<<"epivivazontai="<<epivivazontai<<endl;
	cout<<"apovivazontai="<<apovivazontai<<endl;
	num_of_passengers=num_of_passengers+epivivazontai-apovivazontai;
	cout<<"num_of_passengers="<<num_of_passengers<<endl;
	if (num_of_passengers>maxCapacity)
		num_of_passengers=maxCapacity;
	if (num_of_passengers<0)
		num_of_passengers=0;
	cout<<num_of_passengers<<endl;
	epivates= new epivatis[num_of_passengers];
	return elegxos;
}

int vagoni::betweenStations(){
	paravates=0;
	tyxeros=0;
	int i;
	if(elegxos==1){
		for(i=0; i<num_of_passengers; i++){
			if(epivates[i].eisithrio==0)
				paravates=paravates+1;
		}
		num_of_passengers=num_of_passengers-paravates;
	}
	if(elegxos==0){
		for(i=0; i<num_of_passengers; i++){
			if(epivates[i].eisithrio==0)
				tyxeros=tyxeros+1;
		}
	}
	cout<<"paravates= "<<paravates<<endl;
	return paravates;	
}

void vagoni::printStatistics(){
	cout<<"vrethhkan na paravatoun "<<paravates<<" paravates"<<endl;
	cout<<"ton elegxo apefugan "<<tyxeros<<" epivates pou den eixan eisithrio"<<endl;
}

treno::treno(int N,int totalWaggons): N(N), totalWaggons(totalWaggons){
	int i;
	xrhmata=0;
	cout<<"A metro train with "<<totalWaggons<<" waggons, was created"<<endl;
	vagonia= new vagoni*[totalWaggons];
	for (i=0; i<totalWaggons; i++)
		vagonia[i]= new vagoni(60);
	//vagonia= new vagoni(5);[totalWaggons];
}

treno::~treno(){
	delete [] vagonia;
	cout<<"A metro train was destroyed"<<endl;
}

void treno::operate(){
	sunolikoi_paravates=0;
	int i,j;
	for(i=0; i<N; i++){
		for(j=0; j<totalWaggons; j++){
			vagonia[j]->inStation();
			sunolikoi_paravates=sunolikoi_paravates+vagonia[j]->betweenStations();
		}
	}
}

void treno::printStatistics(){
	cout<<"ta xrhmata pou sulexthhkan apo "<<sunolikoi_paravates<<" sunolikous paravates einai: "<<sunolikoi_paravates*30<<" eurw"<<endl;
}









