package hello.core.interceptor;

import hello.core.common.MyLogger;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.HandlerInterceptor;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@Component
@RequiredArgsConstructor
public class CustomInterceptor implements HandlerInterceptor {

    // bean scope - request
    private final MyLogger myLogger;

    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) {

        String requestURL = request.getRequestURL().toString();
        myLogger.setRequestURL(requestURL);

        return true;
    }
}
