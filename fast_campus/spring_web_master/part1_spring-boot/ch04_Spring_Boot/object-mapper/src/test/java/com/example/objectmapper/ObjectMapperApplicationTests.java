package com.example.objectmapper;

import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.databind.ObjectMapper;

import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

@SpringBootTest
class ObjectMapperApplicationTests {

	@Test
	void contextLoads() throws JsonProcessingException {
		System.out.println("--------------");

		// object mapper는 text jason -> object로 바꾸고
		// object -> text json 으로 바꿈

		// controller request json(text) -> object
		// response object -> json(text)

		var objectMapper = new ObjectMapper();

		// object -> text
		// object mapper는 get method를 사용한다. User class에 get method 없으면 error
		// object mapper를 사용할때는 메소드명 앞이 get으로 시작하지 않도록 유의할것.
		var user = new User("ben", 31, "010-1234-1234");
		var text = objectMapper.writeValueAsString(user);
		System.out.println(text);

		// text -> object
		// objectMapper는 default 생성자를 사용함. User의 default 생성자 생성
		var objectUser = objectMapper.readValue(text, User.class);
		System.out.println(objectUser);
	}

}
