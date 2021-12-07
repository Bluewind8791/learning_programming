package com.fastcampus.jpa.bookmanager.domain;

import org.junit.jupiter.api.Test;

public class UserTest {

    @Test
    void test() {
        User user = new User();
        user.setEmail("email");
        user.setName("Ben");

        System.out.println(">>>" + user);
    }
}
