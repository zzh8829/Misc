#! /usr/bin/env python
#-*- coding:utf-8 -*-

# accounts
accList = [
    {"username":'','password':''}
    #,{"username":'xxx','password':'xxx'}
    ]
# tiebas
tiebaList = [
    'C++','C语言','java','李毅','魔兽世界','python','noip','qt'
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
            Log.makeLog('Sign Failed (Already signed or System error)')
        else:
            Log.makeLog('Sign Successed','You are No. %d '%res['data']['finfo']['current_rank_info']['sign_count'])
                        
class WapTieba(Tieba):
    def __init__(self,username,password):
        Tieba.__init__(self,username,password)
    def login(self):
        url = 'http://wappass.baidu.com/passport/'
        data={
            'login_username':self.username,
            'login_loginpass':self.password,
            'aaa':'登录',
            'login':'yes',
            'can_input':'0',
            'u':'http://wapp.baidu.com/f/q---wiaui_1346040694_8698--1-1-0/m?',
            'tpl':'wapp',
            'tn':'bdIndex',
            'pu':'',
            'ssid':'000000',
            'from':'',
            'bd_page_type':'1',
            'uid':'wiaui_1346040694_8698',}
        return self.openUrl(url,data)

    #Override
    def getTiebas(self):
        page=self.urlopen('http://wapp.baidu.com/m?tn=bdFBW&tab=favorite')
        return re.findall('<a href="/f/[-_\w]+?/m\?kw=([%\w]+?)">.+?</a>',page)
        
    #Override
    def enter(self,kw):
        self.kw=urllib.unquote(kw)
        self.tb_url = 'http://wapp.baidu.com/m?kw=%s'%self.kw
        Log.makeLog('> Enter Tieba %s'%self.kw)

    #Override
    def getTbs(self,tid=None):
        if tid:
            fuck = 1
        else:
            page = self.openUrl(self.tb_url)
            tbs = re.findall(
                '<input type="hidden" name="tbs" value="(\w+)"/>',page)
            if tbs==[]:
                tbs = re.findall('tbs=(\w+)&amp',page);
                print tbs
                if  tbs==[]:
                    Log.makeLog("get Tbs Faild T_T ")
                    return None
        return tbs[0]

            
if __name__ == '__main__':
    try:
        from accList import accList
        from tiebaList import tiebaList
    except:
        pass
    Log = LogMaker()
    for acc in accList:
        user = WapTieba(acc['username'],acc['password'])
        if user.login():
            Log.makeLog('%s Login Success'%user.username)
            for tieba in tiebaList:
                user.enter(tieba)
                user.sign()

print ('Sign Finished')
