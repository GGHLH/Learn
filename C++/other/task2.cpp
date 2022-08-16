#include <iostream>
#include <string>
using namespace std;
/************************************************************/
class kalu
{
public:
	kalu()
	{
		m_iA = 0;
		m_iB = 0;
		m_iC = 0;
		m_iD = 0;
	}
	void set(double aA,double aB,double aC,double aD);
	void get()const;
	kalu operator + (kalu kalu1);
	kalu operator - (kalu kalu1);
	kalu operator * (kalu kalu1);
	kalu operator / (kalu kalu1);
	void display(kalu kalu1);
private:
	double m_iA;
	double m_iB;
	double m_iC;
	double m_iD;
};
// void
void kalu::set(double aA,double aB,double aC,double aD)
{
	m_iA = aA;
	m_iB = aB;
	m_iC = aC;
	m_iD = aD;
}
void kalu::get()const
{
	cout<<"The result is:"<<endl;
	cout<<"("<<m_iA<<","<<m_iB<<")"<<endl;
	cout<<"("<<m_iC<<","<<m_iD<<")"<<endl;
}
kalu kalu::operator + (kalu kalu1)
{
    kalu c;
	c.m_iA = m_iA + kalu1.m_iA;
	c.m_iB = m_iB + kalu1.m_iB;
	c.m_iC = m_iC + kalu1.m_iC;
	c.m_iD = m_iD + kalu1.m_iD;
	return c;
}
kalu kalu::operator - (kalu kalu1)
{
	kalu c;
	c.m_iA = m_iA - kalu1.m_iA;
	c.m_iB = m_iB - kalu1.m_iB;
	c.m_iC = m_iC - kalu1.m_iC;
	c.m_iD = m_iD - kalu1.m_iD;
	return c;
}
kalu kalu::operator * (kalu kalu1)
{
	kalu c;
	c.m_iA = m_iA * kalu1.m_iA;
	c.m_iB = m_iB * kalu1.m_iB;
	c.m_iC = m_iC * kalu1.m_iC;
	c.m_iD = m_iD * kalu1.m_iD;
	return c;
}



void kalu::display(kalu kalu1)
{
	string n;
	kalu c;
	cout<<"Please input method(+,-,*,|):";
	cin>>n;
	if  ("-" == n)
	{
		c = operator- (kalu1);
		cout<<"The result is:"<<endl;
		cout<<"("<<c.m_iA<<","<<c.m_iB<<")"<<endl;
		cout<<"("<<c.m_iC<<","<<c.m_iD<<")"<<endl;
	}
	else if ("+" == n)
	{
		c = operator+ (kalu1);
		cout<<"The result is:"<<endl;
		cout<<"("<<c.m_iA<<","<<c.m_iB<<")"<<endl;
		cout<<"("<<c.m_iC<<","<<c.m_iD<<")"<<endl;
	}
	else if ("*" == n)
	{
		c = operator* (kalu1);
		cout<<"The result is:"<<endl;
		cout<<"("<<c.m_iA<<","<<c.m_iB<<")"<<endl;
		cout<<"("<<c.m_iC<<","<<c.m_iD<<")"<<endl;
	}
	else
	{
		cout<<"The operator is error";
	}
}
// main
// main
int main(void)
{

	kalu kalu1,c2;
	double x = 0;
	double y = 0;
	double z = 0;
	double h = 0;

	cout<<" input 1lst matrix(2D):"<<endl;
	cin>>x>>y>>z>>h;
	kalu1.set(x,y,z,h);

	cout<<" input 2lst matrix(2D):"<<endl;
	cin>>x>>y>>z>>h;
	c2.set(x,y,z,h);

    kalu1.display(c2);
	system("pause");
	return 0;
}