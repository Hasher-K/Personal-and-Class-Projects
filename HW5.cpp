#include <bits/stdc++.h>
using namespace std;
 
class Node
{
  public:
    char data;
    Node* link;
};
 
Node* head;
int length = 0;
 
void add(char data)
{
  Node* temp = new Node();
    
  if (!temp)
  {
      return;
  }
 
  temp->data = data;
  temp->link = head;
 
  head = temp;
  length++;
}

char isEmpty()
{
  return head == NULL;
}
 
char top()
{
  if (!isEmpty())
    return head->data;
  else
    return -1;
}

int size(){
  return length;
}
 
char pop()
{
  Node* temp;

  length--;
 
  if (head == NULL)
  {
    return -1;
    }
  else
  {
    temp = head;
    head = head->link;
    return temp->data;
    }
}

///////////////////////////////////////////////////////
/////////////////Node Float///////////////////////////
/////////////////////////////////////////////////////
class Node_i
{
  public:
    float value;
    Node_i* next;
};
 
Node_i* head_i;
int length_i = 0;
 
void add_i(float value)
{
  Node_i* temp = new Node_i();
    
  if (!temp)
  {
      return;
  }
 
  temp->value = value;
  temp->next = head_i;
 
  head_i = temp;
  length_i++;
}

float isEmpty_i()
{
  return head_i == NULL;
}
 
float top_i()
{
  if (!isEmpty_i())
    return head_i->value;
  else
    return -1;
}

float size_i(){
  return length_i;
}
 
float pop_i()
{
  Node_i* temp;

  length_i--;
 
  if (head_i == NULL)
  {
    return -1;
    }
  else
  {
    temp = head_i;
    head_i = head_i->next;
    return temp->value;
    }
}

///////////////////////////////////////////////////////
////////////////////////////////////////////////////////

int precedence(char c) {
  if(c == '^')
  {
    return 3;
    }
  else if(c == '/' || c=='*')
  {
    return 2;
    }
  else if(c == '+' || c == '-')
  {
    return 1;
    }
  else
  {
    return -1;
    }
}

string infixToPostfix(string s) {
  string final;
 
  for(int i = 0; i < s.length(); i++) {
    char c = s[i];
    
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
      final += c;
      }
    else if(c == '('){
      add('(');
      }
    else if(c == ')') {
      while(top() != '(')
      {
        final += top();
        pop();
        }
      pop();
      }
 
    else {
      while(head != NULL && precedence(s[i]) <= precedence(top())) {
        final += top();
        pop(); 
        }
      add(c);
      }
    }
  while(head != NULL) {
        final += top();
        pop();
    }
    return final;
  }
/////////////////////////////////////

float evaluatePostfix(string inf)
{
  string post = inf;
  float result = 0;
  int num_c = 0;
  int char_c = 0;

  for (int i = 0;post[i]; ++i)
  {
    if (isdigit(post[i])){
      num_c++;
      }else{char_c++;}
    }  
  if(char_c == num_c - 1 ){ 
    for (int i = 0;post[i]; ++i)
    {
      if (isdigit(post[i])){
        num_c++;
        float num = 0;
        num = num * 10.0 + static_cast<float>(post[i] - '0');
        add_i(num);
        }
            
      else
      {
        float val1 = pop_i();
        float val2 = pop_i();
        if(val2 == -1)
        {
          pop_i(); 
          add_i(-42069); 
          break;
        }
        switch (post[i])
        {
          case '+': add_i(val2 + val1); break;
          case '-': add_i(val2 - val1); break;
          case '*': add_i(val2 * val1); break;
          case '/': add_i(val2/val1); break;
          case '^': add_i(pow(val2, val1)); break;
          }
        }
      }
    }else{add_i(-42069);}
  return top_i();
}
 
// Driver Code
int main(int argc, char* argv[])
{
  string func = argv[1];
  string equat = argv[2];
  string out = argv[3];

  if(func == "2"){
    ofstream ofile;
    ofile.open(out, ios_base::app);
    ofile << infixToPostfix(equat) << endl;
  }else if(func == "3"){
    ofstream ofile;
    ofile.open(out, ios_base::app);
    if(evaluatePostfix(equat) == -42069){
      ofile << "nv" << endl;
    }else{
    ofile << fixed << setprecision(1) << round(evaluatePostfix(equat)*10) / 10 << endl;
      }
  }
  return 0;
}