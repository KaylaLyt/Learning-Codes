<%@ page language="java" contentType="text/html; charset=utf-8"
    pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>登陆页面</title>
<style type="text/css">
body{
background: #F0F8FF;
}
table{
text-align:center;
margin-left:30%;
margin-top:60px;
}
</style>
</head>
<body>
<form method = "POST" action = "LoginServlet">
<table>
<tr>
<td>用户名：</td>
<td><input type = "text" name = "username"></td>
</tr>
<tr>
<td>密码：</td>
<td><input type = "password" name = "userpass"></td>
</tr>
<tr>
<td></td>
<td><input type="submit" value="登陆"> <input type="reset" value="重置"></td>
</tr>
</table>

</form>
</body>
</html>