package hello.advanced.app.v4;


import hello.advanced.trace.logtrace.LogTrace;
import hello.advanced.trace.template.AbstractTemplate;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

@Service
@RequiredArgsConstructor
public class OrderServiceV4 {

    private final OrderRepositoryV4 orderRepository;
    private final LogTrace trace;

    public void orderItem(String itemId) throws IllegalAccessException {
        AbstractTemplate<Void> template = new AbstractTemplate<>(trace) {
            @Override
            protected Void call() throws IllegalAccessException {
                orderRepository.save(itemId); // 기존 로직
                return null;
            }
        };

        template.execute("OrderService.orderItem()");
    }
}
