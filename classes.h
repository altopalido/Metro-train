#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

class epivatis{
public: 
	epivatis();
	~epivatis();
//private:
	int eisithrio;
	int meiwmeno;
};

class vagoni{
public:
	
	vagoni(int maxCapacity);
	~vagoni();
	int betweenStations();
	int inStation(); 
	void printStatistics();
private:
	int elegxos;
	int maxCapacity;
	epivatis *epivates;
	int num_of_passengers;
	int tyxeros;
	int paravates;
};

class treno{
public:
	treno(int N,int totalWaggons);
	~treno();
	void operate();
	void printStatistics();
private:
	int N;
	int totalWaggons;
	vagoni **vagonia;
	int xrhmata;
	int sunolikoi_paravates;
};



