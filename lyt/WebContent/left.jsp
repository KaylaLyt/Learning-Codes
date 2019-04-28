<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>left</title>
<style>
body{
background: #F0F8FF;
}
table{
margin-top:25px;
}
tr{
height:40px;
width:140px;
}
td{
border-bottom:1px solid gray;
width:140px;
text-align:center;
}
th{
background:#CCCCCC;
text-align:center;
}

</style>
</head>
<body>
<table>
<th><h2>管理目录</h2></th>
<tr><td><a href ="addUser.jsp" target ="rightframe">用户注册</a></td></tr>
<tr><td><a href ="login.jsp" target ="rightframe">用户登录</a></td></tr>
<tr><td><a href ="readUser.jsp" target ="rightframe">当前用户</a></td></tr>
<tr><td><a href ="logout.jsp" target ="rightframe">用户退出</a></td></tr>
</table>
</body>
</html>