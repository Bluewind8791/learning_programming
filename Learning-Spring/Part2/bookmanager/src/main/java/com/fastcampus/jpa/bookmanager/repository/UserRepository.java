package com.fastcampus.jpa.bookmanager.repository;


import java.util.List;

import com.fastcampus.jpa.bookmanager.domain.User;

import org.springframework.data.jpa.repository.JpaRepository;



public interface UserRepository extends JpaRepository<User, Long> {
    List<User> findByName(String name);

    User findByEmail(String email);

    User getByEmail(String email);

    User readByEmail(String email);

    User queryByEmail(String email);

    User searchByEmail(String email);

    User streamByEmail(String email);

    User findUserByEmail(String email);
    User findSomethingByEmail(String email);

    List<User> findFirst1ByName(String name);
    List<User> findTop1ByName(String name);
}
