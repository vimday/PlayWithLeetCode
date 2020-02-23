import datetime
class Solution:
    def daysBetweenDates(self,date1:str,date2:str)->int:
        data1=datetime.datetime.strptime(date1,"%Y-%m-%d")
        data2=datetime.datetime.strptime(date2,"%Y-%m-%d")
        return abs(data1.__sub__(data2).days)