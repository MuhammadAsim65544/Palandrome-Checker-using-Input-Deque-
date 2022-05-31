#include <iostream>
#define MAX 10
using namespace std;
class Deque
{
	char deque[MAX];
	int front,rear;
	public:
		bool condition=false;
		Deque(int f=-1,int r=-1): rear(r),front(f){ 	}
		void palandrome();
		void inputDeque();
		void outputDeque();
		void pushRear(char );
		void pushFront(char);
		void popRear();
		void popFront();
		void isEmpty();
		void display();
		void peak();
};
int main()
{
	Deque q;
	int ch,check=0;
	do
	{
		cout<<"       Main Menu\n";

		cout<<"1.  Input Restricted Deque\n";
		cout<<"2.  Output Restricted Deque\n";
		cout<<"3.  Palandrome Checker(using Input Deque)\n";
		cout<<"4.  Exit\n";
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				q.inputDeque();
				break;
			case 2:
				q.outputDeque();
				break;
			case 3:
				q.palandrome();
				break;
			case 4:
				exit(-1);
		}
	}while(1);
	
	return 0;
}
void Deque::inputDeque()
{
	int ch;char val;
	do
	{
		cout<<"  Menu for Input Deque\n";
		cout<<"0.Peak\n";
		cout<<"1.Push From Rear\n";
		cout<<"2.Pop From Rear\n";
		cout<<"3.Pop From Front\n";
		cout<<"4.Display\n";
		cout<<"5. Exit\n";
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 0:
				peak();
				break;
			case 1:
				cout<<"Enter data: ";
				cin>>val;
				pushRear(val);
				break;
			case 2:
				popRear();
				break;
			case 3:
				popFront();
				break;
			case 4:
				display();
				break;
		}
			
	}while(ch!=5);
}
void Deque::outputDeque()
{
	int ch;char val;
	do
	{
		cout<<"  Menu for Input Deque\n";
		cout<<"0.Peak\n";
		cout<<"1.Insert From Front\n";
		cout<<"2.Insert From rear\n";
		cout<<"3.Pop From Front\n";
		cout<<"4.Display\n";
		cout<<"5. Exit\n";
		cout<<"Enter choice: ";
		cin>>ch;
		switch(ch)
		{
			case 0:
				peak();
				break;
			case 1:
				cout<<"Enter data: ";
				cin>>val;
				pushFront(val);
				break;
			case 2:
				cout<<"Enter data: ";
				cin>>val;
				pushRear(val);
				break;
			case 3:
				popFront();
				break;
			case 4:
				display();
				break;
		}
			
	}while(ch!=5);
}
void Deque::peak()
{
	if(front!=-1 || front!=MAX)
	cout<<"Peak: "<<deque[front]<<endl;
}
void Deque:: pushRear(char val)
{
   if(rear==MAX-1)
   {
        cout<<"Queue overflow\n";
   		return;
   }
    else
   {
   	 if(front==-1 && rear==-1)
   	 front=0;
	}
   rear++;
   deque[rear]=val;
}
void Deque:: pushFront(char val)
{
	if(front<=0)
	{
		cout<<"You can't add item at front end.\n";
		return;
	}
	else
	{
	front--;
	deque[front]=val;
	}
}
void Deque:: popRear()
{
	int n;
	if(rear==-1) //empty
	{
		cout<<"Stack is empty\n";
		return;	
	}
	n=deque[rear];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		rear=rear-1;
		cout<<"You successfully deleted '"<<n<<"' from rear.\n";	
	}
}
void Deque:: popFront()
{
	int item;
	if(front==-1) 
	{
		cout<<"Queue underflow";
	   	return;
	}
	else
	{
		item=deque[front];
		if(front==rear)
		{
		    front=-1;
			rear=-1;
		}
		else
		front++;
	}
}
void Deque::display()
{
	int f=front,r=rear;
	if(f==-1)
	{
		cout<<"Deque is empty\n";
		return;
	}	
	cout<<"Deque is: ";
	if(f<=r)
	{
		while(f<=r)
		{
			cout<<deque[f]<<" ";
			f++;
		}
	}
	else
	{
		while(f<=MAX-1)
		{
			cout<<deque[f]<<" ";
			f++;
		}
		f=0;
		while(f<=r)
		{
			cout<<deque[f]<<" ";
			f++;
		}
	}
	cout<<"\n";
}
void Deque::palandrome()
{
	while(front!=rear)
	{
		if(deque[front]==deque[rear])
		condition=true;
		else
		condition=false;
		rear--;front++;
	}
	if(condition)
	{
		cout<<"Palandrome\n";
		
	}
	else
	cout<<"Not Palandrome\n";
}
