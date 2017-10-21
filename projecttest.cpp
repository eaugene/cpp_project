#include<bits/stdc++.h>

using namespace std;


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
 
class myComparator
{
public:
    int operator() (const Point& p1, const Point& p2)
    {
        return p1.getX() > p2.getX();
    }
};


int main()
{
	multimap < string , list<Point> > m;
	list<Point> pq;
	
	ifstream f("data1.csv");
 	 if(!f.is_open())
 	 {
	  cout<<"fail";
return 0;
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
	cout<<"\nEXITS";
	exit(0);
}
}while(1);

multimap < string , list<Point> >::iterator p;
for(p=m.begin();p!=m.end();p++)
{
	cout<<"&&&&&&&  "<<p->first[0]<<p->first[1]<<"/"<<p->first[2]<<p->first[3]<<"/"<<p->first[4]<<p->first[5]<<p->first[6]<<p->first[7]<<"\n";
	list<Point>::iterator j=p->second.begin();
	for(;j!=p->second.end();j++)
	{
		cout<<j->getX()<<" -> "<<j->getST()<<" -> "<<j->getET()<<"->"<<j->getEV()<<" $$\n";
	}
}

	return 0;
}
