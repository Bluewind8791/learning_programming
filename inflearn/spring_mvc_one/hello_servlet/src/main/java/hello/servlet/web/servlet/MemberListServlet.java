package hello.servlet.web.servlet;

import hello.servlet.domain.Member;
import hello.servlet.domain.MemberRepository;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

@WebServlet(name = "memberListServlet", urlPatterns = "/servlet/members")
public class MemberListServlet extends HttpServlet {

    private MemberRepository memberRepository = MemberRepository.getInstance();

    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        List<Member> list = memberRepository.findAll();

        resp.setContentType("text/html");
        resp.setCharacterEncoding("UTF-8");

        // 템플릿 엔진이 필요하다... 이 무슨 노가다인가
        PrintWriter writer = resp.getWriter();
        writer.println("<html>");
        writer.println("<head>");
        writer.println("<title>Servlet MemberListServlet</title>");
        writer.println("</head>");
        writer.println("<body>");
        writer.println("    <table>");
        list.forEach(member -> {
            writer.println("     <tr>");
            writer.println("         <td>" + member.getId() + "</td>");
            writer.println("         <td>" + member.getUsername() + "</td>");
            writer.println("         <td>" + member.getAge() + "</td>");
            writer.println("     </tr>");
        });
        writer.println("    </table>");
        writer.println("</body>");
        writer.println("</html>");
    }
}
