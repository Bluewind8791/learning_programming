package hello.advanced.trace.logtrace;

import hello.advanced.trace.TraceStatus;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ThreadLocalLogTraceTest {

    ThreadLocalLogTrace trace = new ThreadLocalLogTrace();

    @Test
    void beginAnd2Level() {
        TraceStatus status1 = trace.begin("hello");
        TraceStatus status2 = trace.begin("hello");
        trace.end(status2);
        trace.end(status1);
    }

    @Test
    void exception() {
        TraceStatus status1 = trace.begin("hello");
        TraceStatus status2 = trace.begin("hello");
        trace.exception(status2, new IllegalAccessException());
        trace.exception(status1, new IllegalAccessException());
    }

}