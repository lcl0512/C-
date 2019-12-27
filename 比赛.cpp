#include <iostream> 
#include <cstring> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;
const int MAX = 110; 
class CHugeInt {
// 在此处补充你的代码
private:
    char maxNum[210];
    int len;
public:
    CHugeInt(char * s){
        strcpy(maxNum,s);
        int i=0,j=strlen(s)-1;
        while(i<j)
        {
            swap(maxNum[i],maxNum[j]);
            i++;
            j--;
        }
        //cout<<"init:"<<maxNum<<endl;
        len=strlen(s);
        //cout<<"Init success"<<endl;
    }
    CHugeInt(){
        len=0;
    } 
    CHugeInt(int n){
        int i=0;
        if(n==0)
        {
            maxNum[i++]='0';
        }else{
            while(n)
            {
                maxNum[i++]=n%10+'0';
                n=n/10;
            }    
        }
        maxNum[i]='\0';
        len=i;
        //cout<<maxNum<<endl;
    }
    CHugeInt  operator+(CHugeInt & a)
    {
            //cout<<"hrer"<<endl;
            int i=0,j=0;
            int t,sum=0;
            CHugeInt temps;
            strcpy(temps.maxNum,maxNum);
            temps.len=len;
            //cout<<"before:"<<temps.maxNum<<endl;
            //maxNum=new char[strlen(a.maxNum)+1];
            //cout<<a.len<<","<<len<<endl;
            int flag=0;
            while(j<a.len&&i<temps.len)
            {
                t=a.maxNum[j]-'0';
                int te=temps.maxNum[i]-'0';
                sum=t+te;
                //cout<<t<<"+"<<te<<":"<<sum<<endl;
                if(sum>=10)
                {
                    temps.maxNum[i]=sum%10+'0';
                    //cout<<temps.maxNum[i]<<endl;
                    temps.maxNum[i+1]=sum/10+temps.maxNum[i+1];
                    if(i+1>=temps.len)
                    {
                        temps.maxNum[i+1]+='0'; 
                    }
                    flag=1;
                }else{
                    //cout<<"sum:"<<sum<<endl;
                    flag=0;
                    temps.maxNum[i]=sum+'0';
                }
                //cout<<temps.maxNum[i]<<endl;
                i++,j++;
                sum=0;
            }
            while(j<a.len)
            {
                if(flag==1)
                {
                    temps.maxNum[i+1]=a.maxNum[j];
                    i++,j++;    
                }else{
                    temps.maxNum[i]=a.maxNum[j];
                    i++,j++;
                }
            }
            if(i>=len)
            {
                if(flag==1){
                    temps.maxNum[i+1]='\0';
                    temps.len=i+1;
                }
                else{
                    temps.maxNum[i]='\0';
                    temps.len=i;
                }        
            }
        return temps;
    }
    /*operator char *()
    {
        return maxNum;
    }*/
    CHugeInt & operator +=(int n)
    {
        CHugeInt temps(n);
        *this=this->operator+(temps);
        //cout<<this->maxNum<<endl;
        return *this;
    }
    friend ostream & operator<<(ostream & os,const CHugeInt & s)
    {
            int i=0,j=s.len-1;
            //cout<<"len:"<<s.len<<endl;
            //cout<<"输出:"<<s.maxNum<<endl;
            for(;j>=i;j--)
                os<<s.maxNum[j];
            return os;
    }
    friend CHugeInt  operator+(int n,CHugeInt  s)
    {
        CHugeInt temps(n);
        s=s+temps;
        return s;
    }
    friend CHugeInt  operator+(CHugeInt  s,int n)
    {
        CHugeInt temps(n);
        s=s+temps;
        return s;
    }
    CHugeInt &  operator++()
    {
        (*this)+=1;
        //cout<<"前置自增后："<<this->maxNum<<endl;
        return *(this);
    }
    CHugeInt   operator++(int n)
    {
        CHugeInt temps;
        strcpy(temps.maxNum,maxNum);
        temps.len=len;
        this->operator +=(1);
        //cout<<temps.maxNum<<endl;
        //cout<<"len:"<<temps.len<<endl;
        return temps;
    }
};
int  main() 
{ 
    char s[210];
    int n;

    while (cin >> s >> n) {
        CHugeInt a(s);
        CHugeInt b(n);

        cout << a + b << endl;
        cout << n + a << endl;
        cout << a + n << endl;
        b += n;
        cout  << ++ b << endl;
        cout << b++ << endl;
        cout << b << endl;
    }
    return 0;
}
