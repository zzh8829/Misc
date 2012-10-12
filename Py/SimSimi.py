# encoding: utf-8

import os,sys,string,urllib,urllib2,json,time,random,re

class SimSimi():
    def __init__(self,name):
        self.cookies = 0
        self.name = name
        self.update()
        self.opener = urllib2.build_opener()
        self.noanswer=[
            u"我不明白你的意思。",
            u"我不太懂你在说什么。",
            u"我们能换一个话题吗？",
            u"你高估我了，我没有你想的那么聪明。",
            u"我不懂你在说什么。",
            u"我对你的问题不太感兴趣。",
            u"我还没想好怎么回答你的问题呢。",
            u"我应该怎么回答你这个奇怪的问题呢？",
            u"我不太懂你的话。",
            u"你能跟我解释一下吗？",
            u"你的问题让我很纠结。",
            u"你的问题让我真的很纠结。",
            u"你的问题难倒我了。",
            u"我没听说过那个东西。",
            u"天天被你们拉去聊天，我都很少了解时事了。",
            u"不要问我那么刁钻古怪的问题啦！",
            u"我对那个不感兴趣，跟我说说你最喜欢的明星吧。",
            u"我不关心那个，跟我说说你最喜欢的明星吧。",
            u"我对那个不感兴趣，跟我说说最近的新闻吧。",
            u"我不关心那个，跟我说说最近的新闻吧。"
        ]
     
    def update(self):
        opener=urllib2.build_opener()
        opener.addheaders = [("Referer", "http://www.simsimi.com/"),
                               ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.1 (KHTML, like Gecko) Safari/537.1"),
                               ("X-Forwarded-For", "10.2.0.123")]
        f=opener.open("http://www.simsimi.com/talk.htm").info()
        if "Set-Cookie" in f:
            newcookie=f["Set-Cookie"]
        else:
            newcookie=""
        newcookie="sagree=true; selected_nc=ch; "+newcookie
        self.cookies=newcookie

    def sendMessage(self,message):
        self.opener.addheaders = [("Accept", "application/json, text/javascript, */*; q=0.01"),
                             ("Accept-Charset", "UTF-8,*;q=0.5"),
                             ("Accept-Language", "zh-CN,zh;q=0.8,en-US;q=0.6,en;q=0.4"),
                             ("Cookie", self.cookies),
                             ("Content-Type", "application/json; charset=utf-8"),
                             ("Referer", "http://www.simsimi.com/talk.htm"),
                             ("User-Agent", "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.1 (KHTML, like Gecko) Safari/537.1"),
                             ("X-Forwarded-For", "10.2.0.123"),
                             ("X-Requested-With", "XMLHttpRequest")]
        h=self.opener.open("http://www.simsimi.com/func/req?%s" % urllib.urlencode({"msg": message.encode('utf-8'), "lc": "zh"}))
        resp = h.read()
        info = h.info()
        if "Set-Cookie" in info:
            self.cookies=info["Set-Cookie"]
        if resp=="{}":
            random.shuffle(self.noanswer)
            resp=self.noanswer[0]
        else:
            resp=json.loads(resp)["response"].replace(u"\n", u" ")
            if resp==u"hi":
                update(self)
            resp=re.sub(u"([Ss]im)?[sS]imi|小(黄|黃)?(鸡|雞)|(机|機)器(鸡|雞)|(黄|黃)小(鸡|雞)", self.name , resp)
            resp=re.sub(u"(鸡|雞)",self.name,resp)
        print resp

if __name__ == '__main__':
    Bot = SimSimi("SimSimi")
    while True:
        message = raw_input("Say Something:\n").decode(sys.stdin.encoding)
        if message == u'EXIT':
            break
        Bot.sendMessage(message)
    print ("Thank You!!")
