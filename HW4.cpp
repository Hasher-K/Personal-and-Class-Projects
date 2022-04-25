#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void towerOfHanoi_3(int n, char from_rod, char to_rod, char mid_rod, string output) { 
 
  if (n == 0){
      return; 
  } 
  towerOfHanoi_3(n - 1, from_rod, to_rod, mid_rod, output); 
  ofstream ofile;
  ofile.open(output, ios_base::app);
  ofile << n << " " << from_rod << " " << to_rod << endl; 
  towerOfHanoi_3(n - 1, to_rod, mid_rod, from_rod, output); 
} 

void towerOfHanoi_4(int num, char from_rod, char to_rod, char mid_rod, char mid_rod2, string output){
  if(num == 0){
    return; 
  }
  if(num == 1){
    ofstream ofile;
    ofile.open(output, ios_base::app);
    ofile << num << " " << from_rod << " " << to_rod << endl;
    return;
  } 
  towerOfHanoi_4(num - 2, from_rod, mid_rod, mid_rod2, to_rod, output);
  ofstream ofile;
  ofile.open(output, ios_base::app);
  ofile << num - 1 << " " << from_rod << " " << mid_rod2 << endl;
  ofile << num << " " << from_rod << " " << to_rod << endl;
  ofile << num - 1<< " " << mid_rod2 << " " << to_rod << endl;
  towerOfHanoi_4(num - 2, mid_rod, to_rod, from_rod, mid_rod2, output);
} 

void towerOfHanoi_5(int num, char from_rod, char to_rod, char mid_rod, char mid_rod2, char mid_rod3, string output){
  if(num == 0){
    return;
  }
  if(num == 1){
    ofstream ofile;
    ofile.open(output, ios_base::app);
    ofile << num << " " << from_rod << " " << to_rod << endl;
    return;
  }
  if(num == 2){
    ofstream ofile;
    ofile.open(output, ios_base::app);
    ofile << num - 1 << " " << from_rod << " " << mid_rod2 << endl;
    ofile << num << " " << from_rod << " " << to_rod << endl;
    ofile << num - 1<< " " << mid_rod2 << " " << to_rod << endl;
    return;
  }
  towerOfHanoi_5(num - 3, from_rod, mid_rod, mid_rod2, mid_rod3, to_rod, output);
  ofstream ofile;
  ofile.open(output, ios_base::app);
  ofile << num - 2 << " " << from_rod << " " << mid_rod3 << endl;
  ofile << num - 1 << " " << from_rod << " " <<  mid_rod2 << endl;
  ofile << num << " " << from_rod << " " << to_rod << endl;
  ofile << num - 1<< " " << mid_rod2 << " " << to_rod << endl;
  ofile << num - 2 << " " << mid_rod3 << " " << to_rod << endl;
  towerOfHanoi_5(num - 3, mid_rod, to_rod, mid_rod2, from_rod, mid_rod3, output);
}
  
  

 
// Driver code

int main(int argc, char* argv[]) 
{   
  string pegs = argv[1];
  
  string d = argv[2];

  stringstream dis(d);
  int disks = 0;
  dis >> disks;
  string output = argv[3];

  if(pegs == "3"){
    towerOfHanoi_3(disks, 'A', 'C', 'B', output); 
    }
  if(pegs == "4"){
    towerOfHanoi_4(disks, 'A', 'D', 'B', 'C', output); 
    }
  if(pegs == "5"){
    towerOfHanoi_5(disks, 'A', 'E', 'B', 'C', 'D', output);
    }
  return 0; 
} 