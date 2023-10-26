package hello.core.common;

import lombok.Setter;
import lombok.extern.slf4j.Slf4j;
import org.springframework.context.annotation.Scope;
import org.springframework.context.annotation.ScopedProxyMode;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import java.util.UUID;

@Slf4j
@Component
@Scope(value = "request", proxyMode = ScopedProxyMode.TARGET_CLASS) // HTTP 요청 당 하나씩 생성
public class MyLogger {

    private String uuid;

    @Setter
    private String requestURL;

    public void log(String msg) {
        log.info(String.format("[%s][%s] %s%n", uuid, requestURL, msg));
    }

    @PostConstruct
    public void init() {
        uuid = UUID.randomUUID().toString();
        log.info(String.format("[%s] request scope bean CREATED : %s \n", uuid, this));
    }

    @PreDestroy
    public void close() {
        log.info(String.format("[%s] request scope bean CLOSED : %s \n", uuid, this));
    }
}
