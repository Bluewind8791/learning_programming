package com.example.exception.dto;

import java.util.List;

public class ErrorResponse {
    
    String statusCode;
    String requestUrl;
    String code;
    String message;
    String resultCode;

    List<Error> errorList;

    public String getCode() {
        return code;
    }
    public List<Error> getErrorList() {
        return errorList;
    }
    public String getMessage() {
        return message;
    }
    public String getRequestUrl() {
        return requestUrl;
    }
    public String getResultCode() {
        return resultCode;
    }
    public String getStatusCode() {
        return statusCode;
    }
    public void setCode(String code) {
        this.code = code;
    }
    public void setErrorList(List<Error> errorList) {
        this.errorList = errorList;
    }
    public void setMessage(String message) {
        this.message = message;
    }
    public void setRequestUrl(String requestUrl) {
        this.requestUrl = requestUrl;
    }
    public void setResultCode(String resultCode) {
        this.resultCode = resultCode;
    }
    public void setStatusCode(String statusCode) {
        this.statusCode = statusCode;
    }
    
}
