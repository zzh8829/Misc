function init(str){
//	checkAll(str,true);
//	showcmt(str.substr(5),"1");
	set_login_status('login_status');
	set_user_name('username_id');
}
function checkAll(str,checked) {
    var a = document.getElementsByName(str);
    var n = a.length;

    for (var i = 0; i < n; i++) {
        a[i].checked = checked;
    }
    em_size(str);
}
function em_size(str) {
    var a = document.getElementsByName(str);
//    var b = document.getElementsByName(str+"size");
    var n = a.length;
    try {
        var input_checkall = document.getElementById("checkall_"+str);
        var size = 0;
        input_checkall.checked = true ;
        for (var i=0; i < n; i++) {
            if (a[i].checked) {
                var piecesArray = a[i].value.split( "|" );
//                b[i].innerHTML = gen_size(piecesArray[3]*1,3,1);
                size += piecesArray[3]*1;
            } else {
                input_checkall.checked = false;
            }
        }
        test = document.getElementById("size_"+str);
        test.innerHTML = gen_size(size, 3, 1);
    } catch (e) {

    }
}
function gen_size(val, li, sepa ) {
	if (parseInt(val)<1) return 0;
    sep = Math.pow(10, sepa); //小数点后的位数
    li = Math.pow(10, li); //开始截断的长度
    retval  = val;
    unit    = 'Bytes';
    if (val >= li*1000000000) {
        val = Math.round( val / (1099511627776/sep) ) / sep;
        unit  = 'TB';
    } else if (val >= li*1000000) {
        val = Math.round( val / (1073741824/sep) ) / sep;
        unit  = 'GB';
    } else if (val >= li*1000) {
        val = Math.round( val / (1048576/sep) ) / sep;
        unit  = 'MB';
    } else if (val >= li) {
        val = Math.round( val / (1024/sep) ) / sep;
        unit  = 'KB';
    }
    return val + unit;
}
function copy(str) {
    var a = document.getElementsByName(str);
    var n = a.length;
    var ed2kcopy = "";
    for (var i = 0; i < n; i++) {
        if(a[i].checked) {
            ed2kcopy += a[i].value;
            ed2kcopy += "\n";
        }
    }
    copyToClipboard(ed2kcopy);
}
function countlink(str){
	var r = 0;
	a = document.getElementsByName(str);
	n = a.length;
	for ( var i = 0; i < n; i++ ){
		if ( a[i].checked) {
			r += 1;
		}
	}
	return r;
}
function copy2popup(str){
	var a = document.getElementsByName(str);
	var n = a.length;
	var ed2kcopy = "";
	for (var i = 0;i < n; i++) {
		if (a[i].checked) {
			ed2kcopy += a[i].value;
			ed2kcopy += "<br>\n";
		}
	}
	return ed2kcopy;
}
function copyToClipboard(txt) {
	if(window.clipboardData) {
   		window.clipboardData.clearData();
   		window.clipboardData.setData("Text", txt);
	} else if(navigator.userAgent.indexOf("Opera") != -1) {
		window.location = txt;
	} else if (window.netscape) {
		try {
			netscape.security.PrivilegeManager.enablePrivilege("UniversalXPConnect");
		} catch (e) {
			alert("被浏览器拒绝！\n请在浏览器地址栏输入'about:config'并回车\n然后将'signed.applets.codebase_principal_support'设置为'true'");
		}
		var clip = Components.classes['@mozilla.org/widget/clipboard;1'].createInstance(Components.interfaces.nsIClipboard);
		if (!clip)
			return;
		var trans = Components.classes['@mozilla.org/widget/transferable;1'].createInstance(Components.interfaces.nsITransferable);
		if (!trans)
			return;
		trans.addDataFlavor('text/unicode');
		var str = new Object();
		var len = new Object();
		var str = Components.classes["@mozilla.org/supports-string;1"].createInstance(Components.interfaces.nsISupportsString);
		var copytext = txt;
		str.data = copytext;
		trans.setTransferData("text/unicode",str,copytext.length*2);
		var clipid = Components.interfaces.nsIClipboard;
		if (!clip)
			return false;
		clip.setData(trans,null,clipid.kGlobalClipboard);
	}
}
function download(str, i, first) {
    var a = document.getElementsByName(str);
    var n = a.length;

	//尝试使用activex方式批量新增下载
	try {
		var ed2k_links = '';
		var ax = new ActiveXObject("IE2EM.IE2EMUrlTaker");
		var emule_version = ax.GetEmuleVersion();
		if ('e' != emule_version.substr(0,1)) {
			throw {errorCode:'eMule not Installed.'};
		}
		for (var i = i; i < n; i++) {
			if(a[i].checked) {
				if (ed2k_links=='') {
					ed2k_links = a[i].value;
				} else {
					ed2k_links += "\n"+a[i].value;
				}
			}
		}
		ax.SendUrl(ed2k_links, 'dd', document.location);
		delete ax;
		return;
	} catch (e) {}

	if (!window.continueDown) {
		//使用最旧的方法来批量新增下载
		for (var i = i; i < n; i++) {
			if(a[i].checked) {
				window.location=a[i].value;
				if (first)
					timeout = 6000;
				else
					timeout = 500;
				i++;
				window.setTimeout("download('"+str+"', "+i+", 0)", timeout);
				break;
			}
		}
	} else {
		//使用稍微新一点的方法来批量新增下载
		for (var i = i; i < n; i++) {
			if(a[i].checked) {
				if(first){
					var k = i;
					var current_link = a[k].nextSibling;
					var multi_text = '';
					var tmp_counter = 0;
					var comma = '';
					while(true){
						if(a[k].checked && current_link){//如果是有效节点并且被选中
							if(current_link.href){
								if(current_link.href.indexOf('ed2k') !== 0){
									current_link = current_link.nextSibling;
									continue; 
								}
								if(tmp_counter > 7){//收集超过若干个有效链接后，退出
									multi_text += '<br />…………'; 
									break; 
								}
								var right_link = current_link;
								tmp_counter++;
								if (navigator.userAgent.toLowerCase().indexOf("msie")==-1) {
									multi_text += comma+current_link.text;
								}else{
									multi_text += comma+current_link.innerText;
								}
								comma = '<br />';
							}

							current_link = current_link.nextSibling;
						}else{//未被选中，或往下没有相邻节点了，那么切换到下个父节点
							if(++k >= n){//如果父节点也到底了，那么退出
								break; 
							}
							current_link = a[k].nextSibling;
						}
					}
					downPopup(right_link,multi_text);
				}

				continueDown(a[i].value);
				//window.location=a[i].value;
				if (first)
					timeout = 6000;
				else
					timeout = 500;
				i++;
				window.setTimeout("download('"+str+"', "+i+", 0)", timeout);
				break;
			}
		}
	}
}
function showPopup(txt,t,l,w,h){
	var popUp = document.getElementById("popupcontent");
 
	popUp.style.top = t + "px";
	popUp.style.left = l + "px";
	popUp.style.width = w + "px";
	popUp.style.height = h + "px";
 
	popUp.innerHTML = txt;// +
//"<div id=\"statusbar\"><button onclick=\"hidePopup();\">关闭窗口<button></div>";
 
//	var sbar = document.getElementById("statusbar");
//	sbar.style.marginTop = (parseInt(h)-40) + "px";
	popUp.style.visibility = "visible";
}
function hidePopup(){
	var popUp = document.getElementById("popupcontent");
	popUp.style.visibility = "hidden";
}
function ajaxRequest(){
 var activexmodes=["Msxml2.XMLHTTP", "Microsoft.XMLHTTP"] //activeX versions to check for in IE
 if (window.ActiveXObject){ //Test for support for ActiveXObject in IE first (as XMLHttpRequest in IE7 is broken)
  for (var i=0; i<activexmodes.length; i++){
   try{
    return new ActiveXObject(activexmodes[i])
   }
   catch(e){
    //suppress error
   }
  }
 }
 else if (window.XMLHttpRequest) // if Mozilla, Safari etc
  return new XMLHttpRequest()
 else
  return false
}

function showcmt(id,page){
    if (page==null){
        page="1";
    }
    xReq = new ajaxRequest();
    xReq.onreadystatechange = function() {
        if (xReq.readyState == 4 && xReq.status == 200){
            document.getElementById("cmts").innerHTML = xReq.responseText;
        }
    }
	if (page=="1"){
	    xReq.open("GET", "/comment/"+id, true);
	}else{
	    xReq.open("GET", "/comment/"+id+"."+page, true);
	}
    xReq.send(null);
}

function makecmt(){
    var xReq = new ajaxRequest();
//    var username = document.getElementById("username").value;
	var username = get_cookie('user')
	if ( username == '' || username == null ){
		username = '游客';
	}
    var comment = document.getElementById("cmt").value;
    var id = document.getElementById("vid").value;
    var postdata = "username="+username+"&comment="+comment+"&id="+id;
    if( xReq == null){
        window.alert("haha");
    }
    xReq.onreadystatechange = function() {
        if (xReq.readyState == 4 && xReq.status == 200) {
            var id = document.getElementById("vid").value;
            window.alert('您的评论已经添加,IE类浏览器需要在新窗口才能看到，古怪的Bug，我讨厌IE，还是Firefox和Chrome好！');
            document.getElementById("cmts").innerHTML = "评论更新中...";
            showcmt(id,"1");
        }
    }
    xReq.open("POST","/comment/submit",true);
    xReq.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    xReq.send(postdata);
}

function get_cookie( check_name ) {
	var a_all_cookies = document.cookie.split( ';' );
	var a_temp_cookie = '';
	var cookie_name = '';
	var cookie_value = '';
	var b_cookie_found = false; // set boolean t/f default f
	for ( i = 0; i < a_all_cookies.length; i++ ){
		a_temp_cookie = a_all_cookies[i].split( '=' );
		cookie_name = a_temp_cookie[0].replace(/^\s+|\s+$/g, '');
		if ( cookie_name == check_name )		{
			b_cookie_found = true;
			if ( a_temp_cookie.length > 1 ){
				cookie_value = unescape( a_temp_cookie[1].replace(/^\s+|\s+$/g, '') );
			}
			return cookie_value;
			break;
		}
		a_temp_cookie = null;
		cookie_name = '';
	}
	if ( !b_cookie_found ){
		return null;
	}
}

function set_login_status( status_id ) {
	var user = get_cookie( 'user' );
	if ( user != null && user != '' ){
		txt = '<a href="/user/'+user+'">'+user+'</a>&nbsp;|&nbsp;<a href="/logout/">退出登录</a>';
	}else{
		txt = '<a href="/login/">登录</a>&nbsp;|&nbsp;<a href="/bbs/register.php">注册</a>';
	}
	if ( document.getElementById(status_id) ) {
		document.getElementById(status_id).innerHTML = txt;
	}
}

function set_user_name( username_id ) {
	var user = get_cookie( 'user' );
	if ( user != null && user != '' ) {
		txt = '您的大名：'+user + '<input type=hidden name=username value="'+user+'">';
	}else{
		txt = '您的大名：游客 | 或者<a href="/login/">登录</a>后留言<input type=hidden name=username value="游客">';
	}
	if ( document.getElementById( username_id) ){
		document.getElementById( username_id ).innerHTML = txt;
	}
}
