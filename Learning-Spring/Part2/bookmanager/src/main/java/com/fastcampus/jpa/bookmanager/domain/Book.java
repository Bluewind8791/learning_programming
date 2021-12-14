package com.fastcampus.jpa.bookmanager.domain;


import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToOne;

import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.NoArgsConstructor;
import lombok.ToString;


@Entity
@NoArgsConstructor
@Data
@ToString(callSuper = true)
@EqualsAndHashCode(callSuper = true)
public class Book extends BaseEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private Long id;

    private String Name;

    private String category;

    private Long authorId; // FK

    private Long publisherId; // FK

    @OneToOne(mappedBy = "book")
    @ToString.Exclude // toString을 제거하지않으면, 순환참조가 되어서 stack overflow error가 걸리게됨
    private BookReviewInfo bookReviewInfo;

}
