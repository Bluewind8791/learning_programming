package hello.core.web;

import hello.core.common.MyLogger;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.servlet.http.HttpServletRequest;

@Controller
@RequiredArgsConstructor
public class LogDemoController {

    private final LogDemoService logDemoService;
    private final MyLogger myLogger;

    @ResponseBody // 문자 그대로 response
    @RequestMapping("log-demo")
    public String logDemo(HttpServletRequest request) {

        myLogger.log("controller test");
        logDemoService.logic("testId");

        return "200";
    }
}
