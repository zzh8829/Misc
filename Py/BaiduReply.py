#! /usr/bin/env python
#-*- coding:utf-8 -*-

global contents,huitie,tiebaList,accList

# accounts
accList = [
    {"username":'xxx','password':'xxx'}
    #,{"username":'xxx','password':'xxx'}
    ]
# tiebas
tiebaList = [
    '易语言'
    ]

# 回帖内容 从这里面随机挑选
contents = [
    '本内容由回帖脚本发送'
    ]

# 回帖的编号 2是第3贴 5是第6贴 (为了跳过顶置) 以此类推 (可以随便选 不用1，2，3，4是为了怕被看出来- -!)
huitie = [2,5,7]

import urllib
import urllib2
import cookielib
import json
import re
import time
import os
import random
import sys
import urlparse

class LogMaker:
    if sys.platform.startswith('win'):
        def decode(self,s):
            try:
                return s.decode('utf8')
            except:
                return s
    else:
        def decode(self,s):
            return s
        
    def __init__(self):
        self.filePath = sys.path[0]
        self.logFile = open(self.filePath+"/sign.log",'a')
        t = time.strftime("%Y-%m-%d %H:%M:%S",time.localtime())
        self.makeLog("## %s"%t)

    def makeLog(self,*args):
        for item in args:
            print(self.decode(item))
            self.logFile.write(item)
            self.logFile.write("\n")

class Tieba:
    def __init__(self,username,password):
        self.username=username
        self.password=password
        cj = cookielib.CookieJar()
        self.opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
        self.opener.addheaders = [('User-agent', 'Mozilla/5.0 (X11; Linux i686)')]
        urllib2.install_opener(self.opener)
        
    def openUrl(self,*args):
        try:
            if len(args)==1:
                wPage=urllib2.urlopen(args[0])
            else:
                req = urllib2.Request(args[0],urllib.urlencode(args[1]))
                wPage=urllib2.urlopen(req)
            return wPage.read()
        except urllib2.HTTPError:
            Log.makeLog('An Error occured, try again in 1 second.')
            time.sleep(1)
            if len(args) > 1 and 'tbs' in args[1]:
                if 'tid' in args[i]:
                    args[1]['tbs']=self.getTbs(args[1]['tid'])
                else:
                    args[1]['tbs']=self.getTbs()
            self.openUrl(*args)

    def login(self):
        def post():
            url = 'https://passport.baidu.com/v2/api/?login'
            page = self.openUrl(url,data)

        data={"username":self.username.decode("utf8").encode("gbk"),"password":self.password,"verifycode":'',
            "mem_pass":"on","charset":"GBK","isPhone":"false","index":"0",
            "safeflg":"0","staticpage":"http://tieba.baidu.com/tb/v2Jump.html",
              "loginType":"1","tpl":"tb","codestring":'',
              "callback":"parent.bdPass.api.loginLite._submitCallBack"}

        post()
        token_url="https://passport.baidu.com/v2/api/?loginliteinfo&username=%s&isPhone=false&tpl=tb&immediatelySubmit=false&index=0&t=1345615911499"%self.username
        token_page=self.openUrl(token_url)
        data["token"]=re.findall("token:'(\w+)'" ,token_page)[0]
        post()

        return True

    
    def getFid(self):
        page = self.openUrl(self.tb_url)
        fid = re.findall("fid:'(\d+)'",page)
        if fid == []:
            Log.makeLog("Get Fid Failed, try again in 1 second.")
            time.sleep(1)
            return self.getFid()
        else:
            return fid[0]

    def getContent(self):
        return random.sample(contents,1)[0]

    def reply(self,tid):
        if tid.__class__ ==[].__class__:
            for i in tid:
                self.reply(i)
            return
        reply_url="http://tieba.baidu.com/f/commit/post/add"
        data = {
            'kw':self.kw,'ie':'utf-8','rich_text':'1',
            'anonymous':'0','content':"此贴由脚本发送",
            'fid':self.fid,'tid':tid
            }
        data['tbs'] = self.getTbs(tid)
        fd = self.openUrl(reply_url,data)

    def getTopics(self):
        page = self.openUrl(self.tb_url)
        #print page
        tids = re.findall('<a href="/p/(\d+)"',page)
        #print tids
        return tids[2:]

    def enter(self,tb_kw,tb_url):
        if tb_url.startswith('http://'):
            self.tb_url=tb_url
            self.kw=tb_kw
        else:
            self.kw=urllib.unquote(tb_kw)
            self.tb_url="http://tieba.baidu.com/f?%s"%tb_url
        
        self.fid=self.getFid()

    def getTbs(self,tid=None):
        if tid:
            page = self.openUrl("http://tieba.baidu.com/p/%s"%tid)
            Log.makeLog ("http://tieba.baidu.com/p/%s"%tid)
            tbs=re.findall("'tbs'  : \"(\w+)\"",page)
        else:
            page = self.openUrl(self.tb_url)
            tbs=re.findall('<input type="hidden" name="tbs" value="(\w+)"/>',page)
        if tbs==[]:
            return None
        return tbs[0]

            
if __name__ == '__main__':
    Log = LogMaker()

    nm = raw_input("Enter name\n")
    ps = raw_input("Enter Pass\n")
    user = Tieba(nm,ps)
    if user.login():
        Log.makeLog('%s Login Success'%user.username)
        for tieba in tiebaList:
            url = urllib.urlencode({'kw':tieba.decode('u8').encode('gb2312'),})
            user.enter(tieba,url)
            #top = user.getTopics()
            #print top
            #for i in huitie:
                #user.reply(top[i])
            user.reply("1869412685")

    print ('Reply Finished')
