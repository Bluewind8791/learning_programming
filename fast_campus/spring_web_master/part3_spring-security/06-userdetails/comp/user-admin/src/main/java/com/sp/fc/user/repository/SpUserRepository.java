package com.sp.fc.user.repository;

import java.util.Optional;

import com.sp.fc.user.domain.SpUser;

import org.springframework.data.jpa.repository.JpaRepository;

public interface SpUserRepository extends JpaRepository<SpUser, Long> {
    
    Optional<SpUser> findSpUserByEmail(String email);
    
}
