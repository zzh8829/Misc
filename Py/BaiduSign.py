#! /usr/bin/env python
#-*- coding:utf-8 -*-

# accounts
accList = [
    {"username":'xxx','password':'xxx'}
    #,{"username":'xxx','password':'xxx'}
    ]
# tiebas
tiebaList = [
    'C++','C语言','java'
    ]
	
import urllib
import urllib2
import cookielib
import json
import re
import time
import os
import random
import sys

class LogMaker:
    if sys.platform.startswith('win'):
        def decode(self,s):
            try:
                return s.decode('utf8')
            except: pass
            try:
                return s.encode('gbk')
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
            try:
                de = self.decode(item)
                print(de)
                self.logFile.write(de)
                self.logFile.write("\n")
            except:pass

class Tieba:
    def __init__(self,username,password):
        self.username=username
        self.password=password
        cj = cookielib.CookieJar()
        self.opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
        self.opener.addheaders = [('User-agent', 'Mozilla/5.0 (X11; Linux i686)')]
        urllib2.install_opener(self.opener)
        self.login()

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
        except urllib2.URLError:
            print("WTF??")

    def sign(self):
        sign_url="http://tieba.baidu.com/sign/add"
        data = {'ie':'utf-8','kw':self.kw}
        tbs = self.getTbs()
        if tbs==None:
            res = None
        else:
            data['tbs']=tbs
            res = self.openUrl(sign_url,data)
            try:
                res = json.loads(res)
            except:
                pass
        if not res or res['error']!='':
            Log.makeLog(res['error'].encode('gbk'))
        else:
            Log.makeLog('OK: No. %d '%res['data']['finfo']['current_rank_info']['sign_count'])

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

    def enter(self,tb_kw,tb_url):
        if tb_url.startswith('http://'):
            self.tb_url=tb_url
            self.kw=tb_kw
        else:
            self.kw=urllib.unquote(tb_kw)
            self.tb_url="http://tieba.baidu.com/f?%s"%tb_url
        Log.makeLog("> Tieba: "+tb_kw)
                
if __name__ == '__main__':
    try:
        from accList import accList
        from tiebaList import tiebaList
    except:
        pass
    Log = LogMaker()
    for acc in accList:
        user = Tieba(acc['username'],acc['password'])
        Log.makeLog('%s Login Success'%user.username)
        for tieba in tiebaList:
            user.enter(tieba,urllib.urlencode({'kw':tieba.decode('u8').encode('gbk')}))
            user.sign()

print ('Sign Finished')
