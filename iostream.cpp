#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//�û��Զ������������� 
ostream& twoSpace(ostream& out)
{
	out<<"  ";
	return out;
 } 
int main()
{
//	int w=4;
//	string str;
//	cin.width(w);  //���ÿ��w 
//	cin>>str;
//	cout.width(++w); 
//	cout<<str;
	double d=122343435.1321233;
	cout<<setprecision(5)<<d<<endl;//������λ��Ч���� 
	cout<<fixed<<setprecision(5)<<d<<endl;//����С���������λ 
	cout<<scientific<<setprecision(5)<<d<<endl;//��ѧ�������������С���������λ 
	
	cout<<twoSpace<<d<<endl;
	return 0;
}
