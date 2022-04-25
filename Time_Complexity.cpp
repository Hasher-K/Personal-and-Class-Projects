#include <iostream>
#include <sstream>
#include <math.h>
#include <time.h>
#include <fstream>
#include <iomanip>



using namespace std;


// x: input array
// n: length of array
double* prefixAverage1(double* x, int len){
	double* a = new double[len];
	for(int j = 0; j < len; j++){
		double total = 0;
		for(int i = 0; i <= j; i++){
			total += x[i];
		}
		a[j] = total/(j+1);
	}
	return a;
}


// x: input array
// n: length of array
double* prefixAverage2(double* x, int len){
	double* a = new double[len];
	double total = 0;
	for(int j = 0; j < len; j++){
		total += x[j];
		a[j] = total/(j+1);
	}
	return a;
}


// x: input array
// n: length of array
int example1(int* x, int len){
	int total = 0;
	for(int i = 0; i < len; i++){
		total += x[i];
	}
	return total;
}


// x: input array
// n: length of array
int example2(int* x, int len){
	int total = 0;
	for(int i = 0; i < len; i+=2){
		total += x[i];
	}
	return total;
}


// x: input array
// n: length of array
int example3(int* x, int len){
	int total = 0;
	for(int i = 0; i < len; i++){
		for(int k = 0; k <= i; k++){
			total += x[i];
		}
	}
	return total;
}


// x: input array
// n: length of array
int example4(int* x, int len){
	int prefix = 0;
	int total = 0;
	for(int i = 0; i < len; i++){
		prefix += x[i];
		total += prefix;
	}
	return total;
}


// x: input array
// n: length of array
int example5(int* first, int* second, int len){
	int count = 0;
	for(int i = 0; i < len; i++){
		int total = 0;
		for(int j = 0; j < len; j++){
			for(int k = 0; k <= j; k++){
				total += first[k];
			}
		}
		if(second[i] == total){
			count++;
		}
	}
	return count;
}



int main(int argc, char** argv){

	// depending on argv call one of these functions:
	// p1 for prefixAverage1, p2 for prefixAverage2, e1 for example1
	// e2 for example2, e3 for example3, e4 for example4, e5 for example5

  string func = argv[1];
  string fileName = argv[2];
  stringstream num(argv[3]);
  int len;
  num >> len;
  
  if(func == "p1"){
    for(int i = 1.0; i <= len; i++){
      
      float time_m = 0.0;
      int len_2 = pow(10.0, i);
      double *arr = new double[len_2];
      for(int x = 0.0; x < len_2; x++){
        arr[x] = 1.0;
      }
      
      clock_t time = clock();
      double* num = prefixAverage1(arr, len_2);
      time = clock() - time;
      time_m += (((float)time)/CLOCKS_PER_SEC) * 1000;

      
      ofstream ofile;
      ofile.open(fileName, ios_base::app);
      ofile << fixed << setprecision(16) << log10(time_m) << endl;
      
    }
  }

  else if(func == "p2"){
    for(int i = 1.0; i <= len; i++){
      
      float time_m = 0.0;
      int len_2 = pow(10.0, i);
      double *arr = new double[len_2];
      for(int x = 0.0; x < len_2; x++){
        arr[x] = 1.0;
      }
      
      clock_t time = clock();
      double* num = prefixAverage2(arr, len_2);
      time = clock() - time;
      time_m += (((float)time)/CLOCKS_PER_SEC) * 1000;

      
      ofstream ofile;
      ofile.open(fileName, ios_base::app);
      ofile << fixed << setprecision(16) << log10(time_m) << endl;
      
    }
  }
  
  else if(func == "e1"){
    for(int i = 1.0; i <= len; i++){
      
      float time_m = 0.0;
      int len_2 = pow(10.0, i);
      int *arr = new int[len_2];
      for(int x = 0.0; x < len_2; x++){
        arr[x] = 1.0;
      }
      int num = 0;
      clock_t time = clock();
      num = example1(arr, len_2);
      time = clock() - time;
      time_m += (((float)time)/CLOCKS_PER_SEC) * 1000;

      
      ofstream ofile;
      ofile.open(fileName, ios_base::app);
      ofile << fixed << setprecision(16) << log10(time_m) << endl;
      
    }
    //ex2
  }
  else if(func == "e2"){
    for(int i = 1.0; i <= len; i++){
      
      float time_m = 0.0;
      int len_2 = pow(10.0, i);
      int *arr = new int[len_2];
      for(int x = 0.0; x < len_2; x++){
        arr[x] = 1.0;
      }
      int num = 0;
      clock_t time = clock();
      num = example2(arr, len_2);
      time = clock() - time;
      time_m += (((float)time)/CLOCKS_PER_SEC) * 1000;

      
      ofstream ofile;
      ofile.open(fileName, ios_base::app);
      ofile << fixed << setprecision(16) << log10(time_m) << endl;
      
    }
    //ex3
  }
  else if(func == "e3"){
    for(int i = 1.0; i <= len; i++){
      
      float time_m = 0.0;
      int len_2 = pow(10.0, i);
      int *arr = new int[len_2];
      for(int x = 0.0; x < len_2; x++){
        arr[x] = 1.0;
      }
      int num = 0;
      clock_t time = clock();
      num = example3(arr, len_2);
      time = clock() - time;
      time_m += (((float)time)/CLOCKS_PER_SEC) * 1000;

      
      ofstream ofile;
      ofile.open(fileName, ios_base::app);
      ofile << fixed << setprecision(16) << log10(time_m) << endl;
      
    }
    //ex4
  }
  else if(func == "e4"){
    for(int i = 1.0; i <= len; i++){
      
      float time_m = 0.0;
      int len_2 = pow(10.0, i);
      int *arr = new int[len_2];
      for(int x = 0.0; x < len_2; x++){
        arr[x] = 1.0;
      }
      int num = 0;
      clock_t time = clock();
      num = example4(arr, len_2);
      time = clock() - time;
      time_m += (((float)time)/CLOCKS_PER_SEC) * 1000;

      
      ofstream ofile;
      ofile.open(fileName, ios_base::app);
      ofile << fixed << setprecision(16) << log10(time_m) << endl;
      
    }
    //ex 5
  }
  else if(func == "e5"){
    for(double i = 0.5; i <= len /2; i += 0.5){
      
      float time_m = 0.0;
      int len_2 = pow(10.0, i);
      int *arr1 = new int[len_2];
      int *arr2 = new int[len_2];
      for(int x = 0.0; x < len_2; x++){
        arr1[x] = 1.0;
        arr2[x] = 1.0;
      }
      int num = 0;
      clock_t time = clock();
      num = example5(arr1, arr2, len_2);
      time = clock() - time;
      time_m += (((float)time)/CLOCKS_PER_SEC) * 1000;

      
      ofstream ofile;
      ofile.open(fileName, ios_base::app);
      ofile << fixed << setprecision(16) << log10(time_m) << endl;
      
    }
 
  }
	return 0;
}
