摘自: 星期、干支、二十八宿计算公式 打印本页 关闭本窗口 
1. 求星期公式
星期=[5+A(实际天数)] mod 7

2. 干支计算公式
六十甲子干支序号，从1->59->0。
六十甲子干支序号=[23+A(实际天数)] mod 60

3. 二十八宿计算公式
二十八宿序号=[23+A(实际天数)] mod 28

4. 实际天数A的计算
A=B(基本天数)+C(闰日天数)
B=(计算年-1)*365+(要计算到年的月日天数)
例：1984年2月1日的基本天数B=(1984-1)*365+(31+1)=723827(天)，
其中，31是1月为31天，1为2月1日为1天。
公元308年8月28日的基本天数
B=(308-1)*365+(31+28+31+30+31+30+31+27)=112055+239=112294(天)
这里的(要计算到年的月日天数)，用的是公历，月日天数的规则我好
象小学就学过了。哈哈……

C=(计算年-1) div 4 -误差修正值 + fixValue2
fixValue2为0或者1。常值为0，当年数为闰年(公历闰年法)之中的3月
1日之后的为1。

误差修正值推算：
公元元年1月1日至1582年10月14日为0。
1582年10月15日至1699年12月31日为10。
从1701年1月1日起每增加一个世纪累加1，但能被400除尽的世纪不累
加1。此方法推算即可。
--有一个问题，1700年这一年的修正值应为多少呢？算法中正好没有
讲到，但看来应该是10。

例1701年1月1日起误差值为11，而1801年1月1日起误差修正值为12，
而1901年1月1日起误差修正值为13，
但2001年误差修正值仍为13，因为2000年能被400整除，故不累加。而
2101年1月1日起误差修正值为14。

5. 实例：1998.3.15的星期、干支与二十八宿
B=(1998-1)*365+(31+28+15)=728979
C=(1998-1) div 4 - 13 + 0 = 486
A=B+C=728979+486=729465
星期序号=(5+729465) mod 7=0，即为星期日
干支序号=(13+729465) mod 60=58，即为辛酉
二十八宿序号=(23+729465) mod 28=4，即为房

===================================================
好可怕！还有一些其它公式……但好象有些参数不知道怎么得到：

二十四节交节日算法：
用已知年的交接时辰加上22个小时35分，超过24要减去24，分数足60
进1个小时，即得到8年后的各节交节时辰。
如2000年雨水交节时辰为16时22分，则2008年雨水交节时辰为14时52
分。
因为16时22分+22时35分=38时57分。38-24=14时。
谁知道公元元年到公元八年的交节日，这个算法就可以实现了。--好
象逆算法可以解决这个问题。谁试试？

农历闰月算法：
农历中，二十四节气(十二节气和十二中气)的中气落在月末的话，下
个月就没有中气。农历将这种有节(节气)无气(中气)的月份规定为闰
月。平均计算，19年有七个闰月。
但二十四个节气的十二节气和十二中气是怎么分的呢？我没有资料，
估记应该是一节气一中气这样交叉。 :(

unit CNYear; 

interface 
uses sysutils; 
type TCNDate = Cardinal; 
function DecodeGregToCNDate(dtGreg:TDateTime):TCNDate; 
function 
GetGregDateFromCN(cnYear,cnMonth,cnDay:word;bLeap:Boolean=Fal
se):TDateTime; 
function GregDateToCNStr(dtGreg:TDateTime):String; 
function isCNLeap(cnDate:TCNDate):boolean; 
implementation 
const cstDateOrg:Integer=32900; //公历1990-01-27的TDateTime表
示 对应农历1990-01-01 
const cstCNYearOrg=1990; 
const cstCNTable:array[cstCNYearOrg..cstCNYearOrg + 60] of 
WORD=( // unsigned 16-bit 
24402, 3730, 3366, 13614, 2647, 35542, 858, 1749, //1997 
23401, 1865, 1683, 19099, 1323, 2651, 10926, 1386, //2005 
32213, 2980, 2889, 23891, 2709, 1325, 17757, 2741, //2013 
39850, 1490, 3493, 61098, 3402, 3221, 19102, 1366, //2021 
2773, 10970, 1746, 26469, 1829, 1611, 22103, 3243, //2029 
1370, 13678, 2902, 48978, 2898, 2853, 60715, 2635, //2037 
1195, 21179, 1453, 2922, 11690, 3474, 32421, 3365, //2045 
2645, 55901, 1206, 1461, 14038); //2050 
//建表方法： 
// 0101 111101010010 高四位是闰月位置,后12位表示大小月,大月30
天,小月29天, 
//闰月一般算小月,但是有三个特例2017/06,2036/06,2047/05 
//对于特例则高四位的闰月位置表示法中的最高为设置为1 特殊处理
用wLeapNormal变量 
// //2017/06 28330->61098 2036/06 27947->60715 2047/05 
23133->55901 

//如果希望用汇编,这里有一条信息:农历不会滞后公历2个月. 
//将公历转换为农历 
//返回:12位年份+4位月份+5位日期 
function DecodeGregToCNDate(dtGreg:TDateTime):TCNDate; 
var 
iDayLeave:Integer; 
wYear,wMonth,wDay:WORD; 
i,j:integer; 
wBigSmallDist,wLeap,wCount,wLeapShift:WORD; 
label OK; 
begin 
result := 0; 
iDayLeave := Trunc(dtGreg) - cstDateOrg; 
DecodeDate(IncMonth(dtGreg,-1),wYear,wMonth,wDay); 
if (iDayLeave < 0) or (iDayLeave > 22295 )then Exit; 
//Raise Exception.Create('目前只能算1990-01-27以后的'); 
//Raise Exception.Create('目前只能算2051-02-11以前的'); 
for i:=Low(cstCNTable) to High(cstCNTable) do begin 
wBigSmallDist := cstCNTable[i]; 
wLeap := wBigSmallDist shr 12; 
if wLeap > 12 then begin 
wLeap := wLeap and 7; 
wLeapShift := 1; 
end else 
wLeapShift := 0; 
for j:=1 to 12 do begin 
wCount:=(wBigSmallDist and 1) + 29; 
if j=wLeap then wCount := wCount - wLeapShift; 
if iDayLeave < wCount then begin 
Result := (i shl 9) + (j shl 5) + iDayLeave + 1; 
Exit; 
end; 
iDayLeave := iDayLeave - wCount; 
if j=wLeap then begin 
wCount:=29 + wLeapShift; 
if iDayLeave < wCount then begin 
Result := (i shl 9) + (j shl 5) + iDayLeave + 1 + (1 shl 21); 
Exit; 
end; 
iDayLeave := iDayLeave - wCount; 
end; 
wBigSmallDist := wBigSmallDist shr 1; 
end; 
end; 
//返回值: 
// 1位闰月标志 + 12位年份+4位月份+5位日期 (共22位) 
end; 
function isCNLeap(cnDate:TCNDate):boolean; 
begin 
result := (cnDate and $200000) <> 0; 
end; 
function 
GetGregDateFromCN(cnYear,cnMonth,cnDay:word;bLeap:Boolean=Fal
se):TDateTime; 
var 
i,j:integer; 
DayCount:integer; 
wBigSmallDist,wLeap,wLeapShift:WORD; 
begin 
// 0101 010010101111 高四位是闰月位置,后12位表示大小月,大月30
天,小月29天, 
DayCount := 0; 
if (cnYear < 1990) or (cnYear >2050) then begin 
Result := 0; 
Exit; 
end; 
for i:= cstCNYearOrg to cnYear-1 do begin 
wBigSmallDist := cstCNTable[i]; 
if (wBIgSmallDist and $F000) <> 0 then DayCount := DayCount + 
29; 
DayCount := DayCount + 12 * 29; 
for j:= 1 to 12 do begin 
DayCount := DayCount + wBigSmallDist and 1; 
wBigSmallDist := wBigSmallDist shr 1; 
end; 
end; 
wBigSmallDist := cstCNTable[cnYear]; 
wLeap := wBigSmallDist shr 12; 
if wLeap > 12 then begin 
wLeap := wLeap and 7; 
wLeapShift := 1; //大月在闰月. 
end else 
wLeapShift := 0; 
for j:= 1 to cnMonth-1 do begin 
DayCount:=DayCount + (wBigSmallDist and 1) + 29; 
if j=wLeap then DayCount := DayCount + 29; 
wBigSmallDist := wBigSmallDist shr 1; 
end; 
if bLeap and (cnMonth = wLeap) then //是要闰月的吗? 
DayCount := DayCount + 30 - wLeapShift; 
result := cstDateOrg + DayCount + cnDay - 1; 
end; 

//将日期显示成农历字符串. 
function GregDateToCNStr(dtGreg:TDateTime):String; 
const hzNumber:array[0..10] of string=('零','一','二','三','
四','五','六','七','八','九','十'); 
function ConvertYMD(Number:Word;YMD:Word):string; 
var 
wTmp:word; 
begin 
result := ''; 
if YMD = 1 then begin //年份 
while Number > 0 do begin 
result := hzNumber[Number Mod 10] + result; 
Number := Number DIV 10; 
end; 
Exit; 
end; 
if Number<=10 then begin //可只用1位 
if YMD = 2 then //月份 
result := hzNumber[Number] 
else //天 
result := '初' + hzNumber[Number]; 
Exit; 
end; 
wTmp := Number Mod 10; //个位 
if wTmp <> 0 then result := hzNumber[wTmp]; 
wTmp := Number Div 10; //十位 
result:='十'+result; 
if wTmp > 1 then result := hzNumber[wTmp] + result; 
end; 
var 
cnYear,cnMonth,cnDay:word; 
cnDate:TCNDate; 
strLeap:string; 
begin 
cnDate:= DecodeGregToCNDate(dtGreg); 
if cnDate = 0 then begin 
result := '输入越界'; 
Exit; 
end; 
cnDay := cnDate and $1F; 
cnMonth := (cnDate shr 5) and $F; 
cnYear := (cnDate shr 9) and $FFF; 
//测试第22位,为1表示闰月 
if isCNLeap(cnDate) then strLeap:='(闰)' else strLeap := ''; 
result := '农历' + ConvertYMD(cnYear,1) + '年' + 
ConvertYMD(cnMonth,2) + '月' 
+ strLeap + ConvertYMD(cnDay,3) ; 
end; 
end.   