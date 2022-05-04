#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

//Searching
//Linear searching
void linear()
{
  map<string,int> first;
  
  first["Wasya"]=10;
  first["Petya"]=24;
  first["Riga"]=98;
  first["Pasha"]=32;
  first["Wicia"]=20;
  //search for name what you want and get their age
    string namecheck = "Wicia";
  //Check for Errors
    bool check= false;

  //Searching result
  for (auto eachComb : first)
  {
        if (namecheck == eachComb.first)
        {
            cout << "Selected name : " << namecheck << "\nAge : " << eachComb.second<<endl;
            check=true;
        }
  }
  //Error output
  if (check == false) cout << "Error" << endl;  

}

//Binary search
void binary()
{
  vector<int> num = {12, 20, 44, 58, 71, 96};
  bool Er=false;
  int numcheck = 71;
  int min =0, max = num.size()-1;
  int mid;
  mid = floor(min + (max - min) / 2);
//Error check
  for (int i=0;i<num.size();i++)
    {
      if(num.at(i)==numcheck) Er=true;
    }
  //Find position in numay(Vector)
if (Er==true)
{
   while (num.at(mid) != numcheck)
  {
        if (num.at(mid) < numcheck){
            mid++;
        }
        if (num.at(mid) > numcheck){
            mid--;
        }
  }
  //Result
  cout <<"Position check : " << numcheck << "\nCurrent position : " << mid <<endl;
}
  //Error
else cout << "Error" << endl;
}

//Sorting
//Number sorting
void numsort()
{
  //numbers
  vector<int> num = {1, 44, 98, 121, 74, 69, 32};
  //num for sorting
  int k;
  //standart sorting method
  for (int i = 0; i < num.size(); i++)
  {
        for (int j = i + 1; j < num.size(); j++)
        {
            if (num[j] < num[i])
            {
                k = num[i];
                num[i] = num[j];
                num[j] = k;
            }
        }
    }
  //result output
  cout << "Number sort : ";
  for (int i = 0;i<num.size();i++)
    {
      cout << num.at(i) << " ";
    }
  cout<<endl;
}

//alphabet sorting
void alphabet()
{
  //char
  vector<char> chara = {'a','A','c','f','j','y','D','H','I','B','Y'};
  //num for sorting
  int k;
  //standart sorting method
  for (int i = 0; i < chara.size(); i++)
  {
        for (int j = i + 1; j < chara.size(); j++)
        {
            if (chara[j] < chara[i])
            {
                k = chara[i];
                chara[i] = chara[j];
                chara[j] = k;
            }
        }
    }
  //result output
  cout << "Alphabet sort : ";
  for (int i = 0;i<chara.size();i++)
    {
      cout << chara.at(i) << " ";
    }
  cout<<endl;
}

//Data Structures

//Stack
//scheme presented below is a standart that was made hundreds times
class Stack
{
   int top,size=10;
   public:
   int juststack[10]; //stack array
  
   Stack() { top = -1; }
   bool push(int x);
   int pop();
   bool isEmpty();
};

//pushes element
bool Stack::push(int item)
   {
      if (top >= (size-1)) 
      {
        cout << "Full";
        return false;
      }
        else 
        {
          juststack[++top] = item;
          cout<<item<<" ";
          return true;
        }
   }
  
//removes elements
int Stack::pop()
{
   if (top < 0) 
   {
      cout << "Empty";
      return 0;
   }
else 
   {
       int item = juststack[top--];
      return item;
   }
}
  
//check if stack is empty
bool Stack::isEmpty()
{
   if (top < 0)
   {
     return true;
   }
  else return false;
}

//Stack main
void stack()
{
  class Stack stack;
   cout << "Stack\n";
   cout<<"Push : ";
   stack.push(22);
   stack.push(54);
   stack.push(674);
   stack.push(64);
   stack.push(4);
  
   cout<<"\nPop : ";
   while(!stack.isEmpty())
      {
      cout<<stack.pop()<<" ";
      }
  
  cout<<endl;
  
}

//Linked list
//same logic as previous
class link 
   {
     public:
     int data;
     link* next;
   };
//New
link* newlink(int data) 
   {
     link* stacklink = new link();
     stacklink->data = data;
     stacklink->next = NULL;
     return stacklink;
   }
//Empty
int isEmpty(link *anum) 
   {
     return !anum;
   }
//Add
void push(link** anum, int new_data)
   {
     link* stacklink = newlink(new_data);
     stacklink->next = *anum;
     *anum = stacklink;
     cout<<new_data<<" ";
   }
//Remove
int pop(link** anum)
{
   if (isEmpty(*anum)) return -1;
   link* temp = *anum;
   *anum = (*anum)->next;
   int popped = temp->data;
   free(temp);
  
   return popped;
}
//Peek
int peek(link* anum)
{
   if (isEmpty(anum)) return -1;
   return anum->data;
}
//Main Link
void links()
{
   link* anum = NULL;
     cout << "Link\n";
     cout<<"Push : ";
       push(&anum, 23);
       push(&anum, 58);
       push(&anum, 985);
       push(&anum, 478);
       push(&anum, 324);
       push(&anum, 19);
       cout<<"\ntop element : "<<peek(anum);
  
     cout<<"\nPop : ";
       while(!isEmpty(anum))
       {
       cout<<pop(&anum)<<" ";
       }
       cout<<"\ntop element : "<<peek(anum)<<endl;
}

//Queue
class Queue 
{
private:
//*5 is max load
int justqueue[5], front, rear;
     
public:
Queue()
{
  front = -1;
  rear = -1;
}
//check full
bool isFull()
{
  //*5 is max load
  if(front == 0 && rear == 5 - 1)
    {
      return true;
    }
  return false;
}
//Check empty
bool isEmpty()
  {
    if(front == -1) return true;
    else return false;
   }
//When full
void enQueue(int value)
{
  if(isFull())
  {
    cout <<"\nFull";
  } 
    else 
    {
      if(front == -1) front = 0;
      rear++;
      justqueue[rear] = value;
      cout << value << " ";
    }
}
//When Empty
int deQueue()
{
  int value;
  if(isEmpty())
  {
    cout << "Empty" << endl;
    return(-1); 
  }
    else 
    { value = justqueue[front]; 
      if(front  >= rear)
        {      
          //only one element
          front = -1;
          rear = -1;
        } 
        else front++;
      
    cout << "Deleted => " << value << " from justqueue";
    return(value);
     }
}
     
//display
void displayQueue()
    { 
    int i;
  if(isEmpty()) 
      {
        cout << endl << "Empty" << endl;
      }
  else 
      {
        cout << endl << "Front = " << front;
        cout << endl << "Queue elements : ";
        for(i=front; i<=rear; i++) cout << justqueue[i] << "\t";
        cout << endl << "Rear = " << rear << endl;
      }
    }
};
//Main queue
void queues()
{
  Queue justq;
     
justq.deQueue();
     
cout<<"Queue created : ";
  //in example 6 to show one additional piece of code in result
justq.enQueue(12);
justq.enQueue(18); 
justq.enQueue(33); 
justq.enQueue(45); 
justq.enQueue(58); 
justq.enQueue(69);
     
justq.displayQueue();
     
//deQueue =>removes 12
justq.deQueue();
     
//queue after dequeue
justq.displayQueue();
}

int main() 
{
  int input;
  cout << "Select one: \n1. Linear and Binary searching\n2. Sorting\n3. Data Structures\n (1,2,3)" << endl;
  cin >> input;
  if (input == 1)
  {
    cout << "Choose one : \n1. Linear\n2. Binary\n(1,2)" << endl;
    int a;
    cin >> a;
    if(a == 1) linear();
    if(a == 2) binary();
    else cout << "Error";
  }
  else if (input == 2)
  {
    cout << "Choose one : \n1. Numbers\n2. Alphabet\n(1,2)" << endl;
    int a;
    cin >> a;
    if(a == 1) numsort();
    if(a == 2) alphabet();
    else cout << "Error";
  }
  else if (input == 3)
  {
    cout << "Choose one : \n1. Stack\n2. Links\n3. Queue\n(1,2,3)" << endl;
    int a;
    cin >> a;
    if(a == 1) stack();
    if(a == 2) links();
    if(a == 3) queues();
    else cout << "Error";
  }
  else cout << "Error";
}
