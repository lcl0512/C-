#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
using namespace std;

int main()
{
	vector<int> v;
	int x;
	fstream fstrm("file.txt",fstream::in);
	fstream ifstrm("sort.txt",fstream::out);
	while(fstrm>>x)
		v.push_back(x);
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();++i)
		ifstrm<<v[i]<<"  ";
	ifstrm.close();
	fstrm.close();
	return 0;
 } 
