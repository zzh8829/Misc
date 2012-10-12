#! /usr/bin/env python
#-*- coding:utf-8 -*-

# accounts
accList = [
    {"username":'xxx','password':'xxx'}
    #,{"username":'xxx','password':'xxx'}
    ]
# tiebas
tiebaList = [
    'zzh8829'#,'C语言','java','李毅','魔兽世界','python','noip','qt'
    ]

global threads

threads = [
    {'title':'Daily Post','content':'每日一贴，永不间断'}]

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
   
    def enter(self,tb_kw,tb_url):
        if tb_url.startswith('http://'):
            self.tb_url=tb_url
            self.kw=tb_kw
        else:
            self.kw=urllib.unquote(tb_kw)
            self.tb_url="http://tieba.baidu.com/f?%s"%tb_url

        self.fid=self.getFid()
        Log.makeLog("> Enter Tieba "+tb_kw)
        

    def getTbs(self,tid=None):
        if tid:
                page = self.openUrl("http://tieba.baidu.com/p/%s"%tid)
                Log.makeLog ("http://tieba.baidu.com/p/%s"%tid)
                tbs=re.findall("'tbs'  : \"(\w+)\"",page)
        else:
            page = self.openUrl(self.tb_url)
            tbs=re.findall('<input type="hidden" name="tbs" value="(\w+)"/>',page)
            if tbs==[]:
                tbs = re.findall("PageData.tbs = \"(\w+)\"",page)
                if tbs ==[]:
                    Log.makeLog("Get tbs Faild T_T" ) 
                    return None
                return tbs[0]
        return tbs[0]

    def postThread(self,title,content):
        post_url="http://tieba.baidu.com/f/commit/thread/add"
        print "Title: "+title
        print "Content: " +content
        print self.tb_url
        data = {
            'kw':self.kw,'ie':'utf-8','rich_text':'1',
            'anonymous':'0','title':title,'content':content,
            'fid':self.fid,'tid':'0','floor_num':'0',
            'mouse_pwd':'28,30,23,3,26,31,24,31,38,30,3,31,3,30,3,31,3,30,3,31,3,30,3,31,3,30,3,31,38,25,22,23,28,26,38,30,29,23,31,3,23,31,31,13471997872471'
            ,'mouse_pwd_t':'1347199787247','mouse_pwd_isclick':'1'
            }
        data['tbs'] = self.getTbs()
        fd = self.openUrl(post_url,data)
            
if __name__ == '__main__':
    try:
        from accList import accList
        from tiebaList import tiebaList
    except:
        pass
    Log = LogMaker()
    nm = raw_input("Enter name")
    ps = raw_input("Enter pass")
    user = Tieba(nm,ps)
    if user.login():
        Log.makeLog('%s Login Success'%user.username)
        for tieba in tiebaList:
            url = urllib.urlencode({'kw':tieba.decode('u8').encode('gb2312'),})
            user.enter(tieba,url)
            
            for thread in threads :
                time.sleep(5)
                user.postThread( thread['title'], thread['content'])

    print ('Post Finished')
