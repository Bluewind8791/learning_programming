package hello.core.scan.filter;

import java.lang.annotation.*;

@Target(ElementType.TYPE) // Class level에 붙는 타겟
@Retention(RetentionPolicy.RUNTIME)
@Documented
public @interface MyExcludeComponent {
}
