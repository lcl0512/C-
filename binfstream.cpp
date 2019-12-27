#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
	char name[20];
	int score;
};
int main()
{
	ofstream out("student.dat",ios::out|ios::binary);
	Student s;
	while(cin>>s.name>>s.score)
		out.write((char*)&s,sizeof(s));
	out.close();
	ifstream in("student.dat",ios::in|ios::binary);
	while(in.read((char*)&s,sizeof(s)))
	{
		int bit=in.gcount();
		cout<<bit<<endl;
		cout<<s.name<<s.score<<endl;
	}
		
	return 0;
 } 
