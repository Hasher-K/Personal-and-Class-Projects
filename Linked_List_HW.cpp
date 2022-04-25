 #include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstring>

using namespace std;

struct Node{
  int value;
  Node* Next;
  Node(int c, Node* nextptr=NULL):
  value(c), Next(nextptr) {};
};

class myNode{
  public:

  //Insert at the top of the Node 
  void insert_at_top(Node*& head, int val){
    head = new Node(val, head);
  }

  //Insert at the end
  void insert_at_end(Node*& head, int val){
    if(head==NULL){
      insert_at_top(head, val);
    }
    else{
      Node* temp = head;
      while(temp->Next!=NULL){
        temp = temp->Next;
      }
      Node* to_be_added = new Node(val, NULL);
      temp->Next = to_be_added;
    }
  }

  //Delete the head
  void delete_the_head(Node*& head, int col){
    if(head==NULL){
      return;
    }
    else{
      for(int i = 0; i < col; i++){
        Node* temp;
        head = head->Next;
        delete temp;
      }
    }
  }

bool search_for_me(Node* head, int num){
    while(head!=NULL){
      if(head->value==num){
        return true;
      }
      head = head->Next;
    }
    return false;
  }


  //insert after an element
  void insert_after_element(Node* head, int num, int new_val){
    if(search_for_me(head, num)){
      while(head!=NULL){
        if(head->value==num){
          Node* temp = head->Next;
          head->Next = new Node(new_val, temp);
          return;
        }
        else{
          head = head->Next;
        }
      }
    }
    else{
      cout<<num<<" is not in the list"<<endl;
      return;
    }
  }


  //Print the Node values
  void printNode(Node* head){
    Node* temp = head;
    while(temp!=NULL){
      cout<< temp->value <<" ";
      temp = temp->Next;
    }
    cout<<endl;
  }
 
    

  //sum
  void sum(Node* head, Node* headB, int count, string output){
    Node* temp = head;
    Node* tempB = headB;
    int col = sqrt(count);
    ofstream ofile(output);
    if(ofile.is_open()){
    while(temp!=NULL){
        for(int i = 0; i < col; i++){
          if(i != col - 1){
            ofile << (temp->value) + (tempB->value)<< ".0" << " ";
          }
          else{
            ofile << (temp->value) + (tempB->value)<< ".0" << endl;
          }
          temp = temp->Next;
          tempB = tempB->Next;
        }
      }
      ofile.close();
    }
  }

  //sub
  void sub(Node* head, Node* headB, int count, string output){
    Node* temp = head;
    Node* tempB = headB;
    int col = sqrt(count);
    ofstream ofile(output);
    if(ofile.is_open()){
    while(temp!=NULL){
        for(int i = 0; i < col; i++){
          if(i != col - 1){
            ofile << (temp->value) - (tempB->value)<< ".0" << " ";
          }
          else{
            ofile << (temp->value) - (tempB->value)<< ".0" << endl;
          }
          temp = temp->Next;
          tempB = tempB->Next;
        }
      }
      ofile.close();
    }
  }


  //tra
  void tra(Node* head, int count, string output, int x){
    Node* temp = head;
    int col = sqrt(count);
    ofstream ofile;
    ofile.open(output, ios_base::app);
      while(temp!=NULL){
        for(int i = 0; i < count; i++){
          if(i%col == x ){
            ofile << (temp->value) << ".0" << " ";
          }
          temp = temp->Next;
      }
      ofile << endl;
    } 
  }

  //mul
  void tra2(Node* head, int count, string output, int x){
    Node* temp = head;
    int col = sqrt(count);
    ofstream ofile;
    ofile.open(output, ios_base::app);
      while(temp!=NULL){
        for(int i = 0; i < count; i++){
          if(i%col == x ){
            ofile << (temp->value) << ".0" << " ";
          }
          temp = temp->Next;
      }
      ofile << endl;
    } 
  }

  void mul(Node* head, Node* headM, int count, string output, int x, int check){
    Node* temp = head;
    Node* tempM = headM;
    int col = sqrt(count);
    int total = 0;
    if(check < col){

      ofstream ofile;
      ofile.open(output, ios_base::app);
      while(temp != NULL){
        for(int i = 0; i < count; i++){
          if(i < col){
            total += (temp->value) * (tempM -> value);
            tempM = tempM -> Next;
            temp = temp -> Next;
            
          }else if(i<col * check && x>=col){
            tempM = tempM -> Next;
            temp = temp -> Next;
          }else if(i > col * check && x >= col){
            total += (temp->value) * (tempM -> value);
            tempM = tempM -> Next;
            temp = temp -> Next;
          }
          else{
            tempM = tempM -> Next;
            temp = temp -> Next;
          }
        }
        
        ofile << total << ".0" << " ";
      }
    }
  }

  void call_mul(Node* head, Node* headM, int count, string output, int x, int check, myNode a, myNode b){
    Node* temp = head;
    Node* tempM = headM;
    int col = sqrt(count);
    for(int i = 0; i < col; i++){
        a.mul(temp, tempM, count, output, x, check);
        b.delete_the_head(tempM, col);
      }
    ofstream ofile;
    ofile.open(output, ios_base::app);
    ofile << endl;
    
    
  }
  



};


int main(int argc, char *argv[]) {
  

  myNode a;
  myNode b;
  Node* head=NULL;
  Node* headB = NULL;

  string function = argv[1];
  
  string num_s;
  int num;
  string line;
  string linea;

  int count_A = 0;
  int count_B = 0;

  if(function == "add" || function == "mul" || function == "sub"){
  string inputA = argv[2];
  string inputB = argv[3];
  string output = argv[4];


    ifstream file_a(inputA);
    if(file_a.is_open()){
      line ="";
      while(getline(file_a, linea)){
        stringstream ss(linea);
      
        while(getline(ss, num_s, ' ')){ 
          count_A++;    
          
          istringstream(num_s) >> num;

          a.insert_at_end(head, num);
          
        } 
      }
    }

    //File B
    ifstream file_b(inputB);
    if(file_b.is_open()){
      while(getline(file_b, line)){
        stringstream sa(line);
      
        while(getline(sa, num_s, ' ')){
          count_B++;
          
          istringstream(num_s) >> num;

          b.insert_at_end(headB, num);
        } 
      }
    }

    if(function == "add"){
      a.sum(head, headB, count_A, output);
    }

    if(function == "mul"){
      myNode mul;
      Node* headM = NULL;
      int col = sqrt(count_A);

      for(int i = 0; i < count_A; i++){
        for(int i = 0; i < col; i++){
          a.tra2(headB, count_A, output + "B.txt", i);
          }
        }
        


      fstream file_b(output + "B.txt");

      if(file_b.is_open()){
        while(getline(file_b, line)){
          stringstream sa(line);
      
          while(getline(sa, num_s, ' ')){
            count_B++;
          
            istringstream(num_s) >> num;

            b.insert_at_end(headM, num);
          } 
        }
        
      }

    
      for(int i = 0; i < col; i++){
      a.call_mul(head, headM, count_A, output, 0, 1, a, b);
        a.delete_the_head(head, col);
        for(int i = 0; i < col; i ++){
          a.insert_at_end(head, i);
        }
   
      }
      string out = output + "B.txt";

      
        char * cstr = new char [(out).length()+1];
        strcpy (cstr, (out).c_str());
      
      int result = remove(cstr);
      }
    
      
    

    if(function == "sub"){
      a.sub(head, headB, count_A, output);
    }

  
  }
  if(function == "tra"){
  string inputA = argv[2];
  string output = argv[3];

    ifstream file_a(inputA);
    if(file_a.is_open()){
      line ="";
      while(getline(file_a, linea)){
        stringstream ss(linea);
      
        while(getline(ss, num_s, ' ')){ 
          count_A++;    
          
          istringstream(num_s) >> num;

          b.insert_at_end(head, num);
          
        } 
      }
    }
    int col = sqrt(count_A);
    for(int i = 0; i < col; i++){
      a.tra(head, count_A, output, i);
    }
  }
  return 0;

}
