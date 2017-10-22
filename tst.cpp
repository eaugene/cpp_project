#include<bits/stdc++.h>
#include<fstream>
#include<istream>
#include<cstring>
using namespace std;
ofstream f1("w.txt",ios::out);
            class Point
{
   string st,et,ev;
   int x;
public:
   Point(string _st,string _et,string _ev,int _x)
   {
   	  st=_st;
   	  et=_et;
   	  ev=_ev;
      x = _x;
   }
   int getX() const { return x; }
   string getET() const { return et; }
   string getEV() const { return ev; }
   string getST() const { return st; }
};


class Record
{
 public:
  void CreateRecord();
  void DeleteRecord();
  void ModifyRecord();
  void DisplayRecord();
};

void Record:: CreateRecord()
{
 char ip[100];
 ofstream f1;
 f1.open("Project.txt",ios::app);
 cout<<"Enter an event: ";
 cin>>ip;
 f1<<ip<<endl;
 cout<<"Enter the date: ";
 cin>>ip;
 f1<<ip<<endl;
 cout<<"Enter the time: ";
 cin>>ip;
 f1<<ip<<endl;
 f1.close();
}

void Record:: DeleteRecord()
{
 char data[100],event[100];
 cout<<"Enter the event to be deleted: ";
 cin>>event;
 ifstream f1;
 ofstream f2;
 f1.open("Project.txt");
 f2.open("temp.txt");
 while(f1.good())
 {
  int k=0,l=0;
  f1.getline(data,100);
  if(strcmp(event,data)==0)
  {
   int i=0;
   while(i<3)
   {
    f1.getline(data,100);
    i++;
   }
  }
  f2<<data<<endl;
 }
 f1.close();
 f2.close();
 f1.open("temp.txt");
 f2.open("Project.txt");
 while(f1.getline(data,100))
  f2<<data<<endl;
 f1.close();
 f2.close();
}

void Record:: ModifyRecord()
{

 char data[100],event[100];
 cout<<"Enter an event or date or time to modify: ";
 cin>>event;
 ifstream f1;
 ofstream f2;
 f1.open("Project.txt");
 f2.open("temp.txt");
 while(f1.good())
 {
  f1.getline(data,100);
  if(strcmp(event,data)==0)
  {
   cout<<"Enter the modified data: ";
   cin>>event;
   f2<<event<<endl;
   continue;
  }
  f2<<data<<endl;
 }
 f1.close();
 f2.close();
 f1.open("temp.txt");
 f2.open("Project.txt");
 while(f1.getline(data,100))
  f2<<data<<endl;
 f1.close();
 f2.close();
}

void Record:: DisplayRecord()
{
 ifstream f1;
 f1.open("Project.txt");
 char data[100];
 while(f1.getline(data,100))
 {
  cout<<data<<endl;
  cout<<endl;
 }
 f1.close();
}


class myComparator
{
public:
    int operator() (const Point& p1, const Point& p2)
    {
        return p1.getX() > p2.getX();
    }
};

class Account
{
private:
    char name[100],paswrd[100],q[100],a[100];

public:
    void input()
    {
        Account a1;
        cout<<"enter your name"<<endl;
        cin>>a1.name;
        cout<<"enter your password"<<endl;
        cin>>a1.paswrd;
        cout<<"enter the secruity question"<<endl;
        cin>>a1.q;
        cout<<"enter the answer"<<endl;
        cin>>a1.a;
        f1.write((char*)&a1,sizeof(a1));
        f1.close();
//        cout<<a2.name<<endl;
    }
void out()
{
        Account a2;int ch;char c[100],d[100],a[100];
        ifstream f2("w.txt");
        f2.read((char *)&a2,sizeof(a2));
        cout<<a2.name<<endl;
        cout<<a2.paswrd<<endl;
do
{
cout<<"1.personal diary management \n 2.Event schedule \n 3.password change \n 4.forgot password\n other->exit"<<endl;
cout<<"enter your choice"<<endl;
cin>>ch;
switch(ch)
{
case 1:
        z:
       cout<<"personal diary management"<<endl;
       //cout<<"new user or existing user"<<endl;
       //cout<<"for new user press 1 or existing user 2"<<endl;
       cout<<"enter ur user name and password"<<endl;
       fflush(stdin);
        gets(c);
        gets(d);
        if(strcmp(a2.name,c)==0)
        {
            if(strcmp(a2.paswrd,d)==0)
            {
            //cout<<"successfully login"<<endl;

            Record r;
 int ch;
 do
 {
  cout<<"1->Add a new record\n2->Modify the record\n3->Delete a record\n4->Display all records\nother->Exit\nEnter your choice: ";
  cin>>ch;
  switch(ch)
  {
   case 1: r.CreateRecord();
           break;
   case 2: r.ModifyRecord();
           break;
   case 3: r.DeleteRecord();
           break;
   case 4: r.DisplayRecord();
           break;
  default: ch=7;
  break;
  }
 }while(ch>=1&&ch<=4);

            }
            else
            {
            cout<<"wrong password"<<endl;
            }
        }
        else
        {
        cout<<"wrong username"<<endl;
        }
       break;
case 2:
    r:
    cout<<"event schedule"<<endl;
    cout<<"enter ur user name and password"<<endl;
        fflush(stdin);
       gets(c);
       gets(d);
       if(strcmp(a2.name,c)==0)
        {
            if(strcmp(a2.paswrd,d)==0)
            {
            //cout<<"successfully login"<<endl;
            multimap < string , list<Point> > m;
	list<Point> pq;

	ifstream f("data1.csv");
 	 if(!f.is_open())
 	 {
	  cout<<"fail";
}
while(f.good())
{
	string dt,st,et,ev;
	string pr;
	getline(f,dt,',');
	if(dt=="")
	{continue;
	}
	getline(f,st,',');
	getline(f,et,',');
	getline(f,ev,',');
	getline(f,pr,'\n');
	multimap < string , list<Point> >::iterator e1=m.find(dt);
	if(e1==m.end())
	{
		//cout<<"not\n";
		list<Point> s;
		s.push_back(Point(st,et,ev,atoi(pr.c_str())));
		m.insert(make_pair(dt,s));
	}
	else
	{
		e1->second.push_back(Point(st,et,ev,atoi(pr.c_str())));
		e1->second.sort(myComparator());
		//cout<<"exists\n";
	}
	//cout<<"\n"<<dt<<"->"<<st<<"->"<<et<<"->"<<ev<<"->"<<pr;
    //delete e;
}
f.close();

int o;
string dt1,st1,et1,ev1;
int pr1;
multimap < string , list<Point> >::iterator e;
do
{
	cout<<"Enter 1-Add Event 2-Delete Event 3-Display Events Other-EXIT\n";
	cin>>o;
	switch(o)
	{
		case 1:cout<<"\nEnter DATE , START TIME , END TIME , EVENT NAME , PRIORITY \n";
		cin>>dt1>>st1>>et1>>ev1>>pr1;
		e=m.find(dt1);
	    if(e==m.end())
	    {
		cout<<"added\n";
		list<Point> s;
		s.push_back(Point(st1,et1,ev1,pr1));
		m.insert(make_pair(dt1,s));
	    }
	    else
	    {
		e->second.push_back(Point(st1,et1,ev1,pr1));
		e->second.sort(myComparator());
		cout<<"added\n";
	    }
     	break;
	 case 2:cout<<"Enter date\n";
	 cin>>dt1;
	 e=m.find(dt1);
	 if(e==m.end())
	 {
	 	cout<<"NO EVENTS IN "<<dt1[0]<<dt1[1]<<"/"<<dt1[2]<<dt1[3]<<"/"<<dt1[4]<<dt1[5]<<dt1[6]<<dt1[7]<<"\n";
	 }
	 else
	 {
	 	list<Point>::iterator j=e->second.begin();
	 	for(;j!=e->second.end();j++)
	{
		cout<<j->getST()<<" -> "<<j->getET()<<"->"<<j->getEV()<<"->"<<j->getX()<<"\n";
	}
	 cout<<"Enter event name to delete\n";
	 	cin>>ev1;
	 	for(j=e->second.begin();j!=e->second.end();j++)
	{
		if(ev1==j->getEV())
		{
			e->second.erase(j++);
			break;
		}
			//cout<<"            "<<j->getST()<<" -> "<<j->getET()<<"->"<<j->getEV()<<"->"<<j->getX()<<"\n";
	}
	if(e->second.size()==0)
	{
		m.erase(e->first);
	}
	 }
	 break;
	case 3:
	//multimap < string , list<Point> >::iterator p;
for(e=m.begin();e!=m.end();e++)
{
	cout<<"DATE : "<<e->first[0]<<e->first[1]<<"/"<<e->first[2]<<e->first[3]<<"/"<<e->first[4]<<e->first[5]<<e->first[6]<<e->first[7]<<"\n";
	list<Point>::iterator j=e->second.begin();
	cout<<"EVENT(S) : \n";
	for(;j!=e->second.end();j++)
	{
		cout<<"            "<<j->getST()<<" -> "<<j->getET()<<"->"<<j->getEV()<<"->"<<j->getX()<<"\n";
	}
}break;

default :
	ofstream f1("data1.csv");
	 //f1<<k;
	 //f1.close();

		for(e=m.begin();e!=m.end();e++)
{
	list<Point>::iterator j=e->second.begin();
	//cout<<"EVENT(S) : \n";
	for(;j!=e->second.end();j++)
	{
		f1<<e->first<<","<<j->getST()<<","<<j->getET()<<","<<j->getEV()<<","<<j->getX()<<"\n";
		//cout<<"            "<<j->getST()<<" -> "<<j->getET()<<"->"<<j->getEV()<<"->"<<j->getX()<<"\n";
	}
}
	f1.close();
	o=4;
	cout<<"\nEXITS";
	break;
}
}while(o>=1&&o<=3);
            }
            else
            {
            cout<<"wrong password"<<endl;
            }

        }
        else
        {
        cout<<"wrong username "<<endl;
        }
       break;
case 3:
    cout<<"changing your password"<<endl;
    cout<<"enter ur username"<<endl;
    fflush(stdin);
    gets(c);
    if(strcmp(a2.name,c)==0)
    cout<<"enter your current password"<<endl;
     gets(a);
    if(strcmp(a,a2.paswrd) == 0)
     {
    cout<<"enter your new password"<<endl;
     gets(d);
     strcpy(a2.paswrd,d);
     f1.open("w.txt",ios::out);
     f1.write((char*)&a2,sizeof(a2));
     f1.close();
    cout<<"your password has been updated"<<endl;
     }
    break;
    case 4:
    cout<<"forgot password"<<endl;
    cout<<"enter answer for this question"<<endl;
    cout<<a2.q<<endl;
    cin>>d;
    if(strcmp(a2.a,d)==0)
    {
    cout<<"your password is "<<a2.paswrd<<endl;
    }
    break;
    default:
    	exit(0);
    //cout<<"enter correct choice"<<endl;
}
}while(1);
}
};
int main()
{
    Account a;
    a.input();
    a.out();
    f1.close();
    return 0;
}
