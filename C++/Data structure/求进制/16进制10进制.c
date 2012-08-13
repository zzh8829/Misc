自己写一个转换函数不就行了？

//返回16进制字符串s对应的整数值，遇到任何一个非法字符都返回-1。
int HexToDec(char *s)
{
	char *p = s;

	//空串返回0。
	if(*p == '\0')
		return 0;
	
	//忽略开头的'0'字符
	while(*p == '0')
		p++;

	int dec = 0;
	char c;

	//循环直到字符串结束。
	while(c = *p++)
	{
		//dec乘16
		dec <<= 4;
		
		//数字字符。
		if(c >= '0' && c <= '9')
		{
			dec += c - '0';
			continue;
		}

		//小写abcdef。
		if(c >= 'a' && c <= 'f')
		{
			dec += c - 'a' + 10;
			continue;
		}

		//大写ABCDEF。
		if(c >= 'A' && c <= 'F')
		{
			dec += c - 'A' + 10;
			continue;
		}

		//没有从任何一个if语句中结束，说明遇到了非法字符。
		return -1;
	}

	//正常结束循环，返回10进制整数值。
	return dec;
}
