#include "DynArray.hh"

int main() {

	int arr[8];

	DynArray primera;
	DynArray segunda (arr, 10);
	DynArray tercera (24, 8);



	primera == segunda;
		
	return 0;

	/*
	DynArray *primera;
	DynArray *segona;
	DynArray *tercera;

	primera = new DynArray();
	segunda = new DynArray(arr,10);
	tercera = new DynArray(24, 8);*/

}