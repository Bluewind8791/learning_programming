package com.example.calculator;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.extension.ExtendWith;
import org.mockito.Mock;
import org.mockito.Mockito;
import org.mockito.junit.jupiter.MockitoExtension;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;


@ExtendWith(MockitoExtension.class) // mocking
@SpringBootTest
public class DollarCalculatorTest {
    
    @Mock
    public MarketApi marketApi;

    @BeforeEach // test 실행되기 이전에
    public void init() {
        Mockito.lenient().when(marketApi.connect()).thenReturn(3000); // 1100 대신 3000을 return 시켜본다
    }


    @Test
    public void testHello() {
        System.out.println("Test hello");
    }

    @Test
    public void dollarTest() {
        MarketApi marketApi = new MarketApi();
		DollarCalculator dollarCalculator = new DollarCalculator(marketApi);
		dollarCalculator.init();

		Calculator calculator = new Calculator(dollarCalculator);

        // testing
        Assertions.assertEquals(22000, calculator.sum(10, 10));
        Assertions.assertEquals(0, calculator.minus(10, 10));
    }

    @Test
    public void mockTest() {

		DollarCalculator dollarCalculator = new DollarCalculator(marketApi);
		dollarCalculator.init();

		Calculator calculator = new Calculator(dollarCalculator);

        // testing
        Assertions.assertEquals(60000, calculator.sum(10, 10));
        Assertions.assertEquals(0, calculator.minus(10, 10));
    }
}
