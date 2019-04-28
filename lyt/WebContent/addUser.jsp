<%@ page language="java" contentType="text/html; charset=utf-8"
	pageEncoding="utf-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"         "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<title>添加用户页面</title>
<style type="text/css">
body{
background: #F0F8FF;
text-align:center;
}
table{
height:300px;
margin-left:30%;
margin-top:60px;
}
td{
text-align:right;
}
</style>
</head>
<body>
	<form action="AddUserServlet" method="POST">
		<table>
			<tr>
				<td>用户名：</td>
				<td><input type="text" name="username"></td>
			</tr>
			<tr>
				<td>密码：</td>
				<td><input type="password" name="userpass"></td>
			<tr>
			<tr>
				<td>确认密码：</td>
				<td><input type="password" name="checkpass"></td>
			</tr>
			<tr>
				<td>性别：</td>
				<td><input id="r1" type="radio" value="男" name="sex">男</input>
					<input id="r2" type="radio" value="女" name="sex">女</input></td>
			</tr>
			<tr>
				<td><label>头像：</label></td>
				<td>
				<select name="image" id="image1" onchange="document.getElementById('image').src = document.getElementById('image1').value;">
				<option value="image/1.jpg" selected="selected">头像1</option>
				<option value="image/2.jpg">头像2</option>
				<option value="image/3.jpg">头像3</option>
				</select>
				<img id="image" src="image/1.jpg" style="width:100px;height:100px" />
				</td>
			</tr>
			<tr>
				<td>联系电话：</td>
				<td><input type="text" name="phone"></td>
			</tr>
			<tr>
				<td>电子邮箱：</td>
				<td><input type="text" name="email"></td>
			</tr>
			<tr>
				<td></td>
				<td><input type="submit" value="注册"> <input type="reset" value="重置"></td>
			</tr>
		</table>
	</form>
</body>
</html>