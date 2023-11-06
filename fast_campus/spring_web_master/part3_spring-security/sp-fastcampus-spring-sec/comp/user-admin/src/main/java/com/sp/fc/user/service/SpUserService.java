package com.sp.fc.user.service;

import java.util.HashSet;
import java.util.Optional;
import java.util.stream.Collectors;

import com.sp.fc.user.domain.SpAuthority;
import com.sp.fc.user.domain.SpUser;
import com.sp.fc.user.repository.SpUserRepository;

import lombok.RequiredArgsConstructor;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.core.userdetails.UserDetailsService;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

@Service
@Transactional
@RequiredArgsConstructor
public class SpUserService implements UserDetailsService {

    private final SpUserRepository userRepository;
    

    @Override
    public UserDetails loadUserByUsername(String username) throws UsernameNotFoundException {
        return userRepository.findSpUserByEmail(username)
            .orElseThrow(() -> new UsernameNotFoundException(username));
    }

    public Optional<SpUser> findUser(String email) {
        return userRepository.findSpUserByEmail(email);
    }

    public SpUser save(SpUser user) {
        return userRepository.save(user);
    }

    public void addAuthority(Long userId, String authority) {
        userRepository.findById(userId).ifPresent(user -> { // find by userId, if not null ->
            SpAuthority newRole = new SpAuthority(user.getUserId(), authority); // make new role
            if (user.getAuthorities() == null) { // if user has no authority
                HashSet<SpAuthority> authorities = new HashSet<>(); // make hash type authorities
                authorities.add(newRole); // add new role
                user.setAuthorities(authorities); // set authority
                save(user);
            } else if (!user.getAuthorities().contains(newRole)) { // else if user doesn't contain newRole
                HashSet<SpAuthority> authorities = new HashSet<>(user.getAuthorities());
                authorities.add(newRole);
                user.setAuthorities(authorities);
                save(user);
            }
        });
    }
    
    public void removeAuthority(Long userId, String authority) {
        userRepository.findById(userId).ifPresent(user -> { // find by userId, if not null ->
            if (user.getAuthorities() == null) { // if user has no authority -> return
                return;
            }
            SpAuthority targetRole = new SpAuthority(user.getUserId(), authority); // set target role
            if (user.getAuthorities().contains(targetRole)) { // if user has target role
                user.setAuthorities(                          // user get authority which isn't target
                    user.getAuthorities().stream().filter(auth -> !auth.equals(targetRole)).collect(Collectors.toSet())
                );
            }
        });
    }
}
