package hello.advanced.trace.threadlocal;

import hello.advanced.trace.threadlocal.code.ThreadLocalService;
import hello.advanced.util.CommonUtil;
import lombok.extern.slf4j.Slf4j;
import org.junit.jupiter.api.Test;

@Slf4j
public class ThreadLocalServiceTest {

    private final ThreadLocalService service = new ThreadLocalService();

    @Test
    void field() {
        log.info("main start");
        Runnable userA = () -> service.logic("userA");
        Runnable userB = () -> service.logic("userB");

        Thread threadA = new Thread(userA);
        threadA.setName("thread-A");
        Thread threadB = new Thread(userB);
        threadA.setName("thread-B");

        threadA.start();
//        CommonUtil.sleep(2000); // 동시성문제 발생 X
        CommonUtil.sleep(100); // 동시성문제 발생
        threadB.start();

        CommonUtil.sleep(2000); // main thread 종료 대기
        log.info("main exit");
    }
}
