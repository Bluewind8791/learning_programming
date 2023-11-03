package com.sp.fc.web;

import lombok.Data;
import lombok.Builder;
import lombok.NoArgsConstructor;
import lombok.AllArgsConstructor;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertFalse;
import static org.junit.jupiter.api.Assertions.assertTrue;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;
import org.springframework.expression.AccessException;
import org.springframework.expression.BeanResolver;
import org.springframework.expression.EvaluationContext;
import org.springframework.expression.ExpressionParser;
import org.springframework.expression.spel.standard.SpelExpressionParser;
import org.springframework.expression.spel.support.StandardEvaluationContext;



@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
class Person {
    private String name;
    private int height;

    public boolean over(int pivot) {
        return height >= pivot;
    }
}

@Data
@Builder
@NoArgsConstructor
@AllArgsConstructor
class Horse {
    private String name;
    private int height;

    public boolean over(int pivot) {
        return height >= pivot;
    }
}

public class SpELTest {
    
    ExpressionParser parser = new SpelExpressionParser();

    Person person = Person.builder()
        .name("홍길동").height(178).build();

    Horse nancy = Horse.builder()
        .name("nancy").height(160).build();


    @DisplayName("4. Context Test")
    @Test
    void test_4() {
        // bean test
        StandardEvaluationContext ctx = new StandardEvaluationContext();
        ctx.setBeanResolver(new BeanResolver() { // bean name 으로 bean 을 찾아줌
            @Override
            public Object resolve(EvaluationContext context, String beanName) throws AccessException {
                return beanName.equals("person") ? person : nancy;
            }
        });
        // context 에서 bean만 가져올수 있는것이 아니라 root 객체를 넣을 수 있다.
        ctx.setRootObject(person); // 이렇게 person 객체를 넣으면 한번에 접근해서 테스트 할 수 있다.
        ctx.setVariable("horse", nancy); // 또는 variable 로 horse 에 nancy 를 주고 # 으로 접근한다.
        assertTrue(parser.parseExpression("over(170)").getValue(ctx, Boolean.class));
        assertFalse(parser.parseExpression("#horse.over(170)").getValue(ctx, Boolean.class));

        // context 안에서 bean을 @person 으로 찾는다
        assertTrue(parser.parseExpression("@person.over(170)").getValue(ctx, Boolean.class));
        assertFalse(parser.parseExpression("@nancy.over(170)").getValue(ctx, Boolean.class));
    }




    @DisplayName("3. Call method")
    @Test
    void test_3() {
        assertTrue(parser.parseExpression("over(170)").getValue(person, Boolean.class));
        assertFalse(parser.parseExpression("over(170)").getValue(nancy, Boolean.class));
    }

    @DisplayName("2. Modify Value")
    @Test
    void test_2() {
        // 값을 변경한 다음 값이 제대로 변경하였는지 검사
        parser.parseExpression("name").setValue(person, "호나우두");
        assertEquals("호나우두", parser.parseExpression("name").getValue(person, String.class));
    }

    @DisplayName("1. Basic Test")
    @Test
    void test_1() {
        // 객체에서 "홍길동"을 스크립트로 꺼내서 paser에서 name 값을 꺼내서 그 값이 person 인지 검사
        assertEquals("홍길동", parser.parseExpression("name")
            .getValue(person, String.class));
    }

}
