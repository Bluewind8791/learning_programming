package hello.advanced.app.v4;


import hello.advanced.trace.logtrace.LogTrace;
import hello.advanced.trace.template.AbstractTemplate;
import lombok.RequiredArgsConstructor;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequiredArgsConstructor
public class OrderControllerV4 {

    private final OrderServiceV4 orderService;
    private final LogTrace trace;

    @GetMapping("/v4/request")
    public String request(String itemId) throws IllegalAccessException {
        AbstractTemplate<String> template = new AbstractTemplate<>(trace) {
            @Override
            public String call() throws IllegalAccessException {
                orderService.orderItem(itemId); // 기존 로직
                return "ok";
            }
        };

        return template.execute("OrderController.request()");
    }
}
