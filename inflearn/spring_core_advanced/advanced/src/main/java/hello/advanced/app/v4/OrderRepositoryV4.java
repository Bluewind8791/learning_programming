package hello.advanced.app.v4;


import hello.advanced.trace.logtrace.LogTrace;
import hello.advanced.trace.template.AbstractTemplate;
import hello.advanced.util.CommonUtil;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Repository;


@Repository
@RequiredArgsConstructor
public class OrderRepositoryV4 {

    private final LogTrace trace;

    public void save(String itemId) throws IllegalAccessException {
        AbstractTemplate<Void> template = new AbstractTemplate<>(trace) {
            @Override
            protected Void call() throws IllegalAccessException {
                // 저장 로직
                if (itemId.equals("ex")) {
                    throw new IllegalAccessException("예외 발생");
                }
                CommonUtil.sleep(1000);
                return null;
            }
        };

        template.execute("OrderRepository.save()");
    }

}
