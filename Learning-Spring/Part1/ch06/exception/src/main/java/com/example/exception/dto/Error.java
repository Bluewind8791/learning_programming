package com.example.exception.dto;

public class Error {
    
    private String field;
    private String message;
    private String invalidValue;

    public String getField() {
        return field;
    }
    public String getInvalidValue() {
        return invalidValue;
    }
    public String getMessage() {
        return message;
    }
    public void setField(String field) {
        this.field = field;
    }
    public void setInvalidValue(String invalidValue) {
        this.invalidValue = invalidValue;
    }
    public void setMessage(String message) {
        this.message = message;
    }

}
