package hello.core.beanfind;

import hello.core.AppConfig;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.config.BeanDefinition;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

class ApplicationContextInfoTest {

    AnnotationConfigApplicationContext ac = new AnnotationConfigApplicationContext(AppConfig.class);

    @Test
    @DisplayName("모든 Bean 출력하기")
    void findAllBeans() {
        String[] beanNames = ac.getBeanDefinitionNames();
        for (String beanName : beanNames) {
            Object bean = ac.getBean(beanName);
            System.out.println("name = " + beanName + "\nbean = " + bean);
        }

    }

    @Test
    @DisplayName("어플리케이션 bean 출력")
    void findAllApplicationBeans() {
        String[] beanNames = ac.getBeanDefinitionNames();
        for (String beanName : beanNames) {
            BeanDefinition beanDefinition = ac.getBeanDefinition(beanName);

            if (beanDefinition.getRole() == BeanDefinition.ROLE_APPLICATION) {
                Object bean = ac.getBean(beanName);
                System.out.println("name = " + beanName + "\nbean = " + bean);
            }
        }
    }

}
