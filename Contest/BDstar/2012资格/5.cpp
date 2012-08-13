#include <iostream> 
#include <cctype>
#include <string>

using namespace std;

string jorc(string word)
{
        string::iterator iter = word.begin();
		if (  ((*iter)=='_') || (isupper(*iter)) )
				return "E";
		iter++;
		for(;iter!=word.end();iter++)
			if (isupper(*iter) )
                return "J";
		if (*(word.end()-1) == '_')
				return "E";
		return "C";
}

bool CJ(string word)
{
		size_t found = word.find('_');
		if ( found !=string::npos)
				return false;
		return true;
}

bool CC(string word)
{
		string::iterator iter =word.begin();
		for (;iter!=word.end();iter++)
				if( ((*iter)!='_')&&(isupper(*iter)) )
						return false;
				else if((iter+1)!=word.end())
				        if( ((*iter)=='_')&& ((*(iter+1)) =='_') )
				            return false;
		return true;
}

string convert(string word)
{
		string check = jorc(word);
		if (check == "E")
			return"Error!" ;
		if(check == "J")
		{
				if(CJ(word))
				{
                    string rword="";
					for( string::iterator it=word.begin();it!=word.end();it++)
                         if( isupper(*it) )
					 	 {
							(*(it))=tolower(*(it));
						   rword+='_';
						   rword+=*it;

						 }
						 else rword+=*it;
					return rword;
				}
		}
		if(check== "C")
		{
				if(CC(word))
				{
					for(string::iterator it= word.begin(); it!= word.end() ;it++)
					{
						if( (*it)=='_')
						{
                            (*(it+1))=toupper(*(it+1));
							word.erase(it);
						}
                    }
				    return word;
				}
		}
		return "Error!";
}

int main()
{
		string word;
		getline(cin,word);
        cout << convert(word);
        system("pause");
		return 0;
}
