package hello.core;

import hello.core.discount.DiscountPolicy;
import hello.core.discount.FixDiscountPolicy;
import hello.core.discount.RateDiscountPolicy;
import hello.core.member.MemberService;
import hello.core.member.MemberServiceImpl;
import hello.core.member.MemoryMemberRepository;
import hello.core.order.OrderService;
import hello.core.order.OrderServiceImpl;

public class AppConfig {

    // MemberRepository 연결
    private MemoryMemberRepository getMemberRepository() {
        return new MemoryMemberRepository();
    }

    // DiscountPolicy 연결
    private DiscountPolicy getDiscountPolicy() {
//        return new FixDiscountPolicy();
        // 정률 할인정책으로 변경
        return new RateDiscountPolicy();
    }

    // MemberService DI
    public MemberService memberService() {
        return new MemberServiceImpl(getMemberRepository());
    }

    // OrderService DI
    public OrderService orderService() {
        return new OrderServiceImpl(getMemberRepository(), getDiscountPolicy());
    }

}
