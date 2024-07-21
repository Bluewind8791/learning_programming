package hello.core.scope;

import lombok.Getter;
import lombok.RequiredArgsConstructor;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.ObjectProvider;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;
import javax.inject.Provider;

import static org.assertj.core.api.Assertions.assertThat;

public class SingletonWithPrototypeTest {

    @Test
    void prototypeFind() {
        AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(PrototypeBean.class);

        PrototypeBean bean1 = ac.getBean(PrototypeBean.class);
        bean1.addCount();
        assertThat(bean1.getCount()).isEqualTo(1);

        PrototypeBean bean2 = ac.getBean(PrototypeBean.class);
        bean2.addCount();
        assertThat(bean2.getCount()).isEqualTo(1);

        ac.close();
    }

    @Test
    void singletonClientUseProtype() {
        AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(ClientBean.class, PrototypeBean.class);

        ClientBean clientBean = ac.getBean(ClientBean.class);
        int count1 = clientBean.logic();
        assertThat(count1).isEqualTo(1);

        ClientBean clientBean2 = ac.getBean(ClientBean.class);
        int count2 = clientBean.logic();
        assertThat(count2).isEqualTo(1);
    }

    @Component
    @Scope("singleton")
    @RequiredArgsConstructor
    static class ClientBean {

//        private final PrototypeBean prototypeBean; // 생성 시점에 주입
//        private final ObjectProvider<PrototypeBean> prototypeBeanProvider;
        private final Provider<PrototypeBean> prototypeBeanProvider;

//        @Autowired
//        public ClientBean(PrototypeBean prototypeBean) {
            // ClientBean을 스프링빈에 등록하기 위하여 생성자로 등록하면서 해당 prototypeBean이 의존관계로 주입된다.
            // 이때 prototypeBean은 이미 만들어져 있다.
//            this.prototypeBean = prototypeBean;
//        }

        public int logic() {
//            PrototypeBean prototypeBean = prototypeBeanProvider.getObject();
            PrototypeBean prototypeBean = prototypeBeanProvider.get();
            prototypeBean.addCount();
            return prototypeBean.getCount();
        }
    }

    @Getter
    @Component
    @Scope("prototype")
    static class PrototypeBean {

        private int count = 0;

        public void addCount() {
            count += 1;
        }

        @PostConstruct
        public void init() {
            System.out.println("PrototypeBean.init " + this);
            System.out.println("count = " + count);
        }

        @PreDestroy
        public void close() {
            System.out.println("PrototypeBean.close");
        }
    }

}
