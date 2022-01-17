package com.fastcampus.jpa.bookmanager.domain.listener;

import java.time.LocalDateTime;

import javax.persistence.PrePersist;
import javax.persistence.PreUpdate;

public class MyEntityListener {
    
    @PrePersist
    public void prePersist(Object obj) {
        if (obj instanceof Auditable) {
            ((Auditable) obj).setCreatedAt(LocalDateTime.now());
            ((Auditable) obj).setUpdatedAt(LocalDateTime.now());
        }
    }

    @PreUpdate
    public void preUpdate(Object obj) {
        if (obj instanceof Auditable) {
            ((Auditable) obj).setUpdatedAt(LocalDateTime.now());
        }
    }
}
