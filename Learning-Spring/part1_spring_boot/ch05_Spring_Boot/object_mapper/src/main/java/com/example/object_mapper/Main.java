package com.example.object_mapper;

import java.util.Arrays;
import java.util.List;

import com.example.object_mapper.dto.Car;
import com.example.object_mapper.dto.User;
import com.fasterxml.jackson.core.JsonProcessingException;
import com.fasterxml.jackson.core.type.TypeReference;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.node.ArrayNode;
import com.fasterxml.jackson.databind.node.ObjectNode;

public class Main {
    
    public static void main(String[] args) throws JsonProcessingException {
        
        System.out.println("main");

        ObjectMapper objectMapper = new ObjectMapper();

        User user = new User();
        user.setName("Ben");
        user.setAge(31);

        Car car1 = new Car();
        car1.setName("K5");
        car1.setCarNumber("1111");
        car1.setType("Sedan");

        Car car2 = new Car();
        car2.setName("Q5");
        car2.setCarNumber("2222");
        car2.setType("SUV");

        List<Car> carList = Arrays.asList(car1, car2);
        user.setCars(carList);

        System.out.println(user);


        // json으로 변경
        String json = objectMapper.writeValueAsString(user);
        System.out.println(json);


        JsonNode jsonNode = objectMapper.readTree(json);
        String _name = jsonNode.get("name").asText();
        int _age = jsonNode.get("age").asInt();
        System.out.println("name : " + _name);
        System.out.println("age : " + _age);

        // json에서 배열의 노드를 가져와야한다.
        JsonNode cars = jsonNode.get("cars");
        ArrayNode arrayNode = (ArrayNode)cars;

        // 형변환
        List<Car> _cars = objectMapper.convertValue(arrayNode, new TypeReference<List<Car>>(){});
        System.out.println(_cars);


        // json 값을 변환시킬 수 있다.
        ObjectNode objectNode = (ObjectNode) jsonNode;
        // fieldname, value
        objectNode.put("name", "steve");
        objectNode.put("age", "20");

        System.out.println(objectNode.toPrettyString());
    }
}
