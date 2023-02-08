#include <omp.h>
#include <iostream>
#include <iomanip>
using namespace std;

double f(double x){
	double return_val;
	return_val = x*x+2*x; //insira sua função aqui
	return return_val;
}
int main(int argc, char **argv){
	double integral, a, b, h, x;
	int n, i, t;
	cout << "Entre com os valores de a, b, and n" << endl;
	cin >> a >> b >> n >> t;
	
	double start = omp_get_wtime();
	cout << "Num T" << "  " << "Integral" << "  " << "Tempo" << endl << endl;
	
	for(int j=1; j<=t;j++){
		h = (b-a)/n;
		integral = (f(a) + f(b))/2.0;
		x = a;
		#pragma omp parallel private(i) num_threads(j)
		{
		#pragma omp for reduction(+:integral)
			for (i=1; i<= n-1; i++){
				#pragma omp critical
				{
					x = x + h;
				}
				integral = integral + f(x);
			}
		}
		
		integral = integral*h; 
		
		double total = omp_get_wtime() - start;
		cout << setprecision(3) << fixed << j << "  " << integral << "  " << total*1000 << endl;
		//cout << "Valor da integral:" << integral << endl << total*1000;
		
	}
	return 0;
}
