<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8" import="java.util.*"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
<style type="text/css">
body{
text-align:center;
font-size:20px;
background: #F0F8FF;
}
</style>
</head>
<body>

	<%
		String username = (String) session.getAttribute("username");
		if (username != null) {
			session.removeAttribute("username");
			session.invalidate();
			out.println("<br/><br/><br/><br/><br/>" + username + " 成功退出！");
		} 
		else {
			out.println("<br/><br/><br/><br/><br/>还未登录！");
		}
		//response.sendRedirect("login.jsp");
	%>
	
	请点击：<a href = 'login.jsp' data-toggle="www.baidu.com">重新登陆</a>
</body>
</html>

