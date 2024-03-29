package hello.core.lifecycle;

import org.springframework.beans.factory.DisposableBean;
import org.springframework.beans.factory.InitializingBean;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

public class NetworkClient /*implements InitializingBean, DisposableBean*/ {

    private String url;

    public NetworkClient() {
        System.out.println("생성자 호출, url = " + url);
    }

    public void setUrl(String url) {
        this.url = url;
    }

    // 서비스 시작 시 호출
    public void connect() {
        System.out.println("connected! : " + url);
    }

    public void call(String message) {
        System.out.println("called : " + url + " message : " + message);
    }

    public void disconnect() {
        System.out.println("disconnected! : " + url);
    }

//    @Override
    @PostConstruct
    public void init() throws Exception {
        connect();
        call("초기화 연결 메세지");
    }

//    @Override
    @PreDestroy
    public void close() throws Exception {
        disconnect();
    }
}
