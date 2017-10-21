#include<bits/stdc++.h>
using namespace std;
 int main()
 {
 	ifstream f("data.csv");
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
	getline(f,st,',');
	getline(f,et,',');
	getline(f,ev,',');
	getline(f,pr,'\n');
	
	
	cout<<"\n"<<dt<<"->"<<st<<"->"<<et<<"->"<<ev<<"->"<<pr;
}
f.close();
	 
	 /*string k;
 	//f<<"hey\nhello";
 	getline(f,k);
 	cout<<k;
	 
	 f.close();
	 //delete f;
	 
	
	 ofstream f1("testabc.txt");
	 
	 cin>>k;
	 f1<<k;
	 f1.close();
	 //delete f;
	 ifstream f2("testabc.txt");
 	//string k;
 	//f<<"hey\nhello";
 	while(getline(f2,k))
 	cout<<k;
	 
	 f.close();*/
 	return 0;
 }
