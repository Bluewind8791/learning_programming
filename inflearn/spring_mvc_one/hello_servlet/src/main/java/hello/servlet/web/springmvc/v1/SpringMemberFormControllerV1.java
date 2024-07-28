package hello.servlet.web.springmvc.v1;


import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

/**
 * @Controller의 역할
 * 1 @Component 추가
 * 2 RequestMappingHandlerMapping
 *
 * 클래스 레벨에 아래와 같이 어노테이션을 붙여도 @Controller와 동일하게 동작한다
 * @RequestMapping
 * @Component
 */

//@RequestMapping
//@Component
@Controller
public class SpringMemberFormControllerV1 {

    @RequestMapping("/springmvc/v1/member/new-form")
    public ModelAndView process(HttpServletRequest req, HttpServletResponse res) {
        // HttpServlet 파라미터도 사용할 수 있다
//        String username = req.getParameter("username");

        return new ModelAndView("new-form");
    }
}
