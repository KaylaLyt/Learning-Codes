<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="lyt1610120061.User"%>

<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>所有用户页面</title>
<style>
body{
background: #F0F8FF;
text-align:center;
font-size:20px;
}
table{
margin-left:30%;
margin-top:50px;
border:2px solid gray;
padding:3px;
}
td{
border:1px solid gray;
padding:6px;
}
th{
padding:10px;
font-weight:normal;
}
span{
font-size:30px;
font-weight:bold;
}
.left{
width:130px;
text-align:right;
}
.right{
text-align:left;
width:310px;
}
</style>
</head>
<body>
<%

	String username = (String)session.getAttribute("username");
	//out.print(username);
	if(username!=null)
	{
	User user = (User)request.getSession().getAttribute("user");
%>

<table>
<th colspan="2">
<span><%=user.getUsername() %></span>登陆成功！
</th>
<tr>
<td class="left">头像</td>
<td class="right">
<img id="image" src="<%=user.getImage() %>" style="width:100px;height:100px" /></td>
</tr>
<tr>
<td class="left">性别</td>
<td class="right"><%=user.getSex() %></td>
</tr>
<tr>
<td class="left">联系电话</td>
<td class="right"><%=user.getPhone() %></td>
</tr>
<tr>
<td class="left">电子邮箱</td>
<td class="right"><%=user.getEmail() %></td>
</tr>
</table>

<%
	}
	else
	{
		
		out.print("<br/><br/><br/><br/>还未登录，请重试！<br/><br/>");
%>
	请点击：<a href = "login.jsp">重新登陆</a>
<%
	}
%>



</body>
</html>