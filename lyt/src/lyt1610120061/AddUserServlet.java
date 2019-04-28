package lyt1610120061;


import java.io.IOException;
import java.io.PrintWriter;
//import java.text.SimpleDateFormat;
//import java.util.Date;

import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class AddUserServlet
 */
@WebServlet("/AddUserServlet")
public class AddUserServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

/**
 * @see HttpServlet#HttpServlet()
 */
public AddUserServlet() {
    super();
    // TODO Auto-generated constructor stub
}

/**
 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
 */
protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    // TODO Auto-generated method stub
    doPost(request,response);
}

/**
 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
 */
protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    // TODO Auto-generated method stub
    request.setCharacterEncoding("utf-8");
    response.setContentType("text/html;charset = utf-8");
    String username = request.getParameter("username");
    String userpass = request.getParameter("userpass");
    String checkpass=request.getParameter("checkpass");
    String image=request.getParameter("image");
    String sex=request.getParameter("sex");
    String phone=request.getParameter("phone");
    String email = request.getParameter("email");
    //Date curTime = new Date();
    //SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
    //String regtime = sdf.format(curTime);
    PrintWriter out = response.getWriter();
    //ServletContext ctx = this.getServletContext();
    //String server = ctx.getInitParameter("server");
    User user = new User();
    user.setUsername(username);
    user.setUserpass(userpass);
    user.setSex(sex);
    user.setImage(image);
    user.setPhone(phone);
    user.setEmail(email);
    if(checkpass.equals(userpass))
    {
    	out.println("两次密码相同！");
    	UserDao dao = new UserDao();
        dao.getConn();
        if(dao.addUser(user)){
            out.print("注册成功！");
        }
        else{
            out.print("注册失败！");
        }
    }
    /*UserDao dao = new UserDao();
    dao.getConn(server);
    if(dao.addUser(user)){
        out.print("注锟斤拷晒锟斤拷锟�");
    }
    else{
        out.print("注锟斤拷失锟杰ｏ拷");
    }*/
    else
    {
    	out.print("两次密码不同！");
    }


}

}
