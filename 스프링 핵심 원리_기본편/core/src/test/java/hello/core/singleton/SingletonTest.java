package hello.core.singleton;

import hello.core.AppConfig;
import hello.core.member.MemberService;
import org.assertj.core.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import static org.assertj.core.api.Assertions.assertThat;

public class SingletonTest {

    @Test
    @DisplayName("스프링 없는 순수한 DI 컨테이너")
    void pureContainer() {
        AppConfig appConfig = new AppConfig();

        // 조회 : 호출할때마다 객체를 생성함
        MemberService memberService1 = appConfig.memberService();
        MemberService memberService2 = appConfig.memberService();

        assertThat(memberService1).isNotEqualTo(memberService2);

        /*
        그러므로 고객들이 요청을 날릴때마다 객체를 계속 생성하고 소멸하게됨.
        엄청난 메모리 낭비
        그러므로 객체를 딱 한개만 생성하고 공유하도록 설계를 하면 됨 -> 싱글톤 패턴
        */
    }

    @Test
    @DisplayName("싱글톤 패턴을 적용한 객체 사용")
    void singletonServiceTest() {
        SingletonService instance1 = SingletonService.getInstance();
        SingletonService instance2 = SingletonService.getInstance();

        assertThat(instance1).isSameAs(instance2);
        // same == 비교
        // equal .equals 비교
    }
}
