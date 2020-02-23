#include<bits/stdc++.h>
using namespace std;
class Solution {
    int x[100]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int get(string date)
    {
        int y=0,m=0,d=0,i,ans=0;
        for(i=0;i<4;i++)y=y*10+date[i]-'0';
        for(i=5;i<7;i++)m=m*10+date[i]-'0';
        for(i=8;i<10;i++)d=d*10+date[i]-'0';
        for(i=0;i<y;i++)if(i%400==0||i%4==0&&i%100)ans+=366;
        else ans+=365;
        if(y%400==0||y%4==0&&y%100)x[2]=29;
        else x[2]=28;
        for(i=1;i<m;i++)ans+=x[i];
        ans+=d;
        return ans;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(get(date1)-get(date2));
    }
};
class Solution {
public:
    struct Date
{
	int y;//year
	int m;//month
	int d;//day in month
};
bool isLeap(int y)//判断是否是闰年
{
	return y%4==0&&y%100!=0||y%400==0;//真返回为1，假为0
}
int daysOfMonth(int y,int m)
{
	int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(m!=2)
		return day[m-1];
	else 
		return 28+isLeap(y);
}
int daysOfDate(Date d)//计算一共的天数
{
	int days=d.d;
	for(int y=1;y<d.y;y++)//计算年
		days+=365+isLeap(y);
	for(int m=1;m<d.m;m++)//计算月
		days+=daysOfMonth(d.y,m);
	//days+=d.d;
	return days;
}
    int daysBetweenDates(string date1, string date2) {
        int y1=stoi(date1.substr(0,4)),m1=stoi(date1.substr(5,2)),d1=stoi(date1.substr(8,2));
        int y2=stoi(date2.substr(0,4)),m2=stoi(date2.substr(5,2)),d2=stoi(date2.substr(8,2));
        Date da1,da2;
        da1.y=y1;da1.m=m1;da1.d=d1;
        da2.y=y2;da2.m=m2;da2.d=d2;
        return abs(daysOfDate(da2)-daysOfDate(da1));
}
};