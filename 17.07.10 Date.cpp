// 17.07.10 Date.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>

class Date
{
public:
	enum Month {jan=1,feb,mar,apr,may,jun,jul,aug,sep,oct,nov,dec};
class Bad_date{};
Date(int dd=0, Month mm=0, int yy=0);
//функциидоступа к дате
int day()const;
Month month()const;
int year()const;
string string_rep() const;
void char_rep (char s[]) const;
static void set_default(int, Month, int);
//функции для изменения даты
Date& add_year(int n);
Date& add_month(int n);
Date& add_day(int n);

void init_date(int dd,int mm,int yy);

private:
int d, m, y;
static Date default_date;

mutable bool cache_valid;
mutable string cache;
void compute_cache_value();

};
void fill(vector<Date>&a)
{
	while(cin)
	{
		Date d;
		try
		{
			cin>>d;
		}
		catch(Date::Bad_date)
		{
			continue;
		}
		aa.push_back(d);
	}
}
inline int Date::day()const
{
	return d;
}
Date& Date::add_month(int n)
{
	if(n==0) return *this;
	if(n>0)
	{
		int delta_y=n/12;
		int mm=m+n%12;
		if(12<mm)
		{
			delta_y++;
			mm-=12;
		}
		//работа со случайностями, когда день d не существует для Month(mm)
		y+=delta_y;
		m=Month(mm);
		return *this;
	}
}
string Date::string_rep() const
{
	if(!cache_valid)
	{
		compute_cache_value();
		cache_valid=true;
	}
	return cache;
}
Date& Date::add_year(int n)
{
	if(d==29 && m==2 && !leapyear(y+n))
	{
		d=1;
		m=3;
	}
	y+=n;
	return *this;
}
Date::Date(int dd, Month mm, int yy)
{
	if(yy==0) yy=default_date.year(); 
	if(mm==0) mm=default_date.year();
	if(dd==0) dd=default_date.year();
	int max;
	switch(mm)
	{
	case feb:
		max=28+leapyear(yy);break;
	case apr: case jun: case sep: case nov:
		max=30;break;
	case jan: case mar: case jul: case aug: case oct: case dec:
		max=31;break;
	default:
			throw Bad_date();
	}
	if(dd<1 || max<dd) throw Bad_date();
	y=yy;
	m=mm;
	d=dd;
}



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

