package com.swagger.repository;

import org.springframework.data.jpa.repository.JpaRepository;

import com.swagger.domain.User;

public interface UserRepository extends JpaRepository<User, Long> {
    
}
