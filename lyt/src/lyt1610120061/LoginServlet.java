package lyt1610120061;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletContext;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class LoginServlet
 */
@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
    private static final long serialVersionUID = 1L;

    /**
     * @see HttpServlet#HttpServlet()
     */
    public LoginServlet() {
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
        PrintWriter out = response.getWriter();
        String username = request.getParameter("username");
        String userpass = request.getParameter("userpass");
        ServletContext ctx = request.getServletContext();
        //String server = ctx.getInitParameter("server");    
        DBOper db = new DBOper();
        db.getConn();
        String sql = "SELECT username,userpass,sex,phone,email,image FROM tb_user WHERE username = ? AND userpass = ?";
        ResultSet rs = db.executeQuery(sql,new String[]{username,userpass});
        try {
            if(rs != null && rs.next()){
                HttpSession session = request.getSession();
                session.setAttribute("username",username);
                SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss");
                String logtime = sdf.format(new Date()); 
                session.setAttribute("logtime",logtime);
                
                Cookie cookie = new Cookie("username",username);
                cookie.setMaxAge(60*60*24*30);
                response.addCookie(cookie);
                request.getSession().setAttribute("username",username);//将用户名保存在整个会话期间  
                RequestDispatcher dispatcher = request.getRequestDispatcher("MainServlet");
                dispatcher.forward(request,response);
                             
                User user = new User();//创建User并保存在整个会话期间
    			user.setUsername(rs.getString("username"));
    			if(rs.getString("username")==null)	out.print("null");
                user.setUserpass(rs.getString("userpass"));
                user.setImage(rs.getString("image"));
                user.setSex(rs.getString("sex"));
                user.setPhone(rs.getString("phone"));
                user.setEmail(rs.getString("email"));
                //if(user!=null) out.print("ok");
                //else	out.print("no");
    			request.getSession().setAttribute("user", user);
    			
            }else{
                out.print("<br/>登录失败");
                out.print("<br/><a href = 'login.jsp'>重新登陆</a>");
            }
        } catch (SQLException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }

    public void init()throws ServletException {

    }

}