#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
//用户自定义流操纵算子 
ostream& twoSpace(ostream& out)
{
	out<<"  ";
	return out;
 } 
int main()
{
//	int w=4;
//	string str;
//	cin.width(w);  //设置宽度w 
//	cin>>str;
//	cout.width(++w); 
//	cout<<str;
	double d=122343435.1321233;
	cout<<setprecision(5)<<d<<endl;//保留五位有效数字 
	cout<<fixed<<setprecision(5)<<d<<endl;//保留小数点后面五位 
	cout<<scientific<<setprecision(5)<<d<<endl;//科学计数法输出保留小数点后面五位 
	
	cout<<twoSpace<<d<<endl;
	return 0;
}
