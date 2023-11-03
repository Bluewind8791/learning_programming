package com.fastcampus.jpa.bookmanager.domain.converter;

import javax.persistence.AttributeConverter;
import javax.persistence.Converter;

import com.fastcampus.jpa.bookmanager.repository.dto.BookStatus;

@Converter
public class BookStatusConverter implements AttributeConverter<BookStatus, Integer> {

    @Override
    public Integer convertToDatabaseColumn(BookStatus attribute) { // BookStatus 객체를 받아서 DB에 저장할때 어떻게 할것인지
        return attribute.getCode();
    }

    @Override
    public BookStatus convertToEntityAttribute(Integer dbData) { // db에서 int값을 받아서 bookstatus를 만듦
        return dbData != null ? new BookStatus(dbData) : null; // null에 대한 exception 처리
    }
    
}
