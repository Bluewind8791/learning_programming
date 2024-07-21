package hello.core;

import hello.core.discount.DiscountPolicy;
import hello.core.discount.RateDiscountPolicy;
import hello.core.interceptor.CustomInterceptor;
import hello.core.member.MemberRepository;
import hello.core.member.MemberService;
import hello.core.member.MemberServiceImpl;
import hello.core.member.MemoryMemberRepository;
import hello.core.order.OrderService;
import hello.core.order.OrderServiceImpl;
import lombok.RequiredArgsConstructor;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;


@Configuration
@RequiredArgsConstructor
public class AppConfig implements WebMvcConfigurer {

    private final CustomInterceptor customInterceptor;

    @Override
    public void addInterceptors(InterceptorRegistry registry) {
        registry.addInterceptor(customInterceptor);
    }

    // MemberRepository 연결
    @Bean
    public MemberRepository memberRepository() {
        System.out.println("called AppConfig.memberRepository");
        return new MemoryMemberRepository();
    }

    // DiscountPolicy 연결
    @Bean
    public DiscountPolicy discountPolicy() {
//        return new FixDiscountPolicy();
        // 정률 할인정책으로 변경
        return new RateDiscountPolicy();
    }

    // MemberService DI
    @Bean
    public MemberService memberService() {
        System.out.println("called AppConfig.memberService");
        return new MemberServiceImpl(memberRepository());
    }

    // OrderService DI
    @Bean
    public OrderService orderService() {
        System.out.println("called AppConfig.orderService");
        return new OrderServiceImpl(memberRepository(), discountPolicy());
    }

}
